#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int d1, d2, m1, m2, y1, y2;
    
    // gather dates
    cin >> d1; 
    cin >> m1;
    cin >> y1;
    cin >> d2;
    cin >> m2;
    cin >> y2;
    
    //cout << "Returned: " << m1 << "/" << d1 << "/" << y1 << endl;
    //cout << "Due: " << m2 << "/" << d2 << "/" << y2 << endl;
    
    // initiate fine
    int fine{};
    
    // check if books is returned early by year
    if (y1 < y2)
    {
        // do nothing - book returned early
    }
    // check if book is returned early/on time by month
    else if (m1 <= m2 && y1 <= y2)
    {
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
    }
    // check if book is returned late by months
    else if (y1 <= y2) 
    {
        //cout << "Returned month(s) late" << endl;
        fine += (500 * (m1 - m2));
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
