#include <iostream>
#include <cstring>
using namespace std;
class Book{
	char *title, *isbn;
	int price;
	public:
	// 실험 :: 포인터형 문자열도 이름이 같게 써도 컴파일이 될까?
	// this->키워드를 붙이지 않는다면 불가능하다.
	Book(const char *title, const char *isbn, const int price):price(price){
		this->title=new char[strlen(title)+1];
		strcpy(this->title,title);
		this->isbn=new char[strlen(isbn)+1];
		strcpy(this->isbn,isbn);
	}
	~Book(){
		delete[] title;
		delete[] isbn;
	}
	void ShowBookInfo(){
		cout<<"title : "<<title<<endl;
		cout<<"ISBN : "<<isbn<<endl;
		cout<<"price : "<<price<<endl;
	}
	Book(const Book& b);
	Book& operator=(const Book& b);
};
Book& Book::operator=(const Book& b){ // 생성자 계열이 아니면 member initializer를 쓸 수 없다.
	// 대입 연산자
	price=b.price;
	delete[] title;
	delete[] isbn;
	title=new char[strlen(b.title)];
	isbn=new char[strlen(b.isbn)];
	strcpy(title, b.title);
	strcpy(isbn, b.isbn);
}
Book::Book(const Book& b):price(b.price){
	title=new char[strlen(b.title)];
	strcpy(title, b.title);
	isbn=new char[strlen(b.isbn)];
	strcpy(isbn, b.isbn);
	cout<<"title setted : "<<title<<endl;
}
// EBook 개체 소멸시 EBook 소멸자 call 후에 Book 소멸자 call됨
// 각 개체의 멤버변수/자료형들은 해당 클래스 소멸자에서 지우는 것임
class EBook:public Book{
	char *DRMkey;
	public:
	EBook(const EBook& eb);
	EBook(const char *_title, const char *_isbn, const int price, const char *_DRMkey):Book(_title, _isbn, price){
		DRMkey=new char[strlen(_DRMkey)+1];
		strcpy(DRMkey, _DRMkey);
	}
	~EBook(){
		delete[] DRMkey;
	}
	void ShowEBookInfo(){ // overriding이 아니다.
		ShowBookInfo();
		cout<<"authen key : "<<DRMkey<<endl;
	}
	EBook& operator=(const EBook& eb);
};
EBook& EBook::operator=(const EBook& eb){
	// 대입 연산자
	delete[] DRMkey;
	DRMkey=new char[strlen(eb.DRMkey)];
	strcpy(DRMkey, eb.DRMkey);
	Book::operator=(eb);
}
EBook::EBook(const EBook& eb):Book(eb){ // 복사 생성자
	// drmkey length에는 /0도 포함되는 모양.
	// 실험해보자.
	DRMkey=new char[strlen(eb.DRMkey)];
	strcpy(DRMkey, eb.DRMkey);// dest, st
}
int main(){
	// string이 아니고 char*을 쓴다면
	// 고정된 최대 길이를 갖게 되어 불편하게 된다.
	// 입력에 따라 최대 길이가 늘어나는 자료형이 필요하다 >> string(stl)
	Book b1("good c++", "55", 20000);
	b1.ShowBookInfo();
	cout<<endl;
	Book b2("test", "0", 0); // default initializer
	b2=b1;
	b2.ShowBookInfo();
	cout<<endl;
	EBook e1("good c++ ebook", "54", 40000, "fdsc");
	e1.ShowEBookInfo();
	cout<<endl;
	EBook e2=e1;
	// 복사 생성자
	e2.ShowEBookInfo();
	return 0;
}