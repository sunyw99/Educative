using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
   public:
    static vector<vector<int>> searchTriplets(vector<int>& arr) {
        vector<vector<int>> triplets;
        // TODO: Write your code here
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 2; i++) {
            int j = i + 1, k = arr.size() - 1;
            while (j < k) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    triplets.push_back({arr[i], arr[j], arr[k]});
                    j++;
                    k--;
                } else if (arr[i] + arr[j] + arr[k] < 0)
                    j++;
                else
                    k--;
            }
        }
        return triplets;
    }
};
