// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n;
const int maxd=3e5,mod=998244353;
int cache[maxd+1]; // n! 저장
pii in[maxd]; // 0-
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>in[i].fi>>in[i].se;
	cache[0]=1;	cache[1]=1;
	for(int i=2;i<=n;i++)
		cache[i]=(int)((1LL*cache[i-1]*i)%mod);
	// n!
	sort(in,in+n);
	int l=0,r=1; // 같은 구간의 양쪽 끝
	int c1=1,c2=1,c12=1;
	while(l<n){
		while(r<n&&in[l].fi==in[r].fi)
			r++;
		c1=(int)((1LL*c1*cache[r-l])%mod);
		l=r;
	}
	for(int i=0;i<n;i++)
		swap(in[i].fi,in[i].se);
	sort(in,in+n);
	l=0,r=1;
	while(l<n){
		while(r<n&&in[l].fi==in[r].fi)
			r++;
		c2=(int)((1LL*c2*cache[r-l])%mod);
		l=r;
	}
	for(int i=0;i<n;i++)
		swap(in[i].fi,in[i].se);
	sort(in,in+n);
		l=0,r=1;
	int l2,r2; 
	// c12
		while(l<n){
		while(r<n&&in[l].fi==in[r].fi)
			r++;
		l2=l,r2=l;
		while(l2<r){
			while(r2<r&&in[l2].se==in[r2].se)
				r2++;
		c12=(int)((1LL*c12*cache[r2-l2])%mod);
		l2=r2;
		}
		l=r;
	}
	for(int i=0;i<n-1;i++)
		if(in[i].se>in[i+1].se){
			c12=0;
			break;
		}
	cout<<(0LL+cache[n]-c1-c2+c12+2*mod)%mod<<'\n';
	return 0;
}