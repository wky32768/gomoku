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
namespace usr {
	#include "usr.cpp"
}

pair <int,int> run(vector<vector<int> >a,int now){
	if(usr::lvl==0) return lv0::ak(a,now);
	else if(usr::lvl==1) return lv1::ak(a,now);
	else if(usr::lvl==2) return lv2::ak(a,now);
	else if(usr::lvl==3) return lv3::ak(a,now);
}

#include "cpp/vs.cpp"

signed main() {
	freopen("log.txt","w",stdout);
	cl_out();
	
	puts("How many games do you want to play?");
	int tot;
	cin >> tot;
	
	vs(tot);
	
	return 0;
}
