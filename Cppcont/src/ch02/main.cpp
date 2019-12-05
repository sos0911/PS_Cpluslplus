#include <iostream>
using namespace std;
class point{
int x, y; // 이 두 변수는 동적 할당으로 생기는 것이 아니다.
	// new, delete를 이용하지 않기 때문에 힙 영역이 아닌 스택 영역에 생긴다.
	public:
point(int x, int y);
void padd(point* p);
int getx();
int gety();
void printinfo();
};
int main(){
	point* pt1=new point(1, 1);
	// 동적할당
	pt1->padd(new point(2,2)); // java형식인데 되나?
	// 동적할당 시는 new로 선언하되 그 첨자는 포인터형이 되어야 한다.
	// reason :: delete시 그 공간의 주소를 delete해야 하기 때문이다.
	// 보통처럼 선언 시는 포인터형이 되던지 변수형이 되던지 상관없다.
	pt1->printinfo();
	return 0;
}
void point::printinfo(){
	cout<<"y : "<<y<<" x : "<<x<<endl;
}
point::point(int x, int y):x(x), y(y){};
// class initializer
void point::padd(point* p){
	x+=p->getx(); y+=p->gety();
}
int point::getx(){
	return x;
}
int point::gety(){
	return y;
}