#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft=1;
	while(true){
		int L,P,V;
		cin>>P>>L>>V;
		if(L==0)
			break;
		int ret=(V/L)*P+(V%L>=P? P:V%L);
		cout<<"Case "<<noft<<": "<<ret<<'\n';
		noft++;
	}
	return 0;
}