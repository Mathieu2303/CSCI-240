#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

// Function 1: example3 - Computes the sum of prefix sums (inefficient version)
double example3(const vector<int>& seq) {
    int n(seq.size());
    double total{0};
    double prefixAverages = 0;
    double totalsum = 0;
    for (int j = 0; j < n; j++) {    // loop from 0 to n-1  
        total = 0;         
        for (int k = 0; k <= j; k++) {     // loop from 0 to j
            total += seq[j];  // sum of all elements 0 - j
        }
        prefixAverages = total / (j + 1);  //calculate take the sum and average it according to index
        totalsum += prefixAverages; // add the index sum 
    }
    return totalsum/n; //divide index sum by vector size to get overall prefix average 
}

// Function 2: example4 - Computes the sum of prefix sums (optimized version)
double example4(const vector<int>& seq) {
    int n = seq.size();
    double total = 0;
    double prefix = 0;

    for (int j = 0; j < n; j++) {  // loop from 0 to n-1
        prefix += seq[j];
        total = prefix/n;
    }

    // Use floating-point division to get a precise average
    return static_cast<double>(total);
}


vector<int> randomIntGenerator(int min, int max, int size){
    vector<int>storingValues(size);
    for (int i = 0; i < size; i++){
        storingValues[i] = min + rand() % (max - min + 1); // generate number from min to max    ex) min = -100, max = 1000  1000 - - 100 = 1100  from -100 to 1000
    }
    return storingValues;
}   


int main() {
    vector<int> seq = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
    
    vector<int> storageOfRandomNumbers = randomIntGenerator(-10000, 10000, 100); // min max size
    vector<int> storageOfRandomNumbers2 = randomIntGenerator(-10000, 10000, 1000); // min max size
    vector<int> storageOfRandomNumbers3 = randomIntGenerator(-10000, 10000, 10000); // min max size
    vector<int> storageOfRandomNumbers4 = randomIntGenerator(-10000, 10000, 100000); // min max size

    double result1 = example3(seq);
    cout <<"Prefix Averages for {31, -41, 59, 26, -53, 58, 97, -93, -23, 84}  O(n^2):" << result1 << endl;
    double result2 = example4(seq);
    cout <<"Prefix Averages for {31, -41, 59, 26, -53, 58, 97, -93, -23, 84}  O(n):" << result2 << endl;


    auto start1 = high_resolution_clock::now();
    example3(storageOfRandomNumbers);  // Run example3 without printing the result
    auto stop1 = high_resolution_clock::now();
    double elapsed1 = duration_cast<milliseconds>(stop1 - start1).count();
    cout << "Time taken for 100 (O(n^2)): " << elapsed1 << " milliseconds" << endl;

    // Measure time for O(n) algorithm (example4)
    auto start2 = high_resolution_clock::now();
    example4(storageOfRandomNumbers);  // Run example4 without printing the result
    auto stop2 = high_resolution_clock::now();
    double elapsed2 = duration_cast<milliseconds>(stop2 - start2).count();
    cout << "Time taken for 100 (O(n)): " << elapsed2 << " milliseconds" << endl;

    auto start3 = high_resolution_clock::now();
    example3(storageOfRandomNumbers2);  // Run example3 without printing the result
    auto stop3 = high_resolution_clock::now();
    double elapsed3 = duration_cast<milliseconds>(stop3 - start3).count();
    cout << "Time taken for 1000 (O(n^2)): " << elapsed3 << " milliseconds" << endl;

    // Measure time for O(n) algorithm (example4)
    auto start4 = high_resolution_clock::now();
    example4(storageOfRandomNumbers2);  // Run example4 without printing the result
    auto stop4 = high_resolution_clock::now();
    double elapsed4 = duration_cast<milliseconds>(stop4 - start4).count();
    cout << "Time taken for 1000 (O(n)): " << elapsed4 << " milliseconds" << endl;
    

    auto start5 = high_resolution_clock::now();
    example3(storageOfRandomNumbers3);  // Run example3 without printing the result
    auto stop5 = high_resolution_clock::now();
    double elapsed5 = duration_cast<milliseconds>(stop5 - start5).count();
    cout << "Time taken for 10000 (O(n^2)): " << elapsed5 << " milliseconds" << endl;

    // Measure time for O(n) algorithm (example4)
    auto start6 = high_resolution_clock::now();
    example4(storageOfRandomNumbers3);  // Run example4 without printing the result
    auto stop6 = high_resolution_clock::now();
    double elapsed6 = duration_cast<milliseconds>(stop6 - start6).count();
    cout << "Time taken for 10000 (O(n)): " << elapsed6 << " milliseconds" << endl;

////////////////// test case 100000
    auto start7 = high_resolution_clock::now();
    example3(storageOfRandomNumbers4);  // Run example3 without printing the result
    auto stop7 = high_resolution_clock::now();
    double elapsed7 = duration_cast<milliseconds>(stop7 - start7).count();
    cout << "Time taken for 100000 (O(n^2)): " << elapsed7 << " milliseconds" << endl;

    // Measure time for O(n) algorithm (example4)
    auto start8 = high_resolution_clock::now();
    example4(storageOfRandomNumbers4);  // Run example4 without printing the result
    auto stop8 = high_resolution_clock::now();
    double elapsed8 = duration_cast<milliseconds>(stop8 - start8).count();
    cout << "Time taken for 100000 (O(n)): " << elapsed8 << " milliseconds" << endl;




}
