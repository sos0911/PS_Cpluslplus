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
	int noft;
	cin>>noft;
	FOR1(i,noft){
		int n;
		cin>>n;
		int dp[2][n], input[2][n]; // 0-
		FOR1(j,2)
			fill(dp[j], dp[j]+n, 0);
		FOR1(j,2)
			FOR1(k,n)
				cin>>input[j][k];
		// dp(bottom-top)
		// dp[x][j] : j열까지 사용할 시 산출 가능한 최대 점수
		dp[0][0]=input[0][0]; dp[1][0]=input[1][0];
		dp[0][1]=input[1][0]+input[0][1]; dp[1][1]=input[0][0]+input[1][1];
		for(int j=2;j<n;j++){
			dp[0][j]=max(dp[1][j-1], max(dp[0][j-2], dp[1][j-2]))+input[0][j];
			dp[1][j]=max(dp[0][j-1], max(dp[1][j-2], dp[0][j-2]))+input[1][j];
		}
		cout<<max(dp[0][n-1], dp[1][n-1])<<'\n';
	}
	return 0;
}