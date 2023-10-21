#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int n; //规格
int qipan1[1000][1000]= {0},qipan2[1000][1000]= {0}; //1表   2实
bool shuying=1;//输赢
int choose;//键盘
int x=1,y=1;
int heibai=1;//1hei,2bai
bool p=1;//是否落子
int h;

int qian() {
	cout<<"欢迎使用  -五子棋 1.0-"<<endl<<endl<<"如果喜欢，请关注  -源900-  获知最新进展。"<<endl<<endl<<endl<<"提示：wsad选位，q落子；黑子先手";
	cout<<endl<<endl<<endl;
	system("pause");
	system("cls");
}

int guige() {
	system("cls");
	cout<<"请输入棋盘规格（请勿过大，否则出错！）：   ";
	cin>>n;
	system("cls");
}
//判断 qipan2[x][y]，heibai
int panduan() {
	h=1;//
	for(int i=1; i<=4; i++) {
		if(qipan2[x+i][y]==heibai)  {
			h++;
		} else {
			break;
		}
	}
	for(int i=-1; i>=-4; i--) {
		if(qipan2[x+i][y]==heibai)  {
			h++;
		} else {
			break;
		}
	}
	if(h>=5) {
		return 10;
	}
	h=1;//
	for(int i=1; i<=4; i++) {
		if(qipan2[x][y+i]==heibai)  {
			h++;
		} else {
			break;
		}
	}
	for(int i=-1; i>=-4; i--) {
		if(qipan2[x][y+i]==heibai)  {
			h++;
		} else {
			break;
		}
	}
	if(h>=5) {
		return 10;
	}
	h=1;//
	for(int i=1; i<=4; i++) {
		if(qipan2[x+i][y+i]==heibai)  {
			h++;
		} else {
			break;
		}
	}
	for(int i=-1; i>=-4; i--) {
		if(qipan2[x+i][y+i]==heibai)  {
			h++;
		} else {
			break;
		}
	}
	if(h>=5) {
		return 10;
	}
	h=1;//
	for(int i=1; i<=4; i++) {
		if(qipan2[x+i][y-i]==heibai)  {
			h++;
		} else {
			break;
		}
	}
	for(int i=-1; i>=-4; i--) {
		if(qipan2[x+i][y-i]==heibai)  {
			h++;
		} else {
			break;
		}
	}
	if(h>=5) {
		return 10;
	}
}
//输赢
int shuyingshuchu() {
	cout<<endl;
	if(heibai==1) {
		cout<<"●方胜！"<<endl;
	}
	if(heibai==2) {
		cout<<"○方胜！"<<endl;
	}
	cout<<endl;
	system("pause");

}

int xiaqi () {
	qipan1[1][1]=1;
	while(shuying) {
		system("cls");
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(qipan1[j][i]==0)  {
					cout<<"  ";
				}
				if(qipan1[j][i]==1) {
					cout<<"●";
				}
				if(qipan1[j][i]==2) {
					cout<<"○";
				}
			}
			cout<<endl;
		}
		p=1;
		while(p) {//落子
			qipan1[x][y]=qipan2[x][y];
			choose=getch();
			if(choose=='w'&&y-1>=1)  {
				y-=1;
				qipan1[x][y]=heibai;
				p=0;
			}
			if(choose=='s'&&y+1<=n) {
				y+=1;
				qipan1[x][y]=heibai;
				p=0;
			}
			if(choose=='a'&&x-1>=1) {
				x-=1;
				qipan1[x][y]=heibai;
				p=0;
			}
			if(choose=='d'&&x+1<=n) {
				x+=1;
				qipan1[x][y]=heibai;
				p=0;
			}
			if(choose=='q'&&qipan2[x][y]==0) {
				qipan2[x][y]=heibai;
				qipan1[x][y]=qipan2[x][y];
				//判断是否5子
				h=panduan();
				if(h==10) {
					shuying=0;
					break;
				}

				if(heibai==1) {
					heibai=2;
				} else {
					heibai=1;
				}
				p=0;
			}
		}
	}
}
//
int chushihua() {
	system("cls");

	n=0; //规格
	for(int i=1; i<=1000; i++) {
		for(int j=1; j<=1000; j++) {
			qipan1[i][j]=0;
			qipan2[i][j]=0;
		}
	}
	shuying=1;//输赢
	choose;//键盘
	x=1,y=1;
	heibai=1;//1hei,2bai
	p=1;//是否落子

	cout<<"再来一局 <<-"<<endl;
	cout<<"退出"<<endl;
	int ch,s=0;
	while(1) {
		//键盘
		ch=getch();
		if(ch=='w') {
			system("cls");
			cout<<"再来一局 <<-"<<endl;
			cout<<"退出"<<endl;
			s=1;
		}
		if(ch=='s') {
			system("cls");
			cout<<"再来一局"<<endl;
			cout<<"退出 <<-"<<endl;
			s=2;
		}
		if(ch==13&&s==1) {
			return 1;
		}
		if(ch==13&&s==2) {
			return 0;
		}
	}
}

int main() {
	system("color 70");
	qian();
	do {
		guige();
		xiaqi();
		shuyingshuchu();
	} while(chushihua()) ;
	system("cls");
	cout<<"本代码由 -源900- 编写"<<endl<<endl;
	return 0;
}
