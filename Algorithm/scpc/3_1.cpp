#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100200;
ll find(ll num){ // f(num)
	ll st=1, sum=0, ret=0;
	while(num-sum!=0){
		while(num-sum>=st){
			sum+=st;
			st++; ret++;
		}
		st=1; 
	}
	return ret;
}
int main(int argc, char** argv){
	int noft;
	scanf("%d", &noft);
	vector<ll> dp(maxn+1);
	for(int i=1;i<=maxn;i++)
		dp[i]=find(i);
	for(int i=1;i<=noft;i++){
		ll a,b;
		scanf("%lld %lld", &a, &b);
		ll ans=-1;
		for(ll j=a;j<=b;j++)
			ans=j>maxn? max(ans,find(j)):max(ans,dp[j]);
			printf("Case #%d\n", i);
			printf("%lld\n", ans);
	}
	return 0;
}