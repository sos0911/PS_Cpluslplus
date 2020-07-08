// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll cnt[1000];
int main(){
	scanf("%d %d",&n,&m);
	int be=0, af;
	memset(cnt,0,sizeof(cnt));
	cnt[0]=1; // psum[0]
	// mod m
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		af=(be+temp)%m;
		cnt[af]++;
		be=af;
	}
	ll ret=0;
	for(int i=0;i<m;i++){
		cout<<"cnt : "<<i<<" "<<cnt[i]<<'\n';
		ret+=cnt[i]*(cnt[i]-1)/2;
	}
	printf("%lld\n", ret);
	return 0;
}