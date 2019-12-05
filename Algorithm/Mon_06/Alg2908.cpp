#include <iostream>
#include <string>
using namespace std;
int main(){
	string A,B;
	cin>>A>>B;
	string reA,reB;
	for(int i=2;i>=0;i--){
		reA+=A.at(i);
		reB+=B.at(i);
	}
	cout<<(reA>reB? reA:reB)<<endl;
	return 0;
}