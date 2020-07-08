// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
int noftc,r,c;
int maxd=-1;
pii maxi;
char cmap[1001][1001]; // 0부터 저장
int dir[][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool visit[1001][1001]={};
// tree -> 한 컴포넌트
bool inrange(pii here){
	return here.fi>=0&&here.fi<r&&here.se>=0&&here.se<c;
}
void solve(pii here, int dist){
	visit[here.fi][here.se]=true;
	if(dist>maxd){
		maxd=dist;
		maxi=here;
	}
	for(int i=0;i<4;i++){
		int nextr=here.fi+dir[i][0];
		int nextc=here.se+dir[i][1];
		if(inrange({nextr,nextc})&&cmap[nextr][nextc]=='.'&&!visit[nextr][nextc])
			solve({nextr,nextc},dist+1);
	}
}
int main(){
	scanf("%d", &noftc);
	for(int i=0;i<noftc;i++){
		scanf("%d%d", &c,&r);
		pii st;
		bool find=false;
		for(int j=0;j<r;j++)
			for(int k=0;k<c;k++){
				scanf(" %c",&cmap[j][k]);
				if(!find&&cmap[j][k]=='.'){
					st={j,k};
					find=true;
				}
			}
		maxd=-1;
		maxi=st;
		solve(st,0); // st에서 가장 먼 노드 찾음
		maxd=-1;
		pii midi=maxi;
		memset(visit,0,sizeof(visit)); // visit 초기화
		solve(midi,0);
		printf("Maximum rope length is %d\n", maxd);
	}
	return 0;
}