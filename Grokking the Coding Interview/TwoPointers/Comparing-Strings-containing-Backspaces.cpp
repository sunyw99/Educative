using namespace std;

#include <iostream>
#include <string>

class BackspaceCompare {
   public:
    static bool compare(const string& str1, const string& str2) {
        // TODO: Write your code here
        int i = str1.length() - 1, j = str2.length() - 1;
        int backspaceCount = 0;
        while (i >= 0 && j >= 0) {
            while (i >= 0 && str1[i] == '#') {
                i--;
                backspaceCount++;
            }
            i -= backspaceCount;
            backspaceCount = 0;
            while (j >= 0 && str2[j] == '#') {
                j--;
                backspaceCount++;
            }
            j -= backspaceCount;
            backspaceCount = 0;
            if (str1[i] != str2[j]) {
                return false;
            } else {
                i--;
                j--;
            }
        }
        if (i == -1 && j == -1)
            return true;
        else
            return false;
    }
};
