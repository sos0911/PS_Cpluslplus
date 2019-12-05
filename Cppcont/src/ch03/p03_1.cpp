#include <iostream>
using namespace std;
struct point{
	// 만약, 구조체 내에서만 쓰이는 매크로 상수를 정의할땐
	// enum으로 정의하는 것이 편하다.
	// enum을 구조체 내에 박을지 별도의 이름공간 내에 선언할지는 개발자 마음이다. 
	int x, y;
	// 모두 public으로 하겠다.
	void MovePos(int x, int y);
	void AddPoint(const point &pos);
	void ShowPos();
}; // typedef를 안 쓰더라도 C++에서는 point형으로 가능했었다ㅠㅠ
int main(){
	point pos1={12,4}; // 구조체 선언 및 초기화 동시 방법
	point pos2={20,30};
	pos1.MovePos(-7,10);
	pos1.ShowPos();
	pos1.AddPoint(pos2);
	pos1.ShowPos();
	return 0;
}
// inline :: 컴파일러의 판단 아래 매크로 함수 OR 일반 함수 동작
inline void point::MovePos(int x, int y){
	// (x,y)만큼 이동
	this->x+=x; this->y+=y;
}
inline void point::AddPoint(const point &pos){
	// pos만큼 이동
	x+=pos.x; y+=pos.y;
}
inline void point::ShowPos(){
	cout<<"["<<x<<" ,"<<y<<"]"<<endl;
}