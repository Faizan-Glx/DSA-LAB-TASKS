#include <iostream>
using namespace std;


class Employee
{
public:
 
    virtual double calculatesalary() = 0;
};


class fulltimeemployee : public Employee
{
private:
    double fixedsalary;

public:
    
    fulltimeemployee(double s)
    {
        fixedsalary = s;
    }

    
    double calculatesalary()
    {
        return fixedsalary;
    }
};


class parttimeemployee : public Employee
{
private:
    int hours;
    double hourlyrate;

public:
    
    parttimeemployee(int h, double rate)
    {
        hours = h;
        hourlyrate = rate;
    }

   
    double calculatesalary()
    {
        return hours * hourlyrate;
    }
};


int main()
{
 
    fulltimeemployee f1(50000);      
    parttimeemployee p1(40, 500);    

  
    cout << "Full-Time Employee Salary: " << f1.calculatesalary() << endl;
    cout << "Part-Time Employee Salary: " << p1.calculatesalary();

    return 0;
}