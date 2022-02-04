#include <iostream>
using namespace std;

class emp{
    private:
        static int emp_id;
        int id;
    protected:
        int salary;
        string jobType;
    public:
        static string company_name;
        string name;
        emp(){//non parameterized constructor
            id=emp_id++;
            name="John Doe";
        }
        emp(int salary,string jobType){//parameterized constructor
            id=emp_id++;
            this->salary=salary;
            this->jobType=jobType;
        }
        emp(emp&e){//copy constructor
            id=e.id;
            name=e.name;
            salary=e.salary;
            jobType=e.jobType;
        }

        ~emp(){//destructor
            cout<<" Destructor\n";
        }

        void getData(int e_salary){
            salary=e_salary;
        }

        void getJobType(string t){
            jobType=t;
        }

        void printData(){
            cout<<"Employee id: "<<id<<"  name: "<<name<<"  basic salary: "<<salary<<"  job type is: "<<jobType;
            //printf("\n");
        }

        void getGrossSalary(){
            cout<<"Gross salary is: "<<5000+salary;
        }
};

int emp::emp_id=101;//static variables need to be globally initialized
string emp::company_name="ABC";

int main(){
    emp e1;
    cout<<"Default values of id and name is:\n";
    e1.printData();
    cout<<"company name is: "<<emp::company_name;
    cout<<"\nenter name, salary and job description\n";
    int  salary;string name,job;
    cin>>e1.name>>salary>>job;
    e1.getData(salary);
    e1.getJobType(job);
    e1.printData();
    e1.getGrossSalary();
    emp e2(500,"worker");
    cout<<"\n\n";
    cout<<"Default values of salary and job title is:\n";
    e2.printData();
    cout<<"company name is: "<<emp::company_name;
    cout<<"\nenter salary and job description\n";
    cin>>salary>>job;
    e2.getData(salary);
    e2.getJobType(job);
    e2.name="John";
    e2.printData();
    e2.getGrossSalary();
    cout<<"\n\n";
    emp e3(e2);//OR emp e4=e2;
    e3.printData();
}
/*
enter id, name and salary and job description
101 A 100 manager
Employee id: 101  name: A  salary: 100  job type is: manager
enter id, salary and job description
102 10000 worker
Employee id: 102  name: John  salary: 10000  job type is: worker
*/
