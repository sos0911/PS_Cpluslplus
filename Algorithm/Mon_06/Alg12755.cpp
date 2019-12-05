#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll s1=1, s2=9, sum=0;
	int n;
	cin>>n;
	while(sum<n){
		sum+=s1*s2;
		s1++; 
		s2*=10;
	}
	sum-=(--s1)*(s2/=10);
	// 타겟은 s1자리이다.
	// s1자리를 가진 수가 s2개만큼 있음
	// 가리키는 수를 구하고
	// 그 수 바로 앞까지의 index 구해서
	// 차이만큼 더해본다.
	ll tar=(long)pow(10, s1-1);
	tar+=(n-(sum+1))/s1; // target
	//cout<<"sum : "<<sum<<" tar : "<<tar<<" s1 : "<<s1<<" s2 : "<<s2<<'\n';
	//cout<<"at : "<<n-(sum+(n-(sum+1))/s1*s1)-1<<'\n';
	int ans=to_string(tar).at(n-(sum+(n-(sum+1))/s1*s1)-1)-'0';
	cout<<ans<<'\n';
	return 0;
}