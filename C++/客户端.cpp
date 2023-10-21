#include<bits/stdc++.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

int main() {
	WSADATA wsdata;
	WSAStartup(MAKEWORD(2, 2), &wsdata);

	SOCKET hSock =socket(PF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("10.1.1.225");
	servAddr.sin_port = htons(4096);

	connect(hSock, (SOCKADDR*)&servAddr, sizeof(servAddr));
	char s[1024] = {};
	recv(hSock, s, 1024, 0);
	cout <<s<<endl;
	system("pause");
	return 0;
}
