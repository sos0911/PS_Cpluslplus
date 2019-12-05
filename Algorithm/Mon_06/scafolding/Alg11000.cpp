#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
struct comp1{
	bool operator()(pii a, pii b){
		return a.first==b.first? a.second<b.second:a.first<b.first;
		// ed 먼저 정렬, 그다음 st
	}	
};
struct comp2{
	bool operator()(pii a, pii b){
		return a.second=b.second? a.first<b.first:a.second<b.second;
		// ed 먼저 정렬, 그다음 st
	}	
};
int solve1(pair<int,int> input[5]){ // 정답
	pair<int,int> pool[5];
	copy(input, input+5, pool);
	sort(pool, pool+5, comp1());
	priority_queue<int> ret;
	FOR1(i,5){
		if(ret.empty()||-ret.top()>pool[i].first)
			ret.push(-pool[i].second);
		else{
			ret.pop();
			ret.push(-pool[i].second);	
		}
	}
	return ret.size();
}
int solve2(pair<int,int> input[5]){ // 오답
	pair<int,int> pool[5];
	copy(input, input+5, pool);
	sort(pool, pool+5, comp2());
	priority_queue<int> ret;
	FOR1(i,5){
		if(ret.empty()||-ret.top()>pool[i].first){
			ret.push(-pool[i].second);
			cout<<"inserted : "<<pool[i].second<<'\n';
		}
		else{
			cout<<"updated : "<<-ret.top()<<" -> "<<pool[i].second<<'\n';
			ret.pop();
			ret.push(-pool[i].second);	
		}
	}
	return ret.size();
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while(true){
	pair<int,int> input[5]={{1,1},{3,7},{5,5},{5,12},{9,16}};// 5개
	/*and((unsigned int)time(NULL));
	FOR1(i,5){
	int a=rand()%11+1; // 1-11
	int b=rand()%11+a;
	input[i]={a,b};
	}*/
	int ret1=solve1(input);
	int ret2=solve2(input);
	if(ret1!=ret2){
		cout<<"mismatch !"<<'\n';
		for(auto i:input)
			cout<<i.first<<" "<<i.second<<'\n';
		cout<<'\n';
		cout<<"solve1 : "<<ret1<<'\n';
		cout<<"solve2 : "<<ret2<<'\n';
		break;
	}
	}
	return 0;
}