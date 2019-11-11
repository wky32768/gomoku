/*
网上抄的，菜到爆炸
*/
int com[16][16],luozi[16][16];
int c,d;
void jushi() { //这是判断落子重要性的函数
	int x,y,i,m,n,lianzi1=0,lianzi2=0,life=0;
	memset(com,0,sizeof(com));
	for(x=1; x<=15; x++)
		for(y=1; y<=15; y++) {
			if(a[x][y]==0) {
				for(m=-1; m<=1; m++)
					for(n=-1; n<=1; n++) {
						if(m!=0 || n!=0) {
							for(i=1; i<=4; i++) {
								if( x+i*m>=1 && x+i*m<=15 && y+i*n>=1 && y+i*n<=15 && a[x+i*m][y+i*n]==now) {
									lianzi1++;
								} else if(a[x+i*m][y+i*n]==0) {
									life++;
									break;
								} else {
									break;
								}
							}
							for(i=-1; i>=-4; i--) {
								if( x+i*m>=1 && x+i*m<=15 && y+i*n>=1 && y+i*n<=15 && a[x+i*m][y+i*n]==now) {
									lianzi1++;
								} else if(a[x+i*m][y+i*n]==0) {
									life++;
									break;
								} else {
									break;
								}
							}
							if(lianzi1==1) {
								com[x][y]+=1;
							} else if(lianzi1==2) {
								if(life==1) {
									com[x][y]+=5;
								} else if(life==2) {
									com[x][y]+=10;
								}
							} else if(lianzi1==3) {
								if(life==1) {
									com[x][y]+=20;
								} else if(life==2) {
									com[x][y]+=100;
								}
							} else if(lianzi1==4) {
								com[x][y]+=500;
							}
							life=0;
							for(i=1; i<=4; i++) {
								if( x+i*m>=1 && x+i*m<=15 && y+i*n>=1 && y+i*n<=15 && a[x+i*m][y+i*n]==3-now) {
									lianzi2++;
								} else if(a[x+i*m][y+i*n]==0) {
									life++;
									break;
								} else {
									break;
								}
							}
							for(i=-1; i>=-4; i--) {
								if( x+i*m>=1 && x+i*m<=15 && y+i*n>=1 && y+i*n<=15 && a[x+i*m][y+i*n]==3-now) {
									lianzi2++;
								} else if(luozi[x+i*m][y+i*n]==0) {
									life++;
									break;
								} else {
									break;
								}
							}
							if(lianzi2==1) {
								com[x][y]+=2;
							} else if(lianzi2==2) {
								if(life==1) {
									com[x][y]+=8;
								} else if(life==2) {
									com[x][y]+=30;
								}
							} else if(lianzi2==3) {
								if(life==1) {
									com[x][y]+=50;
								} else if(life==2) {
									com[x][y]+=200;
								}
							} else if(lianzi2==4) {
								com[x][y]+=1000;
							}
							lianzi1=0;
							lianzi2=0;
							life=0;
						}
					}
			}
		}
}
pair <int,int> ak(vector<vector<int>/**/>a,int UNUSED(now))  {
	int i,j,max=0;
	jushi();
	for(i=1; i<=15; i++)
		for(j=1; j<=15; j++) {
			if(com[i][j]>max) {
				max=com[i][j];
				c=i;
				d=j;
			}
		}
	if(c>=1 && c<=15 && d>=1 && d<=15) return make_pair(c,d);
	else {
		srand((int)time(0));
		L1:;
		int x=rnd()%15+1,y=rand()%15+1;
		if(a[x][y]!=0) goto L1;
		return make_pair(x,y);
	}
}
