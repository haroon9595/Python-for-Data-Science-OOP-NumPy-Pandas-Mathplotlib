#include <iostream>
using namespace std;

int main() 
{
   int n;
   cout<<"enter the number: ";
   cin>>n;
   
   bool isPrime= true;
   for(int i = 2;i*i<=n;i++)
   {
      if(n%i==0)
      {
         isPrime=false;
         break;
      }
     
   }
    if(isPrime==true){
         cout<<"prime number  \n";
      }
      else{
        cout<<"not prime number  \n";
      }
  

}
