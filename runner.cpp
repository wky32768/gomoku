#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
int a[15][15],x,y;
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
		if(i+4<=13 && j-4<=13) {
			if(a[i][j]!=0 && a[i][j]==a[i+1][j-1] && a[i+1][j-1]==a[i+2][j-2] && a[i+2][j-2]==a[i+3][i-3] && a[i+3][j-3]==a[i+4][j-4]) return 1;
		}
	}
	return 0;
}
signed main() {
	freopen("a.in","w",stdout);
	puts("1");
	For(i,1,13) {
		For(j,1,13) cout<<"0 ";
		puts("");
	}
	fclose(stdout);
	while(!over()) {
		system("ai1.exe");
		freopen("a.out","r",stdin);
		cin>>x>>y;
		a[x][y]=1;
		fclose(stdin);
		if(over()) {
			freopen("log.txt","w",stdout);
			puts("ai1 win!");
			For(i,1,13) {
				For(j,1,13) {
					if(a[i][j]==0) cout<<"_ ";
					else if(a[i][j]==1) cout<<"O ";
					else if(a[i][j]==2) cout<<"X ";
				}
				puts("");
			}
			return 0;
		}
		freopen("a.in","w",stdout);
		puts("2");
		For(i,1,13) {
			For(j,1,13) cout<<a[i][j]<<" ";
			puts("");
		}
		fclose(stdout);
		system("ai2.exe");
		freopen("a.out","r",stdin);
		cin>>x>>y;
		a[x][y]=2;
		fclose(stdin);
		if(over()) {
			freopen("log.txt","w",stdout);
			puts("ai2 win!");
			For(i,1,13) {
				For(j,1,13) {
					if(a[i][j]==0) cout<<"_ ";
					else if(a[i][j]==1) cout<<"O ";
					else if(a[i][j]==2) cout<<"X ";
				}
				puts("");
			}
			fclose(stdout);
			return 0;
		}
		freopen("a.in","w",stdout);
		puts("1");
		For(i,1,13) {
			For(j,1,13) cout<<a[i][j]<<" ";
			puts("");
		}
		fclose(stdout);
	}
	return 0;
}