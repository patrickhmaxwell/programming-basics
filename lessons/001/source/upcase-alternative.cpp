// This is a slight simplification of upcase.cpp which avoids storing words in a
// vector by progressively building the next line of output. It determines when
// the line is complete and should be printed by tracking the current column
// number. When the column reaches a number evenly divisible by 8 (by the use of
// the modulous operator: "%"), it's time to print the line.


#include <iostream>
#include <string>
#include <vector>


int main () {

    int column = 1;
    std::string line;
    std::string nextWord;
    // Loop, accepting words from the standard input.
    while (std::cin >> nextWord) {
        for (auto& letter : nextWord) {
            letter = toupper(letter);
        }
        // Shove the next word onto the line we're building.
        line.append(nextWord);

        // Determine when it's time to print the line.
        if (column % 8 == 0) {
            std::cout << line << std::endl;
            line.clear();
        } else {
            line.append(" ");
        }
        column++;
    }
    // Generate a final newline if necessary.
    if (!line.empty()) {
        std::cout << line << std::endl;
    }
    return 0;
}

