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
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	int w[n+1], v[n+1]; // 물건 번호 : 1-(n)
	FOR2(i,1,n+1){
		cin>>w[i];
		cin>>v[i];
	}
	// dp[c][k] : c번까지 물건을 쓸 수 있을 때 무게가 k일때 가치 최댓값
	// 물건 : 1-(n)
	// dp[c][k]=max(dp[c][k], dp[c-1][x]+w[c]) (k=x+w[c])
	// dp[c][k]=max(dp[c][k], dp[c-1][k])
	int dp[101][100001];
	FOR1(i,n+1)
		fill(dp[i], dp[i]+k+1, -1);
	FOR1(i,n){
		dp[i][0]=0;
		FOR1(j,k+1){
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]); // 물건 사용 안함
			int next=j+w[i+1];
			if(next<=k&&dp[i][j]!=-1)
				dp[i+1][next]=max(dp[i+1][next], dp[i][j]+v[i+1]); // 물건 사용
		}
	}
	int ret=0;
	FOR1(i,k+1)
		cout<<dp[n][i]<<'\n';
	FOR1(i,k+1)
		ret=max(ret,dp[n][i]);
	cout<<ret<<'\n';
	return 0;
}