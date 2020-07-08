// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int n,m,nofe,nofv;
bool visit[501]={};
vvi adj;
void solve(int here){
	visit[here]=true;
	for(int next:adj[here])
		if(!visit[next]){
			nofe+=2; nofv++;
			solve(next);
		}
}
int main(){
	int rep=1;
	while(true){
	scanf("%d %d",&n,&m);
		if(n==0&&m==0)
			break;
	adj.assign(n+1,vi());
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d", &a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ret=0;
		for(int i=1;i<=n;i++)
			if(!visit[i]){
				nofe=0; nofv=1;
				solve(i);
				if(nofe+1==nofe)
					ret++;
			}
		if(ret==0)
			printf("Case %d: No trees.\n", rep);
		else if(ret==1)
			printf("Case %d: There is one tree.\n", rep);
		else
			printf("Case %d: A forest of %d trees.\n", rep, ret);
		rep++;
	}
	return 0;
}