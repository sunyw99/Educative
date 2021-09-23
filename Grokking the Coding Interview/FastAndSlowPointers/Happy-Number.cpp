using namespace std;

#include <iostream>

class HappyNumber {
   public:
    static bool find(int num) {
        // TODO: Write your code here
        int slow = num;
        int fast = num;
        while (fast != 1) {
            slow = calculate(slow);
            fast = calculate(calculate(fast));
            if (fast == slow)
                return false;
        }
        return true;
    }

   private:
    static int calculate(int num) {
        return num / 10 * num / 10 + num % 2 * num % 2;
    }
};

int main(int argc, char* argv[]) {
    cout << HappyNumber::find(23) << endl;
    cout << HappyNumber::find(12) << endl;
}
