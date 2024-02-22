#include <iostream> 
using namespace std;

/** sumOfThree
* @brief returns the sum of x, y, and z
*
* @param x : (int)
* @param y : (int)
* @param z : (int)
* @return int
*/

int sumOfThree(int x, int y, int z){
    return x + y + z;
}

/** division
* @brief returns × / y
*
* @param x : (double)
* @param y : (double)
* @return double
*/

double division(double x, double y){
    return x / y;
}

/** isGreatherThan
* @brief returns whether × is greater than y
*
* @param x : (double)
* @param y : (int)
* @return true : × is greater than y
* @return false : × is less than or equal to y
*/

bool isGreaterThan(double x, int y){
    return x > y;
}

/** select
* @brief output the statements based on func_type 
* func_type : output
* "sum"         : "The sum is "
* "division"    : "The quotient is "
* "comparison"  : "The first value being greater than the second value is "
* All other phrases: "Invalid function type\n"
* @param func_type : (string)
* @return string
*/

string select(const string& func_type){
    if (func_type == "sum") {
        return "The sum is ";
    } else if (func_type == "division") {
        return "The quotient is ";
    } else if (func_type == "comparison") {
        return "The first value being greater than the second value is ";
    } else {
        return "Invalid function type\n";
    }
}

/** myPrint
* @brief Calls select() to print out the output with the correct prompt
*
* @tparam T : (int, double, or string) output of sum, division, or isGreaterThan
* @param func_type : (string)
* @param output
*/

template <typename T>
void myPrint(string func_type, T output){
    cout << select(func_type) << output << endl;
}

void myPrint(string func_type, bool output){
    cout << select(func_type) << (output ? "true" : "false") << endl;
}

int main(){
    // initialize 3 int parameters
    int x1 = 2;
    int x2 = 3;
    int x3 = 5;

    // call sumOfThree
    int sum_out = sumOfThree(x1, x2, x3);
    //call myPrint
    myPrint("sum", sum_out);

    // initialize 2 double parameters
    double dividend = 12345.1;
    double divisor = 2345.6;

    // call division
    double div_out = division(dividend, divisor);
    myPrint("division", div_out);

    // compare div_out and sum_out
    bool is_greater_out = isGreaterThan(div_out, sum_out);
    myPrint("comparison", is_greater_out);
    return 0;

}