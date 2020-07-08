#include <bits/stdc++.h>
using namespace std;
int main(){
	int y;
	cin>>y;
	cout<<(((!(y%4)&&(y%100))||!(y%400))? 1:0)<<'\n';
	return 0;
}