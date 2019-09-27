/*
wky只会瞎写(wky32768)
*/
pair <int,int> ak(vector<vector<int>/**/>a,int now)  {
	srand((int)time(0));
	vector <int> q;
	q.clear();
	For(i,1,15) For(j,1,15) {
		if(i+3<=15 && a[i][j]==now && a[i][j]==a[i+1][j] && a[i+1][j]==a[i+2][j] && a[i+2][j]==a[i+3][j]) {
			if(i+4<=15 && a[i+4][j]==0) return make_pair(i+4,j); 
			else if(i-1>=1 && a[i-1][j]==0) return make_pair(i-1,j);
		}
		if(j+3<=15 && a[i][j]==now && a[i][j]==a[i][j+1] && a[i][j+1]==a[i][j+2] && a[i][j+2]==a[i][j+3]) {
			if(j+4<=15 && a[i][j+4]==0) return make_pair(i,j+4); 
			else if(j-1>=1 && a[i][j-1]==0) return make_pair(i,j-1);
		}
		if(i+3<=15 && j+3<=15 && a[i][j]==now && a[i+1][j+1]==a[i][j] && a[i+2][j+2]==a[i][j] && a[i+3][j+3]==a[i][j]) {
			if(i+4<=15 && j+4<=15 && a[i+4][j+4]==0) return make_pair(i+4,j+4); 
			else if(i-1>=1 && j-1>=1 && a[i-1][j-1]==0) return make_pair(i-1,j-1);
		}
		if(i+3<=15 && j-3>=1 && a[i][j]==now && a[i+1][j-1]==a[i][j] && a[i+2][j-2]==a[i][j] && a[i+3][j-3]==a[i][j]) {
			if(i+4<=15 && j-4>=1 && a[i+4][j-4]==0) return make_pair(i+4,j-4);
			else if(i-1>=1 && j+1<=15 && a[i-1][j+1]==0) return make_pair(i-1,j+1);
		}
	}
	For(i,1,15) For(j,1,15) {
		if(i+4<=15 && j+4<=15 && a[i][j]==now && a[i+1][j+1]==a[i][j] && a[i+2][j+2]==0 && a[i+3][j+3]==a[i][j] && a[i+4][j+4]!=3-now) {
			return make_pair(i+2,j+2);
		}
		if(i+4<=15 && i-1>=1 && a[i][j]==now && a[i+1][j]==a[i][j] && a[i+2][j]==0 && a[i+3][j]==a[i][j] && a[i+4][j]!=3-now && a[i-1][j]!=3-now) {
			return make_pair(i+2,j);
		}
		if(i-4>=1 && i+1<=15 && a[i][j]==now && a[i-1][j]==a[i][j] && a[i-2][j]==0 && a[i-3][j]==a[i][j] && a[i-4][j]!=3-now && a[i+1][j]!=3-now) {
			return make_pair(i-2,j);
		}
	}
	For(i,1,15) For(j,1,15) {
		if(i+3<=15 && a[i][j]==3-now && a[i][j]==a[i+1][j] && a[i+1][j]==a[i+2][j] && a[i+2][j]==a[i+3][j]) {
			if(i+4<=15 && a[i+4][j]==0) return make_pair(i+4,j); 
			else if(i-1>=1 && a[i-1][j]==0) return make_pair(i-1,j);
		}
		if(j+3<=15 && a[i][j]==3-now && a[i][j]==a[i][j+1] && a[i][j+1]==a[i][j+2] && a[i][j+2]==a[i][j+3]) {
			if(j+4<=15 && a[i][j+4]==0) return make_pair(i,j+4);
			else if(j-1>=1 && a[i][j-1]==0) return make_pair(i,j-1);
		}
		if(i+3<=15 && j+3<=15 && a[i][j]==3-now && a[i+1][j+1]==a[i][j] && a[i+2][j+2]==a[i][j] && a[i+3][j+3]==a[i][j]) {
			if(i+4<=15 && j+4<=15 && a[i+4][j+4]==0) return make_pair(i+4,j+4);
			else if(i-1>=1 && j-1>=1 && a[i-1][j-1]==0) return make_pair(i-1,j-1);
		}
		if(i+3<=15 && j-3>=1 && a[i][j]==3-now && a[i+1][j-1]==a[i][j] && a[i+2][j-2]==a[i][j] && a[i+3][j-3]==a[i][j]) {
			if(i+4<=15 && j-4>=1 && a[i+4][j-4]==0) return make_pair(i+4,j-4); 
			else if(i-1>=1 && j+1<=15 && a[i-1][j+1]==0) return make_pair(i-1,j+1);
		}
	}
	For(i,1,15) For(j,1,15) {
		if(i+2<=15 && a[i][j]==now && a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j]) {
			if(i+3<=15 && a[i+3][j]==0) return make_pair(i+3,j);
			else if(i-1>=1 && a[i-1][j]==0) return make_pair(i-1,j);
		}
		if(j+2<=15 && a[i][j]==now && a[i][j]==a[i][j+1] && a[i][j+1]==a[i][j+2]) {
			if(j+3<=15 && a[i][j+3]==0) return make_pair(i,j+3); 
			else if(j-1>=1 && a[i][j-1]==0) return make_pair(i,j-1);
		}
		if(i+2<=15 && j+2<=15 && a[i][j]==now && a[i+1][j+1]==a[i][j] && a[i+2][j+2]==a[i][j]) {
			if(i+3<=15 && j+3<=15 && a[i+3][j+3]==0) return make_pair(i+3,j+3);
			else if(i-1>=1 && j-1>=1 && a[i-1][j-1]==0) return make_pair(i-1,j-1);
		}
		if(i+2<=15 && j-2>=1 && a[i][j]==now && a[i+1][j-1]==a[i][j] && a[i+2][j-2]==a[i][j]) {
			if(i+3<=15 && j-3>=1 && a[i+3][j-3]==0) return make_pair(i+3,j-3);
			else if(i-1>=1 && j+1<=15 && a[i-1][j+1]==0) return make_pair(i-1,j+1);
		}
	}
	For(i,1,15) For(j,1,15) {
		if(i+2<=15 && a[i][j]==3-now && a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j]) {
			if(i+3<=15 && a[i+3][j]==0) return make_pair(i+3,j); 
			else if(i-1>=1 && a[i-1][j]==0) return make_pair(i-1,j);
		}
		if(j+2<=15 && a[i][j]==3-now && a[i][j]==a[i][j+1] && a[i][j+1]==a[i][j+2]) {
			if(j+3<=15 && a[i][j+3]==0) return make_pair(i,j+3);
			else if(j-1>=1 && a[i][j-1]==0) return make_pair(i,j-1);
		}
		if(i+2<=15 && j+2<=15 && a[i][j]==3-now && a[i+1][j+1]==a[i][j] && a[i+2][j+2]==a[i][j]) {
			if(i+3<=15 && j+3<=15 && a[i+3][j+3]==0) return make_pair(i+3,j+3);
			else if(i-1>=1 && j-1>=1 && a[i-1][j-1]==0) return make_pair(i-1,j-1);
		}
		if(i+2<=15 && j-2>=1 && a[i][j]==3-now && a[i+1][j-1]==a[i][j] && a[i+2][j-2]==a[i][j]) {
			if(i+3<=15 && j-3>=1 && a[i+3][j-3]==0) return make_pair(i+3,j-3); 
			else if(i-1>=1 && j+1<=15 && a[i-1][j+1]==0) return make_pair(i-1,j+1);
		}
	}
	For(i,1,15) For(j,1,15) {
			if(a[i][j]==0 && ((i-1>=1 && a[i-1][j]!=0) || (i+1<=15 && a[i+1][j]!=0) || (j-1>=1 && a[i][j-1]!=0) || (j+1<=15 && a[i][j+1]!=0)))
				return make_pair(i,j);
		}
	For(i,1,15) For(j,1,15) if(a[i][j]==0) q.push_back(i*16+j);
	int w=q.size(),which=rnd()%w;
	return make_pair(q[which]/16,q[which]%16);
}
