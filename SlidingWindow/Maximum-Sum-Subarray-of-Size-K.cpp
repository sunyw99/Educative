using namespace std;
#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
   public:
    static int findMaxSumSubArray(int k, const vector<int>& arr) {
        int maxSum = 0;
        // TODO: Write your code here
        int windowSum = 0, windowStart = 0;
        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
            windowSum += arr[windowEnd];
            if (windowEnd == windowStart + k) {
                windowSum -= arr[windowStart];
                windowStart++;
                maxSum = maxSum > windowSum ? maxSum : windowSum;
            }
        }
        return maxSum;
    }
};
