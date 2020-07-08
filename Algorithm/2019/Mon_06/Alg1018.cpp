#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int solve(int sy, int sx, vs& cont){ // (i,j)가 맨 왼쪽 위
	// (i,j)==B -> 2로 나눈 나머지가 i+j와 같을 때 B
	int ret=1e9, temp=0;
	FOR2(i,sy,sy+8)
		FOR2(j,sx,sx+8)
			if((i+j)%2==(sy+sx)%2&&cont[i][j]!='B')
				temp++;
			else if((i+j)%2!=(sy+sx)%2&&cont[i][j]!='W')
				temp++;
	ret=min(ret,temp);
	temp=0;
	// (i,j)=>W
	FOR2(i,sy,sy+8)
		FOR2(j,sx,sx+8)
			if((i+j)%2==(sy+sx)%2&&cont[i][j]!='W')
				temp++;
			else if((i+j)%2!=(sy+sx)%2&&cont[i][j]!='B')
				temp++;
	ret=min(ret,temp);
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vs cont; //0-
	cont.reserve(n);
	FOR1(i,n){
		string input;
		cin>>input;
		cont.push_back(input);
	}
	int minn=1e9;
	// 잘라본다
	FOR1(i,n-7)
		FOR1(j,m-7)
			minn=min(minn,solve(i,j,cont));
	cout<<minn<<'\n';
	return 0;
}