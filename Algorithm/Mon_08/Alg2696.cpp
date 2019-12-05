// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int t,m;
int in[10000];
priority_queue<int> maxh;
priority_queue<int,vector<int>,greater<int>> minh;
int mid; // 중앙값
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>m;
		for(int j=0;j<m;j++)
			cin>>in[j];
		// 홀수 때마다 출력
		cout<<m/2<<'\n';
		for(int j=0;j<m;j++){
			mid=in[j];
			if(j%2==0)
				cout<<mid<<'\n';
			else{
				if(j%2!=0){
					if(mid<=in[j]){
						maxh.push(mid);
						minh.push(in[j]);
					}
					else{
						minh.push(mid);
						maxh.push(in[j]);
					}
				}
				else{
					if(mid<maxh.top()){
						int temp=maxh.top();
						maxh.pop();
						maxh.push(mid);
						mid=temp;
					}
					else if(mid>minh.top()){
						int temp=minh.top();
						minh.pop();
						minh.push(mid);
						mid=temp;
					}
				}
			}
		}
		maxh=priority_queue<int>();
		minh=priority_queue<int,vector<int>,greater<int>>();
	}
	return 0;
}