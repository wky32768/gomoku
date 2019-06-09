#include <bits/stdc++.h>
using namespace std;
void ai1() {
	int a[15][15],now;
	freopen("a.in","r",stdin);
	cin>>now;
	for(int i=1; i<=13; i++) for(int j=1; j<=13; j++) cin>>a[i][j];
	fclose(stdin);
	srand((int)time(0));
	L1:;
	int x=rand()%13+1,y=rand()%13+1;
	if(a[x][y]!=0) goto L1;
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
