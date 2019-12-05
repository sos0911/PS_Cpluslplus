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
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	// list
	// 풍선 내 수는 -N~N
	// tc: 최대 O(N^2)
	int n,temp;
	cin>>n;
	list<pii> cont; // (풍선 번호, 값)
	FOR(i,1,n+1,1){
		cin>>temp;
		cont.push_back({i,temp});
	}
	auto itr=cont.begin();
	while(cont.size()!=1){
		cout<<itr->fi<<" ";
		temp=itr->se;
		itr=cont.erase(itr); // 삭제 후 다음 원소
		if(itr==cont.end())
			itr=cont.begin();
		if(temp<0)
			FOR(i,0,(-temp%cont.size()),1){
			if(itr==cont.begin())
				itr=--cont.end();
			else
				itr--;
		}
		else
			FOR(i,0,(temp-1)%cont.size(),1){
			itr++;
			if(itr==cont.end())
				itr=cont.begin();
		}
	}
	cout<<cont.front().fi;
	cout<<'\n';
	return 0;
}