#include <iostream>
#include <typeinfo>
using namespace std;
int check(int tic[4][4]){
	for(int i=1;i<4;i++){
		if(tic[i][1]!=0&&tic[i][1]==tic[i][2]&&tic[i][2]==tic[i][3])
			return tic[i][1]==1? 1: 2;
		if(tic[1][i]!=0&&tic[1][i]==tic[2][i]&&tic[2][i]==tic[3][i])
			return tic[1][i]==1? 1: 2;
	}
	if(tic[1][1]!=0&&tic[1][1]==tic[2][2]&&tic[2][2]==tic[3][3])
		return tic[1][1]==1? 1:2;
	if(tic[3][1]!=0&&tic[3][1]==tic[2][2]&&tic[2][2]==tic[1][3])
		return tic[3][1]==1? 1:2;
	return 0;
}
int main(){
	int tic[4][4]={0};
	int first, ret;
	cin>>first;
	for(int i=0;i<9;i++){
		int x,y;
		cin>>x>>y;
		tic[x][y]=first;
		if((ret=check(tic))){ // 판에 대하여 승자check
			cout<<ret<<'\n';
			return 0;	
		}
		first=first==1? 2:1; // switch
	}
	cout<<0<<'\n';
	return 0;
}