#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
double judge(ll x1, ll y1, ll x2, ll y2){
	// (x1,y1) (x2,y2)
	return x1*y2-x2*y1;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	ll x1,y1,x2,y2;
	cin>>x1>>y1;
	pii stn={x1,y1}; // 기준점
	cin>>x1>>y1;
	double ans=0;
	for(int i=0;i<n-2;i++){
		cin>>x2>>y2;
		ans+=judge(x1-stn.first, y1-stn.second, x2-stn.first, y2-stn.second)/2;
		x1=x2; y1=y2;
	}
	cout<<fixed;
	cout.precision(1);
	cout<<abs(ans)<<'\n'; // 소수점 1자리까지 자동 반올림
	return 0;
}