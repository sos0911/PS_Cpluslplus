#include <iostream>
using namespace std;
class car{
	int gasoline;
	public:
	car(int gaso):gasoline(gaso){}
	int getgas(){
		return gasoline;
	}
};
class hybrid:public car{
	int electric;
	public:
	hybrid(int elec, int gaso):electric(elec), car(gaso){}
	int getelectric(){
		return electric;
	}
};
class hywatercar:public hybrid{
	int water;
	public:
	hywatercar(int water, int elec, int gaso):hybrid(elec, gaso), water(water){}
	int showcurrent(){
		cout<<"현재 가솔린 : "<<getgas()<<endl;
		cout<<"현재 전기량 : "<<getelectric()<<endl;
		cout<<"현재 물 : "<<water<<endl;
	}
};
int main(){
	hywatercar h1(3, 30, 300); // 정적 할당
	hywatercar *h2=new hywatercar(300,30,3); // 동적 할당
	h1.showcurrent();
	cout<<endl; // 개행
	h2->showcurrent();
	delete h2; // 다행히 h2 내에는 동적할당한 또다른 것이 없다.
	return 0;
}