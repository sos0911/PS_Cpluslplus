// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxd=1e6;
bool prime[maxd+1];
vector<int> p;
ll cmin,cmax;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	fill(prime,prime+maxd+1,true);
	p.reserve(100000);
	for(int i=2;i<=maxd;i++)
		if(prime[i]){
			p.push_back(i);
			for(ll j=1LL*i*i;j<=maxd;j+=i)
				prime[j]=false;
		}
	cin>>cmin>>cmax;
	// 각 수에 대하여 소인수분해
	int ret=0; // 제곱ㅇㅇ수
	for(ll i=cmin;i<=cmax;i++){
		ll temp=i;
		int idx=0, be=-1;
		while(temp!=1&&idx<p.size()){
			if(!(temp%p[idx])){
				if(be!=-1&&be==p[idx]){
					ret++;
					break;
				}
				temp/=p[idx];
				be=p[idx];
			}
			else
				idx++;
		}
	}
	cout<<cmax-cmin+1-ret<<'\n';
	return 0;
}