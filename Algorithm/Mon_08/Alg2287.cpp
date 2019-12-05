// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int k,n,a;
set<int> cont[9]; // 1-8(dp)
void solve(int cnt){
	// k cnt개로 만드는 모든 수 저장
	for(int i=1;i<cnt;i++){
		if(!cont[i].size())
			solve(i);
		if(!cont[cnt-i].size())
			solve(cnt-i);
		for(auto itr1=cont[i].begin();itr1!=cont[i].end();itr1++)
			for(auto itr2=cont[cnt-i].begin();itr2!=cont[cnt-i].end();itr2++){
				cont[cnt].insert((*itr1)+(*itr2));
				cont[cnt].insert((*itr1)-(*itr2));
				cont[cnt].insert((*itr1)/(*itr2));
				cont[cnt].insert((*itr1)*(*itr2));
			}
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>k>>n;
	cont[1].insert(k);
	solve(8);
	for(int i=0;i<n;i++){
		cin>>a;
		bool possi=false;
		for(int j=1;j<=8;j++)
			for(auto itr=cont[j].begin();itr!=cont[j].end();itr++)
				if(*itr==a){
					cout<<j<<'\n';
					possi=true;
					goto esc;
				}
		esc:
		if(!possi)
			cout<<"NO"<<'\n';
	}
	return 0;
}