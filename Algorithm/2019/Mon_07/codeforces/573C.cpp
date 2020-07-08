#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n,m,k; // item 수, 버릴 개수, 페이지당 구성원수
	cin>>n>>m>>k;
	ll in[m]; // 버릴 index(m개)
	// 정렬된 상태로 들어온다 가정
	FORL(i,0,m,1)
		cin>>in[i];
	ll cidx=0; // idx부터 버려야 함
	ll rev=0; // 뺀 수
	ll ans=0;
	FORL(i,0,m,1){
		ll cp=(in[cidx]-rev)%k==0? (in[cidx]-rev)/k-1:(in[cidx]-rev)/k; // 속한 page(0-)
		ll cnt=1;
		while((++i)<m&&((in[i]-rev)%k==0? (in[i]-rev)/k-1:(in[i]-rev)/k)==cp)
			cnt++;
		rev+=cnt;
		cidx=i;
		--i;
		ans++;
	}
	cout<<ans<<'\n';
	return 0;
}