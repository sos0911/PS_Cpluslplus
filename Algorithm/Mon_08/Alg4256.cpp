// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int noft, n;
int pre[1001], in[1001]; // 전위,중위
void solve(int ridx, int st, int ed){
	// pre 내 root idx, in 내 구간
	if(st==ed){
		printf("%d ", pre[ridx]);
		return;
	}
	int stn; // inorder에서의 subtree 구간 구분점
	for(int i=st;i<=ed;i++)
		if(in[i]==pre[ridx]){
			stn=i;
			break;
		}
	if(stn-st!=0)
		solve(ridx+1,st,stn-1);
	if(ed-stn!=0)
		solve(ridx+stn-st+1,stn+1,ed);
	printf("%d ", pre[ridx]);
}
int main(){
	scanf("%d", &noft);
	for(int i=0;i<noft;i++){
		scanf("%d", &n);
		for(int j=0;j<n;j++)
			scanf("%d", &pre[j]);
		for(int j=0;j<n;j++)
			scanf("%d", &in[j]);
		solve(0,0,n-1);
		printf("\n");
	}
	return 0;
}