#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	int input[n];
	FOR1(i,n)
		cin>>input[i];
	// greedy
	int sti=lower_bound(input, input+n,k)-input;
	// k보다 같거나 큰 첫번째 원소 반환
	// iter-iter는 자료형(- 오버로딩)
	while(sti>=n||input[sti]>k)
		sti--;
	int ret=0;
	while(k!=0){
		ret+=k/input[sti];
		k%=input[sti];
		sti--;
	}
	cout<<ret<<'\n';
	return 0;
}