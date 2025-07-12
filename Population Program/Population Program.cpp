#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
using namespace std;

static double getValDouble(const string& prompt, double minVal) //Loop until a valid input is reached for double variables
{
    double val;
    while (true) 
    {
        cout << prompt; 
        if (!(cin >> val))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore next lines when input is invalid
        }
        else if (val < minVal) 
        {
            cout << "Please enter a number greater than or equal to " << minVal << "." << endl;
        }
        else
        {
            return val;
        }
    }
}

static int getValInt(const string& prompt, int minVal) //Loop until a valid input is reached for integer variables
{
    int val;
    while (true) 
    {
        cout << prompt; 
        if (!(cin >> val)) 
        {
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (val < minVal) 
        {
            cout << "Please enter an integer greater than or equal to " << minVal << "." << endl;
        }
        else {
            return val;
        }
    }
}

int main() 
{
    cout << "Population Growth Program" << endl;

    double start = getValDouble("Enter the starting number of people in a population (at least 2): ", 2.0); //Get starting population

    double dailyIncreasePercent = getValDouble("Enter the rate of increase per day (percentage, at least 0): ", 0.0); //Get rate of increase

    int days = getValInt("Enter the number of days passed from now (at least 1): ", 1); //Get days forward

    double population = start; 
    double rate = dailyIncreasePercent / 100.0; 

    cout << fixed << setprecision(2) << "\nDay\tPopulation\n"; //Logically rounded to per person instead of parts of a person
    cout << "-------------------------\n";
    for (int day = 1; day <= days; ++day) //Loop until number of days reached
    {
        if (day > 1) 
        {
            population *= (1.0 + rate); //Calculation for population changes  
        }
        double diff = population - floor(population);
        if (diff < 0.50)
        {
            cout << setw(3) << day << ":   " << fixed << setprecision(0) << floor(population) << endl; //Round Down
        }
        else if (diff >= 0.50)
        {
            cout << setw(3) << day << ":   " << fixed << setprecision(0) << ceil(population) << endl; //Round Up
        }
        else
        {
            return 1;
        }
        
    }

    return 0;
}
