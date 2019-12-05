#include <iostream>
#include <cstring>
using namespace std;
class printer{
	char str[30];
	public:
	void setstring(const char* pnt);
	void showstring(); 
};
void printer::setstring(const char* pnt){
	strcpy(str, pnt); // '/0' 자동삽입
}
void printer::showstring(){
	cout<<"saved string :: "<<str<<endl;
}
int main(){
	printer cnt;
	cnt.setstring("Hello world");
	// 리터럴을 char*로 참조(리터럴 데이터는 데이터 영역에 위치한다)
	// 리터럴이기 떄문에 수정 불가능 >> const로 받아야 함
	cnt.showstring();
	cnt.setstring("saved");
	cnt.showstring();
	return 0;
}