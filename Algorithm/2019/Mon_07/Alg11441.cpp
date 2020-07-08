#include <bits/stdc++.h>
using namespace std;
int n,m,temp;
int psum[100001];
// p[i] : 앞에서 i개까지의 합
// p[0]=0;
int main(){
	// scanf, printf
	psum[0]=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &temp);
		psum[i+1]=psum[i]+temp;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int st,ed;
		scanf("%d %d",&st,&ed);
		printf("%d\n", psum[ed]-psum[st-1]);
	}
	return 0;
}