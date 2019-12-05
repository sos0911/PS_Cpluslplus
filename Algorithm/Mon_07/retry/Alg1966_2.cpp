#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
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
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin>>noft;
	FOR(i,0,noft,1){
		int n,m; // ind
		cin>>n>>m;
		queue<pii> cq; // (index, 중요도)
		priority_queue<int> cpq; // max heap, 중요도
		FOR(j,0,n,1){
			int temp;
			cin>>temp;
			cq.push({j,temp});
			cpq.push(temp);
		}
		int ret=1;
		int curpqt;
		while(cq.front().se!=(curpqt=cpq.top())||cq.front().fi!=m){
			// 매 단계마다 curpqt는 갱신되어야 하므로 맨 앞 조건.
			if(curpqt!=cq.front().se){ // 가장 큰 게 아니면 뒤로 감
				auto p=cq.front();
				cq.pop();
				cq.push(p);
			}
			else{ // 가장 중요도가 높음
				auto temp=cq.front();
				cq.pop();
				cpq.pop();
				ret++;
			}
		}
		cout<<ret<<'\n';
	}
	return 0;
}

	/*
	pq 준비
queue<pii>도 준비한다.
(중요도, 처음 queue index)
100이하.
tc당 100*100 = 최대 만번정도 돌게따

만약 자기보다 높은 게 뒤에존재(pq로 검사) =>

queue에서 빼서 뒤로 넣는다.

else

queue에서 빼고 pq pop

done 
*/