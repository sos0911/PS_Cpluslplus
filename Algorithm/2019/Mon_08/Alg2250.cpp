// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pi;
int mini[10001]={}, maxi[10001]={};
int n, root;
pi child[10001];
bool parent[10001]={}; // 자신의 부모가 있는가?
int solve(int here,int level){
	int idx=0;
	if(child[here].fi!=-1)
		idx+=solve(child[here].fi,level+1);
	if(mini[level]==0)
		mini[level]=idx;
	else
	mini[level]=min(mini[level],idx);
	maxi[level]=max(maxi[level],idx);
	if(child[here].se!=-1)
		idx+=solve(child[here].se,level+1);
	return idx+1;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a,b,c;
		// 공백,개행 무시
		scanf("%d%d%d", &a, &b, &c);
		child[a].fi=b;
		child[a].se=c;
		parent[b]=true;
		parent[c]=true;
	}
	for(int i=1;i<=n;i++)
		if(!parent[i]){
			root=i;
			break;
		}
	solve(root,1);
	int ans=-1, ansi;
	for(int i=1;i<=n;i++)
		if(maxi[i]-mini[i]+1>ans){
			ans=maxi[i]-mini[i]+1;
			ansi=i;
		}
	printf("%d %d\n", ansi, ans);
	return 0;
}