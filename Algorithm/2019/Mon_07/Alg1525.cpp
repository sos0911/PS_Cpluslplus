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
int dir[]={-1,1,3,-3};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// bitmask처럼 보이는거+bfs
	// 상태는 103425786.. 으로 진행(string)
	// 123456780으로 만드는 것이 목적
	string end="123456780";
	string in="";
	int temp;
	FOR(i,0,9,1){
		cin>>temp;
		in+=(char)(temp+'0');
	}
	set<string> cont; // visit 역할, 기본 정렬자로도 가능?
	// visit 배열은 메모리초과
	queue<string> bfsq;
	bfsq.push(in);
	cont.insert(in);
	bool possi=false;
	int ret=0;
	while(!bfsq.empty()){
		int len=bfsq.size();
		FOR(i,0,len,1){
			auto here=bfsq.front();
			bfsq.pop();
			if(here==end){
				possi=true;
				goto esc;
			}
			// 상태 바꿔봄
			int tar; // '0' index
			FOR(j,0,here.size(),1)
				if(here[j]=='0'){
					tar=j;
					break;
				}
			FOR(j,0,4,1)
				if(tar+dir[j]>=0&&tar+dir[j]<9){
					if(j/2==0&&tar/3!=(tar+dir[j])/3)
						continue;
					string next=here;
					swap(next[tar], next[tar+dir[j]]);
					if(cont.find(next)==cont.end()){
						bfsq.push(next);
						cont.insert(next);
					}
				}
		}
		ret++;
	}
	esc:
	cout<<(possi? ret:-1)<<'\n';
	return 0;
}