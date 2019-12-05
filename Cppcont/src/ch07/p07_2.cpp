#include <iostream>
#include <cstring>
using namespace std;
class MyFriendInfo{
	char *name;
	int age;
	public:
	MyFriendInfo(const char *_name, const int _age):age(_age){
		name=new char[strlen(_name)+1]; // null
		strcpy(name, _name);
	}
	~MyFriendInfo(){
		delete[] name;
	}
	void ShowMyFriendInfo(){
		cout<<"name : "<<name<<endl;
		cout<<"age : "<<age<<endl;
	}
};
class MyFrienddetailInfo:public MyFriendInfo{
	char *addr;
	char *phone;
	public:
	MyFrienddetailInfo(const char *_addr, const char *_phone, const char *_name, const int age):MyFriendInfo(_name, age){
		addr=new char[strlen(_addr)+1]; // null
		strcpy(addr, _addr);
		phone=new char[strlen(_phone)+1]; // null
		strcpy(phone, _phone);
	}
	~MyFrienddetailInfo(){
		delete[] addr;
		delete[] phone;
	}
	void ShowMyFrienddetailInfo(){
		ShowMyFriendInfo();
		cout<<"address : "<<addr<<endl;
		cout<<"phone n : "<<phone<<endl;
	}
};
int main(){
	// 입력
	// cin은 개행을 버퍼에 남겨두고 무시하고 진행
	// 모두 최대 19자
	// string을 빨리 배우고 싶다..
	// String s; getline(cin, s)
	char *addr=new char[20];
	char *phone=new char[20];
	char *name=new char[20];
	int age;
	cin>>addr>>phone>>name>>age;
	MyFrienddetailInfo test1(addr, phone, name, age);
	test1.ShowMyFrienddetailInfo();
	delete[] addr;
		delete[] phone;
		delete[] name;
	return 0;
}