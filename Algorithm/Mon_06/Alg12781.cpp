	#include <bits/stdc++.h>
	using namespace std;
	int judge(int x1, int y1, int x2, int y2){
		// (x1,y1), (x2,y2)
		return x1*y2-x2*y1;
	}
	int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int x1,y1,x2,y2,x3,y3,x4,y4;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		// (x2-x1, y2-y1)벡터에 대해 각 두 점이 서로 다른 위치에 있어야 한다.
		// ccw
		int ret;
		ret=judge(x2-x1, y2-y1, x3-x2, y3-y2);
		int a=ret>0? 1:ret<0? -1:0;
		ret=judge(x2-x1,y2-y1,x4-x2,y4-y2);
		int b=ret>0? 1:ret<0? -1:0;
		if(a*b<0)
			cout<<1<<'\n';
		else
			cout<<0<<'\n';
	return 0;
	}