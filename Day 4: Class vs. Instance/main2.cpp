/*

  Updated else if block to reduce number of checks (removing &&)
    Before:
      Was checking if < 13 and then checking the reverse of that in the following else if (redundant)
        if(age < 13)
          .....
        else if (age >= 13 && age < 18) - redundant code here bc if it reaches this point it has to be >= 13
    After:
      No redundant checks
        if(age < 13)
          ...
        else if (age < 18)

  Updated/simplified age assignment with ternary operator (reduced to a single if instead of an if-else)
    Before:
      Did an if else to check how to assign
        if(initialAge < 0)
        {
            age = 0;
            cout << "Age is not valid, setting age to 0." << endl;
        }
        else 
        {
            age = initialAge;
        }
    After:
      Used ternary operator to simplify assignment and used a single if to determine print
        age = (initialAge < 0) ? 0 : initialAge;
        if (initialAge < 0) 
        {
            cout << "Age is not valid, setting age to 0." << endl;
        }
        
*/

using namespace std;
#include <iostream>

class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        age = (initialAge < 0) ? 0 : initialAge;
        if (initialAge < 0) 
        {
            cout << "Age is not valid, setting age to 0." << endl;
        }
    }

    void Person::amIOld(){
        if(age < 13)
        {
            cout << "You are young." << endl;
        }
        else if (age < 18)
        {
            cout << "You are a teenager." << endl;
        }
        else 
        {
            cout << "You are old." << endl;
        }
    }

    void Person::yearPasses(){
        age++;
    }

int main(){
    int t;
    int age;
    cin >> t;
    for(int i=0; i < t; i++) {
        cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
            p.yearPasses(); 
        }
        p.amIOld();
      
        cout << '\n';
    }

    return 0;
}
