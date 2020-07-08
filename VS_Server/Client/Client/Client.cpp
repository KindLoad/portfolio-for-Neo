
#include <stdio.h>
#include <WinSock2.h>
#include <string>

#pragma comment(lib, "ws2_32")


#define PORT 4578
#define PACKET_SIZE 1024
#define SERVER_IP "172.17.10.61"

int main() {
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET hSocket;
	hSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN tAddr = {};
	tAddr.sin_family = AF_INET;
	tAddr.sin_port = htons(PORT);
	tAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	connect(hSocket, (SOCKADDR*)&tAddr, sizeof(tAddr));

	char cMsg[100];

	scanf("%[^\n]", cMsg);
	send(hSocket, cMsg, strlen(cMsg), 0);

	char cBuffer[PACKET_SIZE] = {};
	recv(hSocket, cBuffer, PACKET_SIZE, 0);

	printf("Recv Msg : %s\n", cBuffer);

	closesocket(hSocket);

	WSACleanup();
	return 0;
}