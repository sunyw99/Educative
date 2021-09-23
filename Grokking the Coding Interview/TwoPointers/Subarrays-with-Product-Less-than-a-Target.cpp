using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class SubarrayProductLessThanK {
   public:
    static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
        vector<vector<int>> result;
        // TODO: Write your code here
        double product = 1;
        int left = 0;
        for (int right = 0; right < arr.size(); right++) {
            product *= arr[right];
            while (product >= target && left < arr.size()) {
                product /= arr[left++];
            }
            deque<int> tempList;
            for (int i = right; i >= left; i--) {
                tempList.push_front(arr[i]);
                vector<int> resultVec;
                std::move(std::begin(tempList), std::end(tempList), std::back_inserter(resultVec));
                result.push_back(resultVec);
            }
        }
        return result;
    };