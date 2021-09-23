using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class ShortestWindowSort {
   public:
    static int sort(const vector<int>& arr) {
        // TODO: Write your code here
        int i = 0, j = arr.size() - 1;
        while (i < arr.size() - 1 && arr[i] <= arr[i + 1]) {
            i++;
        }
        if (i == arr.size() - 1) {
            return 0;
        }
        while (j > 0 && arr[j] >= arr[j - 1]) {
            j--;
        }

        // find the maximum and minimum of the subarray
        int subarrayMax = numeric_limits<int>::min(), subarrayMin = numeric_limits<int>::max();
        for (int k = i; k <= j; k++) {
            subarrayMax = max(subarrayMax, arr[k]);
            subarrayMin = min(subarrayMin, arr[k]);
        }
        while (i > 0 && arr[i - 1] > subarrayMin) {
            i--;
        }
        while (j < arr.size() - 1 && arr[j + 1] < subarrayMax) {
            j++;
        }

        return j - i + 1;
    }
};
