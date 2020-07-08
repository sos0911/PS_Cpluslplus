#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<double> vd;
typedef vector<int> vi;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,l;
	cin>>n>>l;
	vd edtape(n+1,-1); // -1로 초기화 
	vi input;
	input.reserve(n); // 물 새는 위치 저장
	FOR1(i,n){
		int in;
		cin>>in;
		input.push_back(in);
	}
	sort(input.begin(), input.end()); // 오름차순
	int iter=0;
	int ret=0;
	FOR1(i,n)
		if(edtape[iter]-input[i]<0.5){
			edtape[++iter]=input[i]+l-0.5;
			ret++;
		}
	cout<<ret<<'\n';
	return 0;
}