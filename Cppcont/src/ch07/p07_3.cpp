#include <iostream>
using namespace std;
class Rectangle{
	int hei, wid;
	public:
	Rectangle(int hei, int wid):hei(hei),wid(wid){}
	void ShowAreaInfo(){
		cout<<"면적 : "<<hei*wid<<endl;
	}
};
class square : public Rectangle{
	public:
	square(int len):Rectangle(len, len){}
	// 부모 클래스의 멤버변수는 해당 클래스의 생성자로 생성함을 원칙으로 한다.
	// 주로 class constructor에 부모 클래스의 constructor를 같이 끼워넣는다.
	// showareaInfo 메소드는 rectangle 것을 사용
};
int main(){
	Rectangle rec(4,3);
	rec.ShowAreaInfo();
	square sq(7);
	sq.ShowAreaInfo();
	return 0;
}