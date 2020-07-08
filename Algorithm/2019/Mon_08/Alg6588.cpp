// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxd=1e6;
bool prime[maxd+1];
vector<int> p; // prime
int n;
bool bins(int tar){
	int lo=0,hi=p.size()-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(p[mid]==tar)
			return true;
		else if(p[mid]>tar)
			hi=mid-1;
		else
			lo=mid+1;
	}
	return false;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 백만까지 체로 걸러냄
	// 3+3같은 것도 가능
	p.reserve(100000);
	fill(prime,prime+maxd+1,true);
	for(int i=2;i<=maxd;i++)
		if(prime[i]){
			p.push_back(i);
			for(ll j=1LL*i*i;j<=maxd;j+=i)
				prime[j]=false;
		}
	// 소수이려면 홀수일 수밖에 없음
	while(true){
		cin>>n;
		if(!n)
			break;
		bool possi=false;
		for(int j=0;j<=p.size()-1;j++)
			if(bins(n-p[j])){
				cout<<n<<" = "<<p[j]<<" + "<<n-p[j]<<'\n';
				possi=true;
				break;
			}
		if(!possi)
			cout<<"Goldbach's conjecture is wrong."<<'\n';
	}
	return 0;
}