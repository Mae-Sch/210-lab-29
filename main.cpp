// Headers for data types, input/ output, and std namespace
#include <iostream>
#include <list>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;
// function to progress the cycle one stage
// int for current day, map for sheep map
void stepDay(int, map<string, list<int>[3]>);
// function which reports for under/over feeding/shearing/milking within the map
void reportDay(int, map<string, list<int>[3]>);
// 3 helper functions for above which checks for miscare for an idividual sheep
int checkSheepFeeding(list<int>[3]);
int checkSheepMilking(list<int>[3]);
int checkSheepShearing(list<int>[3]);

// decalare 3 functions which takes an array of 3 lists as input by reference
// bool represents whether sheep should be sheared/milked/fed this day
// this functions should be as editable as possible, or have variables determined during runtime
// this function is what we can very between trials to try different feeding, shearing, and milking algorithsm
// the three functions each correspond to one of our 3 processes
void feedSheep(list<int>[3] &);
void milkSheep(list<int>[3] &);
void shearSheep(list<int>[3] &);

const int NUM_SHEEP = 20;
const int NUM_DAYS = 25;
const int MIN_FEED_GAP = 1; // we want to avoid feeding a sheep twice in 1 day
const int MAX_FEED_GAP = 2;
const int MIN_MILK_GAP = 0;
const int MAX_MILK_GAP = 1;
const int MIN_SHEAR_GAP = 5;
const int MAX_SHEAR_GAP = 10;
const int MAX_OPERATIONS = NUM_SHEEP * 2.5; // maximum operations the farm staff can perform in a day, they only have so much time!

// begin Main function
int main() {
// Declare map of array[3]s of lists of ints to hold data
    map<string, list<int>[3]> Herd;
// Read initial data from file into map
// Data in file will be formated as follows:
// initial days are all negtaive or 0, because they take place before the simulation begins
// each sheep will be required to have at minimum 4 data points per category. This allows us to have care algorithms which analyzes the pervious 4 instances of care for.
// due to this, any data more than 4 is technically unused, but it doesn't hurt to have extra data
    // Sheep name
    // days eaten ie. -8 -7 -4 -3 -3
    // days milked ie. -7 -5 -3 -2 -1
    // days sheared ie. -8 -4 0
    // repeate previous 4 lines for each sheep
// data read will be based on getline()
    ifstream inFile("intialSheep.txt");
    if (!inFile.is_open()) {
        cout << "error, intial data could not be opened\n";
        return 0;
    }

    while (!inFile.eof()) {
        string name;
        getline(cin, name);
    }

    inFile.close();

// decalare a list of ints each for feeding, shearing, and milking
// each element in the list will represent a day, and the value
// shows if we over/under/correctly fed/sheared/milked the sheep, and by how much
// positive values for an excess of the process, negative for a shortage, and 0 for correct amount
    list<int> feedLog;
    list<int> milkLog;
    list<int> shearLog;

// loop to progress time
    // for each cycle:
        // run our fed, shear, and milk determining function for each sheep
        // add the current day to any sheep's list who undergoes the process
        // report any individual sheep who did not have their needs met
            // determined by const values. ie MAX_FEED_GAP = 2 determines the maxium
            // number of days a sheep can go without food without a shortage repeated
    for (int day = 1; day < NUM_DAYS; ++day) {
        stepDay(day, Herd);
    }

// Output total wasted time (food that was not eaten, over milking, over shearing)
// give a strong description of the results of our trial
// end of main function
    return 0;
}
