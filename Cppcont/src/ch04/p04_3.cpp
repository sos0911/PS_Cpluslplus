#include <iostream>
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
	~NameCard();
};
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
	NameCard mans("hong", "BCAENG", "010-2222-3333", COMP_POS::SENIOR);
	NameCard mana("kim", "CBAENG", "010-4444-2222", COMP_POS::ASSIST);
	manc.ShowNameCardInfo();
	mans.ShowNameCardInfo();
	mana.ShowNameCardInfo();
	return 0;
}