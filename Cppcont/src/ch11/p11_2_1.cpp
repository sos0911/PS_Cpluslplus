//11-2 문제
#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {  }
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend ostream& operator<<(ostream& os, const Point* pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}
ostream& operator<<(ostream& os, const Point* pos){
	os<<'['<<pos->xpos<<", "<<pos->ypos<<']'<<endl;
	return os;
}

typedef Point * POINT_PTR;

class BoundCheckPointPtrArray 
{
private:
	POINT_PTR * arr; // 왜 굳이 더블 포인터로?
	// 왜냐하면 이것이 point*형 배열을 가리키는 포인터이기 때문이다.
	// 배열을 가리키려면 더블 포인터 or 배열 포인터
	// 더블 포인터를 사용하려면 포인터에 배열을 선언해 주고 사용해야 함
	int arrlen;

	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { } // 복사 생성자, 대입 연산자 사용 금지
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }

public:
	BoundCheckPointPtrArray(int len) :arrlen(len)
	{
		arr=new POINT_PTR[len];
	}
	POINT_PTR& operator[] (int idx)
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		
		return arr[idx];
	}
	POINT_PTR operator[] (int idx) const // const를 활용한 [] 오버로딩
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		
		return arr[idx];
	}
	int GetArrLen() const 
	{
		return arrlen;
	}
	~BoundCheckPointPtrArray()
	{
		delete []arr;
	}
};
int main(void)
{
	BoundCheckPointPtrArray arr(3); // bcpp 안에 point*형 배열을 가지고 있음
	arr[0]=new Point(3, 4); // bcpp에 대한 [] 오버로딩
	arr[1]=new Point(5, 6);
	arr[2]=new Point(7, 8);

	for(int i=0; i<arr.GetArrLen(); i++)
		cout<<arr[i]<<endl;
	// arr[i]이 [] 오버로딩에 의해 point*형으로 바뀌고
	// point*에 대한 [] 오버로딩에 의해 point 내용물 출력 

	delete arr[0];
	delete arr[1];
	delete arr[2];
	return 0;
}
