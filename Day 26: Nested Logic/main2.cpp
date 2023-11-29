/*

    Improved performance by exiting main on early/on time returns and reducing number of nested logic statements.
        Before 1:
            if (y1 < y2)
            {
                // do nothing - returned early
            }
        After 1:
            if (returnYear < dueYear)
            {
                cout << fine << endl;
                return 0;
            }
        Before 2:
            // check if book is returned early/on time by day
            if (d1 <= d2)
            {
                //cout << "Return on time/early" << endl;
            }
            // check if book is returned late by days
            else if (d1 > d2) 
            {
                //cout << "Returned day(s) late" << endl;
                fine += (15 * (d1 - d2));
            }
        After 2:
            // check if book is returned early/on time by day
            if (returnDay <= dueDay)
            {
                //cout << "Return on time/early" << endl;
                cout << fine << endl;
                return 0;
            }
            
            // book is returned late by days
            //cout << "Returned day(s) late" << endl;
            fine += (15 * (returnDay - dueDay)); 
    
    Renamed variables to more explanatory names
        Before:
            int d1, d2, m1, m2, y1, y2;
        After:
            int returnDay, dueDay, returnMonth, dueMonth, returnYear, dueYear;
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int returnDay, dueDay, returnMonth, dueMonth, returnYear, dueYear;
    
    // gather dates
    cin >> returnDay; 
    cin >> returnMonth;
    cin >> returnYear;
    cin >> dueDay;
    cin >> dueMonth;
    cin >> dueYear;
    
    //cout << "Returned: " << m1 << "/" << d1 << "/" << y1 << endl;
    //cout << "Due: " << m2 << "/" << d2 << "/" << y2 << endl;
    
    // initiate fine
    int fine{};
    
    // check if books is returned early by year
    if (returnYear < dueYear)
    {
        cout << fine << endl;
        return 0;
    }
    // check if book is returned early/on time by month
    else if (returnMonth <= dueMonth && returnYear <= dueYear)
    {
        // check if book is returned early/on time by day
        if (returnDay <= dueDay)
        {
            //cout << "Return on time/early" << endl;
            cout << fine << endl;
            return 0;
        }
        
        // book is returned late by days
        //cout << "Returned day(s) late" << endl;
        fine += (15 * (returnDay - dueDay));  
    }
    // check if book is returned late by months
    else if (returnYear <= dueYear) 
    {
        //cout << "Returned month(s) late" << endl;
        fine += (500 * (returnMonth - dueMonth));
    }
    // book is late by years - flat fee
    else 
    {
        //cout << "Returned year(s) late" << endl;
        fine += 10000;
    }
    
    //cout << "Total fine: " << fine << endl;
    cout << fine << endl;
    return 0;
}
