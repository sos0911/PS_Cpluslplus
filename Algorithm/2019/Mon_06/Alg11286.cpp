#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct comp{
	bool operator()(int a, int b){
		return abs(a)==abs(b)? a>b:abs(a)>abs(b);
	}
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, input;
	cin>>n;
	priority_queue<int, vector<int>, comp> pq; // 최대 힙
	// functor : 함수처럼 사용
	for(int i=0;i<n;i++){
		cin>>input;
		if(input==0){
			if(pq.empty())
				cout<<0<<'\n';
			else{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
		}
		else
			pq.push(input);
	}
	return 0;
}