using namespace std;

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
   public:
    static int findLength(const string& str) {
        int maxLength = 0;
        // TODO: Write your code here
        int windowStart = 0;
        unordered_map<int, char> charLastPos;
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char windowEndChar = str[windowEnd];
            if (charLastPos.find(windowEndChar) != charLastPos.end()) {
                windowStart = max(windowStart, charLastPos[windowEndChar] + 1);
            }
            charLastPos[windowEndChar] = windowEnd;
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};