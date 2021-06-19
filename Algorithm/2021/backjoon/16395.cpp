// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[30][30];
ll solve(int n, int k){
    if(n < k)
        return 0;
    if(k==0 || n==0)
        return 1;
    if(k==1)
        return n;
    ll& ret = dp[n][k];
    if(ret != -1)
        return ret;
    return ret = solve(n-1, k-1) + solve(n-1,k);
}
int main(){
    int n,k;
    cin>>n>>k;
    memset(dp, -1, sizeof(dp));
    // dp(재귀)
    cout<<solve(n-1,k-1)<<'\n';
	return 0;
}