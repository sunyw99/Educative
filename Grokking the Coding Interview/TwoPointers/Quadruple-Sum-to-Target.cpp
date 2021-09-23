using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class QuadrupleSumToTarget {
   public:
    static vector<vector<int>> searchQuadruplets(vector<int>& arr, int target) {
        vector<vector<int>> quadruplets;
        // TODO: Write your code here
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 3; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < arr.size() - 2; j++) {
                if (j > i + 1 && arr[j] == arr[j - 1]) {
                    continue;
                }
                searchPairs(arr, target, i, j, quadruplets);
            }
        }
        return quadruplets;
    }

   private:
    static void searchPairs(vector<int>& arr, int target, int i, int j, vector<vector<int>>& quadruplets) {
        int left = j + 1, right = arr.size() - 1;
        while (left < right) {
            int currentSum = arr[i] + arr[j] + arr[left] + arr[right];
            if (currentSum == target) {
                quadruplets.push_back({arr[i], arr[j], arr[left], arr[right]});
                left++;
                right--;
                while (left < right && arr[left] == arr[left - 1])
                    left++;
                while (left < right && arr[right] == arr[right + 1])
                    right--;
            } else if (currentSum > target)
                right--;
            else
                left++;
        }
    }
};
