using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
   public:
    static int findLength(const vector<char>& arr) {
        int maxLength = 0;
        // TODO: Write your code here
        int windowStart = 0, windowLength = 0;
        unordered_map<char, int> charFrequency;
        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
            charFrequency[arr[windowEnd]]++;
            windowLength++;
            while (charFrequency.size() > 2) {
                char windowStartChar = arr[windowStart];
                charFrequency[windowStartChar]--;
                if (charFrequency[windowStartChar] == 0)
                    charFrequency.erase(windowStartChar);
                windowLength--;
                windowStart++;
            }
            maxLength = maxLength > windowLength ? maxLength : windowLength;
        }
        return maxLength;
    }
};