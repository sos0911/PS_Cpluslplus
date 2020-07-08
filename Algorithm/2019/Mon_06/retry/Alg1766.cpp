#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi; 
vvi adj;
vi deg;// 간선 개수
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
	// minheap => greater
		cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	adj.assign(n+1,vi()); // 1-
	deg.assign(n+1, 0);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		deg[b]++;
	}
	for(int i=1;i<=n;i++)
		if(!deg[i]) // deg[i]==0?
			pq.push(i); // start 지점 집어넣음
	while(!pq.empty()){
		int temp=pq.top(); // 존재하는 것 중 가장 작은 것
		pq.pop();
		for(int i:adj[temp])
			if((--deg[i])==0)
				pq.push(i);
		cout<<temp<<" ";
	}
	cout<<'\n';
	return 0;
}