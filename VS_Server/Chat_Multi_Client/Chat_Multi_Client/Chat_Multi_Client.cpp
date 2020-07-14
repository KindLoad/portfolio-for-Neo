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
	//준비 단계
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	// 보내는 소켓 생성
	SOCKET SendRecvSocekt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//서버 정보를 입력
	SOCKADDR_IN tAddr = {};
	tAddr.sin_family = AF_INET;
	tAddr.sin_port = htons(PORT);
	tAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

	//연결
	connect(SendRecvSocekt, (SOCKADDR*)&tAddr, sizeof(tAddr));

	while (1) {
		char buf[PACKET_SIZE];
		printf(">> ");
		scanf(" %[^\n]", buf);
		printf(" ");

		//메세지 전송
		int SendSize = send(SendRecvSocekt, buf, strlen(buf), 0);
		int RecvSize = recv(SendRecvSocekt, buf, sizeof(buf), 0);
		
		buf[RecvSize] = '\0';
		//printf("server >> %s\n", buf);
	}
	closesocket(SendRecvSocekt);

	WSACleanup();
	return 0;
}