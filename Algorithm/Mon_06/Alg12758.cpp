#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int mod=1000000007;
using namespace std;
ll sum=0;
// dp[i][j] => i번째 물체의 j번째 높이를 택할 때 가짓수
void find(int hei, vector<int>& ref){
	// hei의 약수를 ref에 저장한다.
	int i=1;
	for(;i*i<hei;i++)
		if(hei%i==0){
			ref.push_back(i);
			ref.push_back(hei/i);
		}
	if(i*i==hei)
		ref.push_back(i);
	sort(ref.begin(), ref.end()); // 오름차순 정렬
}
void solve(int n, vector<vector<int>>& arr, vector<vector<int>>& dp){
	for(int i=0;i<arr.size();i++)
		dp[i].assign(arr[i].size(), 0); // dp에 size 배정
	for(int i=0;i<arr[0].size();i++)
		dp[0][i]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<arr[i].size();j++){
			for(int k=0;k<arr[i-1].size()&&arr[i-1][k]<=arr[i][j]; k++)
				dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
		}
	}
	for(int i=0;i<arr[n-1].size();i++)
		sum=(sum+dp[n-1][i])%mod;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin>>noft;
	vector<vector<int>> dp, arr; 
	// dp : 각 물체에 대한 중간값
	// arr : 각 물체에 대한 약수
	arr.reserve(301);
	dp.reserve(301);
	for(int i=0;i<noft;i++){
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			arr.push_back(vector<int>()); // 임시객체 생성 후 집어넣기
			dp.push_back(vector<int>());
		int hei;
		cin>>hei;
			find(hei, arr[j]);
		}
		solve(n, arr, dp);
		cout<<sum<<'\n';
		sum=0;
		arr.clear();
		dp.clear();
	}
	return 0;
}