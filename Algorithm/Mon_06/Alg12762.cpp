#include <iostream>
#include <vector>
#define FOR(i,n) for(int i=0;i<n;i++)
#define RFOR(i,n,l) for(int i=n;i>=l;i--) 
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, temp;
	cin>>n;
	vector<int> input;
	input.reserve(n);
	for(int i=0;i<n;i++){
		cin>>temp;
		input.push_back(temp);
	}
	vector<int> dpasc(n,1); // 0-i까지 볼때 최대 내림차순 길이
	vector<int> dpdesc(n,1); // i-maxl까지 볼때 최대 오름차순 길이
	// 항상 index i는 사용한다 가정
	// dp 오름차순, 내림차순
		FOR(i,n)
			FOR(j,i)
			if(input[j]>input[i])
				dpasc[i]=max(dpasc[i], dpasc[j]+1);
		RFOR(i,n-1,0)
			RFOR(j,n-1,i+1)
			if(input[j]>input[i])
				dpdesc[i]=max(dpdesc[i], dpdesc[j]+1);
	int ans=-1;
	ans=max(ans, dpasc[n-1]);
	ans=max(ans, dpdesc[0]);
	for(int i=0;i<n;i++)
		ans=max(ans, dpasc[i]+dpdesc[i]-1);
	cout<<ans<<'\n';
	return 0;
}