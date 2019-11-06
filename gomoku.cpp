#include <bits/stdc++.h>
#define int long long
#define il inline
#define For(i, a, b) for (register int i = a; i <= b; i++)
using namespace std;

int x, y, now, win1, win2;
vector<vector<int>/**/> a;

#include "cpp/prepare.cpp"

namespace lv0 {
	#include "temp/lv0.cpp"
}
namespace lv1 {
	#include "temp/lv1.cpp"
}
namespace lv2 {
	#include "temp/lv2.cpp"
}
namespace lv3 {
	#include "temp/lv3.cpp"	
}
namespace lv4 {
	#include "temp/lv4.cpp"	
}
namespace usr {
	#include "usr.cpp"
}

pair <int,int> run(vector<vector<int> >a,int now,int test) {
	if(test==-1) {
		if(usr::lvl==0) return lv0::ak(a,now);
		else if(usr::lvl==1) return lv1::ak(a,now);
		else if(usr::lvl==2) return lv2::ak(a,now);
		else if(usr::lvl==3) return lv3::ak(a,now);
		else if(usr::lvl==4) return lv4::ak(a,now);
	} else {
		if(test==0) return lv0::ak(a,now);
		else if(test==1) return lv1::ak(a,now);
		else if(test==2) return lv2::ak(a,now);
		else if(test==3) return lv3::ak(a,now);
		else if(test==4) return lv4::ak(a,now);
	}
}

#include "cpp/vs.cpp"

signed main() {
	freopen("log.txt","w",stdout);
	cl_out();
	
	f_out("CON");
	puts("1:AI 1v1");
	puts("2:test your AI");
	cl_out();

	char ch=getchar();
	if(ch=='1') {
		f_out("CON");
		puts("How many games do you want to play?");
		int tot;
		cin >> tot;
		cl_out();
		vs(tot,-1);
	} else {
		for(int i=0;i<=4;i++) {
			win1=win2=0;
			pair <int,int> temp=vs(100,i);
			if(temp.first<temp.second) {
				f_out("CON");
				cout<<"Congratulations! You Won AI"<<i<<" !\n";
				cl_out();
			} else {
				f_out("CON");
				cout<<"Sorry. You losed at AI"<<i<<" !\n";
				cl_out();
				break;
			}
		}
	}
	return 0;
}