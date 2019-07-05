#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int x,y,now,win1,win2;
vector<vector<int> >a;
unsigned long long rnd() {
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
pair <int,int> ans;
void clr(vector<vector<int> >&a,int x,int y){
	a.resize(0);
	a.resize(x);
	for(int i=0;i<x;i++){
		a[i].resize(0);
		a[i].resize(y); 
	}
}
signed main() {
	puts("how many plays do you want to play?");
	int tot;
	cin>>tot;
	f_out("log.txt");
	fclose(stdout);
	for(int gg=1; gg<=tot; gg++) {
		clr(a,15,15);
		while(!over()) {
			int tot=0;
			for(int i=1;i<=13;i++) for(int j=1;j<=13;j++) if(a[i][j]!=0) tot++;
			if(tot==169) break;
			ans=ai1(a,1);
			a[ans.first][ans.second]=1;
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
			ans=ai2(a,2);
			a[ans.first][ans.second]=2;
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
		}
L3:
		;
		cout<<"Game"<<gg<<"/"<<tot<<"\n\n\n";
		cl_out();
		f_out("CON");
		if(gg%100==0 || gg==tot) cout<<gg<<"/"<<tot<<"==="<<win1<<" "<<win2<<'\n';
		cl_out();
	}
	freopen("log.txt","a",stdout);
	cout<<win1<<" "<<win2<<"\n";
	return 0;
}
