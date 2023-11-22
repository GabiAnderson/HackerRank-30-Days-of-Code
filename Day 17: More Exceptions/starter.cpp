#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
// DO NOT CHANGE CODE ABOVE
//Write your code here
// DO NOT CHANGE CODE BELOW
int main()
{
    Calculator myCalculator=Calculator();
    int T,n,p;
    cin>>T;
    while(T-->0){
      if(scanf("%d %d",&n,&p)==2){
         try{
               int ans=myCalculator.power(n,p);
               cout<<ans<<endl; 
         }
         catch(exception& e){
             cout<<e.what()<<endl;
         }
      }
    }
    
}
