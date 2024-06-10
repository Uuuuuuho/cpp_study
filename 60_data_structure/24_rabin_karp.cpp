#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const int prime = 101; // prime number used for hashing

int hashString(const string& str, int len) {
    int hash = 0;
    for (int i = 0; i < len; i++) {
        hash += str[i] * pow(prime, i);
    }
    return hash;
}

void search(const string& text, const string& pattern) {
    int patternHash = hashString(pattern, pattern.length());
    int textHash = hashString(text, pattern.length());
    for (int i = 0; i <= text.length() - pattern.length(); i++) {
        if (patternHash == textHash) {
            int j;
            for (j = 0; j < pattern.length(); j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == pattern.length()) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < text.length() - pattern.length()) {
            textHash = prime * (textHash - text[i] * pow(prime, 0)) + text[i + pattern.length()] * pow(prime, pattern.length() - 1);
        }
    }
}

int main() {
    string text = "ABCABCDABABCDABCDABDE";
    string pattern = "ABCDABD";
    search(text, pattern);
    return 0;
}
