#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	map<int,int> cont;
	int n;
	cin>>n;
	cin.get();
	// 공백 제거
	cont.insert(make_pair(0, -1));
	cont.insert(make_pair(n+1, -1));
	// error 방지
	// 왜 cnt가 longlong이어야 하지..
	ll cnt=0;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp; 
		cin.get();
		cont.insert(make_pair(temp, 0));
		auto itr=cont.find(temp); // auto&?
		auto cur=itr; // 대입 생성자 오버로딩됨?
		// 된다! iterator class내에서 대입 연산자가 오버로딩된 상태이다.
		cur->second=(++itr)->second;
		--itr; --itr;
		int temp2;
		temp2=cur->second=max(cur->second, itr->second)+1;
		cout<<(cnt+=temp2)<<'\n';
	}
	return 0;
}