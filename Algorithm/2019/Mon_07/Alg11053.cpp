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
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// bottom-top
	// dp[i] : i번째 문자열에서 끝나는 부분 증가 수열 중 가장 큰 길이
	int n;
	cin>>n;
	int input[n]; // 0-
	FOR1(i,n)
		cin>>input[i];
	int dp[n];
	fill(dp, dp+n, 1); // 최소 길이는 자신=1
	FOR2(i,1,n){
		// dp[i] 결정
		FOR1(j,i)
			if(input[i]>input[j])
				dp[i]=max(dp[i], dp[j]+1);
	}
	int ret=1;
	FOR1(i,n)
		ret=max(ret,dp[i]);
	cout<<ret<<'\n';
	return 0;
}