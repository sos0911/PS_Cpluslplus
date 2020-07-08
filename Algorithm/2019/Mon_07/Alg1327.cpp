#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<list<int>> vli; 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef double db;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define RFORL(i,s,e,d) for(ll i=s;i>=e;i+=d)
string rev(string str){
	reverse(str.begin(), str.end());
	return str;
}
int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	// 12345678
	string st="", ed="";
	FOR(i,0,n,1){
		int temp;
		cin>>temp;
		st+=(char)(temp+'0');
		ed+=(char)(i+1+'0');
	}
	queue<string> bfsq;
	bfsq.push(st);
	set<string> visit;
	visit.insert(st);
	int ans=0; bool possi=false;
	while(!bfsq.empty()){
		int len=bfsq.size();
		FOR(i,0,len,1){
			auto here=bfsq.front();
			bfsq.pop();
			if(here==ed){
				possi=true;
				goto esc;
			}
			for(int i=0;i+k<=n;i++){
				string next=here.substr(0,i)+rev(here.substr(i,k))+here.substr(i+k);
				// 임시객체 -> rev에 substr 넘기자마자 객체소멸
				if(visit.find(next)==visit.end()){
					visit.insert(next);
					bfsq.push(next);
				}
			}
		}
		ans++;
	}
	esc:
	cout<<(possi? ans:-1)<<'\n';
	return 0;
}