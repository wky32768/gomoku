#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int a[15][15],x,y,now,win1,win2;
unsigned long long rnd(){
    static unsigned long long i=(19260817)^((int)(time(0))),j;
    i=i*i;
    i=i/100000;
    i=i%10000000000;
    j=i/100000;
    return j;
}
#include "ai1_func.cpp"
#include "ai2_func.cpp"
bool over() {
	For(i,1,13) For(j,1,13) {
		if(j+4<=13) {
			if(a[i][j]!=0 && a[i][j]==a[i][j+1] && a[i][j+1]==a[i][j+2] && a[i][j+2]==a[i][j+3] && a[i][j+3]==a[i][j+4]) return 1;
		}
		if(i+4<=13) {
			if(a[i][j]!=0 && a[i][j]==a[i+1][j] && a[i+1][j]==a[i+2][j] && a[i+2][j]==a[i+3][j] && a[i+3][j]==a[i+4][j]) return 1;
		}
		if(i+4<=13 && j+4<=13) {
			if(a[i][j]!=0 && a[i][j]==a[i+1][j+1] && a[i+1][j+1]==a[i+2][j+2] && a[i+2][j+2]==a[i+3][j+3] && a[i+3][j+3]==a[i+4][j+4]) return 1;
		}
		if(i+4<=13 && j-4>=1) {
			if(a[i][j]!=0 && a[i][j]==a[i+1][j-1] && a[i+1][j-1]==a[i+2][j-2] && a[i+2][j-2]==a[i+3][j-3] && a[i+3][j-3]==a[i+4][j-4]) return 1;
		}
	}
	return 0;
}
void f_in(char *a) {
	freopen(a,"r",stdin);
}
void f_out(char *a) {
	freopen(a,"w",stdout);
}
#define cl_in() fclose(stdin)
#define cl_out() fclose(stdout)
signed main() {
	puts("how many plays do you want to play?");
	int tot;
	cin>>tot;
	f_out("log.txt");
	fclose(stdout);
	for(int gg=1; gg<=tot; gg++) {
		memset(a,0,sizeof a);
		f_out("a.in");
		puts("1");
		For(i,1,13) {
			For(j,1,13) cout<<"0 ";
			puts("");
		}
		cl_out();
		while(!over()) {
			ai1();
			f_in("a.out");
			cin>>x>>y;
			a[x][y]=1;
			fclose(stdin);
			if(over()) {
				freopen("log.txt","a",stdout);
				puts("ai1 win!");
				For(i,1,13) {
					For(j,1,13) {
						if(a[i][j]==0) cout<<"_ ";
						else if(a[i][j]==1) cout<<"O ";
						else if(a[i][j]==2) cout<<"X ";
					}
					puts("");
				}
				win1++;
				goto L3;
			}
			f_out("a.in");
			puts("2");
			For(i,1,13) {
				For(j,1,13) cout<<a[i][j]<<" ";
				puts("");
			}
			fclose(stdout);
			ai2();
			f_in("a.out");
			cin>>x>>y;
			a[x][y]=2;
			fclose(stdin);
			if(over()) {
				freopen("log.txt","a",stdout);
				srand((int)time(0));
				puts("ai2 win!");
				For(i,1,13) {
					For(j,1,13) {
						if(a[i][j]==0) cout<<"_ ";
						else if(a[i][j]==1) cout<<"O ";
						else if(a[i][j]==2) cout<<"X ";
					}
					puts("");
				}
				win2++;
				goto L3;
			} 
			f_out("a.in");
			puts("1");
			For(i,1,13) {
				For(j,1,13) cout<<a[i][j]<<" ";
				puts("");
			}
			fclose(stdout);
		}
L3:
		;
		cout<<"Game"<<gg<<"/"<<tot<<"\n\n\n";
		cl_out();
		f_out("CON");
		cout<<gg<<"/"<<tot<<'\n';
		cl_out();
	}
	freopen("log.txt","a",stdout);
	cout<<win1<<" "<<win2<<"\n";
	return 0;
}
