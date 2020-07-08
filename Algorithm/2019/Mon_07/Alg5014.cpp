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
int main(){
	// tc : 최대 O(3000000)
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int f,s,g,u,d;
	cin>>f>>s>>g>>u>>d; // s -> g
	// 노드는 1-f
	// 방법은 u,-d
	queue<int> bfsq;
	bool visit[f+1]; // 0-
	fill(visit, visit+f+1, false);
	bfsq.push(s);
	visit[s]=true;
	int ret=0;
	bool possi=false;
	while(!bfsq.empty()){
		int len=bfsq.size();
		FOR(i,0,len,1){
		int here=bfsq.front();
		bfsq.pop();
			if(here==g){
				possi=true;
				goto esc; // break
			}
		if(here+u<=f&&!visit[here+u]){
			bfsq.push(here+u);
			visit[here+u]=true;
		}
			if(here-d>=1&&!visit[here-d]){
			bfsq.push(here-d);
			visit[here-d]=true;
		}
		}
		ret++;
	}
	esc:
	cout<<(possi? to_string(ret):"use the stairs")<<'\n';
	return 0;
}