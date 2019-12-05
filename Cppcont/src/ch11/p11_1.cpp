#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;    	// ������ �Ѿ��� ��
public:
	Gun(const int bnum) : bullet(bnum)
	{ }
	explicit Gun(Gun& g):bullet(g.bullet){
		cout<<"gun copy constructor called"<<endl;
	}
	void Shut()
	{
		cout<<"BBANG!"<<endl;
		bullet--;
	}
	Gun& operator=(Gun& g){
		cout<<"gun operator= called"<<endl;
		bullet=g.bullet;
	}
	void ShowInfo(){
		cout<<"bullet : "<<bullet<<endl;
	}
};

class Police // 상속x, 그러므로 virtual 키워드 사용 안해도 됨
{
private:
	int handcuffs;    // ������ ������ ��
	Gun * pistol;     // �����ϰ� �ִ� ����
public:
	Police(const int bnum, const int bcuff)
		: handcuffs(bcuff)
	{
		if(bnum>0)
			pistol=new Gun(bnum);
		else
			pistol=nullptr;
	}
	explicit Police(Police& p):handcuffs(p.handcuffs){ // 같은 class 안이므로 참조자로 private 접근가능
		cout<<"police copy constructor called"<<endl;
		if(p.pistol==nullptr)
			pistol=nullptr;
		else
			pistol=new Gun(*(p.pistol));
	}
	// 대입 연산자는 두 객체가 이미 생성되었다는 상황을 기억해야 함
	Police& operator=(const Police& p){
		cout<<"police operator= called"<<endl;
		handcuffs=p.handcuffs;
		if(!p.pistol) // nullptr인가를 이렇게 물어볼 수 있다.
			// 왜냐? nullptr은 0으로 치환되기 떄문. if(!0) = true => p==nullptr
			// c++11 => nullptrptr
			pistol=nullptr;
		else
			*pistol=*(p.pistol); // 객체 대입
	}
	void PutHandcuff() 
	{
		cout<<"SNAP!"<<endl;
		handcuffs--;
	}
	void Shut()
	{
		if(pistol==nullptr)
			cout<<"Hut BBANG!"<<endl;
		else
			pistol->Shut();
	}
	void ShowInfo(){
		pistol->ShowInfo();
			cout<<"cuff : "<<handcuffs<<endl;
	}
	~Police()
	{
		if(pistol!=nullptr)
			delete pistol;
	}
};

int main(void)
{
	Police p1(3, 5);
	Police p2(0, 2);
	Police p3(p1); // 복사 생성자
	Police p4(1,1);
	p4=p1;
	Police p5(5,5);
	p3.ShowInfo();
	cout<<endl;
	p4.ShowInfo();
	p5=p2;
	return 0;
}