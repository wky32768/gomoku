#include <bits/stdc++.h>
using namespace std;
pair <int,int> ai1(vector<vector<int> >a,int now) {
	srand((int)time(0));
	L1:;
	int x=rnd()%13+1,y=rand()%13+1;
	if(a[x][y]!=0) goto L1;
	return make_pair(x,y);
}
