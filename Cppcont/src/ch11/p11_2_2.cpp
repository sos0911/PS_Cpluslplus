//p.468
#include <iostream>
using namespace std;
using Int_ptr=int*;
class BoundCheck2D{
	// 더블 포인터 사용
	Int_ptr* ptr;
	int one, two;
	BoundCheck2D(const BoundCheck2D& bc){}
	BoundCheck2D& operator=(const BoundCheck2D& bc){} // 복사, 대입 방지
	public:
	BoundCheck2D(int hei, int wid):one(hei),two(wid){
		ptr=new Int_ptr[hei];
		for(int i=0;i<hei;i++)
			ptr[i]=new int[wid];
	}
	Int_ptr operator[](int n) const{
		if(n<0 || n>=one){
			cout<<"Array boundexception"<<endl;
			exit(1);	
		}
		return ptr[n];
	}
	Int_ptr operator[](int n){
		if(n<0 || n>=one){
			cout<<"Array boundexception"<<endl;
			exit(1);	
		}
		return ptr[n];
	}
	~BoundCheck2D(){
		for(int i=0;i<one;i++)
			delete[] ptr[i];
		// 각 구성원이 1차원 int배열의 포인터이므로
		// delete[]를 하는 게 맞을 거야..
	}
	// arr2d[n][m]은 int<< 오버로딩 안해도됨
	// int*에 대한 오버로딩은 이미 되어있음(반환형 : int&)
};
int main(){
	BoundCheck2D test(3,4);
	for(int i=0;i<3;i++)
		for(int j=0;j<4;j++)
			test[i][j]=i+j;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++)
			cout<<test[i][j]<<" ";
		// cout에 대한 int 오버로딩 << 은 이미 되어있다.
		cout<<endl;
	}
	return 0;
}