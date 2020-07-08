#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	vector<multiset<int>> cont;
	cont.reserve(100);
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cont.push_back(multiset<int>());
		int input;
		for(int j=0;j<m;j++){
			cin>>input;
			cont[i].insert(input); // 오름차순 정렬
		}
	}
	vector<int> ans(n, 0); // 문제 부분
	for(int i=0;i<m;i++){
		int max=-1, temp;
		for(int j=0;j<n;j++)
			if(max<(temp=(*(--cont[j].end()))))
				max=temp;
		for(int j=0;j<n;j++){
			auto itr=cont[j].end();
			if(max==(temp=(*(--itr))))
				ans[j]++;
			cont[j].erase(itr); // 하나의 원소만 소거
		}
	}
	int maxn=-1;
	for(int i=0;i<n;i++)
		maxn=max(maxn, ans[i]);
	for(int i=0;i<n;i++)
		if(ans[i]==maxn)
			cout<<i+1<<" ";
	cout<<'\n';
	return 0;
}