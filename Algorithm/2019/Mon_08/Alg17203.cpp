// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int psum[1001]={};
int n,q;
int main(){
	scanf("%d", &n);
	int be, af;
	scanf("%d", &be);
	for(int i=1;i<n;i++){
		scanf("%d", &af);
		psum[i]=psum[i-1]+abs(af-be);
		be=af;
	}
	for(int i=0;i<q;i++){
		int st,ed;
		scanf("%d %d", &st, &ed);
		printf("%d\n", psum[ed-1]-psum[st-1]);
	}
	return 0;
}