#include <iostream>
using namespace std;
class point{
	int y, x;
	public:
	point(int y, int x):y(y),x(x){}
	point& operator+=(const point& p){
		y+=p.y; x+=p.x;
		return *this;
	}
	point& operator-=(const point& p){
		y-=p.y; x-=p.x;
		return *this;
	}
	// inline 함수인데 private 영역에 접근하는 함수다. 어떻게 되지?
	// 잘 됩니다.
	// 어차피 컴파일러 판단에 의해 그냥 함수처럼 작동할지 매크로 함수로 작동할지 정해지니까 상관없는듯?
	inline void ShowInfo(){
		cout<<"y : "<<y<<" x : "<<x<<endl;
	}
}; // point도 하나의 자료형이므로 ;을 붙여주는 것 같다.
// 함수의 정의부분에는 ;을 붙이지 않는다.
int main(){
	point p1(1,2);
	point p2(4,5);
	point p3(-4,2);
	(p1-=p2).ShowInfo();
	(p1+=p3).ShowInfo();
	return 0;
}