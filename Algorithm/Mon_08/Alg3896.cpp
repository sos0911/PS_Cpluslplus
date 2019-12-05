// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxd=10000;
bool prime[maxd];
vector<int> p; // prime
int t;
pair<bool,int> binse(int tar){
	// 이분탐색
	int lo=0,hi=p.size()-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(p[mid]>=tar)
			hi=mid-1;
		else
			lo=mid+1;
	}
	pair<bool,int> ret;
	if(p[lo]==tar)
		ret={true,lo};
	else
		ret={false,hi};
	return ret;
	// lower+bound
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// lower_bound로 찾아본다.
	fill(prime,prime+maxd+1,true);
	//p.reserve(100001);
	int cnt=0; // 소수 수
	for(int i=2;i<=maxd;i++)
		if(prime[i]){
			p.push_back(i);
			cnt++;
			if(cnt==100000){
				cout<<"break!"<<'\n';
				break;
			}
			for(ll j=i*i;j<=maxd;j+=i)
				prime[j]=false;
		}
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		auto res=binse(n);
		if(res.fi)
			cout<<"0"<<'\n';
		else
			cout<<p[res.se+1]-p[res.se]<<'\n';
	}
	return 0;
}