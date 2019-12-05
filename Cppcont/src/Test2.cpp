#include <iostream>
#include <cstring>
using namespace std;
class point{
	int y, x;
	char* name;
	public:
point(int y, int x, const char* _name):y(y),x(x){
	name=new char[strlen(_name)+1]; // null
	strcpy(name, _name);
}
	~point(){
		cout<<"destrutor called!!"<<endl;
		delete[] name;
	}
	void ShowStatus(){
		cout<<"name : "<<name<<endl;
		cout<<"[ "<<y<<" , "<<x<<" ]"<<endl;
		cout<<endl;
	}
};
using Pnt_Ptr=point*;
int main(){
	Pnt_Ptr* arr=new Pnt_Ptr[3];
	for(int i=0;i<3;i++)
		arr[i]=new point(i, i, "test");
	for(int i=0;i<3;i++)
		arr[i]->ShowStatus();
	cout<<"소멸자 호출 시도"<<endl;
	//delete[] arr;
	// delete[]는 포인터에 대해 소멸자를 호출
	// delete[]는 각 구성원에 대해 소멸자를 호출하므로 구성원이 포인터면 안되고 객체 or raw type이여야 한다.
	// 즉, delete[]라고 해서 for-delete가 아니라는 말이다.
	for(int i=0;i<3;i++)
		delete arr[i];
	// delete-for문은 각 구성원에 대해 delete 처리를 한다.
	return 0;
}