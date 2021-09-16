using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class ReplacingOnes {
   public:
    static int findLength(const vector<int>& arr, int k) {
        int maxLength = 0;
        // TODO: Write your code here
        int windowStart = 0, windowLength = 0;
        int replacedCount = 0;
        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
            if (arr[windowEnd] == 0) {
                replacedCount++;
            }
            windowLength++;
            while (replacedCount > k) {
                if (arr[windowStart] == 0)
                    replacedCount--;
                windowStart++;
                windowLength--;
            }
            maxLength = max(maxLength, windowLength);
        }
        return maxLength;
    }
};