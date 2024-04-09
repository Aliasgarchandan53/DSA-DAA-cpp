#include <iostream>
using namespace std;

int max(int a,int b){
    return (a>b)?a:b ;
}

void swap(int*a,int*b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int main(){
    int choice;
    cout<<"Enter choice :\n";
    cin>>choice;
    int a,b; 
    cout<<"Pass two integers a and b :\n"; 
    cin>>a>>b;
    switch(choice){
        case 1:{
            int c = max(a,b);
            cout<<"Greatest is "<<c<<endl;
            break;}
        case 2:{
            cout<<"Before swap a= "<<a<<" b="<<b<<endl;
            swap(&a,&b);
            cout<<"After swap a= "<<a<<" b="<<b<<endl;
            break;}
    }
    return 0;
}


/*This coding challenge is organized in the following way:

First line of input reads an integer to select the coding challenge:

-Reading value '1' selects the coding-challenge 1 ( tests the ability 
    to define a function and pass arguments by value.)

-Reading value '2' selects the coding challenge 2 (tests the ability to pass 
    arguments by reference to a function)

Coding Challenge -1
Define a function named "Maximum" that accepts two integers (pass by value) 
    as arguments and returns the greatest of the two arguments.

Coding Challenge -2
Define a function named "Swap" that accepts two integers (pass by reference) as 
    arguments and swaps their value.*/
