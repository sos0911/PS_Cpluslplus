#include <iostream>
#include <deque>
using namespace std;
int main(){
	deque<int> cont;
	cout<<'[';
			deque<int>::iterator iter;
			for(iter=cont.begin();iter!=cont.end()-1;++iter)
				cout<<*iter<<",";
			cout<<*iter<<']'<<'\n';
	return 0;
}