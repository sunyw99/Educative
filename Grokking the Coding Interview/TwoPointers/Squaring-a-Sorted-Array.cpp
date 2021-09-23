using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
   public:
    static vector<int> makeSquares(const vector<int>& arr) {
        int n = arr.size();
        vector<int> squares(n);
        // TODO: Write your code here
        int left = 0, right = n - 1;
        int squareIndex = n - 1;
        while (left <= right) {
            int leftSquare = arr[left] * arr[left];
            int rightSquare = arr[right] * arr[right];
            if (leftSquare > rightSquare) {
                squares[squareIndex--] = leftSquare;
                left++;
            } else {
                squares[squareIndex--] = rightSquare;
                right--;
            }
        }
        return squares;
    }
};
