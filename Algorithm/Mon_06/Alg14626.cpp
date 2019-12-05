#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string input;
	cin>>input;
	int ret=0, idx;
	for(int i=0;i<input.size();i++)
		if(input[i]!='*')
		ret+=i%2==0? input[i]-'0':3*(input[i]-'0');
		else
		idx=i;
	int stn=(10-ret%10)%10;
	if(idx%2==1)
		while(stn%3!=0)
			stn+=10;
	cout<<(idx%2==0? stn:stn/3)<<'\n';
	return 0;
}