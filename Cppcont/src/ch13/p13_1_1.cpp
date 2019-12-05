#include <iostream>
using namespace std;
template <class T> // = <typename T>
T SumArray(T arr[], int len){ // 배열 자체를 넘겨받네..
	T sum=0;
	for(int i=0;i<len;i++)
		sum+=arr[i];
	return sum;
}
int main(){
	int t1[]={1,2,3,4,5};
	// t1의 자료형은 int[]. 크기는 4*5=20b
	double t2[]={1.1,2.2,3.3,4.4,5.5};
	cout<<SumArray(t1, sizeof(t1)/sizeof(int))<<endl;
	cout<<SumArray(t2, sizeof(t2)/sizeof(double))<<endl;
	return 0;
}