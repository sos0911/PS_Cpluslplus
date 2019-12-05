#include <iostream> // 입출력 함수들을 모아 놓았나 보다.
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
	srand((unsigned int)time(0));
	for(int i=0;i<5;i++)
		cout<<i+1<<"번째 난수 : "<<rand()%100<<endl; // 0-99
}