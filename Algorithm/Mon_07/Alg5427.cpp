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
int dir[][2]={{-1,0},{1,0},{0,1},{0,-1}};
int w,h;
bool isrange(int y, int x){
	return y>=0&&y<h&&x>=0&&x<w? true:false;
}
// tc : 최대 O(wh)*100
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin>>noft;
	FOR(i,0,noft,1){
		cin>>w>>h;
		int cmap[h][w]; // 0-
		queue<pii> fire, per;
		bool fvisit[h][w], pvisit[h][w];
		FOR(j,0,h,1){
			fill(fvisit[j], fvisit[j]+w,false);
			fill(pvisit[j], pvisit[j]+w,false);
		}
		FOR(j,0,h,1){
			string temp;
			cin>>temp;
			FOR(k,0,w,1){
				cmap[j][k]=temp[k];
				if(temp[k]=='*'){
					fire.push({j,k});
					fvisit[j][k]=true;
				}
				else if(temp[k]=='@'){
					per.push({j,k});
					pvisit[j][k]=true;
				}
			}
		}
			// 불 bfs, 사람 dfs 번갈아가기
		int ret=0;
		bool possi=false;
		while(!per.empty()){
			int flen=fire.size(), plen=per.size();
			FOR(i,0,flen,1){
				auto here=fire.front();
				fire.pop();
				FOR(j,0,4,1){
					int nexty=here.fi+dir[j][0];
					int nextx=here.se+dir[j][1];
					if(isrange(nexty,nextx)&&cmap[nexty][nextx]!='#'&&!fvisit[nexty][nextx]){
						cmap[nexty][nextx]='*';
						fire.push({nexty,nextx});
						fvisit[nexty][nextx]=true;
					}
				}
			}
			FOR(i,0,plen,1){
					auto here=per.front();
				per.pop();
					if(!isrange(here.fi,here.se)){
						possi=true;
						goto esc;
					}
				FOR(j,0,4,1){
					int nexty=here.fi+dir[j][0];
					int nextx=here.se+dir[j][1];
					if(isrange(nexty,nextx)){
						// 시작 위치는 포함하지 않아도 된다.
						// 어차피 포함하는 해는 최적해가 될 수 없다.
						if(cmap[nexty][nextx]=='.'&&!pvisit[nexty][nextx]){
						per.push({nexty,nextx});
						pvisit[nexty][nextx]=true;
						}
					}
					else
						per.push({nexty,nextx});
				}
			}
			ret++;
		}
		esc:
		cout<<(possi? to_string(ret):"IMPOSSIBLE")<<'\n';
	}
	return 0;
}