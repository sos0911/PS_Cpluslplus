// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
int n;
int dir[][2]={{-1,0},{1,0},{0,1},{0,-1}};
// 미리 방향을 정해야 한다.
// (시작 지점, 방향)
struct Info{
	pii cen; // 중심점
	bool ver; // 수직?
	Info(pii cen, bool ver):cen(cen),ver(ver){}
};
char cmap[51][51];
bool visit[51][51][2]={};
bool check(int y, int x, bool ver){ // 회전 check
	if(((((y==0)||(y==n-1)))&&ver)||(((x==0)||(x==n-1))&&!ver))
		return false;
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			if(y+i>=0&&y+i<n&&x+j>=0&&x+j<n){
				if(cmap[y+i][x+j]=='1')
					return false;
			}
	return true;
}
bool check2(int y, int x, bool ver){ // 한칸옮기기
	if(!ver){
		for(int i=-1;i<=1;i++)
			if(cmap[y][x+i]=='1')
				return false;
	}
	else{
		for(int i=-1;i<=1;i++)
			if(cmap[y+i][x]=='1')
				return false;
	}
	return true;
}
// 통나무가 범위 내인지 확인
bool isrange(int y, int x, bool ver){
	if(ver){
		if(y-1>=0&&y+1<n&&x>=0&&x<n)
			return true;
		else
			return false;
	}
	else{
		if(x-1>=0&&x+1<n&&y>=0&&y<n)
			return true;
		else
			return false;
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	vector<pii> st, ed;
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		for(int j=0;j<n;j++){
			cmap[i][j]=temp[j];
			if(temp[j]=='B')
				st.push_back({i,j});
			if(temp[j]=='E')
				ed.push_back({i,j});
		}
	}
	queue<Info> bfsq;
	int temp=st[0].fi==st[1].fi? 0:1;
	int temp2=ed[0].fi==ed[1].fi? 0:1;
	bfsq.push(Info({st[1].fi,st[1].se},temp));
	visit[st[1].fi][st[1].se][temp]=true; // 중심점이 visit
	int ans=0;
	bool possi=false;
	while(!bfsq.empty()){
		int qsize=bfsq.size();
		for(int i=0;i<qsize;i++){
			auto here=bfsq.front();
			bfsq.pop();
			if(here.cen.fi==ed[1].fi&&here.cen.se==ed[1].se&&here.ver==temp2){
				possi=true;
				goto esc;
			}
			for(int j=0;j<4;j++){
				int nexty=here.cen.fi+dir[j][0];
				int nextx=here.cen.se+dir[j][1];
				if(isrange(nexty,nextx,here.ver)&&check2(nexty,nextx,here.ver)&&!visit[nexty][nextx][here.ver]){
					visit[nexty][nextx][here.ver]=true;
					bfsq.push(Info({nexty,nextx},here.ver));
				}
			}
			// 회전
			if(isrange(here.cen.fi,here.cen.se,!here.ver)&&check(here.cen.fi,here.cen.se,!here.ver)&&!visit[here.cen.fi][here.cen.se][!here.ver]){
					visit[here.cen.fi][here.cen.se][!here.ver]=true;
					bfsq.push(Info(here.cen,!here.ver));
				}
		}
		ans++;
	}
	esc:
	cout<<(possi? ans:0)<<'\n';
	return 0;
}