// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int n,m;
int dir[][2]={{0,1},{1,0}}, dir2[][2]={{0,-1},{-1,0}};
vector<vector<char>> cmap;
vector<vector<int>> dist; // (0,0)에서의 경로상거리(-1 초기화)
vector<vector<bool>> visit;
map<int,int> cont; // 거리에 따른 집합군 개수 나타냄
// possi : backward dfs에서 도달 가능한 정점
bool inrange(int r,int c){
	return r>=0&&r<n&&c>=0&&c<m;
}
// 도달하면 false
bool dfs(int r, int c, int d){
	visit[r][c]=true;
	dist[r][c]=d;
	if(r==n-1&&c==m-1)
		return false;
	bool check=true;
	for(int i=0;i<2;i++){
		int nextr=r+dir[i][0];
		int nextc=c+dir[i][1];
		if(inrange(nextr,nextc)&&cmap[nextr][nextc]!='#'&&!visit[nextr][nextc])
			if(!dfs(nextr,nextc,d+1))
				check=false;
	}
	return check;
}
void backdfs(int r, int c){
	// 뒤에서부터 dfs
	// 도달가능한 곳에 표시 목적
	visit[r][c]=true;
	for(int i=0;i<2;i++){
		int nextr=r+dir2[i][0];
		int nextc=c+dir2[i][1];
		if(inrange(nextr,nextc)&&cmap[nextr][nextc]!='#'&&!visit[nextr][nextc])
			backdfs(nextr,nextc);
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// answer is at most 2
	cin>>n>>m;
	cmap.assign(n,vector<char>(m,'.'));
	dist.assign(n,vector<int>(m,-1));
	visit.assign(n,vector<bool>(m,false));
	for(int i=0;i<n;i++){
		string in;
		cin>>in;
		for(int j=0;j<m;j++)
			if(in[j]=='#')
				cmap[i][j]='#';
	}
	if(dfs(0,0,0)){
		cout<<0<<'\n';
		return 0;
	}
	// 이제 경로는 1개 이상 있는 것이다.
	// dfs로 경로들 위 cell들을 거리 tracking.
	// 거리가 같은 cell들이 2개 이상 있으면 경로가 2개 이상 있다는 것.
	// 1이냐 2냐?
	for(int i=0;i<n;i++)
		fill(visit[i].begin(),visit[i].end(),false);
	backdfs(n-1,m-1);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(dist[i][j]!=-1&&visit[i][j])
				cont[dist[i][j]]++;
	for(auto& p:cont)
		if(p.fi!=0&&p.fi!=n+m-2&&p.se==1){
			cout<<1<<'\n';
			return 0;
		}
	cout<<2<<'\n';
	return 0;
}