#include <iostream>
using namespace std;
class calculator{
	int op[4]; // 0으로 초기화 / +/-*
	public:
	void init();
	double add(double a, double b);
	double div(double a, double b);
	double min(double a, double b);
	double mul(double a, double b);
	void showopcnt();
};
void calculator::init(){
	for(int i=0;i<4;i++)
		op[i]=0;
}
inline double calculator::add(double a, double b){
	op[0]++;
	return a+b;
}
inline double calculator::div(double a, double b){
	op[1]++;
	return a/b;
}
inline double calculator::min(double a, double b){
	op[2]++;
	return a-b;
}
inline double calculator::mul(double a, double b){
	op[3]++;
	return a*b;
}
void calculator::showopcnt(){
	cout<<"덧셈 : "<<op[0]<<" 뺄셈 : "<<op[1]<<" 곱셈 : "<<op[2]<<" 나눗셈 : "<<op[3]<<endl;
}
int main(){
	calculator cal;
	cal.init();
	cout<<"3.2 + 2.4 = "<<cal.add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.7 = "<<cal.div(3.5, 1.7)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.min(2.2, 1.5)<<endl;
	cout<<"4.9 * 1.2 = "<<cal.mul(4.9, 1.2)<<endl;
	cal.showopcnt();
	return 0;
}