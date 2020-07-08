// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int n;
int people[10001];
int dp[10001][2];
vvi adj;
bool visit[10001]={};
int solve(int here,bool used){
	// root가 here인 subtree에서 그 subtree 내 우수 마을 최대 인구 수
	// 이미 root가 used로 결정됨
	// 구조상 불가능한 경우도 최댓값 고르는 과정에서 제거됨
	int& ret=dp[here][used];
	if(ret!=-1)
		return ret;
	visit[here]=true;
	ret=used? people[here]:0;
	if(used){
		for(int next:adj[here])
			if(!visit[next])
				ret+=solve(next,false);
	}
	else{
		// 선택 or 선택x
		for(int next:adj[here])
			if(!visit[next])
				ret+=max(solve(next,false),solve(next,true));
	}
	visit[here]=false;
	return ret;
}
int main(){
	scanf("%d", &n);
	adj.assign(n+1,vi());
	for(int i=1;i<=n;i++)
		scanf("%d", &people[i]);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n", max(solve(1,false),solve(1,true)));
	return 0;
}