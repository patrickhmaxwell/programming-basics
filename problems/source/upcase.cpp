#include <iostream>
#include <string>
#include <vector>


using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::endl;


int main (){
    string words("hello world");//create string variable to store words
    vector <string> v1(0),v2(0); //create vector to store string values and vector to reset values
    while (cin >> words && words != "q"){ //create loop to store words variable into vector variable add functionality so that we can quit with entering a "q"
        for (auto &i : words) //create for range to call letters in string variable words individually
            i = toupper(i); // change lowercase value to UPPERCASE
        v1.push_back(words); //add words to vector
        if (v1.size()==8) { // create if statement for vector total of 8 elements
            for (auto p : v1) // create for range to print results
                cout << p << " ";
            cout << endl;
            v1=v2;};

    }// end of while loop
    for (auto p : v1) // create for range to print results
        cout << p << " ";
    cout << endl;

}

