#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        const int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        vector<int> newDigits = digits;
        newDigits.insert(newDigits.begin(), 1);
        return newDigits;
    }
};

int main() {
    vector<int> digits = {9};
    Solution solution;
    vector<int> newDigits = solution.plusOne(digits);

    for (int &digit : newDigits) {
        cout << digit << endl;
    }
    return 0;
}
