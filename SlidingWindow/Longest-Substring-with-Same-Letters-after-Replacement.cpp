using namespace std;

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
   public:
    static int findLength(const string& str, int k) {
        int maxLength = 0;
        // TODO: Write your code here
        int windowStart = 0, windowLength = 0;
        unordered_map<char, int> charFreq;
        int maxRepeatCount = 0;
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char windowEndChar = str[windowEnd];
            charFreq[windowEndChar]++;
            windowLength++;
            maxRepeatCount = max(maxRepeatCount, charFreq[windowEndChar]);
            while (windowLength - maxRepeatCount > k) {
                char windowStartChar = str[windowStart];
                charFreq[windowStartChar]--;
                windowLength--;
                windowStart++;
            }
            maxLength = max(maxLength, windowLength);
        }
        return maxLength;
    }
};