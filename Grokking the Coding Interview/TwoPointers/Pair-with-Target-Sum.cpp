using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class PairWithTargetSum {
   public:
    static pair<int, int> search(const vector<int>& arr, int targetSum) {
        // TODO: Write your code here
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int currentSum = left + right;
            if (currentSum < targetSum) {
                left++;
            } else if (currentSum > targetSum) {
                right--;
            } else
                return make_pair(left, right);
        }
        return make_pair(-1, -1);
    }
};

//Another approach using unordered_map:

class PairWithTargetSum {
   public:
    static pair<int, int> search(const vector<int>& arr, int targetSum) {
        // TODO: Write your code here
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); i++) {
            if (map.find(targetSum - arr[i]) != map.end())
                return make_pair(map[targetSum - arr[i]], i);
            else
                map[arr[i]] = i;
        }
        return make_pair(-1, -1);
    }
};