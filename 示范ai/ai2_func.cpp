#include <bits/stdc++.h>
using namespace std;
int sx[8]= {-1,0,1,1,1,0,-1,-1},zy[8]= {1,1,1,0,-1,-1,-1,0}; //放到全局变量！！
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
	if(aa<1||aa>9||bb<1||bb>9||a[aa][bb]==ch1) flag=1;//是否堵上
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
	if(aa<1||aa>9||bb<1||bb>9||a[aa][bb]==ch2) flag=1;//是否堵上
	else flag=0;
	return cs;
}
void ai2() {
	int a[15][15],now;
	freopen("a.in","r",stdin);
	cin>>now;
	for(int i=1; i<=13; i++) for(int j=1; j<=13; j++) cin>>a[i][j];
	fclose(stdin);

	int x,y;

	if(now==1) {
		ch1='1',ch2='2';
	} else {
		ch1='2',ch2='1';
	}

	for(int i=1; i<=9; ++i) //堵截对方！！！
		for(int j=1; j<=9; ++j)
			if(a[i][j]=='0') {
				int cs=0;
				for(int k=0; k<8; ++k) {
					int flagk;
					int shuk=cha(i,j,k,flagk,a);//k方向上的棋子
					for(int l=0; l<8; ++l)
						if(l!=k) {
							int flagl;
							int shul=cha(i,j,l,flagl,a);
							if((k+4)%8==l) { //在一条直线上
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
	for(int i=1; i<=9; ++i) //自己！！！
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
	x=rand()%13+1,y=rand()%13+1;
	if(a[x][y]!=0) goto L2;
	a[x][y]=now;

	L1:;

	a[x][y]=now;
	freopen("a.in","w",stdout);
	cout<<3-now<<'\n';
	for(int i=1; i<=13; i++) {
		for(int j=1; j<=13; j++) cout<<a[i][j]<<" ";
		puts("");
	}
	fclose(stdout);
	freopen("a.out","w",stdout);
	cout<<x<<" "<<y<<'\n';
	fclose(stdout);
	return;
}
