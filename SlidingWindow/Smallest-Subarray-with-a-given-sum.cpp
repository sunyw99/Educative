using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
   public:
    static int findMinSubArray(int S, const vector<int>& arr) {
        // TODO: Write your code here
        int minSize = arr.size();
        int windowStart = 0, windowEnd = 0;
        if (arr.size() == 0)
            return -1;
        int windowSum = arr[0], windowSize = 1;
        while (windowEnd < arr.size()) {
            if (windowSum >= S) {
                minSize = minSize < windowSize ? minSize : windowSize;
                windowSum -= arr[windowStart];
                windowStart++;
                windowSize--;
            } else {
                windowSum += arr[++windowEnd];
                windowSize++;
            }
        }
        return minSize;
    }
};