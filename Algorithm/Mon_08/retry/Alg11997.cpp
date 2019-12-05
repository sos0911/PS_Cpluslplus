#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
int n;
pii in[1001]; // (x,y)
int psum[1001][1001]={};
bool emer[1001][1001]={}; // 상대좌표에 해당하는 게 나타났는지 저장
const int stn=1000001;
int main(){
	scanf("%d", &n);
	vi x, y; 
	bool chkx[stn]={}, chky[stn]={};
	for(int i=0;i<n;i++){
		scanf("%d %d", &in[i].fi, &in[i].se);
		if(!chkx[in[i].fi]){
			x.push_back(in[i].fi);
			chkx[in[i].fi]=1;	
		}
		if(!chky[in[i].se]){
			y.push_back(in[i].se);
			chky[in[i].se]=1;	
		}
	}
	sort(in,in+n);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int cxi=0, cyi=0; 
	int xs=x.size(), ys=y.size();
	// 출현빈도 check
	for(int i=0;i<n;i++){
		if(in[i].fi!=x[cxi]){
			cxi++;
			cyi=0;
		}
		while(in[i].se!=y[cyi])
			cyi++;
		emer[cxi][cyi]=1;
	}
	cxi=0, cyi=0;
	// psum 채우기
	for(int i=0;i<xs;i++)
		for(int j=0;j<ys;j++){
			psum[i+1][j+1]=psum[i][j+1]+psum[i+1][j]-psum[i][j];
			if(emer[i][j]){
				cout<<"emer : "<<i<<" "<<j<<'\n';
				psum[i+1][j+1]++;
			}
		}
	// 가능한 가짓수 모두 나누어봄
	int ans=1e9;
	for(int i=0;i<=xs;i++){
		for(int j=0;j<=ys;j++)
			cout<<psum[i][j]<<" ";
		cout<<'\n';	
	}
	// 수정요 ㅈㄴ어렵네 시발
	for(int i=0;i<xs;i++)
		for(int j=0;j<ys;j++){
			int maxv=-1;
			int a=psum[i+1][j+1];
			maxv=max(maxv,a);
			int b=psum[xs][j+1]-psum[xs][1]-psum[i+1][j+1]+psum[i+1][j+1];
			maxv=max(maxv,b);
			int c=psum[]
			maxv=max(maxv,c);
			int d=
			maxv=max(maxv,d);
			cout<<"i : "<<i<<" j : "<<j<<'\n';
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<'\n';
			ans=min(ans,maxv);
		}
	printf("%d\n", ans);
	return 0;
}
/*
(1,1) (i,j)
(i+1,1) (1000,j)
(1,j+1) (i,1000)
(i+1,j+1) (1000,1000)
*/