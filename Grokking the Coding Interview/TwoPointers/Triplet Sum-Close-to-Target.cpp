using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class TripletSumCloseToTarget {
   public:
    static int searchTriplet(vector<int>& arr, int targetSum) {
        // TODO: Write your code here
        sort(arr.begin(), arr.end());
        int smallestDiff = numeric_limits<int>::max();
        for (int i = 0; i < arr.size() - 2; i++) {
            int left = i + 1, right = arr.size() - 1;
            while (left < right) {
                int currentDiff = targetSum - arr[i] - arr[left] - arr[right];
                if (currentDiff == 0) {
                    return targetSum;
                }
                if (abs(currentDiff) < abs(smallestDiff) || (abs(currentDiff) == abs(smallestDiff) && currentDiff > smallestDiff)) {
                    smallestDiff = currentDiff;
                }
                if (currentDiff > 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return targetSum - smallestDiff;
    }
};
