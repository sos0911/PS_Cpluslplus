#include <iostream>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	if(n%2==0)
		cout<<"I LOVE CBNU"<<'\n';
	else{
		FOR(i,n)
			cout<<"*";
		cout<<'\n';
		FOR(j,n/2+1){
		FOR(i,n/2-j)
			cout<<" ";
		if(j==0)
			cout<<"*";
		else{
			cout<<"*";
			FOR(i,2*j-1)
				cout<<" ";
			cout<<"*";
		}
			cout<<'\n';
		}
	}
	return 0;
}