// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int n,q;
const int stn=1000001;
int psum[stn]={};
int main(){
	scanf("%d %d", &n, &q);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d", &temp);
		psum[i+1]=psum[i]^temp;
	}
	int ans=0;
	for(int i=0;i<q;i++){
		int st,ed;
		scanf("%d %d", &st, &ed);
		ans^=psum[ed]^psum[st-1];
	}
	printf("%d\n", ans);
	return 0;
}