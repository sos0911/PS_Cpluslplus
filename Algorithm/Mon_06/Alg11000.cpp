#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct comp{
	bool operator()(pii a, pii b){
		return a.first==b.first? a.second<b.second:a.first<b.first;
		// ed 먼저 정렬, 그다음 st
	}	
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// pq나 set을 써보자
	int n;
	cin>>n;
	pii pool[n]; // input
	priority_queue<int, vector<int>, greater<int>> ret; // min heap
	// ed 오름차순으로 정렬
	FOR1(i,n)
		cin>>pool[i].first>>pool[i].second;
	// (st,ed)
	//int cont[n];
	//memset(cont, -1, sizeof(cont));
	sort(pool, pool+n, comp());
	// 수업을 하나씩 꺼내 cont[ind]와 겹치지 않으면 끝나는 시간 저장
	FOR1(i,n){
		if(ret.empty()||ret.top()>pool[i].first)
			ret.push(pool[i].second);
		else{
			ret.pop();
			ret.push(pool[i].second);	
		}
	}
	// pq에 남아있는 size가 강의실 개수
	cout<<ret.size()<<'\n';
	return 0;
}