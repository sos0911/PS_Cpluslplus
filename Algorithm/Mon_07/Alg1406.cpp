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
	// string은 char[]이므로, list로 구현
	list<char> cont;
	string in;
	getline(cin, in);
	FOR(i,0,in.size(),1)
		cont.push_back(in[i]);
	auto itr=cont.end(); // 커서 위치
	int nofi;
	cin>>nofi;
	cin.get(); // 개행 제거
	string temp;
	FOR(i,0,nofi,1){
		//cin>>temp;
		getline(cin, temp);
		if(temp[0]=='P')
			itr=++cont.insert(itr,temp[2]);
		else if(temp[0]=='L'){
			if(itr!=cont.begin())
				itr--;
		}
		else if(temp[0]=='D'){
			if(itr!=cont.end())
				itr++;
		}
		else
			if(itr!=cont.begin())
				itr=cont.erase(--itr);
	}
	for(char c:cont)
		cout<<c;
	cout<<'\n';
	return 0;
}