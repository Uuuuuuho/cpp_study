#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPrefixTable(const string& pattern) {
    vector<int> prefixTable(pattern.length(), 0);
    int i = 1, j = 0;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[j]) {
            prefixTable[i] = j + 1;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = prefixTable[j - 1];
            } else {
                prefixTable[i] = 0;
                i++;
            }
        }
    }
    return prefixTable;
}

void search(const string& text, const string& pattern) {
    vector<int> prefixTable = getPrefixTable(pattern);
    int i = 0, j = 0;
    while (i < text.length()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        if (j == pattern.length()) {
            cout << "Pattern found at index " << i - j << endl;
            j = prefixTable[j - 1];
        } else if (i < text.length() && text[i] != pattern[j]) {
            if (j != 0) {
                j = prefixTable[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABCABCDABABCDABCDABDE";
    string pattern = "ABCDABD";
    search(text, pattern);
    return 0;
}
