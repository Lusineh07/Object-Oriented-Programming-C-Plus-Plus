#include <iostream> 
#include <vector> 
#include <fstream> 
#include <ctime> 
using namespace std;

/**
* @brief returns the first index of elem if it exists, otherwise returns -1
* iterativeSearch starts at the first index and iterates sequentially to the next until it either
* finds the element or until it reaches the the end (i.e. element does not exist)
* 
* @param v : vector of elements
* @param elem: integer to look for
* @return int
*/
template<typename T>
int iterativeSearch(vector<T>v, int elem) {
    // use a for loop where the index, i goes from 0 to the size of v
    // inside the for loop, use an if statement to check whether the element at i (e.g. v[i]) equals elem
    // inside the if statement return i
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == elem) {
            return i; // Return the index if element is found
        }
    }
    // outside of the for loop return -1
    return -1; 
}

/**
* @brief returns the index of elem, if it exists in v. Otherwise it returns -1.
* binarySearch is recursive (i.e. function calls itself).
* It utilizes the fact that v is increasing order (e.g. values go up and
* duplicates are not allowed).
*
* It calculates the mid from the start and end index. It compares v[mid] (i.e. value
* at mid) with elem and decides whether to search the left half (lower values)
* or right half (upper values).
*
*
* @param v : vector of elements
* @param start : leftmost index (starting value is 0)
* @param end :rightmost index (starting value is v.size ())
* @param elem : integer to look for
* @return int
*/
template<typename T>
int binarySearch (vector<T> & v, int start, int end, int elem){
    //write an if statement that checks the terminating case 
    //inside the if statement return -1
    if (start > end) {
        return -1;
    }
    // instantiate the midpoint
    int mid = (start + end) / 2;    
    // Use if/else statements to do the following:
    if (v[mid] > elem){         // 1) update end (search left half)
        end = mid - 1;            
    } else if (v[mid] < elem){  // 2) update start (search right half)
        start = mid + 1;
    }else {                       // 3) return mid (found the elem)
        return mid;
    }
    // return a recursive call to binarySearch(...)
    return binarySearch (v, start, end, elem);
}

/**
* @brief updates v to contain the values from filename (leave as is)
*
* It is expected that the files contain values ranging from one to
* one hundred million in ascending order (no duplicates).
*
* @param filename : string
* @param v :vector
*/
template<typename T>
void vecGen(string filename, vector<T> & v) {
    ifstream file(filename);
    T num;
    v.clear();
    while (file.is_open() && file >> num) {
        v.push_back(num);
    }
    file.close();
}

/**
*
** @brief writes to file the time it took to search with respect to the
*  size of the vector, n
*  Number of Elements (n)               Time (sec)
    XXXX                                 X. XXXXX
    XXXX                                 X. XXXXX
*  @param filename (string) : filename (e.g. output_10000 _numbers. csv)
*  @param times (vector<double>) : average times
*  @param n (vector<int>) : sizes of vectors
*/

void writeTimes(string filename, const vector<double> times, const vector<int> n){
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (sec) " << endl;
    for(int i = 0; i < times.size(); i++){
        myFile << n[i] << "\t" << times [i] << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}

/**
* @brief computes the average of the elements in vector, a
*
* @param a vector of double
* @return double
*/

double average (const vector<double> a) {

    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        double val = a[i];
        sum += val;
    }
    return sum / a.size();
}

int main () {
    // populate v with 10000 sorted numbers 
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    // test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    double total_elapsed_time_iterative = 0.0;
    double total_elapsed_time_binary = 0.0;

    // reads through all 10 of the test_elem values and calls iterative search
    // and records how long each search took (leave as is)
    for(int i = 0; i < elem_to_find.size(); i++) {
        // gets the elem to search for
        int elem = elem_to_find[i];

        // stopwatches the time
        clock_t start = clock();                            // start time
        int index_if_found = iterativeSearch(v, elem);      // call search
        clock_t end = clock();                              // end time

        // calculates the total time it took in seconds
        double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);

        // for average time
        total_elapsed_time_iterative += elapsed_time_in_sec;
        //prints the index and how long it took to find it 
        if(index_if_found != -1) {
        cout << "Iterative Search: Element " << elem << " found at index " << index_if_found << " in " << elapsed_time_in_sec << " seconds." << endl;
        } else {
            cout << "Iterative Search: Element " << elem << " not found in " << elapsed_time_in_sec << " seconds." << endl;
        }
    }

    vector<double> d;
    vecGen ("1000_double. csv", d);
    vector<double> double_to_find;
    vecGen ("double_to_find.csv", double_to_find);
    // repeat the for loop above so that it records the time

    // it takes for binarySearch to do the same operation
    // reads through all 10 of the test_elem values and calls iterative search
    // and records how long each search took (leave as is)
    for(int i = 0; i < elem_to_find.size(); i++) {
        // gets the elem to search for
        int elem = elem_to_find[i];

        // stopwatches the time
        clock_t start = clock();                                         // start time
        int index_if_found = binarySearch (v, 0, v.size() - 1, elem);    // call search
        clock_t end = clock();                                           // end time

        // calculates the total time it took in seconds
        double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);
        // for average time
        total_elapsed_time_binary += elapsed_time_in_sec;


        //prints the index and how long it took to find it 
        if(index_if_found != -1) {
        cout << "Binary Search: Element " << elem << " found at index " << index_if_found << " in " << elapsed_time_in_sec << " seconds." << endl;
        } else {
            cout << "Binary Search: Element " << elem << " not found in " << elapsed_time_in_sec << " seconds." << endl;
        }
    }
    
    double average_time_iterative = total_elapsed_time_iterative / elem_to_find.size();
    double average_time_binary = total_elapsed_time_binary / elem_to_find.size();
    double speedup = average_time_iterative / average_time_binary;

    cout << "Average Time for Iterative Search: " << average_time_iterative << " seconds." << endl;
    cout << "Average Time for Binary Search: " << average_time_binary << " seconds." << endl;
    cout << "Speedup: " << speedup << endl;
}