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
int visit[26], visit2[10]; // check, 0-9
vector<char> emer; // 출현한 문자들
string in[10];
int n, ans=-1;
void solve(int idx){
	// emer idx
	if(idx==emer.size()){
		// 검사
		int temp=0;
		FOR(i,0,n,1)
			for(int j=0,rep=1;j<in[i].size();j++,rep*=10)
				temp+=visit[in[i][in[i].size()-1-j]-'A']*rep;
		ans=max(ans,temp);
		return;
	}
	for(int i=9;i>=0;i--)
		if(!visit2[i]){
			visit[emer[idx]-'A']=i;
			visit2[i]=1;
			solve(idx+1);
			visit2[i]=0;
		}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(visit,0,sizeof(visit));
	memset(visit2,0,sizeof(visit2));
	cin>>n;
	FOR(i,0,n,1){
		cin>>in[i];
		FOR(j,0,in[i].size(),1)
			if(!visit[in[i][j]-'A']){
				emer.push_back(in[i][j]);
				visit[in[i][j]-'A']=1;
			}
	}
	solve(0);
	cout<<ans<<'\n';
	return 0;
}