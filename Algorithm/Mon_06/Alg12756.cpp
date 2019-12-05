#include <iostream>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int aa, al, ba, bl;
	cin>>aa>>al>>ba>>bl;
	while(al>0&&bl>0){
		al-=ba; bl-=aa;
	}
	if(al>0)
		cout<<"PLAYER A"<<'\n';
	else if(bl>0)
		cout<<"PLAYER B"<<'\n';
	else
		cout<<"DRAW"<<'\n';
	return 0;
}