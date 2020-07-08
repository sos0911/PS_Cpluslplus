#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
vvi map;
vvb visited;
int m,n,k;
int dir[][2]={{-1,0},{1,0},{0,1},{0,-1}};
int bfs(vvi& map, vvb& visited){
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(!visited[i][j]&&map[i][j]==1){
				// bfs
				queue<pair<int,int>> bfsq;
				visited[i][j]=true;
				bfsq.push({i,j}); // yx
				while(!bfsq.empty()){
					auto temp=bfsq.front();
					bfsq.pop();
					for(int k=0;k<4;k++){
						int nexty=temp.first+dir[k][0];
						int nextx=temp.second+dir[k][1];
					if(nexty>=0&&nexty<n&&nextx>=0&&nextx<m&&!visited[nexty][nextx]&&map[nexty][nextx]==1){
						bfsq.push({nexty,nextx});
						visited[nexty][nextx]=true;
					}
					}
				}
				ans++;
			}
	return ans;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>m>>n>>k;
		map.assign(n,vector<int>()); // 세로, 가로
		// assign : 전에 저장된 것들을 날리고 새로 배정
		for(int j=0;j<n;j++)
			map[j].assign(m,0);
		int a,b;
		for(int j=0;j<k;j++){
			cin>>a>>b;
			map[b][a]=1;
		}
		visited.assign(n, vector<bool>());
		for(int j=0;j<n;j++)
			visited[j].assign(m,false);
		cout<<bfs(map, visited)<<'\n';
	}
	return 0;
}