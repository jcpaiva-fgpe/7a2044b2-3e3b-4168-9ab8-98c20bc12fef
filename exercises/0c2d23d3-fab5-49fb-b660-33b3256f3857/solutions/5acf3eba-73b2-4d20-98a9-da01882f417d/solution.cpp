#include<iostream>
using namespace std;
int main() {
   int n, i, j, m=-1, s, ini_m, fi_m;
   cout<<"\nEnter the number of data element in the array: ";
   cin>>n;
   int a[n];
   for(i = 0; i < n; i++) {
      cout<<"Enter element "<<i+1<<": ";
      cin>>a[i];
   }
   for(i = 1; i < n+1; i++) {
      s = 0;
      for(j = 0; j < n; j++) {
         if(j < i)
            s += a[j];
         else
            s = s+a[j]-a[j-i];
         if(m< s) {
            ini_m = j-i+1;
            fi_m = j;
            m = s;
         }
      }
   }
   cout<<"\nThe maximum sub array is: ";
   for(i = ini_m; i <= fi_m; i++)
      cout<<a[i]<<" ";
      cout<<"\nThe maximum sub-array sum is: "<<m;
}