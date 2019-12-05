// 대회용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<list<int>> vli; 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef double db;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define RFORL(i,s,e,d) for(ll i=s;i>=e;i+=d)
const int stn=200001;
int n,m,k,q;
int tleft[stn]={}, tright[stn]={}; 
int safeleft[stn]={}, saferight[stn]={}; // col=stn일때 해당 열에 대한 가장 가까운 left,right 저장
// 0으로 초기화
ll dp[stn][4]={}, curc[4]={}; // dp, 지금 row의 가능한 c값
vi safe; // safe column
ll ans=0;
ll solve(int row, int stc, int dec){
	// 오른쪽까지 가서 가는것과 왼쪽까지 가서 가는것
	ll ansa=abs(stc-tright[row]);
	ansa+=abs(tright[row]-tleft[row]);
	ansa+=abs(tleft[row]-dec);
	ll ansb=abs(stc-tleft[row]);
	ansb+=abs(tright[row]-tleft[row]);
	ansb+=abs(tright[row]-dec);
	return 1+min(ansa,ansb);
}
ll solvelast(int stc){
	// 마지막 줄에서 다 훑는 방법
		ll ansa=abs(stc-tright[n]);
	ansa+=abs(tright[n]-tleft[n]);
	ll ansb=abs(stc-tleft[n]);
	ansb+=abs(tright[n]-tleft[n]);
	return 1+min(ansa,ansb);
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k>>q;
	// row 번호 1부터 시작
	for(int i=1;i<k+1;i++){
		int r,c;
		cin>>r>>c;
		if(tleft[r]==0)
			tleft[r]=c;
		else
			tleft[r]=min(tleft[r], c);
		tright[r]=max(tright[r], c);
	}
	for(int i=0;i<q;i++){
		int temp;
		cin>>temp;
		safe.push_back(temp);
	}
	sort(safe.begin(), safe.end());
	// 각 열에 대해 safe를 채운다.
	for(int i=1;i<=safe[0];i++)
		saferight[i]=safe[0];
	for(int i=safe[0];i<safe[1];i++)
		safeleft[i]=safe[0];
	for(int i=1;i<safe.size()-1;i++){
		for(int j=safe[i-1]+1;j<=safe[i];j++)
			saferight[j]=safe[i];
		for(int j=safe[i];j<safe[i+1];j++)
			safeleft[j]=safe[i];
	}
	for(int i=safe[safe.size()-1];i<=m;i++)
		safeleft[i]=safe[safe.size()-1];
	for(int i=safe[safe.size()-2]+1;i<=safe[safe.size()-1];i++)
		saferight[i]=safe[safe.size()-1];
	while(!tleft[n])
		n--;
	if(n==1){
		cout<<tright[1]-1<<'\n';
		return 0;
	}
	// 각 행에 대해 계산
	if(tright[1]==0){
		dp[1][2]=saferight[1]-1;
		curc[2]=saferight[1];
	}
	else{
		if(safeleft[tright[1]]!=0){
		dp[1][2]=tright[1]-1+abs(safeleft[tright[1]]-tright[1]);
		curc[2]=safeleft[tright[1]];
		}
		if(saferight[tright[1]]!=0){
		dp[1][3]=tright[1]-1+abs(saferight[tright[1]]-tright[1]);
		curc[3]=saferight[tright[1]];
		}
	}
	for(int i=2;i<n;i++){
		if(tright[i]==0){
			for(int j=0;j<4;j++)
				dp[i][j]=dp[i-1][j]+1; // 안 움직이는 게 이득
			continue;
		}
		int temp[4];
		temp[0]=safeleft[tleft[i]];
		temp[1]=saferight[tleft[i]];
		temp[2]=safeleft[tright[i]];
		temp[3]=saferight[tright[i]];
		for(int j=0;j<4;j++)
			dp[i][j]=1e11;
		for(int j=0;j<4;j++){
			if(curc[j])
				for(int p=0;p<4;p++)
					if(temp[p])
						dp[i][p]=min(dp[i][p], dp[i-1][j]+solve(i, curc[j], temp[p]));
		}
		for(int j=0;j<4;j++)
			curc[j]=temp[j];
	}
	ll ans=1e11;
	for(int i=0;i<4;i++)
		if(curc[i])
			ans=min(ans,dp[n-1][i]+solvelast(curc[i]));
	cout<<ans<<'\n';
	return 0;
}