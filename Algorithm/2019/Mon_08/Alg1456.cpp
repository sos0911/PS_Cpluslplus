// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxd=1e7;
bool prime[maxd+1];
ll cnt=0;
ll a,b;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>a>>b;
	fill(prime, prime+maxd+1, true);
	for(int i=2;i<=maxd;i++)
		if(prime[i]){
			// 제곱수 생성
			ll rep=1LL*i*i;
			while(rep<=b){
				if(rep>=a)
					cnt++;
				// 어차피 겹칠 수가 없다.
				if(i>=1e5)
					break;
				rep*=i;
			}
			for(ll j=1LL*i*i;j<=maxd;j+=i)
				prime[j]=false;
		}
	cout<<cnt<<'\n';
	return 0;
}