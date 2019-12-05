#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;
int main(){
	bool tset[5];
	int tset2[5];
	for(bool b:tset)
		cout<<b<<endl; // false로 자동 초기화
	for(int i:tset2)
		cout<<i<<endl;
	cout<<typeid(tset).name()<<endl; // type : A5_b : bool 배열형
	cout<<typeid(tset2).name()<<endl; // 배열형이기 때문에 구간 for문 사용가능
	// 끝을 아므로
	// 2차원 배열인 경우 구간 for문 샤용불가
	return 0;
}