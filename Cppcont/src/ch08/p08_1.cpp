#include <iostream>
#include <cstring>
using namespace std;
// 한 cpp 안에 여러 클래스를 박아넣는 형태라
// 순서를 잘 지켜서 넣어야 한다.
namespace RISK_LEVEL{
	enum{RISK_A, RISK_B, RISK_C};
}
class Employee
{
private:
	char name[100];
public:
	Employee(const char * name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout<<"name: "<<name<<endl;
	}
	virtual int GetPay()const=0;
	virtual void ShowSalaryInfo()const=0;
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char * name, int money)
		: Employee(name), salary(money)
	{  }
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char * name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{  }
	void AddWorkTime(int time)
	{
		workTime+=time;
	}
	int GetPay() const
	{
		return workTime*payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;    // 월 판매실적
	double bonusRatio;    // 상여금 비율 
public:
	SalesWorker(const char * name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{  }
	virtual void AddSalesResult(int value)
	{
		salesResult+=value;
	}
	int GetPay() const
	{ // 쌓인 인센티브와 기본급여를 합한 금액을 return
		return PermanentWorker::GetPay()  
					+ (int)(salesResult*bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl;
	}
};
class ForeignSalesWorker:public SalesWorker{
	int risk; // 위험 레벨
	int riskm; // 위험수당
	public:
	ForeignSalesWorker(const char * name, int money, double ratio, int risk):risk(risk), riskm(0), SalesWorker(name, money, ratio){}
	virtual void AddSalesResult(int value){
		SalesWorker::AddSalesResult(value);
		switch(risk){
			case RISK_LEVEL::RISK_A:
			riskm=SalesWorker::GetPay()*0.3;
				break;
			case RISK_LEVEL::RISK_B:
			riskm=SalesWorker::GetPay()*0.2;
				break;
			case RISK_LEVEL::RISK_C:
			riskm=SalesWorker::GetPay()*0.1;
				break;
		}
	}
	virtual void ShowSalaryInfo() const{
		SalesWorker::ShowSalaryInfo();
		cout<<"risk pay : "<<riskm<<endl;
		cout<<"sum : "<<SalesWorker::GetPay()+riskm<<endl;
		cout<<endl;
	}
};
// 기능적(handler) 클래스
class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	// empnum은 동적할당된 것이 아니므로 자동으로 0으로 초기화는 안됨
	EmployeeHandler() : empNum(0) 
	{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++]=emp;
	}
	void ShowAllSalaryInfo() const
	{
		
		for(int i=0; i<empNum; i++)
			empList[i]->ShowSalaryInfo();
		
	}
	void ShowTotalSalary() const
	{
		int sum=0;
		
		for(int i=0; i<empNum; i++)
			sum+=empList[i]->GetPay();
		
		cout<<"salary sum: "<<sum<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	//Employee t1("test"); // 역시 abstract class라 객체 생성이 제한된다.
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;
	ForeignSalesWorker *f1=new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	f1->AddSalesResult(7000);
	handler.AddEmployee(f1);
	// emplyee*형이지만 상속된 관계이므로 가리키기 가능
	ForeignSalesWorker *f2=new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_B);
	f2->AddSalesResult(7000);
	handler.AddEmployee(f2);
	
	ForeignSalesWorker *f3=new ForeignSalesWorker("Dong", 1000, 0.1, RISK_LEVEL::RISK_C);
	f3->AddSalesResult(7000);
	handler.AddEmployee(f3);
	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();
	return 0;
}