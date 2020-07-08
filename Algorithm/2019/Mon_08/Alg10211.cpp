// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int psum[1001];
int main(){
	psum[0]=0;
	int noft;
	scanf("%d", &noft);
	for(int i=0;i<noft;i++){
		int n,temp;
		scanf("%d", &n);
		for(int j=0;j<n;j++){
			scanf("%d", &temp);
			psum[j+1]=psum[j]+temp;
		}
		int ans=-1e9;
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				ans=max(ans,psum[k]-psum[j-1]);
		 printf("%d", ans);
	}
	return 0;
}