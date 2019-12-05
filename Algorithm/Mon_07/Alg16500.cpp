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
int n, tarlen;
string tar; 
string input[101];
bool solve(int len){
	// cur에 1-N번째 문자열을 계속 붙여봐서 그 중 하나가 정답이면 true
	// cur은 앞까지는 일치하므로 그 뒤만 확인
	if(len==tarlen)
		return true;
	FOR1(i,n){
		int ilen=input[i].size();
		if(len+ilen<=tarlen){
			bool error=false;
		FOR1(j,ilen)
			if(tar[len+j]!=input[i][j]){
				error=true;
				break;
			}
			if(!error)
				if(solve(len+ilen))
					return true;
		}
	}
	// 해당사항 없음
	return false;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>tar;
	tarlen=tar.size();
	cin>>n;
	FOR1(i,n)
		cin>>input[i]; // 0-
	cout<<(solve(0)? 1:0)<<'\n';
	return 0;
}
/*bool dp[s];

앞에서부터 s개의 문자열까지 사용 가능할 시
뒤에 나머지를 붙여서 완성 가능한지를 판별
점화식 : dp[s-1]에 s번쨰 문자열을 붙이냐 마느냐..

*/