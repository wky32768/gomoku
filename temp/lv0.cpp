/*
这只是一个随机，测试用的 
*/
pair <int,int> ak(vector<vector<int> >a,int now) {
	srand((int)time(0));
	L1:;
	int x=rnd()%13+1,y=rand()%13+1;
	if(a[x][y]!=0) goto L1;
	return make_pair(x,y);
}
