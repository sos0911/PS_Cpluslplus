#include <iostream>
using namespace std;
class point{
	int y, x;
	public:
	point(int y, int x):y(y),x(x){}
	friend bool operator==(const point& p1, const point& p2);
};
bool operator==(const point& p1, const point& p2){
	return (p1.y==p2.y && p1.x==p2.x);
}
bool operator!=(const point& p1, const point& p2){
	return !(p1==p2);
	// ==가 true가 아니면 true 반환 => 같지 않으면 모두 !=므로
}
int main(){
	point p1(3,3);
	point p2(3,4);
	point p3(3,3);
	cout<<"p1과 p2는"<<((p1==p2)==1? "같음":"다름")<<endl;
	cout<<"p1과 p2는"<<((p1!=p2)==1? "다름":"같음")<<endl;
	cout<<"p1과 p3는"<<((p1==p3)==1? "같음":"다름")<<endl;
	return 0;
}