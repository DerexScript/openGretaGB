#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)

//IP Header
typedef struct ip_hdr{
	unsigned char ip_header_len:4;
	unsigned char ip_version :4;
	unsigned char ip_tos;
	unsigned short ip_total_length;
	unsigned short ip_id;
	unsigned char ip_frag_offset :5;
	unsigned char ip_more_fragment :1;
	unsigned char ip_dont_fragment :1;
	unsigned char ip_reserved_zero :1;
	unsigned char ip_frag_offset1;
	unsigned char ip_ttl;
	unsigned char ip_protocol;
	unsigned short ip_checksum;
	unsigned int ip_srcaddr;
	unsigned int ip_destaddr;
} IPV4_HDR;

// TCP header
typedef struct tcp_header{
	unsigned short source_port;
	unsigned short dest_port;
	unsigned int sequence;
	unsigned int acknowledge;
	unsigned char ns :1;
	unsigned char reserved_part1:3;
	unsigned char data_offset:4;
	unsigned char fin :1;
	unsigned char syn :1;
	unsigned char rst :1;
	unsigned char psh :1;
	unsigned char ack :1;
	unsigned char urg :1;
	unsigned char ecn :1;
	unsigned char cwr :1;
	unsigned short window;
	unsigned short checksum;
	unsigned short urgent_pointer;
} TCP_HDR;

void StartSniffing(SOCKET sniffer);
int ProcessPacket(char* Buffer, int Size);
int monitorTCPPacket(char* Buffer, int Size);

int socks() {
    WSADATA wsaData;
    SOCKET sniffer = INVALID_SOCKET;
    struct sockaddr_in dest;
    int in = 0;

    // Initialize Winsock
    //cout << "Iniciando WinSock..." << endl;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        //cout << "Falha ao iniciar Socket" << endl << endl;
        system("pause>null");
        return 1;
    }
    //cout << "WinSock iniciado com sucesso!" << endl << endl;

	//Create a RAW Socket
	//cout << "Criando RAW Socket..." << endl;
	sniffer = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
	if (sniffer == INVALID_SOCKET){
		//cout << "Falha ao criar RAW Socket." << endl << endl;
		system("pause>null");
		return 1;
	}
	//cout << "RAW Socket criado com sucesso!" << endl << endl;

    //Get my IP from the local host
    //cout << "Obtendo meu IP local..." << endl;
    char myHN[80];
    if (gethostname(myHN, sizeof(myHN)) == SOCKET_ERROR){
        //cout << "Erro ao obter meu IP local" << endl << endl;
        system("pause>null");
        return 1;
    }
    struct hostent *phe = gethostbyname(myHN);
    if (phe == 0){
        //cout << "Erro ao obter meu IP local" << endl << endl;
        system("pause>null");
        return 1;
    }
    for (in = 0; phe->h_addr_list[in] != NULL; ++in){
        memcpy(&dest.sin_addr.s_addr, phe->h_addr_list[in], sizeof(struct in_addr));
    }
    in -= 1;
    dest.sin_family = AF_INET;
    dest.sin_port = 0;
    //cout << "IP local obtido com sucesso: " << inet_ntoa(dest.sin_addr) << endl << endl;

    //Binding socket to local system and port 0 ...
    //cout << "Ligando socket ao endereco " << inet_ntoa(dest.sin_addr) << ", na porta 0!" << endl << endl;
    if (bind(sniffer,(struct sockaddr *)&dest,sizeof(dest)) == SOCKET_ERROR){
		//cout << "Ligacao ao endereco " << inet_ntoa(dest.sin_addr) << ", falhou..." << endl << endl;
		system("pause>null");
		return 1;
	}
	//cout << "Ligacao ao endereco " << inet_ntoa(dest.sin_addr) << ", realizada com sucesso!" << endl << endl;

    //Enable this socket with the power to sniff : SIO_RCVALL is the key Receive ALL ;)
    int j=1;
    //cout << "Configurando o socket para farejar ..." << endl;
	if (WSAIoctl(sniffer, SIO_RCVALL, &j, sizeof(j), 0, 0, (LPDWORD) &in , 0 , 0) == SOCKET_ERROR){
		//cout << "WSAIoctl() falhou." << endl << endl;
		system("pause>null");
		return 1;
	}
	//cout << "Socket configurado com sucesso!" << endl << endl;

	//cout << "Comecando a fareijar" << endl << endl;
	StartSniffing(sniffer);

    WSACleanup();
    system("pause>null");
    return 0;
}

void StartSniffing(SOCKET sniffer){
	char *Buffer = (char *)malloc(65536);
	int mangobyte;
	int control = 0;
	if (Buffer == NULL){
		//cout << "malloc() failed." << endl;
		return;
	}
	do{
		mangobyte = recvfrom(sniffer , Buffer , 65536 , 0 , 0 , 0);
		if(mangobyte > 0){
			control = ProcessPacket(Buffer, mangobyte);
		}else{
			//cout << "recvfrom() failed." << endl;
		}
	}while (mangobyte > 0 && control == 0);
	free(Buffer);
}

int ProcessPacket(char* Buffer, int Size){
    IPV4_HDR *iphdr;
	iphdr = (IPV4_HDR *)Buffer;
	int control = 0;
	switch (iphdr->ip_protocol) {
		case 6: //TCP Protocol
            control = monitorTCPPacket(Buffer,Size);
            return control;
		break;
	}
	return 0;
}

int monitorTCPPacket(char* Buffer, int Size){
    unsigned short iphdrlen;
    int control = 0;
    IPV4_HDR *iphdr;
    struct sockaddr_in dest;
    iphdr = (IPV4_HDR *)Buffer;
    iphdrlen = iphdr->ip_header_len*4;
    TCP_HDR *tcpheader;
    tcpheader=(TCP_HDR*)(Buffer+iphdrlen);
    memset(&dest, 0, sizeof(dest));
	dest.sin_addr.s_addr = iphdr->ip_destaddr;
    if(strcmp(inet_ntoa(dest.sin_addr), "192.168.101.248") == 0){ //informe o ip do servidor onde ser� feita a requisi��o
        char findPost[] = "POST /gxn.php HTTP/1.1";
        char comparePost[strlen(findPost)];
        char getPost[strlen(Buffer+iphdrlen+tcpheader->data_offset*4)];
        ZeroMemory(getPost, strlen(Buffer+iphdrlen+tcpheader->data_offset*4));
        strcpy(getPost, Buffer+iphdrlen+tcpheader->data_offset*4);
        getPost[strlen(getPost)] = '\0';
        for(int i = 0; i < (signed)strlen(findPost); i++){
            comparePost[i] = getPost[i];
        }
        comparePost[22] = '\0';
        if(strcmp(comparePost, findPost) == 0){
            //cout << getPost << endl;
            control = 1;
        }
        ZeroMemory(Buffer+iphdrlen+tcpheader->data_offset*4, Size);
	}
	return control;
}
