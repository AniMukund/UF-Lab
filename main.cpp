#include <iostream>
#include "StringData.h"
#include <vector>
#include <string>
#include <chrono>
using namespace std;


int linearSearch(vector<string> & setOfElements, string guide){

    for (int i = 0; i < setOfElements.size(); i++) {
        if (setOfElements[i] == guide) {
            return i;
        }
    }

    return -1;

}


int binarySearch(vector<string> & setOfElements, string guide) {

    int lowerBound = 0;
    int upperBound = setOfElements.size() - 1;

    while (lowerBound <= upperBound) {

        int middleValue = lowerBound + ((upperBound - lowerBound)/2);

        if (setOfElements[middleValue] == guide) {
            return middleValue;
        }

        else if (setOfElements[middleValue] < guide) {
            lowerBound = middleValue + 1;
        }

        else {
            upperBound = middleValue - 1;
        }
    }

    return -1;

}


int main() {
    vector <string> setOfElements = getStringData();

    auto initialTime = std::chrono::system_clock::now();
    int linSearchResult = linearSearch(setOfElements, "not_here");
    auto finalTime = std::chrono::system_clock::now();
    auto timeForProcess = finalTime - initialTime;

    cout << "The index value of the linear search for not_here is: " << linSearchResult << ". The time taken is " << timeForProcess << "." << endl;

    initialTime = std::chrono::system_clock::now();
    int binSearchResult = binarySearch(setOfElements, "not_here");
    finalTime = std::chrono::system_clock::now();
    timeForProcess = finalTime - initialTime;

    cout << "The index value of the binary search for not_here is " << binSearchResult << ". The time taken is " << timeForProcess << "." << endl;

     initialTime = std::chrono::system_clock::now();
     linSearchResult = linearSearch(setOfElements, "mzzzz");
     finalTime = std::chrono::system_clock::now();
     timeForProcess = finalTime - initialTime;

    cout << "The index value of the linear search for mzzzz is: " << linSearchResult << ". The time taken is " << timeForProcess << "."<< endl;

    initialTime = std::chrono::system_clock::now();
    binSearchResult = binarySearch(setOfElements, "mzzzz");
    finalTime = std::chrono::system_clock::now();
    timeForProcess = finalTime - initialTime;

    cout << "The index value of the binary search for mzzzz is " << binSearchResult << ". The time taken is " << timeForProcess << "."<< endl;


    initialTime = std::chrono::system_clock::now();
    linSearchResult = linearSearch(setOfElements, "aaaaa");
    finalTime = std::chrono::system_clock::now();
    timeForProcess = finalTime - initialTime;

    cout << "The index value of the linear search for aaaaa is: " << linSearchResult << ". The time taken is " << timeForProcess << "."<< endl;

    initialTime = std::chrono::system_clock::now();
    binSearchResult = binarySearch(setOfElements, "aaaaa");
    finalTime = std::chrono::system_clock::now();
    timeForProcess = finalTime - initialTime;

    cout << "The index value of the binary search for aaaaa is " << binSearchResult << ". The time taken is " << timeForProcess << "."<< endl;

    cout << "This is the intentional breaker!";


}
