/*
ztn的代码，打了5min 
*/
#include <bits/stdc++.h>
using namespace std;
pair <int,int> ak(vector<vector<int> >a,int now)  {
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
	L1:;
	return make_pair(x,y);
}
