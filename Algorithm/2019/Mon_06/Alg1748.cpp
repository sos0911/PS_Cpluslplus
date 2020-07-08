//#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
typedef long long ll;
using namespace std;
int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	string input;
	char c_input[10];
	//cin>>input;
	scanf("%s", c_input);
	input=c_input;
	int len=input.size();
	int s1=1, s2=9;
	ll ans=0;
	while(s1!=len){
		ans+=s1*s2;
		++s1; s2*=10;
	}
	int add=stoll(input)-(int)pow(10, s1-1)+1;
	// 10^k로부터 추가되는 숫자들 수
	ans+=add*s1;
	//cout<<ans<<'\n';
	printf("%lld\n", ans);
	return 0;
}