// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxd=2e5;
const ll INF=1e15;
int t,n,a,b;
string s;
ll dp[maxd+1][2];
ll solve(int pos, int add){
	// 현재 위치가 pos고 pos가 시작될 때 높이는 1+add
	// 앞으로의 결과를 반환
	if(pos==n-1)
		return add? 2*a+b:a+b;
	ll& ret=dp[pos][add];
	if(ret!=INF)
		return ret;
	if(s[pos+1]=='1'){ // 무조건 높이를 2로 고정
		if(!add)
			ret=min(ret,solve(pos+1,1)+2*a+2*b);
		else
			ret=min(ret,solve(pos+1,1)+a+2*b);
	}
	else{
		// 높이 변경하던지 고대로 가던지
		if(!add){
			ret=min(ret,solve(pos+1,0)+a+b);
			ret=min(ret,solve(pos+1,1)+2*a+2*b);
		}
		else{
			ret=min(ret,solve(pos+1,1)+a+2*b);
			if(s[pos]!='1')
			ret=min(ret,solve(pos+1,0)+2*a+b);
		}
	}
	return ret;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// dp로도 커버 가능
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>a>>b;
		cin>>s;
		for(int i=0;i<maxd+1;i++)
			fill(dp[i],dp[i]+2,INF); // 초기화
		cout<<solve(0,0)+b<<'\n';
	}
	return 0;
}