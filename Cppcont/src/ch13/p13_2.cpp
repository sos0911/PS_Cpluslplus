#include <iostream>
using namespace std;
// 클래스 템플릿(틀)
class Point{
	int y, x;
	public:
	Point(int y=0, int x=0):y(y),x(x){}
	// class initializer에서는 매개변수와 멤버변수가 동일한 이름을 가지는 것을 허용
	void SetPos(int _y, int _x){
		y=_y;
		x=_x;
	}
	void ShowPos(){
		cout<<"["<<y<<","<<x<<"]"<<endl;
	}
};
template <class T>
class SmartPtr{
	T* temptr;
	public:
	SmartPtr(T* ptr):temptr(ptr){}
	T& operator*() const{return *temptr;}
	T* operator->() const{return temptr;}
	~SmartPtr(){delete temptr;}
	// temptr이 가리키는 객체는 동적 할당되었다는 가정 포함
};
int main(){
	SmartPtr<Point> ptr1(new Point(3,4));
	SmartPtr<Point> ptr2(new Point(1,2));
	// 객체 자체가 마치 포인터처럼 작동한다.
	// 객체이므로 단순 포인터보다 할 수 있는 여지가 많다.
	ptr1->ShowPos();
	ptr2->ShowPos();
	ptr1->SetPos(10, 20);
	ptr2->SetPos(30, 40);
	ptr1->ShowPos();
	ptr2->ShowPos();
	return 0;
}