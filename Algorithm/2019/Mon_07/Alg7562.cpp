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
int dir[][2]={{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2}};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin>>noft;
	FOR(i,0,noft,1){
		int l; // 한변 길이
		cin>>l;
		pii st, ed;
		cin>>st.fi>>st.se;
		cin>>ed.fi>>ed.se;
		queue<pii> bfsq;
		bool visit[l][l];
		FOR(j,0,l,1)
			fill(visit[j], visit[j]+l, false);
		bfsq.push(st); // start
		int ret=1;
		while(!bfsq.empty()){
			int size=bfsq.size();
			FOR(j,0,size,1){
				auto here=bfsq.front();
				bfsq.pop();
				if(here.fi==ed.fi&&here.se==ed.se)
					goto esc; // 탈출
				FOR(k,0,8,1){
					int nexty=here.fi+dir[k][0];
					int nextx=here.se+dir[k][1];
					if(nexty>=0&&nexty<l&&nextx>=0&&nextx<l&&!visit[nexty][nextx]){
						bfsq.push({nexty,nextx});
						visit[nexty][nextx]=true;
					}
				}
			}
			ret++;
		}
		esc:
		cout<<ret<<'\n';
	}
	return 0;
}