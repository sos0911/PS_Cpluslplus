#include <iostream>
// 복사 생성자 :: 객체를 생성하는데 인자를 다른 class를 받는 생성자
// 즉, 생성하는데 복사하면서 생성하는 생성자.
#include <cstring>
using namespace std;
namespace COMP_POS{
enum {CLERK, SENIOR, ASSIST, MANAGER};
}
class NameCard{
	char* name;
	char* comp;
	char* phone;
	int level; // 직급
	public:
	NameCard(const char* name, const char* comp, const char* phone, int level);
	void ShowNameCardInfo();
	NameCard(const NameCard& n1);
	~NameCard();
};
NameCard::NameCard(const NameCard& n1){
	name=new char[strlen(n1.name)+1];
	strcpy(name, n1.name);
	comp=new char[strlen(n1.comp)+1];
	strcpy(comp, n1.comp);
	phone=new char[strlen(n1.phone)+1];
	strcpy(phone, n1.phone);
	level=n1.level;
}
NameCard::NameCard(const char* name, const char* comp, const char* phone, int level){
	this->name=new char[strlen(name)+1]; // null
	strcpy(this->name, name);
	this->comp=new char[strlen(comp)+1]; // null
	strcpy(this->comp, comp);
	this->phone=new char[strlen(phone)+1]; // null
	strcpy(this->phone, phone);
	this->level=level;
}
NameCard::~NameCard(){
	delete[] name;
	delete[] comp;
	delete[] phone;
	cout<<"메모리 해제 완료(동적할당)"<<endl;
}
void NameCard::ShowNameCardInfo(){
	cout<<"이름 : "<<name<<endl;
	cout<<"회사 : "<<comp<<endl;
	cout<<"전화번호 : "<<phone<<endl;
	switch(level){
		case COMP_POS::CLERK:
			cout<<"직급 : "<<"사원"<<endl;
			break;
		case COMP_POS::SENIOR:
			cout<<"직급 : "<<"주임"<<endl;
			break;
		case COMP_POS::ASSIST:
			cout<<"직급 : "<<"대리"<<endl;
			break;
		case COMP_POS::MANAGER:
			cout<<"직급 : "<<"매니저"<<endl;
			break;
	}
}
int main(){
	NameCard manc("Lee", "ABCENG", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1=manc; // 복사 생성자 호출
	// 암묵적으로 copy1(manc)로 바뀌어서 인자가 name&인 생성자를 호출하게 된다.
	// default가 아니게 해야함
	NameCard mans("hong", "BCAENG", "010-2222-3333", COMP_POS::SENIOR);
	NameCard copy2=mans;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}