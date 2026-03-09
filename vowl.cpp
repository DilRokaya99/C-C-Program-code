#include <iostream>
#include <cstring>

bool isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void countVowelsInWords(const char* text) {
    if (text == nullptr || *text == '\0') {
        std::cout << "Invalid input." << std::endl;
        return;
    }

    while (*text) {
        int vowelCount = 0;
        while (*text && !isspace(*text)) {
            if (isVowel(*text)) {
                vowelCount++;
            }
            text++;
        }

        while (*text && isspace(*text)) {
            text++;
        }

        if (vowelCount > 0) {
            std::cout << "Word contains " << vowelCount << " vowel(s)." << std::endl;
        }
    }
}

int main() {
    const char* inputText = "This is a sample text with some words.";

    countVowelsInWords(inputText);

    return 0;
}
