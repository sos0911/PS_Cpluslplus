#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
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
typedef vector<pii> vpi;
typedef pair<int,pii> pip;
ll Answer;
struct comp{
	bool operator()(const pair<int,pii>& a, const pair<int,pii>& b){
		return a.fi==b.fi? a.se.fi<b.se.fi:a.fi<b.fi;
	}	
};
struct comp2{
	bool operator()(const pair<int,pii>& a, int key){
		return a.fi<key;
	}	
	bool operator()(int key, const pair<int,pii>& a){
		return key<a.fi;
	}	
};
int main(int argc, char** argv)
{
		cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int m,n;
		cin>>m>>n;
		vector<pair<int, pii>> in(n,{0,{0,0}}); // 0- (y+x, 좌표)
		FOR1(i,n){
			cin>>in[i].se.fi>>in[i].se.se;
			in[i].fi=in[i].se.fi+in[i].se.se;
		}
		sort(in.begin(), in.end(), comp()); // x+y 오름차순, x 오름차순
		FOR1(i,n){
			int ret=1e9+10; // 한 변 길이
			auto itr=upper_bound(in.begin(),in.end(),in[i].fi,comp2);
			int stn=itr->fi;
			FOR2(j,i+1,n){
				if(in[j].fi==stn){
					if(in[j].se.fi>=in[i].se.fi&&in[j].se.se>=in[i].se.se)
					ret=min(ret, max(in[j].se.fi-in[i].se.fi, in[j].se.se-in[i].se.se));
				}
			else
				break;
			}
			if(ret==1e9+10)
				ret=min(m-in[i].se.fi, m-in[i].se.se);
			Answer+=ret;
		}
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}