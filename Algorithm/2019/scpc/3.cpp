#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int main(){
	ll noft;
	scanf("%lld", &noft);
	for(int i=1;i<=noft;i++){
		ll a,b;
		scanf("%lld %lld", &a, &b);
		ll ed=find(b); // f(b)
		ll be=find(b-1); // 전
		ll af=ed; // 후
		ll ans;
		if(be<=af){
			ll afidx=b-1;
			while(true){
				if((be=find(afidx-1))>(af=find(afidx)))
					break;
				afidx--;
			}
			while(true){
				if((be=find(afidx-1))<(af=find(afidx)))
					break;
				afidx--;
			}
			ans=max(af, ed);
		}
		else if(be>af){
			ll afidx=b-1;
			while(true){
				if((be=find(afidx-1))<(af=find(afidx)))
					break;
				afidx--;
			}
			ans=af;
		}
			printf("Case #%d\n", i);
			printf("%lld\n", ans);
	}
	return 0;
}