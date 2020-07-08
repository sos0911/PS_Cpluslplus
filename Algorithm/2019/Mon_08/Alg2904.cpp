// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxd=1e6;
int n;
bool prime[maxd+1];
vector<int> p;
vector<vector<int>> cnt; // 각 수마다 소인수분해 결과 저장
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	p.reserve(100000);
	fill(prime, prime+maxd+1,true);
	for(int i=2;i<=maxd;i++)
		if(prime[i]){
			p.push_back(i);
			for(ll j=1LL*i*i;j<=maxd;j+=i)
				prime[j]=false;
		}
	cin>>n;
	cnt.assign(n, vector<int>(p.size(),0));
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		// 소인수분해
		int idx=0; // 소수 vector idx
		while(temp!=1&&idx<p.size()){ // 조건 1개 필요?
			if(!(temp%p[idx])){
				cnt[i][idx]++;
				temp/=p[idx];
			}
			else
				idx++;
		}
	}
	int ret=0,ans=1; // 최소 수행 횟수
	for(int i=0;i<p.size();i++){
		int sum=0;
		for(int j=0;j<n;j++)
			sum+=cnt[j][i];
		int aver=sum/n;
		for(int j=0;j<n;j++)
			if(cnt[j][i]<aver)
				ret+=aver-cnt[j][i];
		ans*=(int)pow(p[i],aver);
	}
	cout<<ans<<" "<<ret<<'\n';
	return 0;
}