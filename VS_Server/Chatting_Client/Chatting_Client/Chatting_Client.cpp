
#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <WinSock2.h>
#include <string>

#pragma comment(lib, "ws2_32")


#define PORT 4578
#define PACKET_SIZE 1024
#define SERVER_IP "172.17.10.61"

using namespace std;

int main() {
	WSADATA wsaData;
	char buf[PACKET_SIZE];
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET SendRecvSocekt; //보내는 소켓
	SendRecvSocekt = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN tAddr = {};
	tAddr.sin_family = AF_INET;
	tAddr.sin_port = htons(PORT);
	tAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	connect(SendRecvSocekt, (SOCKADDR*)&tAddr, sizeof(tAddr));

	while (1) {
		printf("input data: ");
		cin.getline(buf, PACKET_SIZE);
		send(SendRecvSocekt, buf, sizeof(buf), 0);
		memset(buf, 0, PACKET_SIZE);
		recv(SendRecvSocekt, buf, PACKET_SIZE, 0);
		printf("[Server] : %s\n", buf);
		memset(buf, 0, PACKET_SIZE);
	}

	closesocket(SendRecvSocekt);

	WSACleanup();
	return 0;
}