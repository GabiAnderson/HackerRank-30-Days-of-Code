#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;
// DO NOT ALTER CODE ABOVE
// calculator class with single function
class Calculator
{
    public:
        // function
        int power(int n, int p)
        {
            // throw exception for invalid n and p
            if (n < 0 || p < 0)
            {
                throw std::invalid_argument("n and p should be non-negative");
            }
            
            // return n^p
            return pow(n, p);
        }  
};
// DO NOT ALTER CODE BELOW
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
