using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation {
   public:
    static bool findPermutation(const string& str, const string& pattern) {
        // TODO: Write your code here
        int windowStart = 0;
        int matchedChar = 0;
        unordered_map<char, int> charCount;
        for (int i = 0; i < pattern.length(); i++) {
            charCount[pattern[i]]++;
        }
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char rightChar = str[windowEnd];
            if (charCount.find(rightChar) != charCount.end()) {
                charCount[rightChar]--;
                if (charCount[rightChar] == 0)
                    matchedChar++;
            }
            if (matchedChar == charCount.size())
                return true;
            if (windowEnd - windowStart + 1 >= pattern.length()) {
                char leftChar = str[windowStart];
                if (charCount.find(leftChar) != charCount.end()) {
                    if (charCount[leftChar] == 0)
                        matchedChar--;
                    charCount[leftChar]++;
                }
                windowStart++;
            }
        }
        return false;
    }
};