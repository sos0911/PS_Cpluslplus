// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxd=1e6;
vector<int> fun; // f(k) 저장
// idx가 f(k)고 값이 fun[x]가 처음 시작될 때 idx
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	fun.reserve(maxd*2);
	fun.push_back(0);
	fun.push_back(1);
	ll sum=1,ans=1;
	for(int i=2;i<=n;i++){
		// 점화식(구글링..)
		int temp=1+fun[i-fun[fun[i-1]]];
		fun.push_back(temp);
		cout<<"temp : "<<temp<<'\n';
		sum+=temp;
		if(sum>=n){
			ans=i;
			break;
		}
	}
	cout<<ans<<'\n';
	return 0;
}