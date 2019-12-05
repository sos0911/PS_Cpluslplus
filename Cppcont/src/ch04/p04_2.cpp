#include <iostream>
using namespace std;
// new로 할당 시 반환값은 공간 주소 시작주소이다.
// 통용 원칙은 한 클래스 내에 다른 클래스를 갖고 있을 떄,
// 마치 stack마냥 더 큰 클래스 생성자에서 거기에 속하는 클래스 생성자를 불러내는 방식이 된다.
// 고로, 큰 클래스 생성자가 불리기 전 작은 클래스 생성자가 불리는 일이 없다고 봐도 무방하다.
class point{
	int x, y;
	public:
	point(int _x, int _y);
	void showinfo();
};
point::point(int _x, int _y):x(_x),y(_y){};
void point::showinfo(){
	cout<<"["<<x<<" ,"<<y<<"]"<<endl;
}
class circle{
	point* cen;
	int rad; // 반지름
	public:
	circle(int _y, int _x, int _rad);
	void showinfo();
	~circle();
};
circle::~circle(){
	delete cen;
	cout<<"circle 객체 메모리 해제"<<endl;
}
circle::circle(int _y, int _x, int _rad){
	cen=new point(_y, _x);
	rad=_rad;
}
void circle::showinfo(){
	cout<<"rad : "<<rad<<endl;
	cen->showinfo();
}
class ring{
	circle* in;
	circle* out;
	// ?? circle* in, out이 안된다.
	// ring class 생성자 호출 전 circle 객체를 먼저 생성하여 넘겨주는 것이 아니라면
	// circle 객체를 포인터형으로 갖고 있지 말고 원형으로 가지고 있어도 괜찮다.
	// 어차피 위에서 말한 경우가 아니라면 ring class가 생겨야 circle class도 initiate되기 떄문
	public:
	~ring();
	ring(int iy, int ix, int lrad, int oy, int ox, int orad);
	void showinfo();
};
ring::~ring(){
	delete in;
	delete out;
	cout<<"ring 객체 메모리 해제"<<endl;
}
ring::ring(int iy, int ix, int lrad, int oy, int ox, int orad){
	in=new circle(iy, ix, lrad);
	out=new circle(oy, ox, orad);
}
void ring::showinfo(){
	cout<<"inner : "<<endl;
	in->showinfo();
	cout<<"outer : "<<endl;
	out->showinfo();
}
int main(){
	ring ri(1,1,4,2,2,9);
	ri.showinfo();
	return 0;
}