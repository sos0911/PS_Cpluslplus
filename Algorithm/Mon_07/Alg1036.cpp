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
const int MAXD=60;
struct Info{
	vi num;
	int idx;
	Info():num(MAXD,0){}
};
struct comp{
	// 내림차순 정렬
	// true면 그대로
	bool operator()(Info a, Info b){
		for(int i=0;i<MAXD;i++)
			if(a.num[i]>b.num[i])
				return true;
			else if(a.num[i]<b.num[i])
				return false;
			else
				continue;
		return a.idx<b.idx;
	}
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n;
	vector<Info> cont(36,Info()); // 0-35
	for(int i=0;i<36;i++)
		cont[i].idx=i;
	// 각 자리가 최대 MAXD자리라 가정
	// 가장 오른쪽 자리가 36^0
	// 앞일수록 자릿수가 높은것
	FOR(i,0,n,1){
		string in;
		cin>>in;
		FOR(j,0,in.size(),1){
			if(in[j]>='0'&&in[j]<='9')
				cont[in[j]-'0'].num[MAXD-(in.size()-j)]++;
					// 최대 n이 50이므로 ㄱㅊ
			else
				cont[in[j]-'A'+10].num[MAXD-(in.size()-j)]++;
					// 최대 n이 50이므로 ㄱㅊ
		}
	}
	vector<Info> cont2(cont); // 복사
	for(int j=0;j<36;j++)
		for(int i=0;i<MAXD;i++)
			cont2[j].num[i]*=(35-cont2[j].idx);
	// carry
	for(int j=0;j<36;j++)
		for(int i=59;i>=1;i--){
		cont[j].num[i-1]+=cont[j].num[i]/36;
		cont[j].num[i]%=36;
		cont2[j].num[i-1]+=cont2[j].num[i]/36;
		cont2[j].num[i]%=36;
	}
	// cont는 입력받은 그대로를 더한 36진수이다.
	sort(cont2.begin(), cont2.end(), comp());
	/*for(Info in:cont2){
		cout<<"idx : "<<in.idx<<'\n';
		for(int i:in.num)
			cout<<i;
		cout<<'\n';
	}*/
	vi ans(MAXD,0);
	cin>>k;
	FOR(i,0,36,1){
		if(i<k)
			FOR(j,0,MAXD,1)
			ans[j]+=35*cont[cont2[i].idx].num[j];
		else
			FOR(j,0,MAXD,1)
			ans[j]+=cont[cont2[i].idx].idx*cont[cont2[i].idx].num[j];
	}
	// carry
	for(int i=59;i>=1;i--){
		ans[i-1]+=ans[i]/36;
		ans[i]%=36;
	}
	int i=0;
	for(;ans[i]==0&&i<MAXD;i++);
	if(i==MAXD)
		cout<<0;
	else
	for(;i<MAXD;i++)
		if(ans[i]>=0&&ans[i]<=9)
			cout<<ans[i];
		else
			cout<<(char)(ans[i]-10+'A');
	cout<<'\n';
	return 0;
}
// int carry[MAXD]; 36진수의 각 자릿수 저장하여 처리