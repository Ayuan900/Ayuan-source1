#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

BOOL FindProcessHandleAndKill();// �رմ���ɱ������
int stop();//���ڹر�����
int zhuye();//��Ŀ¼ҳ 

int zhuye() {
	
} 

// �رմ���ɱ������
BOOL FindProcessHandleAndKill(HWND hWnd) {
	DWORD   ProcessID;
	HANDLE   hProcess;
	if (hWnd == NULL) {
		return   FALSE;
	} else {
		if (GetWindowThreadProcessId(hWnd, &ProcessID) == 0) { //&#65418;&#65383;&#65392;&#65436;
			return FALSE;
		} else {
			hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);
			if (hProcess == NULL) {
				return FALSE;
			} else {
				if (TerminateProcess(hProcess, 0)) {
					return TRUE;
				} else {
					return FALSE;
				}
			}
		}
	}
}

//���ڹر�����
int stop() {
	HWND hWnd = ::GetForegroundWindow();
	if (FindProcessHandleAndKill(hWnd))
		return TRUE;
	return FALSE;
}




int main() {
	system("color 70") ;
	cout<<"                                              ----- Դ900������ -----"<<endl;
	cout<<"                                                  ��-- ��¼ --��"<<endl;
	cout<<"                                                       �˳�"<<endl;
	int ch,s=0;
	while(1) {
		//����
		ch=getch();
		if(ch=='w') {
			system("cls");
			cout<<"                                              ----- Դ900������ -----"<<endl;
			cout<<"                                                  ��-- ��¼ --��"<<endl;
			cout<<"                                                       �˳�"<<endl;
			s=1;
		}
		if(ch=='s') {
			system("cls");
			cout<<"                                              ----- Դ900������ -----"<<endl;
			cout<<"                                                       ��¼"<<endl;
			cout<<"                                                  ��-- �˳� --��"<<endl;
			s=2;
		}
		if(ch==13&&s==2) {
			stop();
		}
	}
}
