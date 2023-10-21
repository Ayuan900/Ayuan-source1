#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

BOOL FindProcessHandleAndKill();// 关闭窗口杀掉程序
int stop();//窗口关闭引子
int zhuye();//主目录页 

int zhuye() {
	
} 

// 关闭窗口杀掉程序
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

//窗口关闭引子
int stop() {
	HWND hWnd = ::GetForegroundWindow();
	if (FindProcessHandleAndKill(hWnd))
		return TRUE;
	return FALSE;
}




int main() {
	system("color 70") ;
	cout<<"                                              ----- 源900工作室 -----"<<endl;
	cout<<"                                                  【-- 登录 --】"<<endl;
	cout<<"                                                       退出"<<endl;
	int ch,s=0;
	while(1) {
		//键盘
		ch=getch();
		if(ch=='w') {
			system("cls");
			cout<<"                                              ----- 源900工作室 -----"<<endl;
			cout<<"                                                  【-- 登录 --】"<<endl;
			cout<<"                                                       退出"<<endl;
			s=1;
		}
		if(ch=='s') {
			system("cls");
			cout<<"                                              ----- 源900工作室 -----"<<endl;
			cout<<"                                                       登录"<<endl;
			cout<<"                                                  【-- 退出 --】"<<endl;
			s=2;
		}
		if(ch==13&&s==2) {
			stop();
		}
	}
}
