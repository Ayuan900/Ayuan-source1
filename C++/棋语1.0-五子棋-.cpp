#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int n; //���
int qipan1[1000][1000]= {0},qipan2[1000][1000]= {0}; //1��   2ʵ
bool shuying=1;//��Ӯ
int choose;//����
int x=1,y=1;
int heibai=1;//1hei,2bai
bool p=1;//�Ƿ�����
int h;

int qian() {
	cout<<"��ӭʹ��  -������ 1.0-"<<endl<<endl<<"���ϲ�������ע  -Դ900-  ��֪���½�չ��"<<endl<<endl<<endl<<"��ʾ��wsadѡλ��q���ӣ���������";
	cout<<endl<<endl<<endl;
	system("pause");
	system("cls");
}

int guige() {
	system("cls");
	cout<<"���������̹��������󣬷����������   ";
	cin>>n;
	system("cls");
}
//�ж� qipan2[x][y]��heibai
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
//��Ӯ
int shuyingshuchu() {
	cout<<endl;
	if(heibai==1) {
		cout<<"��ʤ��"<<endl;
	}
	if(heibai==2) {
		cout<<"��ʤ��"<<endl;
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
					cout<<"��";
				}
				if(qipan1[j][i]==2) {
					cout<<"��";
				}
			}
			cout<<endl;
		}
		p=1;
		while(p) {//����
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
				//�ж��Ƿ�5��
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

	n=0; //���
	for(int i=1; i<=1000; i++) {
		for(int j=1; j<=1000; j++) {
			qipan1[i][j]=0;
			qipan2[i][j]=0;
		}
	}
	shuying=1;//��Ӯ
	choose;//����
	x=1,y=1;
	heibai=1;//1hei,2bai
	p=1;//�Ƿ�����

	cout<<"����һ�� <<-"<<endl;
	cout<<"�˳�"<<endl;
	int ch,s=0;
	while(1) {
		//����
		ch=getch();
		if(ch=='w') {
			system("cls");
			cout<<"����һ�� <<-"<<endl;
			cout<<"�˳�"<<endl;
			s=1;
		}
		if(ch=='s') {
			system("cls");
			cout<<"����һ��"<<endl;
			cout<<"�˳� <<-"<<endl;
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
	cout<<"�������� -Դ900- ��д"<<endl<<endl;
	return 0;
}
