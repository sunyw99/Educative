using namespace std;

#include <iostream>
#include <vector>

class CircularArrayLoop {
   public:
    static bool loopExists(const vector<int>& arr) {
        // TODO: Write your code here
        int len = arr.size();
        for (int i = 0; i < len; i++) {
            bool isForward = arr[i] > 0;
            int slow = i;
            int fast = i;
            do {
                slow = nextIndex(arr, slow, isForward);
                fast = nextIndex(arr, fast, isForward);
                if (fast != -1)
                    fast = nextIndex(arr, fast, isForward);
            } while (slow != -1 && fast != -1 && slow != fast);
            if (slow != -1 && slow == fast)
                return true;
        }
        return false;
    }

   private:
    static int nextIndex(const vector<int>& arr, int currentIndex, bool isForward) {
        int nextIndex = (currentIndex + arr[currentIndex]) % arr.size();
        if (nextIndex < 0)
            nextIndex += arr.size();
        bool isNextForward = arr[nextIndex] > 0;
        if (nextIndex == currentIndex || isNextForward != isForward)
            return -1;
        return nextIndex;
    }
};

int main(int argc, char* argv[]) {
    cout << CircularArrayLoop::loopExists(vector<int>{1, 2, -1, 2, 2}) << endl;
    cout << CircularArrayLoop::loopExists(vector<int>{2, 2, -1, 2}) << endl;
    cout << CircularArrayLoop::loopExists(vector<int>{2, 1, -1, -2}) << endl;
}
