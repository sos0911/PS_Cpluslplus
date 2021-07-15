// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int dp[11]; 
int solve(int n){
    // 길이 n을 쪼개서 얻는 즐거움의 최댓값 저장
    if(n==1)
        return 0;
    int& ret = dp[n];
    if(ret != -1)
        return ret;
    for(int i=1;i<n;i++)
        ret = max(ret, i*(n-i) + solve(i) + solve(n-i));
    return ret;
}
int main(){
    // 반복동적도 가능할듯?
    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<solve(n)<<'\n';
	return 0;
}