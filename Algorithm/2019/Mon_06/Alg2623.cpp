#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int main(){
	int n,m;
	cin>>n>>m;
	vvi adj(n+1, vi()); // 관계표
	vi deg(n+1, 0);
	for(int i=0;i<m;i++){
		int num,a,b;
		cin>>num;
		cin>>a;
		for(int j=1;j<num;j++){
			cin>>b;
			adj[a].push_back(b);
			deg[b]++;
			a=b;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(!deg[i])
			q.push(i);
	vector<int> ans;
	ans.reserve(n);
	bool cycle=false;
	for(int i=0;i<n;i++){
		if(q.empty()){
			cycle=true;
			break;
		}
		int temp=q.front();
		q.pop();
		ans.push_back(temp);
		for(int i:adj[temp])
			if(!(--deg[i]))
				q.push(i);
	}
	if(cycle)
		cout<<0<<'\n';
	else
		for(int i:ans)
			cout<<i<<'\n';
	return 0;
}