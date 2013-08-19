// JY: Hey Patrick, this is a great start. A lot of stuff is covered even in
// this small program, including:
//
//     * variables
//     * iteration (for and while loops using ranges)
//     * basic utilities from the standard library (vector, string, and io)
//     * retrieving input from the user
//
// It's also a reasonable way to solve the problem. You probably didn't know it,
// but you solved the problem in a more efficient way than the method described
// in your email. The problem stated in the email said to write a program that
// reads in *all* words until the user is finished entering words. Only then
// does the program print out the upper-case version. Your program reads in
// words in batches of 8 (stored in the vector), and then prints that batch of 8
// in upper-case. Afterwards, it discards these words and moves on to the next
// batch of 8. I say this is more efficient because your program does not need
// to hold all words in memory until the user is done entering them. Imagine if
// the user entered 100 million words. Your program would handle that just fine
// since only 8 words need to be held in memory at any given time. The stated
// program might run out of memory and crash. Good job :).
//
// Well, I figure I can provide some pointers on style, design, performance, and
// some direction on what things are important to learn that you might not get
// from a book on C++. I've added some comments to your code below. Keep in mind
// that my comments are sometimes just opinions given a particular context, so
// don't necessarily take them as set-in-stone-for-all-eternity :). Try
// addressing my feedback, stripping out my comments, and submitting your
// changes.


#include <iostream>
#include <string>
#include <vector>


//
// JY: If you find yourself importing a lot of symbols from other namespaces
// ("std" in this case), you can import all symbols in a namespace with the
// following line:
//
//     using namespace std;
//
// Another option is to not import symbols at all and just use the
// fully-qualified namespace when referring to the symbols in your program. For
// example, you could eliminate the 'using' statements and just prefix all uses
// of cout with std:: (as an example):
//
//     std::cout << "hello world" << std::endl;
//
// Knowing which option is best depends on the particular context and depends on
// a deeper familiarity with C++. For the time being, any of these approaches is
// fine.
//
// By the way, a "namespace" is a way to prevent symbols like "cout" from
// clashing with symbols defined elsewhere in a large program. You could have a
// symbol "cout" defined in the std namespace and another symbol "cout" defined
// in some other namespace (say, funky::cout).
//
using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::endl;


// JY: I generally add a single space before opening curly-braces:
//
//     int main() {
int main (){

    // JY: You don't need to create the words variable with an initial string.
    // It is sufficient for this program to just write:
    //     string words;
    //
    // The variable will be automatically initialized to the empty string: "".
    // Also, the name of this variable is misleading. It doesn't contain
    // multiple words, but a single word entered by the user at any given time.
    // The loop replaces the word each iteration. A better name for the variable
    // might be "nextWord".
    string words("hello world");//create string variable to store words

    // JY: There is no need to initialize vectors with a specific size in this
    // case. It suffices to just write:
    //
    //     vector<string> v1;
    //
    // The vector will automatically be initialized with zero elements. In
    // addition, there is no need for variable v2. Instead of writing v1 = v2,
    // you can just write:
    //
    //     v1.clear();
    //
    // which will clear all elements from v1 and make its size zero again. The
    // name of this variable could be improved as well. I'd change it from "v1"
    // to "words" since it's your list of words that are waiting to get printed.
    vector <string> v1(0),v2(0); //create vector to store string values and vector to reset values
    while (cin >> words && words != "q"){ //create loop to store words variable into vector variable add functionality so that we can quit with entering a "q"

        // JY: When writing for and while loops, it's generally more clear to
        // use curly-braces (even though they are optional in C++):
        //
        //     for (auto& i : words) {
        //         i = toupper(i);
        //     }
        //
        // Notice that I put the "&" next to "auto" rather than "i". This is a
        // personal preference which I can explain once you've learned a bit
        // more.
        for (auto &i : words) //create for range to call letters in string variable words individually
            i = toupper(i); // change lowercase value to UPPERCASE
        v1.push_back(words); //add words to vector

        // JY: Be consistent in your spacing when writing operators (such as ==,
        // =, +, etc). I tend to include a single space on either side of the
        // operator:
        //
        //     v1.size() == 8
        if (v1.size()==8) { // create if statement for vector total of 8 elements
            for (auto p : v1) // create for range to print results
                cout << p << " ";
            cout << endl;
            // JY: The code is easier to read if the closing curly-brace is on a
            // line of its own:
            //
            //         v1 = v2;
            //     }
            v1=v2;};
        // JY: No need for the blank line below. This curly-brace is closing the
        // "scope" of the while loop. It belongs next to the code which is
        // inside that scope, namely, the code above.

    }// end of while loop

    for (auto p : v1) // create for range to print results
        cout << p << " ";
    cout << endl;

    // JY: All of this code is contained within something called the main
    // "function." This function returns a value of type "int", which stands for
    // "integer" (see line 69). We should add the line below for correctness,
    // which returns a value of zero. You will understand this better as you
    // learn more about C++. For convenience, C++ allows you to omit the return
    // value for the main function, but it will generate a compilation error for
    // other functions. It's best practice to just include it explicitly:
    //
    //     return 0;
}


