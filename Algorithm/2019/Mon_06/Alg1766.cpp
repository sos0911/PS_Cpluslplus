#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<bool> vb;
vb visit;
vvi adj;
stack<int> s;
void dfs(int node){
	// 들어갈 시 visit 표시
	visit[node]=true;
	for(auto& a:adj[node])
		if(!visit[a])
			dfs(a);
	s.push(node);
}
int main(){
	// cycle x
		cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	adj.assign(n+1,vi()); // 1-
	visit.assign(n+1,false);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	for(int i=1;i<=n;i++)
		if(!visit[i])
			dfs(i);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<'\n';
	return 0;
}