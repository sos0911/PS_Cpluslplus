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
};
// EBook 개체 소멸시 EBook 소멸자 call 후에 Book 소멸자 call됨
// 각 개체의 멤버변수/자료형들은 해당 클래스 소멸자에서 지우는 것임
class EBook:public Book{
	char *DRMkey;
	public:
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
};
int main(){
	Book b1("good c++", "55", 20000);
	b1.ShowBookInfo();
	cout<<endl;
	EBook e1("good c++ ebook", "54", 40000, "fdsc");
	e1.ShowEBookInfo();
	return 0;
}