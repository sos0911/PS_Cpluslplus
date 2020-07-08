#include <iostream>
#include <string>
#include <set>
// map은 쓸 필요가 없다.
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 필수 옵션
	// puts, gets 이런 c 기반 입출력 함수들을 안 쓸려면..
	// 나중에 뭐가 더 빠른지 테스트 필요
	int n, m;
	cin>>n>>m;
	cin.get();
	set<string> hear;
	for(int i=0;i<n;++i){
		string input;
		getline(cin, input);
		hear.insert(input);
	}
	set<string> dual; // 듣보
	for(int i=0;i<m;++i){
		string input;
		getline(cin, input);
		auto itr=hear.find(input);
		if(itr!=hear.end())
			dual.insert(*itr);
	}
	cout<<dual.size()<<'\n';
	for(auto itr=dual.begin();itr!=dual.end();++itr)
		cout<<*itr<<'\n';
	return 0;
}