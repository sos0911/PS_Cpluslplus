#include <iostream>
using namespace std;
// cin, cout과 c 관련 입출력 함수 중
// 차이는 메모리가 cin이 더 많이 먹는다(약간 더)
int main(){
	cin.tie(NULL);
	// cout 출력은 tie를 풀었으므로 프로그램 종료 시 와르르 쏟아질 것이다
	// 디버깅 시 주석처리해야함
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// cin 사용
	// 대신 c 관련 입출력 사용 금지
	int noftc;
	cin>>noftc;
	for(int i=0;i<noftc;i++){
	int x1, y1, x2, y2, r1, r2;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
	if(x1==x2&&y1==y2&&r1==r2){
		cout<<-1<<'\n';
		continue;
	}
	int stn=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		if(stn<(r1-r2)*(r1-r2)||stn>(r1+r2)*(r1+r2))
			cout<<0<<'\n';
		else if(stn==(r1-r2)*(r1-r2)||stn==(r1+r2)*(r1+r2))
			cout<<1<<'\n';
		else
			cout<<2<<'\n';
	}
	return 0;
}