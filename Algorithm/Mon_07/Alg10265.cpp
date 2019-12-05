#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<list<int>> vli; 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef double db;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define RFORL(i,s,e,d) for(ll i=s;i>=e;i+=d)
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	return 0;
}
/*
화살표의 의미 :
i=>j일때 i는 j가 가야 간다.

각 사람당 같이 가야 하는 사람은 1명이다.
= 각 노드에 대해 들어오는 화살표는 무조건 1개다.
visit 준비.
= 각 i에 대해 !visit(i)일때 
방향 그래프 -> i번째 사람에 대하여
dfs를 돌려서
가장 큰 size..

dfs시 size 내 i가 있다는 소리는 i에 대해 조건충족
완료

ㅅㅂ scc+knapsack 보류
*/