#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int n,maxt,maxm,l;
int bfs(vector<vector<tuple<int,int,int>>>& rel){
	queue<tuple<int,int,int>> bfsq; // 현재 노드, 지금까지 쌓인 이동시간, 택시비
	vector<int> visited(n+1, maxm+1);
	// 상한선 이동시간, 택시비
	// 현재 visited에 있는 수치보다 낮으면 통과
	bfsq.push(make_tuple(1,0,0)); // c++17
	// 도중에 예산 초과 시 stop
	while(!bfsq.empty()){
		auto& temp=bfsq.front();
		bfsq.pop();
		for(auto& t:rel[get<0>(temp)])
			if(get<1>(temp)+get<1>(t)<=maxt && get<2>(temp)+get<2>(t)<visited[get<0>(t)]){
				// 수치보다 낮음
				bfsq.push(make_tuple(get<0>(t),get<1>(temp)+get<1>(t),get<2>(temp)+get<2>(t)));
				visited[get<0>(t)]=get<2>(temp)+get<2>(t);
				//cout<<"visited "<<get<0>(t)<<" renew : "<<get<2>(temp)+get<2>(t)<<endl;
				//cout<<"time : "<<get<1>(temp)+get<1>(t)<<endl;
			}
	}
	if(visited[n]==maxm+1) // 갱신x => 불가능
		return -1;
	else
		return visited[n];
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>maxt>>maxm>>l;
	vector<vector<tuple<int,int,int>>> rel; // 각 노드마다 길 정보 저장
	// 길 정보 : 목적지 이동시간(move) 택시비
	rel.reserve(n+1); // 0-
	for(int i=0;i<n+1;i++)
	rel.push_back(vector<tuple<int,int,int>>()); 
	int a,b,t,m;
	for(int i=0;i<l;i++){
		cin>>a>>b>>t>>m;
		rel[a].push_back(make_tuple(b,t,m));
		rel[b].push_back(make_tuple(a,t,m));
	}
	cout<<bfs(rel)<<'\n';
	return 0;
}