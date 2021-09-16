using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
   public:
    static int findLength(const string& str, int k) {
        int maxLength = 0;
        // TODO: Write your code here
        int windowStart = 0, windowLength = 0;
        unordered_map<char, int> charFrequency;
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            charFrequency[str[windowEnd]]++;
            windowLength++;
            while (charFrequency.size() > k) {
                char windowStartChar = str[windowStart];
                charFrequency[windowStartChar]--;
                if (charFrequency[windowStartChar] == 0)
                    charFrequency.erase(windowStartChar);
                windowStart++;
                windowLength--;
            }
            maxLength = maxLength > windowLength ? maxLength : windowLength;
        }
        return maxLength;
    }
};
