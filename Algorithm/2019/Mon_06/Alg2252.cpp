#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<bool> vb;
vvi adj;
vb visit;
stack<int> s;
void dfs(int node){
	visit[node]=true;
	for(auto i:adj[node])
		if(!visit[i])
			dfs(i);
	s.push(node);
}
int main(){
	// dfs 위상정렬
	// 각 학생을 노드로 생각한다.
	// 뒷 학생이 뒤에 와야 하므로 뒷 학생을 향한 edge
	// 답이 없는 경우는 고려하지 않음.
		cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m; // n:학생 수
	cin>>n>>m;
	adj.assign(n+1, vi());
	visit.assign(n+1, false);
	int a,b;
	for(int i=0;i<m;i++){
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