#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
typedef vector<vector<vector<int>>> vvv;
typedef vector<vector<int>> vv;
typedef vector<int> v;
typedef pair<p,pair<int,int>> ppp;
// 좌표, 꺾인 횟수, 방향
int dir[][2]={{0,-1},{0,1},{-1,0},{1,0}};
const int INF=1e9;
enum edir{
	left,
	right, 
	up, 
	down // 0-
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// using bfs
	int n;
	cin>>n;
	vector<vector<char>> map(n, vector<char>());
	vvv dp(n, vv(n, v(4, INF))); // 3차원
	// 각 좌표당 각 방향에서 꺾인 최소 횟수 저장
	string input;
	p st,ed;
	for(int i=0;i<n;i++){
		cin>>input;
		for(int j=0;j<input.size();j++){
			if(input[j]=='A')
				st={i,j}; // (y,x);
				if(input[j]=='B')
				ed={i,j}; // (y,x);
			map[i].push_back(input[j]);
		}
	}
	queue<ppp> bfsq;
	// queue에 (좌표), 최소 꺾인횟수, 방향 저장
	for(int i=0;i<4;i++)
	bfsq.push({st, {0,i}});
	while(!bfsq.empty()){
		auto temp=bfsq.front();
		bfsq.pop();
		if(temp.first==ed)
			continue;
		for(int i=0;i<4;i++){
			int nexty=temp.first.first+dir[i][0];
			int nextx=temp.first.second+dir[i][1];
			int nextn=temp.second.first; // 꺾인 횟수
			if(temp.second.second!=i)
				nextn++;
			if(nexty>=0&&nexty<n&&nextx>=0&&nextx<n&&map[nexty][nextx]!='x'&&nextn<dp[nexty][nextx][i]){
				dp[nexty][nextx][i]=nextn;
				bfsq.push({{nexty,nextx},{nextn,i}});
			}
		}
	}
	int minn=INF;
	for(int i=0;i<4;i++)
		minn=min(minn, dp[ed.first][ed.second][i]);
	cout<<minn<<'\n';
	return 0;
}