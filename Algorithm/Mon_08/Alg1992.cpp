// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int n;
string in[64];
void div(int r, int c, int len){
	bool united=true;
	char stn=in[r][c];
	for(int i=r;i<r+len;i++)
		for(int j=c;j<c+len;j++)
			if(in[i][j]!=stn){
				united=false;
				goto esc:
			}
	esc:
	cout<<"(";
	if(united)
		cout<<stn;
	else{
		div(r,c,len/2);
		div(r,c+len/2,len/2);
		div(r+len/2,c,len/2);
		div(r+len/2,c+len/2,len/2);
	}
	cout<<")";
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>in[i];
	div(0,0,n);
	cout<<'\n';
	return 0;
}