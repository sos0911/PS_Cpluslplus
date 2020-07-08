#include <iostream>
#include <string>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int sh,sm,eh,em,n;
	int ans=0;
	cin>>sh>>sm>>eh>>em>>n;
	for(int i=sh;i<=eh;i++)
		for(int j=(i==sh?sm:0);j<=(i==eh?em:59);j++)
			if(i/10==n||i%10==n||j/10==n||j%10==n)
				ans++;
		cout<<ans<<'\n';
	// h가 0x일 때 0 check 필요
	return 0;
}