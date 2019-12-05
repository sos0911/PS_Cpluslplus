#include <bits/stdc++.h>
using namespace std;
int n,q;
int psum[100001][3];
int main(){
	for(int i=0;i<3;i++)
		psum[0][i]=0;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d", &temp);
		for(int j=0;j<3;j++)
			if(j+1==temp)
				psum[i+1][j]=psum[i][j]+1;
			else
				psum[i+1][j]=psum[i][j];
	}
	for(int i=0;i<q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d %d %d\n",psum[b][0]-psum[a-1][0], psum[b][1]-psum[a-1][1], psum[b][2]-psum[a-1][2]);
	}
	return 0;
}