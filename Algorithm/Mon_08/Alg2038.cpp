// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int n;
const int maxd=1e6;
vector<int> cache; // [tar,st] 저장
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	// to-pointer
	int tar=2,st=2,curi=1;
	// 수열에서 tar가 위치하는 가장 첫 번째 위치=st
	// vector 내 idx=curi
	cache.reserve(maxd);
	cache.push_back(-1);
	cache.push_back(1);
	while(st<=n){
		cache.push_back(st);
		tar++;
		// f(tar-1)가 뭔지 찾아놓는다.
		while(cache[curi]<=tar&&curi!=cache.size())
			curi++;
		curi--;
		cout<<"fun : "<<tar-1<<" : "<<curi<<'\n';
		st=cache[tar-1]+curi;
		cout<<"st : "<<st<<" tar : "<<tar<<'\n';
	}
	cout<<tar<<'\n';
	return 0;
}