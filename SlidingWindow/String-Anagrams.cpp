using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams {
   public:
    static vector<int> findStringAnagrams(const string& str, const string& pattern) {
        vector<int> resultIndices;
        // TODO: Write your code here
        int windowStart = 0;
        int matchedCount = 0;
        unordered_map<char, int> charCount;
        for (auto chr : pattern) {
            charCount[chr]++;
        }
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char rightChar = str[windowEnd];
            if (charCount.find(rightChar) != charCount.end()) {
                charCount[rightChar]--;
                if (charCount[rightChar] == 0)
                    matchedCount++;
            }
            if (matchedCount == charCount.size()) {
                resultIndices.push_back(windowStart);
            }
            if (windowEnd - windowStart + 1 >= pattern.length()) {
                char leftChar = str[windowStart];
                if (charCount.find(leftChar) != charCount.end()) {
                    if (charCount[leftChar] == 0)
                        matchedCount--;
                    charCount[leftChar]++;
                }
                windowStart++;
            }
        }
        return resultIndices;
    }
};