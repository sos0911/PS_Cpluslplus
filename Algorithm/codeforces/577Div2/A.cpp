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
int n,m;
int cnt[26], val[1000];
string in[1000];
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>in[i];
	for(int i=0;i<m;i++)
		cin>>val[i];
	int ans=0;
	for(int i=0;i<m;i++){
		memset(cnt,0,sizeof(cnt));
		for(int j=0;j<n;j++)
			cnt[in[j][i]-'A']++;
		int maxi, maxn=-1;
		for(int j=0;j<26;j++)
			if(cnt[j]>maxn){
				maxn=cnt[j];
				maxi=j;
			}
		ans+=maxn*val[i];
	}
	cout<<ans<<'\n';
	return 0;
}