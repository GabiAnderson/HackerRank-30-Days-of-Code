#include <iostream>
#include <vector>

using namespace std;


class Person{
    protected:
        string firstName;
        string lastName;
        int id;
    public:
        Person(string firstName, string lastName, int identification){
            this->firstName = firstName;
            this->lastName = lastName;
            this->id = identification;
        }
        void printPerson(){
            cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
        }
    
};

class Student :  public Person{
    private:
        vector<int> testScores;  
    public:
        /*    
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student(string firstName, string lastName, int id, vector<int> scores) : Person(firstName, lastName, id)
        {
            // iterate through provided scores to fill vector
            for(int i = 0; i < scores.size(); i++)
            {
                //cout << "Score " << i << ": " << scores[i] << endl;
                this->testScores.push_back(scores[i]);
            }
            
            
            // check that the constructors are properly assigning and holding values
            /*
            for(int i = 0; i < testScores.size(); i++)
            {
                cout << "Test Score " << i << ": " << testScores[i] << endl;
            }
            
            cout << "Name: " << this->firstName << " " << this->lastName << endl;
            cout << "ID: " << this->id << endl;
            
            cout << "_______________" << endl;
            */
        }

        /*    
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate()
        {
            int sum{};
            // iteratre through scores to compute sum
            for(int i = 0; i < this->testScores.size(); i++)
            {
                sum += this->testScores[i];
            }
            
            // divide sum by # of scores to get average
            int average = sum / this->testScores.size();
            
            //cout << sum << endl;
            
            // use average to compute letter grade
            if(90 <= average) // && average <= 100)
            {
                return 'O';
            }
            else if (80 <= average) // && average < 90) 
            {
                return 'E';
            }
            else if (70 <= average) // && average < 80) 
            {
                return 'A';
            }
            else if (55 <= average) // && average < 70) 
            {
                return 'P';
            }
            else if (40 <= average) // && average < 55) 
            {
                return 'D';
            }
            else 
            {
                return 'T'; 
            }
        }
};

int main() {
    string firstName;
    string lastName;
    int id;
    int numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for(int i = 0; i < numScores; i++)
    {
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
        
        // double check the provided code is grabbing scores correctly
        //cout << "Score " << i << ": "<< tmpScore << endl;
    }
    
    // double check provided code is filling vector of scores correctly
    /*
    for(int i = 0; i < scores.size(); i++)
    {
        cout << "Score: " << scores[i] << endl;
    }
    */
    
    Student* s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << "\n";
    return 0;
}
