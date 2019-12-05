#include <iostream>
//typedef int(*Fp)(int); // 일반 변수로 보이게 한다 // c++ 03
// 보통은 typedef는 typedef 자료형 별칭 순으로 오지만 함수 포인터는 포인터 이름을 별칭으로 가정할 수 있다.
// define하고는 다르게 typedef는 전처리기 구문이 아니므로 신경쓰자 = (;을 붙여야 한다)
using namespace std;
template <class T>
class test{
	T data;
	public:
	test(const T& data):data(data){}
	void ShowInfo(){
		cout<<data<<endl;
	}
};
template<>
// T가 없으므로 <>, 어떤 템플릿에 대해 일부 or 전부를 정의한다는 의미
class test<int>{
	int data;
	public:
	test(int data):data(data){}
	// 특수화되는 클래스 템플릿에서 원래 템플릿과 함수가 달라도 된다.(+ 함수 이름까지)
	void ShowInfo2(){
		cout<<data<<endl;
	}
};
int main(){
	test<double> t1(5.55);
	test<int> t2(1);
	t1.ShowInfo();
	t2.ShowInfo2();
	return 0;
}