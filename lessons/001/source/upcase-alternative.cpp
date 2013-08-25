#include <iostream>
#include <string>
#include <vector>


int main () {

    int column = 1;
    std::string line;
    std::string nextWord;
    while (std::cin >> nextWord && nextWord != "q") {
        for (auto& letter : nextWord) {
            letter = toupper(letter);
        }
        line.append(nextWord);

        if (column % 8 == 0) {
            std::cout << line << std::endl;
            line.clear();
        } else {
            line.append(" ");
        }
        column++;
    }
    if (!line.empty()) {
        std::cout << line << std::endl;
    }
    return 0;
}

