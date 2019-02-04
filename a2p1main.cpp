#include <iostream>
#include "a2p1.h"
#include <iomanip>
using namespace std;

int main(){
    const int SIZE=10;
    info();
    Employee* emps[SIZE];
    emps[0]=new TEmp();
    emps[1]=new TEmp("Wuz", "Chris", "22-267-8012", "12323405", 6, 25);
    emps[2]=new TEmp("Jackson", "Priscilla", "63-232-1456", "08001896", 12, 23.50);
    emps[3]=new Admin();
    emps[4]=new Admin("Bush", "GeorgeJr","06-1342-0456", 59099.76, "Librarian");
    emps[5]=new Admin("Clever", "Bob", "22-267-812", 79345.00, "Business Manager");
    emps[6]=new Prof();
    emps[7]=new Prof("Steiger", "Ludwig", "65-102-456", 79345.00, 3);
    emps[8]=new Prof("Flop", "Boby", "11-178-120", 69009.00, 0);
    emps[9]=new Prof("Daisy", "Ana", "34-567-812", 67099.00, 3);
    double totalToPay=0.0;
    for (int i=0; i<SIZE; ++i){
        totalToPay +=emps[i]->getNetMonthlyPay();
        emps[i]->print(cout);
        cout<<endl;
    }
    cout<<"\nTotal wages this month: $"<<setprecision(10)<<totalToPay;
    cout<<"\nThank you for using our program! Bye! "<<endl;
//    return 0;
}
