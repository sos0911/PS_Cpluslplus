// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxd=4e6;
bool prime[maxd+1];
vector<int> p;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	fill(prime, prime+maxd+1,true);
	p.reserve(200000);
	for(int i=2;i<=maxd;i++)
		if(prime[i]){
			p.push_back(i);
			for(ll j=1LL*i*i;j<=maxd;j+=i)
				prime[j]=false;
		}
	// two pointer
	cin>>n;
	int se=0,ed=0,sum=0,ans=0;
	while(true){
		if(sum>=n)
			sum-=p[se++];
		else if(ed==p.size())
			break;
		else
			sum+=p[ed++];
		if(sum==n)
			ans++;
	}
	cout<<ans<<'\n';
	return 0;
}