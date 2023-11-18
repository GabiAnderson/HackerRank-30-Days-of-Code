#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;

    // CHANGE NOTHING ABOVE THIS POINT

    Difference(vector<int> els)
    {
        // fill elements variable
        for(int i = 0; i < els.size(); i++)
        {
            //cout << els[i] << endl;
            elements.push_back(els[i]);
        }
    }

    // Find largest maximum difference between 2 elements in elements vector and set that to max difference
    void computeDifference()
    {
        // cannot add #include <climits> for INT_MIN and INT_MAX
        // so have to use std::numeric_limits<int>::min()
       int high {numeric_limits<int>::min()};
       int low {numeric_limits<int>::max()};

       // find highest and lowest value in vector of elements
       for(int i = 0; i < elements.size(); i++)
       {
           int current = elements[i];
           
           if(current < low)
           {
               low = current;
           }
           
           if(current > high)
           {
               high = current;
           }

           // compute absolute difference
           maximumDifference = abs((high - low));
       } 
    }

}; // End of Difference class

// CHANGE NOTHING BEYOND THIS POINT
int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}
