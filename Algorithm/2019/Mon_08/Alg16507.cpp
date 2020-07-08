// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int r,c,q;
ll psum[1001][10001]={};
// 0으로 초기화
int main(){
	// psum practice 2d
	scanf("%d %d %d", &r, &c, &q);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			int temp;
			scanf("%d", &temp);
			psum[i+1][j+1]=psum[i+1][j]+psum[i][j+1]-psum[i][j]+temp;
		}
	for(int i=0;i<q;i++){
		int r1,c1,r2,c2;
		scanf("%d %d %d %d", &r1, &c1 ,&r2, &c2);
		printf("%lld\n", (psum[r2][c2]-psum[r1-1][c2]-psum[r2][c1-1]+psum[r1-1][c1-1])/((r2-r1+1)*(c2-c1+1)));
	}
	return 0;
}