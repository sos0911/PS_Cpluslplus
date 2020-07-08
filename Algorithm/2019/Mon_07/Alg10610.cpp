#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
#define fi first
#define se second
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef priority_queue<int> pq;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string n;
	cin>>n;
	int sum=0;
	bool zero=false;
	int len=n.size();
	FOR1(i,len){
		if(n[i]=='0')
			zero=true;
		sum+=n[i]-'0';
	}
	if(!zero||sum%3!=0){
		cout<<-1<<'\n';
		return 0;
	}
	char in[len];
	FOR1(i,len)
		in[i]=n[i];
	sort(in, in+len, greater<char>());
	for(char c:in)
		cout<<c;
	cout<<'\n';
	return 0;
}