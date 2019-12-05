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
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin>>noft;
	FOR(i,0,noft,1){
		string input;
		cin>>input;
		list<int> cont;
		auto itr=cont.end();
		int len=input.size();
		FOR(j,0,len,1){
			if(input[j]=='<'){
				if(itr!=cont.begin())
				itr--;
			}
			else if(input[j]=='>'){
					if(itr!=cont.end())
						itr++;
			}
			else if(input[j]=='-'){
					if(itr!=cont.begin())
				itr=cont.erase(--itr);
			}
			else
				cont.insert(itr,input[j]); // itr 앞에 삽입
		}
		for(char c:cont)
			cout<<c;
		cout<<'\n';
	}
	return 0;
}