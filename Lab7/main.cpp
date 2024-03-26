#include <iostream> 
#include <fstream>
using namespace std;

void writeToFile(string filename, int * arr, int sample_size){ 
    ofstream file(filename);
    for(int i = 0; i < sample_size; i++) { 
        file << arr[i] << "\n";
    }
    file.close ();
    printf ("Wrote to %s\n", filename.c_str());
}

void writeToFile(string filename, string * arr, int sample_size){ 
    ofstream file(filename);
    for(int i = 0; i < sample_size; i++) { 
        file << arr[i] << " ";
    }
    file.close ();
    printf ("Wrote to %s\n", filename.c_str());
}

void writeToFile(string filename, char * arr, int sample_size){ 
    ofstream file(filename);
    for(int i = 0; i < sample_size; i++) { 
        file << arr[i] << "\n";
    }
    file.close ();
    printf ("Wrote to %s\n", filename.c_str());
}

void readFile(string filename){
    ifstream file(filename);
    string val;
    if(file.is_open()) { 
        // while (file.good()){
        //     file >> val;
        //     cout << val << "\n";
        // }
        while (!file.eof()){
            file >> val;
            if (!file.eof()) {
                cout << val << "\n";
            }
        }
    }
    file.close ();
    printf ("Read and wrote from %s\n", filename.c_str());
}

int main(){
    const int SAMPLE_SIZE = 10;

    int array_int [SAMPLE_SIZE] = {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10};
    string array_str [SAMPLE_SIZE] = {"This", "is","a", "sentence.",
                                    "This", "is","another", "sentence.",
                                    "The", "end."};
    char array_char [SAMPLE_SIZE] = {'a', 'b', 'c', 'd', 'e', '0', '1', '2', '3', '4'};

    string int_file = "array_int.csv";
    writeToFile(int_file, array_int, SAMPLE_SIZE);

    string str_file = "array_str.csv";
    writeToFile(str_file, array_str, SAMPLE_SIZE);

    string char_file = "array_char.csv";
    writeToFile(char_file, array_char, SAMPLE_SIZE);

    readFile(char_file);

    return 0;
}