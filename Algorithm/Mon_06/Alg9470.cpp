#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int main(){
		cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin>>noft;
	for(int i=0;i<noft;i++){
		int k,m,p;
		cin>>k>>m>>p;
		vvi adj(m+1, vi());
		vi deg(m+1, 0);
		int a,b;
		for(int j=0;j<p;j++){
			cin>>a>>b;
			adj[a].push_back(b);
			deg[b]++;
		}
		vector<pair<int,int>> dp(m+1, {0, -1}); // 1- // max 개수, max
		queue<int> q;
		for(int j=1;j<=m;j++)
			if(!deg[j]){
				q.push(j);
				dp[j]={1,1}; // 1에서부터 시작
			}
		for(int j=0;j<m;j++){ // 노드 개수만큼
			int temp=q.front();
			q.pop();
			for(int k:adj[temp]){
				if(dp[temp].second>dp[k].second){
					dp[k].first=1; // max값 갱신되었으므로
					dp[k].second=dp[temp].second;
				}
				else if(dp[temp].second==dp[k].second)
						if((++dp[k].first)==2){
							dp[k].second++;
							dp[k].first=0;
						}
				if(!(--deg[k]))
					q.push(k);
			}
		}
		cout<<k<<" "<<dp[m].second<<'\n';
	}
	return 0;
}