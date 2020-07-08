#include <iostream>
#include <vector>
#include <algorithm> // sort()
#include <queue>
using namespace std;
// true면 바꾸지 않음
struct comp_st{
	bool operator()(const pair<int,int>& a, const int& b){
		return a.first<b;
	}
	bool operator()(const int& a, const pair<int,int>& b){
		return a<b.first;
	}
};
bool comp(pair<int,int>& p1, pair<int,int>& p2){
	return p1.first<p2.first;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	cin.get();
	// 개행 제거
	vector<pair<int,int>> start; // 시작시간, 컴퓨터 번호
	start.reserve(n);
	vector<pair<int,int>> end; // 종료시간, 시작시간
	end.reserve(n);
	for(int i=0;i<n;i++){
		int st, ed;
		cin>>st>>ed;
		cin.get();
		start.push_back(make_pair(st, -1)); // -1은 할당x 표시
		end.push_back(make_pair(ed, st));
	}
	sort(start.begin(), start.end(), comp);
	sort(end.begin(), end.end(), comp);
	priority_queue<int, vector<int>, greater<int>> pq; // heap - 비어 있는 자리
	auto itr1=start.begin();
	auto itr2=end.begin();
	int idx=1; // 통상시 사용 가능한 최소 컴퓨터 번호
	vector<int> freq(100001); // 0으로 초기화
	while(itr1!=start.end()&&itr2!=end.end()){
		if(itr1->first<=itr2->first){
			if(pq.empty()||pq.top()>idx){
				itr1->second=idx;
				freq[idx]++;
				idx++;
			}
			else{
				itr1->second=pq.top();
				pq.pop();
				freq[itr1->second]++;
			}
			itr1++;
		}
		else{
			auto ret=lower_bound(start.begin(), start.end(), itr2->second, comp_st());
			pq.push(ret->second); // 사용 종료
			itr2++;
		}
	}
	// 답 : idx-1
	if(itr1!=start.end()){ // 사용할 사람만 남음
		if(pq.empty()||pq.top()>idx){
				itr1->second=idx;
				freq[idx]++;
				idx++;
			}
		else{
				itr1->second=pq.top();
				pq.pop();
				freq[itr1->second]++;
			}
	}
	// 사용 종료만 남았으면 상관x
	cout<<idx-1<<'\n';
	for(int i=1;i<=idx-1;i++)
		cout<<freq[i]<<" ";
	cout<<'\n';
	return 0;
}