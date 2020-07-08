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
const int INF=1e9;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int dp[n+1];
	fill(dp, dp+n+1, INF);
	dp[1]=0;
	// 불가능한 경우는 포함x
	FOR1(i,n){
		if(2*i<=n)dp[2*i]=min(dp[i]+1, dp[2*i]);
		if(3*i<=n)dp[3*i]=min(dp[i]+1, dp[3*i]);
		dp[i+1]=min(dp[i]+1, dp[i+1]);
	}
	cout<<dp[n]<<'\n';
	return 0;
}