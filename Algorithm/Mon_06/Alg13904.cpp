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
struct comp{
	bool operator()(pii a, pii b){
		return a.fi==b.fi? a.se>b.se:a.fi<b.fi;
	}
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	pii input[n]; // (마감일 잔여, 과제 점수)
	FOR1(i,n)
		cin>>input[i].fi>>input[i].se;
	sort(input, input+n, comp());
	int day=1, ret=0;
	priority_queue<int> pool; // min heap
	FOR1(i,n){
		if(input[i].fi>=day){
			pool.push(-input[i].se);
			ret+=input[i].se;
			day++;
		}
		else{ // deadline 규정 어긋남
			// 이놈 앞에 것까지는 모두 처리되었다고 가정
			if(-pool.top()<input[i].se){
				// 제일 작은 놈 빼고 넣음
				// 이게 가능한게 이미 데드라인으로 정렬된 상태에서 하는거므로
				// .. (내일 완성)
				ret-=-pool.top();
				ret+=input[i].se;
				pool.pop();
				pool.push(-input[i].se);
				// day는 추가하지 않는다.
			}
		}
	}
	cout<<ret<<'\n';
	return 0;
}