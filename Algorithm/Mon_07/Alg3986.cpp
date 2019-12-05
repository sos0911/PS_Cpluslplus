#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define RFORL(i,s,e,d) for(ll i=s;i>=e;i+=d)
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int ret=0; // ans
	FOR(i,0,n,1){
		stack<char> cont;
		string in;
		cin>>in;
		int len=in.size();
		FOR(j,0,len,1)
			if(cont.empty())
				cont.push(in[j]);
			else{ 
				if(cont.top()==in[j]) // 단어 쌍 출현
					cont.pop();
				else
					cont.push(in[j]);
				}
		// end
		if(cont.empty())
			ret++;
	}
	cout<<ret<<'\n';
	return 0;
}