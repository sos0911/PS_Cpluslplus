#include <iostream>
using namespace std;
// 한 파일 내에 여러 클래스들을 때려박게 되면
// include 문제 때문에 순서를 잘 지켜서 넣어야 한다. 그게 불편할 수 있다.
// 하지만 알고리즘 대회에서는 한 파일 내에 모든 class를 떄려박아야 하므로 불편하다.
// java는 그런 게 없던 것 같은데..
class point{
	int y, x;
	public:
	point(int y=0, int x=0):y(y),x(x){}
	void ShowPosition(); // 함수 선언부에는 ;을 붙여준다.
	friend point operator-(const point& p1, const point& p2);
};
void point::ShowPosition(){
	cout<<"y : "<<y<<" x : "<<x<<endl;
}
point operator-(const point& p1, const point& p2){
	point temp(p1.y-p2.y, p1.x-p2.x);
	return temp;
}
int main(){
	point p1(3,4);
	point p2(4,5);
	point p3=p1-p2; // 복사 생성자가 실행된다.(얕은 복사-DEFAULT 복사 생성자)(생성하면서 복사되는..)
	// 로컬변수의 주소를 받아오는데 문제는 저 함수가 끝나면서 temp도 소실된다.
	// 왜냐? 함수 안에서 정적 할당으로 생긴 변수이기 때문에.
	// 그러므로 return문으로 인해 메모리에 temp가 아직 임시변수로 올라가 있을 때 값들을 받아오던지
	// 동적할당으로 생성하고 없애주면 된다.
	p3.ShowPosition();
	return 0;
}