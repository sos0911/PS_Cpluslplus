// 대회용 템플릿
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
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	return 0;
}
/*
s(i) bbaba
t(j) bb
     01234

답 : 3

>>
     0 1 2
s = -1 0 1

ans=ma(ams,3-s[1]-1) = 2

ans=ma(ans,1-s[0]-1) = 0

5-s[2]-1 = 5-1-1 = 3

s[i] : t의 index i-1까지 갖는 prefix가 
최소한도로 필요한 s의 substring 끝나는 idx

다시 뒤에서 앞으로 훑을 때,
t의 해당 idx가 가장 최후반으로 위치할 수 있는 idx를 찾을 수 있다.

s[i]에는 t의 해당 idx가 가장 최전반으로 위치 가능한 idx가 있으므로
ans=max(ans,i-s[j]-1)
그 사이의 것+1은 없어도 상관없다는 소리이다.
(둘 중 하나만 존재하면 된다.)

마지막에 제일 끝부분 처리만 해주면 완벽
 */