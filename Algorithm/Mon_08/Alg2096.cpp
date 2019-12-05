// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
// sliding window
int n;
int pmin[3]={}, pmax[3]={}, cmin[3]={}, cmax[3]={};
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int j=0;j<3;j++)
		cin>>pmin[j];
	copy(pmin,pmin+3,pmax);
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++)
			cin>>pmin[j];
		
	}
	return 0;
}