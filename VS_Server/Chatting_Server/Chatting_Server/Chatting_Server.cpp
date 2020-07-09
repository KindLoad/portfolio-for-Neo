#include <stdio.h>
#include <WinSock2.h>
#include <iostream>

#pragma comment(lib, "ws2_32")

#define PORT 4578
#define PACKET_SIZE 1024

using namespace std;

int main() {
	WSADATA wsaData;
	char buf[PACKET_SIZE];
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET RecvSocket; // 받는 소켓(연결용)
	RecvSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN Client_Addr, ListenAddr = {}; //소켓 연결 클래스
	ListenAddr.sin_family = AF_INET;
	ListenAddr.sin_port = htons(PORT);//조심
	ListenAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(RecvSocket, (SOCKADDR*)&ListenAddr, sizeof(ListenAddr)); //bind 연결
	listen(RecvSocket, SOMAXCONN); //대기

	
	int Clinet_size = sizeof(Client_Addr);
	SOCKET SendRecvSocket = accept(RecvSocket, (SOCKADDR*)&Client_Addr, &Clinet_size); // 소켓을 받음

	while (1) {
		recv(SendRecvSocket, buf, sizeof(buf), 0);
		printf("[client]:%s\n", buf);
		char send_buf[PACKET_SIZE];
		memset(send_buf, 0, PACKET_SIZE);
		printf("input data: ");
		cin.getline(send_buf, PACKET_SIZE);
		send(SendRecvSocket, send_buf, sizeof(send_buf), 0);
	}
	closesocket(SendRecvSocket);
	closesocket(RecvSocket);

	WSACleanup();
	return 0;
}