// 단계별 프로젝트 - 07.5
// handler class 생성
#include <iostream>
#include <cstring>
#define MAXLEN 30
using namespace std;
// handler 안 enum은 밖으로 빼도 상관없다.
// 하지만 handler 안에서만 쓰이는 enum이라 명시하기 위해 안으로 집어넣음
// enum을 앞으로 모두 뺴는 게 관리하기 용이할 수는 있겠다

class acc{
	int accid, left;
	char* name; // for 동적할당
	public:
	acc(int accid, const char* name, int left);
	acc(acc& _acc);
	~acc();
	inline int getid() const;
	inline int getleft() const;
	virtual inline void modleft(int add);
	inline char* getname() const;
	virtual void ShowInfo();
};
	void acc::ShowInfo(){
		cout<<"계좌 ID : "<<accid<<endl;
		cout<<"이름 : "<<name<<endl;
		cout<<"잔액 : "<<left<<endl;
	}
	acc::acc(acc& _acc):accid(_acc.accid),left(_acc.left){ // initializer
		// initailizer 내에서는 인자변수와 멤버변수가 이름이 같아도 단순대입이 가능하다.
		// 하지만 deep copy의 경우(대입만으로 불가능한 경우)는 같으면 안됨
		this->name=new char[strlen(_acc.name)+1];
		strcpy(this->name, _acc.name);
	}
	acc::acc(int accid, const char* _name, int left):accid(accid), left(left){
		this->name=new char[strlen(_name)+1];
		cout<<"할당된 공간 길이 : "<<strlen(_name)+1<<endl;
		strcpy(this->name, _name);
	}
	acc::~acc(){
		delete[] name;
	}
// inline 함수의 경우 선언부에 lnline 선언하고
// 정의 부분은 생략해도 됨(const는 안됨)
void acc::modleft(int add){
	left+=add;
}
int acc::getid() const{
		return accid;
	}
int acc::getleft() const{
		return left;
	}
char* acc::getname() const{
		return name;
	}
class Normalacc:public acc{
	double rate; // 이자 비율
	public:
	Normalacc(const int id, const char *name, const int left, const int rate):rate(rate), acc(id, name, left){}
	inline void modleft(int add); // overriding(virtual)
	virtual void ShowInfo();
	// 이자 비율의 여분의 돈까지 늘어나야 함
};
void Normalacc::modleft(int add){
	add>=0? acc::modleft(add+(int)(rate/100*add)) : acc::modleft(add);
}
void Normalacc::ShowInfo(){
	acc::ShowInfo();
	cout<<"이자율 : "<<rate<<"%"<<endl;
}
class HighCreditacc:public acc{
	enum{A=1,B,C};
	double rate;
	char grade;
	public:
	HighCreditacc(const int id, const char *name, const int left, const int rate, const int kind);
	inline void modleft(int add); // overriding(virtual)
	virtual void ShowInfo();
};
void HighCreditacc::ShowInfo(){
	acc::ShowInfo();
	cout<<"이자율 : "<<rate<<"%"<<endl;
	cout<<"신용등급 : "<<grade<<endl;
}
HighCreditacc::HighCreditacc(const int id, const char *name, const int left, const int rate, const int kind):acc(id, name, left){
	switch(kind){
		case A:
			this->rate=rate+7;
			grade='A';
			break;
		case B:
			this->rate=rate+4;
			grade='B';
			break;
		case C:
			this->rate=rate+2;
			grade='C';
			break;
	}
}
void HighCreditacc::modleft(int add){
	add>=0? acc::modleft(add+(int)(rate/100*add)) : acc::modleft(add);
}
class AccountHandler{
	acc* accarray[100]; // 최대 99명 저장
	int ind; // 1-99, 다음 계좌 번호=ind
	public:
	enum{make=1, in, out, print, esc}; // 메뉴 enum
	void showmenu() const;
	void makeaccout();
	bool inmoney();
	bool outmoney();
	void printinf() const;
	AccountHandler():ind(1){}
	~AccountHandler();
};
AccountHandler::~AccountHandler(){
	// accarray(acc*형) 배열 자체는 동적 할당이 아니지만
	// 각 셀 안의 내용물은 동적 할당되었다.
	// 그러므로 소멸자가 필요함
	for(int i=1;i<=ind-1;i++)
		delete accarray[i];
}
void AccountHandler::showmenu() const{
		cout<<"---menu---"<<endl;
		cout<<"1. 계좌개설"<<endl;
		cout<<"2. 입금"<<endl;
		cout<<"3. 출금"<<endl;
		cout<<"4. 전체 계좌정보 출력"<<endl;
		cout<<"5. 프로그램 종료"<<endl;
		cout<<"선택 : ";
	}
void AccountHandler::makeaccout(){
	cout<<"[계좌 종류 선택]"<<endl;
	cout<<"1. 보통예금계좌 2. 신용관리계좌"<<endl;
	int choice;
	cin>>choice;
	if(choice==1){
		cout<<"[보통예금계좌 생성]"<<endl;
		int id, left, rate;
		char name[MAXLEN];
		cout<<"계좌 ID : ";
	cin>>id;
	cout<<"이름(최대 30자) : ";
	cin>>name;
	cout<<"입금액 : ";
	cin>>left;
	cout<<"이자율 : ";
	cin>>rate;
		accarray[ind++]=new Normalacc(id, name, left, rate);
	}
	else{
		cout<<"[신용관리계좌 생성]"<<endl;
	int id, left, rate, kind;
		char name[MAXLEN];
		cout<<"계좌 ID : ";
	cin>>id;
	cout<<"이름(최대 30자) : ";
	cin>>name;
	cout<<"입금액 : ";
	cin>>left;
	cout<<"이자율 : ";
	cin>>rate;
	cout<<"신용등급 : (123-ABC) : ";
	cin>>kind;
		accarray[ind++]=new HighCreditacc(id, name, left, rate, kind);
	}
}
bool AccountHandler::inmoney(){
	int id, add;
	cout<<"계좌 ID : ";
	cin>>id;
	cout<<"입금액 : ";
	cin>>add;
	bool check=false;
	for(int i=1;i<=ind-1;i++)
		if(accarray[i]->getid()==id){
			if(add>=0){
			accarray[i]->modleft(add);
			check=true;
			}
			break;	
		}
	if(!check)
		return false;	
	return true;
}
bool AccountHandler::outmoney(){
	int id, sub;
	cout<<"계좌 ID : ";
	cin>>id;
	cout<<"출금액 : ";
	cin>>sub;
	bool check=false;
	for(int i=1;i<=ind-1;i++)
		if(accarray[i]->getid()==id){
			if(sub>=0 && accarray[i]->getleft()>=sub){
			accarray[i]->modleft(-sub);
			check=true;
			}
			break; // 출금 가능하던 가능하지 않던 break	
		}
	if(!check)
		return false;	
	return true;
}
void AccountHandler::printinf() const{
	for(int i=1;i<=ind-1;i++){
		cout<<endl;
		accarray[i]->ShowInfo();
	}
}
int main(){
	int choice;
	AccountHandler handler; // void 생성자 호출
	while(true){
		handler.showmenu();
		cin>>choice;
		// switch문에서 블록 처리를 case에 안하면
		// 거기서 지역 변수를 생성하면 switch 문 전체에서 사용가능하나
		// 초기화하는 지역 구문이 있다면 오류
		// 블록 처리를 거기에 하든가 해야함
		switch(choice){
			case AccountHandler::make:
				handler.makeaccout();
				cout<<"success for making accout"<<endl;
				cout<<endl;
				break;
			case AccountHandler::in:
				if(handler.inmoney())
				cout<<"in complete"<<endl;
				   else
				   cout<<"잘못된 id이거나 잘못된 input. inmoney failed"<<endl;
				cout<<endl;
				break;
			case AccountHandler::out:
				if(handler.outmoney())
				cout<<"out complete"<<endl;
				   else
				   cout<<"잘못된 id이거나 잘못된 input이거나 잔여량 부족. withdraw failed"<<endl;
				cout<<endl;
				break;
			case AccountHandler::print:
				handler.printinf();
				cout<<endl;
				break;
			case AccountHandler::esc:
				cout<<"exit from program"<<endl;
				return 0;
			default:
				cout<<"다시 입력하세요."<<endl;
		}
	}
	return 0;
}