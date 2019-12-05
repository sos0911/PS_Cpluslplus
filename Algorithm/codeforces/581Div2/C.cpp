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
const int maxd=1e6;
int n,m;
int adj[101][101], mind[101][101]={};// 1부터
bool visit[101]={};
int ans[maxd+1];
queue<int> bfsq;
// mind : i=j 간의 최소 거리
int in[maxd+1];
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char temp;
			cin>>temp; // 공백, 개행 무시
			adj[i][j]=(int)(temp-'0');
		}
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>in[i];
	// bfs
	for(int i=1;i<=n;i++){
		visit[i]=true;
		bfsq.push(i);
		int dist=0; // 출발점까지의 거리
		while(!bfsq.empty()){
			int s=bfsq.size();
			for(int j=0;j<s;j++){
			int temp=bfsq.front();
			bfsq.pop();
				mind[i][temp]=dist;
			for(int i=1;i<=n;i++)
				if(adj[temp][i]&&!visit[i]){
					bfsq.push(i);
					visit[i]=true;
				}
			}
			dist++;
		}
		memset(visit,0,sizeof(visit));
	}
	// 답 완성
	int cnt=1;
	ans[0]=in[0];
	int bei=0;
	for(int i=1;i<m;i++)
		if(mind[ans[cnt-1]][in[i]]<i-bei){
			ans[cnt++]=in[i-1];
			bei=i-1;
		}
	ans[cnt++]=in[m-1];
	cout<<cnt<<'\n';
	for(int i=0;i<cnt;i++)
		cout<<ans[i]<<" ";
	cout<<'\n';
	return 0;
}