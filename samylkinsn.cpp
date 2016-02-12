#include <iomanip>
#include <iostream>
#include <cmath>
 using namespace std;

 int main ()
 {
     float s,s1;
     for (int i=1; i<pow(10,9); i++) s+=1.0/pow(i,2);
     cout<<s<<endl;
     for (int i=pow(10,9); i>0; i--) s1+=1.0/pow(i,2);
     cout<<s1<<endl;
 }
