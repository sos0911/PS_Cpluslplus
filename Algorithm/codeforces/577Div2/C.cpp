// 대회용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<list<int>> vli; 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef double db;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define RFORL(i,s,e,d) for(ll i=s;i>=e;i+=d)
int n,k;
int in[200001];
ll f(int mid){
	// 중앙값을 mid로 정할 때
	// 가능한지 아닌지를 판단
	ll ret=0;
	for(int i=n/2;i<n;i++)
		ret+=max(0,mid-in[i]);
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>in[i];
	sort(in,in+n);
	// 이분법
	ll lo=1, hi=2e9;
	// 가능한 median <= 2e9
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		if(f(mid)>k)
			hi=mid-1;
		else
			lo=mid+1;
	}
	cout<<hi<<'\n';
	return 0;
}