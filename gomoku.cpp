//pfyakking
#define QiPu

#ifdef UNUSED
#elif defined(__GNUC__)
# define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#elif defined(__LCLINT__)
# define UNUSED(x) /*@unused@*/ x
#else
# define UNUSED(x) x
#endif
//pfyakking

#pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <windows.h>
#define il inline
#define For(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

int x, y, now, win1, win2;
vector<vector<int>/**/> a;

#include "cpp/prepare.cpp"

namespace usr {
	#include "usr.cpp"
}

namespace lv0 {
	#include "ai/lv0.cpp"
}
namespace lv1 {
	#include "ai/lv1.cpp"
}
namespace lv2 {
	#include "ai/lv2.cpp"
}
namespace lv3 {
	#include "ai/lv3.cpp"	
}
namespace lv4 {
	#include "ai/lv4.cpp"	
}
namespace lv5 {
	#include "ai/lv5.cpp"	
}

pair <int,int> run(vector<vector<int> >a,int now,int test) {
	if(test==-1) {
		if(usr::lvl==0) return lv0::ak(a,now);
		else if(usr::lvl==1) return lv1::ak(a,now);
		else if(usr::lvl==2) return lv2::ak(a,now);
		else if(usr::lvl==3) return lv3::ak(a,now);
		else if(usr::lvl==4) return lv4::ak(a,now);
		else if(usr::lvl==5) return lv5::ak(a,now);
	} else {
		if(test==0) return lv0::ak(a,now);
		else if(test==1) return lv1::ak(a,now);
		else if(test==2) return lv2::ak(a,now);
		else if(test==3) return lv3::ak(a,now);
		else if(test==4) return lv4::ak(a,now);
		else if(test==5) return lv5::ak(a,now);
	}
	return make_pair(8,8);
}

#include "cpp/vs.cpp"

int main() {
	freopen("log.txt","w",stdout);
	cl_out();
	
	f_out("CON");
	int mode=MessageBox(NULL,"1v1选是，能力测试选否","模式选择", MB_YESNOCANCEL|MB_ICONASTERISK); 
	cl_out();

	if(mode=='1') {
		f_out("CON");
		puts("How many games do you want to play?");
		int tot;
		cin >> tot;
		cl_out();
		vs(tot,-1);
	} else {
		For(i,0,5) {
			win1=win2=0;
			pair <int,int> ai=vs(15,i);
			if(ai.first<ai.second) {
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
