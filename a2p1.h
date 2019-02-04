/**********************
 * 159.234
 * Assignment 2 part 1
 *
 * Jamie Scott 18041508
 ***********************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

// function to display author's details

void info(){
    cout<<"159.234 Assignment 2P1"<<endl<<"Scott, J"<<'\t'<<"ID 18041508"<<endl<<endl;
}

/******************************
 * Employee class declaration
 ******************************/

class Employee{
protected:
    string mFName;
    string mGName;
    
private:
    string mIRD;
    
public:
    Employee(const string& FName, const string& GName, const string& IRD);
    virtual ~Employee();
    
    virtual void print(ostream&);
    virtual double getNetMonthlyPay()=0;
    
    void setFName(const string&);
    string getFName() const;
    void setGName(const string&);
    string getGName() const;
    void setIRD(const int&);
    string getIRD() const;
};

/*********************************
 * Employee class implementation *
 *********************************/

Employee::Employee( const string& FName, const string& GName, const string& IRD): mFName(FName), mGName(GName), mIRD(IRD){}
Employee:: ~Employee(){}

void Employee::print(ostream &output){
    output<<mIRD<<'\t'<<mFName<<'\t'<<mGName;
}

void Employee:: setFName(const string& FName){
    mFName=FName;
}

string Employee::getFName() const{
    return mFName;
}

void Employee::setGName(const string& GName){
    mGName=GName;
}

string Employee::getGName() const{
    return mGName;
}
void Employee::setIRD(const int& IRD){
    mIRD=IRD;
}

string Employee::getIRD() const{
    return mIRD;
}

/**************************************
 * Salaried Employee class declaration
 *************************************/

class SalaryEmp: public Employee {
    
protected:
    double mAPay;
    
public:
    SalaryEmp (const string& FName = "No_SEMP", const string& GName = "No_SEMP", const string& IRD = "SEMP00-0000-000", const double& APay = 0);
    virtual ~SalaryEmp();
    
    void setAPay(const double&);
    double getAPay()const;
};

/****************************************
 * Salaried Employee class implementation
 ****************************************/

SalaryEmp::SalaryEmp (const string& FName, const string& GName, const string& IRD, const double& APay): Employee (FName, GName, IRD), mAPay(APay){}
SalaryEmp:: ~SalaryEmp(){}

void SalaryEmp::setAPay(const double& APay){
    mAPay=APay;
}

double SalaryEmp::getAPay()const{
    return mAPay;
}

/**************************************
 * Prof class declaration
 **************************************/

class Prof: public SalaryEmp{
private:
    int mDaysLeave;
    const int mTax = 28;
    
public:
    Prof (const string& FName = "No_PR", const string& GName = "No_PR", const string& IRD = "PR00-0000-000", const double& APay = 0, const int& DaysLeave =0);
    
    void setDaysLeave(const int&);
    double getDaysLeave()const;
    
    double getNetMonthlyPay();
    void print(ostream&);
};

/*********************************
 * Professor  class implementation
 *********************************/
Prof::Prof(const string& FName, const string& GName, const string& IRD, const double& APay, const int& DaysLeave): SalaryEmp(FName, GName, IRD, APay), mDaysLeave(DaysLeave){}

void Prof::setDaysLeave(const int& DaysLeave){
    mDaysLeave=DaysLeave;
}

double Prof::getDaysLeave()const{
    return mDaysLeave;
}

double Prof::getNetMonthlyPay(){
/*converts annual salary to daily figure.
 Multiply by unpaid days leave to calculate the necessary deduction.
 Take deduction away from gross monthly pay and apply tax rate to get net monthly pay */
    double GrossMonthlyPay;
    double UnpaidLeaveDeduction;
    double NetMonthlyPay;
    GrossMonthlyPay=mAPay/12;
    UnpaidLeaveDeduction=mAPay/365 * mDaysLeave;
    NetMonthlyPay=(GrossMonthlyPay-UnpaidLeaveDeduction)*(1-(mTax/100.0));
    return NetMonthlyPay;
}

void Prof::print(ostream &output){
    output<<left<<setw(15)<<Employee::getIRD()<<left<<setw(12)<<mFName<<left<<setw(20)<<mGName<<'$'<<left<<setw(10)<<getNetMonthlyPay();
}

/****************************
 * Admin class declaration
 ****************************/

class Admin: public SalaryEmp{
private:
    string mJob;
    const int mTax = 25;
    
public:
    Admin(const string& FName = "NO_ADM", const string& GName = "No_ADM", const string& IRD = "ADM00-0000-000", const double& APay = 0, const string& Job = "NO_ADM");
    
    void setJob(const string& Job);
    string getJob() const;
    
    double getNetMonthlyPay();
    void print(ostream&);
};

/*********************************
 * Admin class implementation
 *********************************/
Admin::Admin( const string& FName, const string& GName,const string& IRD, const double& APay, const string& Job): SalaryEmp( FName, GName,IRD, APay), mJob(Job){}

void Admin::setJob(const string &Job){
    mJob=Job;
}

string Admin::getJob() const{
    return mJob;
}

double Admin::getNetMonthlyPay(){
    double NetMonthlyPay;
    NetMonthlyPay=(mAPay/12)*(1-(mTax/100.0));
    return NetMonthlyPay;
}

void Admin::print(ostream &output){
    output<<left<<setw(15)<<Employee::getIRD()<<left<<setw(12)<<mFName<<left<<setw(20)<<mGName<<'$'<<getNetMonthlyPay();
}

/****************************
 * TEmp class declaration
 ****************************/
class TEmp: public Employee{
private:
    string mID;
    int mHWorked;
    double mHPay;
    const int mTax = 20;
    
public:
    TEmp(const string& GName = "No_TA", const string& FName = "NO_TA", const string& IRD = "TA00-0000-000", const string& ID = "000000000", const int& HWorked = 0, const double HPay = 0);
    
    void setID (const string& ID);
    string getID () const;
    void setHWorked (const int& HWorked);
    int getHWorked () const;
    void setHPay (const double HPay);
    double getHPay () const;
    
    double getNetMonthlyPay();
    void print(ostream&);
};

/****************************
 * TEmp class declaration
 ****************************/

TEmp::TEmp( const string& FName, const string& GName,const string& IRD, const string& ID, const int& HWorked, const double HPay): Employee(FName, GName, IRD), mID(ID), mHWorked(HWorked), mHPay(HPay){}

void TEmp::setID (const string& ID){
    mID=ID;
}

string TEmp::getID() const{
    return mID;
}

void TEmp::setHWorked (const int& HWorked){
    mHWorked=HWorked;
}

int TEmp::getHWorked() const{
    return mHWorked;
}

void TEmp::setHPay(const double HPay){
    mHPay=HPay;
}

double TEmp::getHPay() const{
    return mHPay;
}

double TEmp:: getNetMonthlyPay(){
    double NetMonthlyPay;
    NetMonthlyPay=(mHWorked*mHPay)*(1-(mTax/100.00));
    return NetMonthlyPay;
}

void TEmp:: print(ostream& output){
    output<<left<<setw(15)<<Employee::getIRD()<<left<<setw(12)<<mFName<<left<<setw(20)<<mGName<<'$'<<getNetMonthlyPay();
}
