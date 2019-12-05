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
typedef double db;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	// A-
	string in;
	cin>>in;
	int stn[n];
	FOR(i,0,n,1)
		cin>>stn[i];
	double ret=0; // ans
	stack<db> cont; 
	int len=in.size();
	FOR(i,0,len,1){
		if(in[i]>='A'&&in[i]<='Z')
			cont.push((db)stn[in[i]-'A']);
		else{
			// 제일 위 두 개를 연산해서 다시 넣는다.
			db a=cont.top();
			cont.pop();
			db b=cont.top();
			cont.pop();
			switch(in[i]){
				case '*':
					cont.push(b*a);
					break;
				case '/':
					cont.push(b/a);
					break;
				case '+':
						cont.push(b+a);
					break;
				case '-':
						cont.push(b-a);
					break;
			}
		}
	}
	// stack에 남은 것이 ans
	cout.precision(2);
	cout<<fixed<<cont.top()<<'\n';
	return 0;
}