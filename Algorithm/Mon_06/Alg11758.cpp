	#include <bits/stdc++.h>
	using namespace std;
	int judge(int x1, int y1, int x2, int y2){
		// (x1,y1) 벡터 vs (x2,y2)벡터
		return x1*y2-x2*y1;
	}
	int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
		int x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		int ret=judge(x2-x1, y2-y1, x3-x2, y3-y2);
		if(ret>0)
			cout<<1<<'\n';
		else if(ret<0)
			cout<<-1<<'\n';
		else
			cout<<0<<'\n';
	return 0;
	}