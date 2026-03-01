#include <iostream>
using namespace std;

int main() 
{
   int n;
   int sum=0;
   cout<<"enter the number: ";
   cin>>n;
   for(int i =1; i<=n;i++)
   {
    if(i%3==0)
    {
        sum=sum+i;
    }
   }
   
 cout<<"sum is: " << sum;

   
  
  

}
