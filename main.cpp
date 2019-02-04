////////////////   159201   ///////////////////////////////////
//ASSIGNMENT 4 - Big Numbers
//Jamie Scott
//ID: 180415608
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

/////// PART A

//copy the template class List here
template <class T>
class List {
private:
    struct Node{
        T data;
        Node *next;
    };
    Node *front, *current;
public:
    List();
    ~List();
    void AddtoFront(T newitem);
    bool FirstItem (T &item);
    bool NextItem (T &item);
    void ReverseList (Node *&front);
};

template <class T>
List<T>::List(){
    front=NULL;
    current=NULL;
}

template <class T>
List<T>::~List(){}

template <class T>
void List<T>::AddtoFront(T newitem){
    Node *temp;
    temp = new Node;
    temp->next=front;
    temp->data=newitem;
    front=temp;
}

template <class T>
bool List<T>::FirstItem(T &item){
    if (front==NULL){return false;}
    item = front->data;
    current=front;
    return true;
}

template <class T>
bool List<T>::NextItem(T &item){
    //check current==null??
    current=current->next;
    if (current==NULL){return false;}
    item = current->data;
    return true;
}

template <class T>
void List<T>::ReverseList(Node *&front){
    Node *temp1, *temp2, *temp3;
    temp2 = front;
    temp3 = front->next;
    while(temp3!=NULL){
        temp1=temp3->next;
        temp3->next=front;
        front=temp3;
        temp3=temp1;
    }
    temp2->next=NULL;
    return;
}

/////// PART B
class BigNumber {
private:
    //complete here...
    //include here a List of integers, or shorts etc
    List <int> listofdigits;
    
public:
    //complete here...
    //what methods do you need?
    BigNumber();
    ~BigNumber();
    void ReadFromString (string decstring );
    void PrintBigNumber ();
    void AddBigNumbers(BigNumber B1,BigNumber B2);
    //void ReverseBigNumber ();
};

BigNumber::BigNumber(){}
//  listofdigits = new List
// anything here?

BigNumber::~BigNumber(){
    //you can keep that empty
}

void BigNumber::ReadFromString (string decstring ) {
    //cout<< "testing string passing: "<< decstring << endl;
    //read a string, adding a new node per digit of the decimal string
    // To translate 'digits' to integers: myinteger=decstring[index]-48
    
    for(int i = 0; i < decstring.size(); i++) {
        if(decstring[i]!='\n' && decstring[i]!='\r'){
            int temp=decstring[i]-48;
            cout << "Digit " << i << " is " << temp << endl;  //Comment this out for your final version
            //You need to use the AddtoFront()
            listofdigits.AddtoFront(temp);
        }
    }
}

void BigNumber::PrintBigNumber() {
    //   int tempdigit;
    //   bool ok;
    //   ok = listofdigits.FirstItem(&tempdigit);
    //   while(ok){
    //     cout<<tempdigit;
    //     ok = listofdigits.NextItem(&tempdigit);
    //   }
    //   cout<<endl;
    // //complete here, print the list (i.e., use FirstItem() and NextItem() )
    // //remember that the print out may be inverted, depending on the order you enter the 'digits'
    // }
    
    // void BigNumber:: AddBigNumbers(BigNumber B1,BigNumber B2){
    //   int carry = 0;
    //   int temp1, temp2, tempres;
    //   if ((B1.listofdigits.FirstItem(&temp1)==true)) && ((B2.listofdigits.FirstItem(&temp2)==true)){
    //     tempres = temp1+temp2;
    //     if tempres>10{
    //       carry = tempres/10;
    //       tempres = tempres-carry;
    //     }
    //     listofdigits.AddtoFront(tempres);
    //   }
    //   while (B1.NextItem(&temp1)) && (B2.NextItem(&temp2)){
    //     tempres=temp1+temp2+carry;
    //     if tempres>10{
    //       carry = tempres/10;
    //       tempres = tempres-carry;
    //     }
    //     listofdigits.AddtoFront(tempres);
    //   }
    //   while (B1.NextItem(&temp1)){
    //     tempres=temp1+carry;
    //     if tempres>10{
    //       carry = tempres/10;
    //       tempres = tempres-carry;
    //     }
    //     listofdigits.AddtoFront(tempres);
    //   }
    //   while (B2.NextItem(&temp2)){
    //     tempres=temp2+carry;
    //     if tempres>10{
    //       carry = tempres/10;
    //       tempres = tempres-carry;
    //     }
    //     listofdigits.AddtoFront(tempres);
    //   }
    //complete here.
    //use FirstItem(), NextItem() and AddNode()
    //to add two big numbers, what do you have to do? Be careful about the carry
    //Remember to add the last carry, the resulting number can have one more digit than B1 or B2
}

// void BigNumber::ReverseBigNumber (){
//   BigNumber *listpointer;
//   listofdigits.ReverseList(*listpointer);
// }

/////// PART C


BigNumber B1, B2, RES;

int main (int argc, char ** argv){
    string numberstring;
    int stringseq=0;
    ifstream input_file;
    if(argc==2) input_file.open(argv[1]);
    else { cout<< "cannot read the file " << argv[1] << endl; exit(0);}
    while(!input_file.eof()){
        getline(input_file,numberstring);
        if(!input_file.eof()){
            cout << "reading a big number from file:" << numberstring << endl;//Comment this out for your final version
            if(stringseq==0){
                B1.ReadFromString(numberstring);
                stringseq=1;
            }
            else B2.ReadFromString(numberstring);
        }
    }
    //print
    B1.PrintBigNumber();//PROBLEM: Is the printing inverted? How can you solve this problem? Before or after using AddBigNumbers()?
    cout << "+" << endl;
    B2.PrintBigNumber();
    cout << "=" << endl;
    //compute the addition
    RES.AddBigNumbers(B1,B2);
    //print the result
    RES.PrintBigNumber();
}
