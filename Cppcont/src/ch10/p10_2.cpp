#include <iostream>
using namespace std;
class point{
	int y, x;
	public:
	point(int y, int x):y(y),x(x){}
	point(const point& p):y(p.y),x(p.x){}
	// ?? default 복사 생성자는 const 키워드를 무조건 넣어줘야 하나보다
	// default 복사 생성자
	void ShowPosition(){
		cout<<"y : "<<y<<" x : "<<x<<endl;
	}
	point operator-(){
		// p의 값들을 반전
		point temp(-y, -x);
		return temp;
		// 동적할당을 하면 메모리 누수를 막을 방법이 없다.
		// 포인터로 따로 주소를 받아놓고 delete를 하지 않는 이상 ㅅㅂ
	}
	friend const point operator~(point& p); // ...
	friend point test(const point& p); // only for 탐색
};
const point operator~(point& p){ 
	// operator는 빨간색으로 highlight되지만 정의부를 class 밖으로 뺴낸 경우 주황색으로 나옴
	// 참조자로 받아도 호출 위치가 class 밖이면 private는 그냥은 접근불가
	// 반환형이 point이므로 return하는 순간 temp의 값을 긁어온 임시객체가 메모리에 올라가고 temp는 소멸
	point temp(p.x, p.y);
	return temp;
}
point test(const point& p){
	point temp(p.y+1, p.x+1);
	return temp;
}
int main(){
	point p1(1,3);
	point p2=-p1;
	// return temp;로 함수 종료 후 잠깐 메모리에 temp가 올라가며 복사 생성자로 p2에 값을 긁어오고 -p1을 소멸시킴 
	p1.ShowPosition();
	p2.ShowPosition();
	point p3=~p1; // ~p1은 임시객체로 이 행이 지나면 메모리에서 소멸됨
	(test(~p1)).ShowPosition(); // 어떻게 되지?
	// 임시객체가 const형이므로 그 객체가 인자로 들어가는 함수에서도 인자를 const형으로 받아야 한다.
	// 참조자로 변경 막기 위함
	p3.ShowPosition();
	return 0;
}
// 보통은 연산자 오버로딩 시 원래 객체에 영향이 가는 경우는 point& 반환형, 그게 아니면서 함수 내에서 새로운 객체를 만들어 반환하는 경우는 point 반환형으로 갈음한다
// const point형 연산자 오버로딩 메소드면 임시객체가 const형으로 선언되어 그 임시객체에 대한 함수는 무조건 const 함수로 호출되어야 한다
// 그 임시객체가 함수의 인자로 들어가는 경우는 어떻게 될까?