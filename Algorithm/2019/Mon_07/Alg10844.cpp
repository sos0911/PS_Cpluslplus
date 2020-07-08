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
const int mod=1000000000;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int dp[n+1][10]; // 0-9 (0으로 시작하는 수는 없다.논외)
	// dp[n][x] : 길이가 n자리고 x로 시작하는 계단 수의 수
	FOR1(i,n+1)
		fill(dp[i], dp[i]+10, 0);
	for(int i=1;i<=9;i++)
		dp[1][i]=1;
	FOR2(i,2,n+1)
		FOR1(j,10){
		if(j==0)
			dp[i][j]+=dp[i-1][1];
		else if(j==9)
			dp[i][j]+=dp[i-1][8];
		else{
			dp[i][j]+=dp[i-1][j-1];
			dp[i][j]+=dp[i-1][j+1];
		}
		dp[i][j]%=mod;
	}
	int ret=0;
	FOR1(i,10){
		ret+=dp[n][i];
		ret%=mod;
	}
	cout<<ret<<'\n';
	return 0;
}