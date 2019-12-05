#include <iostream>
#include <vector>
#include <tuple>
// 1. not bfs -> use dfs
// 2. visited[n]이 갱신될 때마다 저장되는 값이 정답일지 아닐지 모르므로 취사선택
// 3. 중간 노드에서 전 상태보다 시간이 적게 걸리고 택시비가 많은 선택지가 답이 될 수도 있다.
// 끝 노드에서 시간 제한에 걸릴 위험성이 줄어들기 때문
// 따라서 둘 중 하나라도 전 상태보다 낫다면 길을 만들어 봐야함
using namespace std;
typedef vector<vector<tuple<int,int,int>>> cont;
// 길 정보 : 목적지 이동시간(move) 택시비
typedef vector<tuple<int,int,int>> nd; // node
typedef vector<pair<int,int>> vp;
const int MAXN=1e9;
int n,maxt,maxm,l,ans=MAXN;
cont rel; // 각 노드당 길 정보 저장
vp visited; // visited(cache)
vector<bool> visited2; // 방문한 노드 저장
// visited : 시간, 돈
void dfs(int node, int acct, int accm){ // adj
	if(node==n){
		ans=min(ans, visited[n].second);
		return; // 도착
	}
	for(auto a: rel[node]){
		int tt=get<1>(a)+acct;
		int tm=get<2>(a)+accm;
		if(!visited2[get<0>(a)]&&(tt<=maxt&&tm<=maxm)&&(tt<visited[get<0>(a)].first||tm<visited[get<0>(a)].second)){ // 각 값이 최대값 안에 들어가되 하나라도 전 상태보다 나으면 진행
			// 이미 dfs로 한 경로를 다 봤으니 visited를 바꿔서 다른 route 진행해도 무방
			visited[get<0>(a)].first=tt;
			visited[get<0>(a)].second=tm;
			visited2[get<0>(a)]=true;
			//cout<<"dfs : "<<get<0>(a)<<" "<<tt<<" "<<tm<<" called"<<endl;
			dfs(get<0>(a), tt, tm);
			visited2[get<0>(a)]=false;
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>maxt>>maxm>>l;
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
	visited.assign(n+1, {maxt+1,maxm+1});
	visited2.assign(n+1, false);
	visited2[1]=true; // check
	dfs(1,0,0);
	if(ans>maxm)
		cout<<-1<<'\n';
	else
		cout<<ans<<'\n';
	return 0;
}