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
struct Info{
	pii coord;
	int key; // 열쇠를 갖고 있는 상태
	// 갖고 있다면 1로 표현 = bitmask
	Info(int c, int r, int key):coord(c,r),key(key){}
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// bfs
	int n,m;
	cin>>n>>m;
	char cmap[n][m]; // 0-
	int visit[n][m][1<<6];
	queue<Info> bfsq;
	memset(visit,0,sizeof(visit)); // 0이면 방문x
	FOR(i,0,n,1){
		string temp;
		cin>>temp;
		FOR(j,0,m,1){
			cmap[i][j]=temp[j];
			if(cmap[i][j]=='0'){
				visit[i][j][0]=1;
				bfsq.push(Info(i,j,0));
			}
		}
	}
	// 상태 : (r,c)에서의 key 상태
	int ans=0;
	bool possi=false;
	while(!bfsq.empty()){
		int len=bfsq.size();
		FOR(i,0,len,1){
			auto here=bfsq.front();
			bfsq.pop();
			if(cmap[here.coord.fi][here.coord.se]=='1'){
				possi=true;
				goto esc;
			}
			FOR(j,0,4,1){
				int nextr=here.coord.fi+dir[j][0];
				int nextc=here.coord.se+dir[j][1];
				if(nextr>=0&&nextr<n&&nextc>=0&&nextc<m&&cmap[nextr][nextc]!='#'){
					char tar=cmap[nextr][nextc];
					if(tar>='a'&&tar<='f'){
						if(!visit[nextr][nextc][here.key|(1<<(tar-'a'))]){
						bfsq.push(Info(nextr,nextc,here.key|(1<<(tar-'a'))));
						visit[nextr][nextc][here.key|(1<<(tar-'a'))]=1;
						}
					}
					else if(tar>='A'&&tar<='F'){
						if(here.key&(1<<(tar-'A'))&&!visit[nextr][nextc][here.key]){
						bfsq.push(Info(nextr,nextc,here.key));
						visit[nextr][nextc][here.key]=1;
						}
					}
					// 빈곳, 현위, 출구
					else if(!visit[nextr][nextc][here.key]){
						bfsq.push(Info(nextr,nextc,here.key));
						visit[nextr][nextc][here.key]=1;
					}
				}
			}
		}
		ans++;
	}
	esc:
	cout<<(possi? ans:-1)<<'\n';
	return 0;
}
// visit에도 bitmask 넣어야겠다
// 늦게 문따러 오더라도 그 뒤에 필요한 키를 가지고 오는거면
// 진행할수 있어야함