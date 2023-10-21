#include<bits/stdc++.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

int main() {
	WSADATA wsdata;
	WSAStartup(MAKEWORD(2,2),&wsdata);

	SOCKET hSersock=socket(PF_INET,SOCK_STREAM,0);

	SOCKADDR_IN servAddr;
	servAddr.sin_family=AF_INET;
	servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servAddr.sin_port=htons(4096);
	bind(hSersock,(SOCKADDR*)&servAddr,sizeof(servAddr));

	listen(hSersock,5);

	SOCKADDR_IN clnAddr;
	int clntAddrSz=sizeof(clnAddr);
	SOCKET hSock =accept(hSersock,(SOCKADDR*)&servAddr,&clntAddrSz);

	cout<<"连接成功！"<<endl;
	char s[1024]="发送的信息";
	send(hSock,s,1024,0);
	cout<<"已发送信息！"<<endl;
	system("pause");
	return 0;
}
