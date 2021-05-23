#include <iostream>
using namespace std;
int main()
{
 int length;
 int l1;
 int w1;
 int width;
 int a1;
 int a2;
 cout<<"enter length :";
 cin>>length;
 cout<<"enter length 2 :";
 cin>>l1;
 cout<<"enter width :";
 cin>>width;
 cout<<"enter width 2 :";
 cin>>w1;
 
 
 a1=width*length;

 a2=w1*l1;
 
 
 if(a1>a2)
 {
 cout<<"area 1 is greater than 2 :"<<a1<<endl;
 
 }
 else if(a2>a1)
 {
 cout<<"area 2 is greater than 1 :"<<a2<<endl;
 } 

 else
 cout<<"areas are equal :"<<a2<<endl;
}