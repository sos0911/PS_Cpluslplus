#include <bits/stdc++.h>
using namespace std;
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
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
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	list<char> cont(n,'?');
	auto itr=cont.begin(); // 처음부터 시작
	bool error=false;
	FOR(i,0,k,1){
		int s; char tar; string temp;
		cin>>s>>temp;
		tar=temp[0];
		FOR(j,0,s%n,1){
			if(itr==cont.begin())
				itr=--cont.end();
			else
				itr--;
		}
		if(*itr=='?')
		*itr=tar;
		else if(*itr!=tar){
			error=true;
			break;
		}
	}
	if(error)
		cout<<"!"<<'\n';
	else{
		// 중복 검사
		bool visit[26];
		bool error2=false;
		fill(visit,visit+26,false);
		for(char c:cont)
			if(c>='A'&&c<='Z'){
				if(!visit[c-'A'])
				visit[c-'A']=true;
				else{
					error2=true;
					break;
				}
			}
		if(error2)
			cout<<"!"<<'\n';
		else
		FOR(i,0,n,1){
		cout<<*(itr++);
		if(itr==cont.end())
			itr=cont.begin();
		}
	}
	return 0;
}