#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpi;
vvi adj;
vi dp; // 각 건물당 완성 최소 시간 저장
vpi input; // degree 수, 짓는 시간
queue<int> sq;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, in;
	cin>>n;
	adj.assign(n+1, vi());
	dp.assign(n+1, -1); // -1로 초기화
	input.assign(n+1, {0, -1});
	for(int i=1;i<=n;i++){
		cin>>in;
		input[i].second=in;
		while(true){
			cin>>in;
			if(in==-1)
				break;
			adj[in].push_back(i);
			input[i].first++;
		}
	}
	for(int i=1;i<=n;i++)
		if(input[i].first==0){
			sq.push(i);
			dp[i]=input[i].second;
		}
	while(!sq.empty()){
		int temp=sq.front(); // top()은 pq
		sq.pop();
		for(int i:adj[temp]){
			input[i].first--;
			dp[i]=max(dp[i], dp[temp]+input[i].second);
			// temp는 이미 dp의 값이 확정된 상태이다.
			// 들어오는 노드가 전부 지어져야 한다.
			if(!input[i].first) // input[i]==0?
				sq.push(i); // 간선이 모두 없어졌으므로 도착 루트 모두 탐색
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dp[i]<<'\n';
return 0;
}