#include <iostream>
#include <cstring>
// cstring의 strlen 함수는 null을 뺸 실제 문자열 길이를 반환하므로
// strlen을 사용해서 복사 생성자를 만들 시 new char[strlen(str)+1] 이렇게 선언해야 함
using namespace std;
class String{
	int len; // 실제 길이(maxlen이 아니라..)
	char* inf;
	public:
	String(); // default
	String(const char* _inf);
	~String();
	String(const String& str);
	String& operator=(const String& str);
	friend String operator+(const String& str1, const String& str2);
	String& operator+=(const String& str);
	friend bool operator==(const String& str1, const String& str2);
	friend ostream& operator<<(ostream& os, const String& str);
	friend istream& operator>>(istream& is, String& str);
};
String::String():len(0){
	inf=nullptr;
}
String::String(const char* _inf){
	len=strlen(_inf);
	inf=new char[len+1];
	strcpy(inf, _inf);
}
String::~String(){
	if(inf) // null이 아니라면
	delete[] inf;
	// 포인터 배열이 아니므로 delete[]
}
String::String(const String& str){
	len=str.len;
	inf=new char[len+1];
	strcpy(inf, str.inf); // 같은 class이므로 참조자로 private 접근 가능
}
String& String::operator=(const String& str){ // 대입 연산자
	len=str.len;
	if(inf)
	delete[] inf;
	inf=new char[str.len+1];
	strcpy(inf, str.inf);
	return *this;
}
String& String::operator+=(const String& str){
	// *this=*this+str;
	len+=str.len;
	char* temp=new char[len+1];
	strcpy(temp, inf);
	if(inf)
	delete[] inf;
	strcat(temp, str.inf);
	inf=temp;
	return *this;
}
	String operator+(const String& str1, const String& str2){
		// 단순히 더한다.
	char* temp=new char[str1.len+str2.len+1];
	strcpy(temp, str1.inf);
	strcat(temp, str2.inf);
	String st(temp);
		return st;
	}
	bool operator==(const String& str1, const String& str2){
		return !strcmp(str1.inf, str2.inf);
		// 반환형 int ㅅㅂ..
		// 같을 때 0, 1이면 str1>str2, -1이면 str1<sr2
		// !0 = true
	}
	ostream& operator<<(ostream& os, const String& str){
		os<<str.inf;
		return os;
	}
	istream& operator>>(istream& is, String& str){
		// str에 input을 받는다는 것 자체가 str을 갓 생성하고 한다는 의미이다.
		// 중단됨
		char temp[100]; // 최대 100자
		is>>temp;
		str=String(temp);
		return is;
		// 모두 정적 생성 & 대입
	}
int main(){
	String str1="I like ";
	String str2="String class";
	String str3=str1+str2;

	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<<str3<<endl;

	str1+=str2;
	if(str1==str2) 	
		cout<<"동일 문자열!"<<endl;
	else
		cout<<"동일하지 않은 문자열!"<<endl;

	String str4;
	cout<<"문자열 입력: ";
	cin>>str4;
	cout<<"입력한 문자열: "<<str4<<endl;
	return 0;
}