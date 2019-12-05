
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
ll Answer;

int main(int argc, char** argv)
{
	//setbuf(stdout, NULL);
		//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int T, test_case;
	scanf("%d", &T);
	//cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int m,n;
		scanf("%d", &m);
		scanf("%d", &n);
		//cin>>m>>n;
		pii in[n]; // 0- (x,y)
		FOR1(i,n)
			scanf("%d %d", &in[i].fi, &in[i].se);
			//cin>>in[i].fi>>in[i].se;
		FOR1(i,n){
			int mind=1e9+10; // 최적인 두 점을 가지는 정사각형의 변길이
			FOR1(j,n)
				if(j!=i&&in[j].fi>=in[i].fi&&in[j].se>=in[i].se){
					int temp=max(in[j].fi-in[i].fi, in[j].se-in[i].se);
					if(temp<mind)
						mind=temp;
				}
			if(mind==1e9+10)
				mind=min(m-in[i].fi, m-in[i].se);
			//cout<<"mind : "<<mind<<'\n';
			Answer+=mind;
		}
		printf("Case #%d\n", test_case+1);
		printf("%lld\n", Answer);
		//cout << "Case #" << test_case+1 << endl;
		//cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}