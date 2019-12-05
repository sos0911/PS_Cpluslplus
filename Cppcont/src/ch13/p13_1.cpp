#include <iostream>
using namespace std;
class Point{
	int y, x;
	public:
	Point(int y, int x):y(y),x(x){}
	void Showpos() const{
		cout<<"["<<y<<","<<x<<"]"<<endl;
	}
};
template <typename T> // 아래 함수 or class는 template입니다.
void Swap(T& p1, T& p2){
	T temp=p1; // default 복사 생성자 호출(얕은 복사)
	p1=p2; // default 대입 연산자 호출
	p2=temp;
}
int main(){
	Point p1(1,1);
	Point p2(2,3);
	p1.Showpos();
	p2.Showpos();
	Swap(p1, p2);
	cout<<"change done"<<endl;
	p1.Showpos();
	p2.Showpos();
	return 0;
}