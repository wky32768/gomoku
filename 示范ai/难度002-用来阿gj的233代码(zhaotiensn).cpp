#include <bits/stdc++.h>
using namespace std;
void ai2() {
	int a[15][15],now;
	freopen("a.in","r",stdin);
	cin>>now;
	for(int i=1; i<=13; i++) for(int j=1; j<=13; j++) cin>>a[i][j];
	fclose(stdin);

	int x,y;
L2:
	;
	for(int i=1;i<=13;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]==0&&(a[i+1][j]!=0||a[i][j+1]!=0)){
				x=i;y=j;
				goto L1;
			}
		}
	}
	x=rnd()%13+1,y=rnd()%13+1;
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
