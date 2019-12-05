#include <iostream>
using namespace std;
typedef struct point{
	int x, y;
}point;
// 끝에 별칭을 붙여줌으로써 소스 코드 내에서 사용할 별명을 정할 수 있다.(struct point->point)
point& adder(const point& p1, const point& p2);
int main(){
	point* _p1=new point;
	_p1->x=1; _p1->y=1;
	point* _p2=new point;
	_p2->x=2; _p2->y=2;
	point* res=&adder(*_p1, *_p2); 
	// pointer형으로 선언하였고 받아오는 리턴형이 참조자형이라 불필요한 복사x
	// 참조자형으로 가능한건 포인터로도 가능하다는 걸 잊지 말자.
	cout<<res->x<<" "<<res->y<<endl;
	delete _p1;
	delete _p2;
	delete res;
	return 0;
}
point& adder(const point& p1, const point& p2){
	// p1, p2 더한 결과를 반환
	// 참조자는 자신의 private 영역에 접근 가능하다.
	// 왜냐? 접근제어 연산자는 instance 기준이 아니라 class 기준이기 떄문이다.
	// 같은 class는 다른 instance여도 private에 접근가능
	// 근데 애초에 이건 struct입니다. 해당 사항이 없음
	point* temp=new point;
	temp->x=p1.x+p2.x;
	temp->y=p1.y+p2.y;
	return *temp;
}