#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
#define fi first
#define se second
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef priority_queue<int> pq;
typedef vector<pii> vp;
int n;
int imap[21][21]; // 0-
int solve(int sy, int sx, int ey, int ex, int way){
	// way=1이면 가로, 2면 세로
	// 범위 내 보석과 불순물 조사
	if(sy==ey||sx==ex) // 항상 두 개로 쪼개져야 함
		return 0;
	vp dir;
	bool visity[ey-sy], visitx[ex-sx];
	fill(visity, visity+ey-sy, false);
	fill(visitx, visitx+ex-sx, false);
	int gem=0;
	FOR2(i,sy,ey)
		FOR2(j,sx,ex){
			if(imap[i][j]==1)
				dir.push_back({i,j});
			else if(imap[i][j]==2)
				gem++;
	}
	if(gem==1&&!dir.size())
		return 1;
	if(!gem)
		return 0;
	if(!dir.size()) // 보석이 1개 초과인데 불순물 없음
		return 0;
	int ret=0;
	if(way!=1)
		for(auto& p:dir){
			bool possi=true;
			FOR2(i,sx,ex)
				if(imap[p.fi][i]==2){
					possi=false;
					break;
				}
			if(possi&&!visity[p.fi-sy]){
				visity[p.fi-sy]=true;
				ret+=solve(sy,sx,p.fi,ex,1)*solve(p.fi+1,sx,ey,ex,1);
			}
		}
	if(way!=2){
		for(auto& p:dir){
			bool possi=true;
			FOR2(i,sy,ey)
				if(imap[i][p.se]==2){
					possi=false;
					break;
				}
			if(possi&&!visitx[p.se-sx]){
				visitx[p.se-sx]=true;
				ret+=solve(sy,sx,ey,p.se,2)*solve(sy,p.se+1,ey,ex,2);
			}
	}
	}
	return ret;
}
int main(){
	// (s,e] 원칙 고수
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	FOR1(i,n)
		FOR1(j,n)
			cin>>imap[i][j];
	int ans=solve(0,0,n,n,0);
	cout<<(ans==0? -1:ans)<<'\n'; // 왼쪽 위, 오른쪽 위 좌표
	return 0;
}