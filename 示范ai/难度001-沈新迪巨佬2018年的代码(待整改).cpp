#include <bits/stdc++.h>
using namespace std;
int sx[8]= {-1,0,1,1,1,0,-1,-1},zy[8]= {1,1,1,0,-1,-1,-1,0}; //�ŵ�ȫ�ֱ�������
char ch1,ch2;
int cha(int aa,int bb,int fx,int &flag,int a[15][15]) {
	int cs=0;
	aa+=sx[fx];
	bb+=zy[fx];
	while(aa>0&&aa<=9&&bb>0&&bb<=9&&a[aa][bb]==ch2) {
		cs++;
		aa+=sx[fx];
		bb+=zy[fx];
	}
	if(aa<1||aa>9||bb<1||bb>9||a[aa][bb]==ch1) flag=1;//�Ƿ����
	else flag=0;
	return cs;
}
int cha2(int aa,int bb,int fx,int &flag,int a[15][15]) {
	int cs=0;
	aa+=sx[fx];
	bb+=zy[fx];
	while(aa>0&&aa<=9&&bb>0&&bb<=9&&a[aa][bb]==ch1) {
		cs++;
		aa+=sx[fx];
		bb+=zy[fx];
	}
	if(aa<1||aa>9||bb<1||bb>9||a[aa][bb]==ch2) flag=1;//�Ƿ����
	else flag=0;
	return cs;
}
pair <int,int> ai2(vector<vector<int> >a,int now) {
	int x,y;
	if(now==1) {
		ch1='1',ch2='2';
	} else {
		ch1='2',ch2='1';
	}
	for(int i=1; i<=9; ++i) //�½ضԷ�������
		for(int j=1; j<=9; ++j)
			if(a[i][j]=='0') {
				int cs=0;
				for(int k=0; k<8; ++k) {
					int flagk;
					int shuk=cha(i,j,k,flagk,a);//k�����ϵ�����
					for(int l=0; l<8; ++l)
						if(l!=k) {
							int flagl;
							int shul=cha(i,j,l,flagl,a);
							if((k+4)%8==l) { //��һ��ֱ����
								if(shuk+shul>=4) {
									x=i,y=j;
									goto L1;
								}
								if((shuk==3&&!flagk)||(shul==3&&!flagl)) {
									x=i,y=j;
									goto L1;
								}
								if(shuk+shul==3&&!flagl&&!flagk) {
									x=i,y=j;
									goto L1;
								}
								if(shuk+shul==3&&(!flagl||!flagk)) {
									cs++;
									if(cs>=3) {
										x=i,y=j;
										goto L1;
									}
								}
								if(shuk+shul==2&&!flagl&&!flagk) {
									cs++;
									if(cs>=3) {
										x=i,y=j;
										goto L1;
									}
								}
							} else {
								if(shul>=2&&shuk>=2) {
									if(shul>2&&shuk>2) {
										x=i,y=j;
										goto L1;
									} else if(!flagl||!flagk) {
										x=i,y=j;
										goto L1;
									}
								}
							}
						}
				}
			}
	for(int i=1; i<=9; ++i) //�Լ�������
		for(int j=1; j<=9; ++j)
			if(a[i][j]==' ') {
				int cs=0;
				for(int k=0; k<8; ++k) {
					int flagk;
					int shuk=cha2(i,j,k,flagk,a);
					for(int l=0; l<8; ++l)
						if(l!=k) {
							int flagl;
							int shul=cha2(i,j,l,flagl,a);
							if((k+4)%8==l) {
								if(shuk+shul>=4) {
									x=i,y=j;
									goto L1;
								}
								if((shuk==3&&!flagk)||(shul==3&&!flagl)) {
									x=i,y=j;
									goto L1;
								}
								if(shuk+shul==3&&!flagl&&!flagk) {
									x=i,y=j;
									goto L1;
								}
								if(shuk+shul==3&&(!flagl||!flagk)) {
									cs++;
									if(cs>=3) {
										x=i,y=j;
										goto L1;
									}
								}
								if(shuk+shul==2&&!flagl&&!flagk) {
									cs++;
									if(cs>=3) {
										x=i,y=j;
										goto L1;
									}
								}
							} else {
								if(shul>=2&&shuk>=2) {
									if(shul>2&&shuk>2) {
										x=i,y=j;
										goto L1;
									} else if(!flagl||!flagk) {
										x=i,y=j;
										goto L1;
									}
								}
							}
						}
				}
			}
L2:
	;
	x=rnd()%13+1,y=rnd()%13+1;
	if(a[x][y]!=0) goto L2;
	return make_pair(x,y);
}
