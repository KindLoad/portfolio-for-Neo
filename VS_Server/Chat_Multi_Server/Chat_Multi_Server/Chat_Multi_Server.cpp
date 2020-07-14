#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <thread>
#include <cstring>
#include <string>
#include <vector>

#define PACKET_SIZE 1024
#define PORT 4578

#pragma comment (lib , "ws2_32.lib")

using namespace std;

void __cdecl Recvthread(void* p) {
	SOCKET sock = (SOCKET)p;
	char buf[PACKET_SIZE];
	
    while (true) {
        //수신
        int recvsize = recv(sock,buf, sizeof(buf), 0);
        if (recvsize <= 0)
        {
            printf("connect end\n");
            break;
        }

        buf[recvsize] = '\0'; //문장 끝 지정
        printf("client >> %s\n", buf);

        //전송
        int sendsize = send(sock, buf, strlen(buf), 0);
        if (sendsize <= 0) break;
    }
    closesocket(sock);
}

int main()
{
	//준비 과정
	WSADATA wsaData;
	char buf[PACKET_SIZE];
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//받는 소켓 지정
	SOCKET RecvSocket; // 받는 소켓(연결용)
	RecvSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);


	//서버에 소켓 정보를 입력
	SOCKADDR_IN ListenAddr = {}; //소켓 연결 클래스
	ListenAddr.sin_family = AF_INET;
	ListenAddr.sin_port = htons(PORT);//조심
	ListenAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	//연결
	bind(RecvSocket, (SOCKADDR*)&ListenAddr, sizeof(ListenAddr)); //bind 연결
	listen(RecvSocket, 5); //5인만 대기

	SOCKADDR_IN Client_Addr = { 0 };
	int Client_size = sizeof(Client_Addr);

	while (1) {
		SOCKET Client_sock = accept(RecvSocket, (SOCKADDR*)&Client_Addr, &Client_size);
		printf("클라이언트 접속\n");
		printf("IP : %s, 포트 : %d, \n",inet_ntoa(Client_Addr.sin_addr), Client_Addr.sin_port);
		_beginthread(Recvthread, NULL, (void*)Client_sock);
	}
	closesocket(RecvSocket);

	WSACleanup();
	return 0;


}

