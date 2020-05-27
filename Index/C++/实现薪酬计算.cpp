#include<iostream>
using namespace std;
class Emp{
public:
	Emp(string name ,int id,int grand):e_name(name),e_id(id),e_grand(grand){}
	void PrintInfo()
	{
			PrintBase();
			PrintOther();
	}
	void PaySalary(){
		double salary = CalBase() + CalMerit();
		cout<<"薪资为:"<<salary<<endl;
	}
protected:
	void PrintBase(){
		cout<<"姓名:"<<e_name<<endl;
		cout<<"工号:"<<e_id<<endl;
		cout<<"等级:"<<e_grand<<endl;
	}
	double CalBase(){
		int day;
		cout<<"缺勤天数:";
		cin>>day;
		attand =(23-day)*1.0/23;
		e_basic = s_grand[e_grand-1]*attand;
		return e_basic;
	}
	double attand;
private:		
	void PrintOther(){}
	double CalMerit(){
		return s_grand[e_grand-1]/2;
	}
	string e_name;
	int e_id;
	int e_grand;
	double e_basic;
	static int s_grand[8];
};
int Emp::s_grand[8]={1000,2000,3000,4000,5000,6000,7000,8000};

class Tec:public Emp{
public:
	Tec(string name,int id,int grand,double allowance ):Emp(name,id,grand),t_allowance(allowance){}
	void PrintInfo(){
		PrintBase();
		PrintOther();
	}
	void PaySalary(){
		double salary = CalBase()+CalMerit();
		cout<<"薪资为："<<salary<<endl;
	}

private:
	void PrintOther(){
		cout<<"津贴:"<<t_allowance<<endl;
	}
	double CalMerit(){
		double ave;
		cout<<"进度因数:";
		cin>>ave;
		return 23*8*t_allowance*ave; 
	}
	double t_allowance;
};



int main()
{
		Emp man1("张飞",1001,4);
		man1.PrintInfo();
		man1.PaySalary();
		Tec man2("赵云",1002,5,10);
		man2.PrintInfo();
		man2.PaySalary();

		return 0;
}
