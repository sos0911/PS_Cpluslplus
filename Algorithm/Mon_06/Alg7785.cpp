#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	set<string> cont;
	// 초기 용량x(tree)
	int n;
	cin>>n;
	// cin.ignore()
	cin.get();
	// 버퍼 내 개행문자 제거
	for(int i=0;i<n;i++){
		string temp;
		getline(cin, temp);
		// 다음 개행 문자까지 읽음
		stringstream ss(temp);
		string name, cond;
		ss>>name; ss>>cond;
		if(cond.compare("enter")==0)
			cont.insert(name);
		else{
			// 안전한 삭제 방법(map,set)
			auto temp=cont.find(name);
			if(temp!=cont.end())
				cont.erase(temp);
		}
	}
	// 역순출력(사전순 저장됨)
	for(auto itr=cont.rbegin();itr!=cont.rend();++itr)
		cout<<*itr<<'\n';
	return 0;
}

// https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string
// way of spliting words