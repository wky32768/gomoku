namespace aq{
	int q(vector<vector<int> >chessground,int i,int j,int t){
		if(chessground[i][j]!=0)return 0;
		int px[]={ 0,-1,-1,-1};
		int py[]={-1, 0,-1,+1};
		int mx=0;
		for(int pi=0;pi<4;pi++){
			int tot=0;
			int x,y;
			int p=0;
			x=i+px[pi];
			y=j+py[pi];
			while(x>0&&x<16&&y>0&&y<16&&chessground[x][y]==t){
				tot++;
				x+=px[pi];
				y+=py[pi];
			}
			if(x>0&&x<16&&y>0&&y<16&&chessground[x][y]==0){
				p++;
			}
			x=i-px[pi];
			y=j-py[pi];
			while(x>0&&x<16&&y>0&&y<16&&chessground[x][y]==t){
				tot++;
				x-=px[pi];
				y-=py[pi];
			}
			if(x>0&&x<16&&y>0&&y<16&&chessground[x][y]==0){
				p++;
			}
			tot=tot*3+p;
			if(tot>mx)mx=tot;
		}
		return mx;
	}
}
pair<int,int> ai1(vector<vector<int> >chessground,int v){
	vector<vector<int> >q1,q2;
	q1.resize(18);
	q2.resize(18);
	for(int i=1;i<=15;i++){
		q1[i].resize(18);
		q2[i].resize(18);
		for(int j=1;j<=15;j++){
			q1[i][j]=aq::q(chessground,i,j,v);
			q2[i][j]=aq::q(chessground,i,j,3-v);
		}
	}
	for(int v=14;v>=1;v--){
		vector<pair<int,int> >tot;
		for(int g=2;g>=0;g--){
			for(int i=1;i<=15;i++){
				for(int j=1;j<=15;j++){
					if(q1[i][j]>=3*v+g){
						tot.push_back(make_pair(i,j));
					}
				}
			}
			if(tot.size()!=0){
				return tot[rnd()%tot.size()];
			}
		}
		for(int g=2;g>=0;g--){
			for(int i=1;i<=15;i++){
				for(int j=1;j<=15;j++){
					if(q2[i][j]>=3*v+g){
						tot.push_back(make_pair(i,j));
					}
				}
			}
			if(tot.size()!=0){
				return tot[rnd()%tot.size()];
			}
		}
	}
	return make_pair(7,7);
}

