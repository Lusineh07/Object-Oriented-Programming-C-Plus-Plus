#include <iostream> 
#include <vector>
using namespace std;

/**
* @brief prints the elements in the array and their memory locations
*
* @param arr - array of integers
* @param size - the number of elements in the array
*/

void printMemArr(vector<int> v){
    printf ("Array - Each int is worth %lu bytes\n", sizeof(v [0]));
    // for(int i = 0; i < v; i++) {
    //     printf("Value :%i at Memory Location: %p\n", v[i], v + i);
    // } 
}

/**
* @brief increments all of the elements in arr by 10
*
* @param arr - array of integers
* @param size - the number of elements in the array
*/

void incArrBy10(vector<int>  & v){
    // for(int i = 0; i < v(); i++) {
    //     v[i] += 10;
    // }
}

int main(){
    // const int SIZE = 5;
    // int arr [SIZE];
    // for(int i = 0; i < SIZE; i ++) {
    //     arr[i] = 100 + i;
    // }
    // printf("Before --------------------------------------\n");
    // printMemArr(arr, SIZE);
    // incArrBy10 (arr, SIZE);
    // printf("After ---------------------------------------\n");
    // printMemArr(arr, SIZE);
    return 0;
}