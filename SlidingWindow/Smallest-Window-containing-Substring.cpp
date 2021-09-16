using namespace std;

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class MinimumWindowSubstring {
   public:
    static string findSubstring(const string& str, const string& pattern) {
        // TODO: Write your code here
        int windowStart = 0;
        int minStart = 0, minLength = str.length() + 1;  //注意minLength的初始化要额外+1，以应对“不存在符合条件substr”的case
        int matchedCount = 0;
        unordered_map<char, int> charCount;
        for (auto chr : pattern) {
            charCount[chr]++;
        }
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char rightChar = str[windowEnd];
            if (charCount.find(rightChar) != charCount.end()) {
                charCount[rightChar]--;
                if (charCount[rightChar] >= 0)
                    matchedCount++;
            }
            while (matchedCount == pattern.length()) {
                if (windowEnd - windowStart + 1 < minLength) {
                    minLength = windowEnd - windowStart + 1;
                    minStart = windowStart;
                }
                char leftChar = str[windowStart];
                if (charCount.find(leftChar) != charCount.end()) {
                    if (charCount[leftChar] >= 0)
                        matchedCount--;
                    charCount[leftChar]++;
                }
                windowStart++;
            }
        }
        return minLength > str.length() ? "" : str.substr(minStart, minLength);
    }
};
