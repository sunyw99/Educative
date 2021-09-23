using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
   public:
    static int remove(vector<int>& arr) {
        // TODO: Write your code here
        int nextDifferentNum = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[nextDifferentNum - 1] != arr[i]) {
                arr[nextDifferentNum] = arr[i];
                nextDifferentNum++;
            }
        }
        return nextDifferentNum;
    }
};
