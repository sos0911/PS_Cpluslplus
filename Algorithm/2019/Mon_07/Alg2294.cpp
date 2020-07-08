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
	// bottom-top c++
	int n,k;
	cin>>n>>k;
	int dp[101][10001];
	// n번째 동전까지 사용할 시 k원을 만드는 가짓수 -> bottom-top
	// 동전은 0-(n-1)
	int input[n];
	FOR1(i,n)
		cin>>input[i];
	FOR1(i,n)
		fill(dp[i], dp[i]+k+1, INF);
	for(int i=0;i<n;i++){
		dp[i][0]=0;
		for(int j=0;j<=k;j++){
			dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
			if(j+input[i]<=k) // input[i] 사용하는 방법 갱신
				dp[i][j+input[i]]=min(dp[i][j+input[i]], dp[i][j]+1);
		}
	}
	cout<<(dp[n-1][k]==INF? -1:dp[n-1][k])<<'\n';
	return 0;
}