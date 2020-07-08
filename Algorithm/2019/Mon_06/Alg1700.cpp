#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k, input, input2;
	cin>>n>>k;
	set<int> pool; // 오름차순 정렬
	// 중복 허용x
	int ret=0;
	int use[k]; // 0-
	FOR1(i,k)
		cin>>use[i];
	FOR1(i,k){
		if(pool.size()<n)
			pool.insert(use[i]);
		else if(pool.find(use[i])==pool.end()){
			// 가장 시간이 흐른 뒤 쓰는 전기용품 콘센트를 뺀다
			// 단, 모두 다 쓰지 않는다면 아무거나 빼서 꽂는다
			set<int> temp(pool);
			for(int j=i+1;j<k;j++){
				if(temp.size()==1)
					break;
				auto itr=temp.find(use[j]);
				if(itr!=temp.end())
					temp.erase(itr);
			}
				pool.erase(*(temp.begin()));
				pool.insert(use[i]);	
			ret++;
		}
	}
	cout<<ret<<'\n';
	return 0;
}