#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;

        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                nums[i + 1] = nums[j];
                i++;
            }
        }

        return i + 1;
    }
};

int main() {
    int len;

    Solution solution;
    vector<int> num = {1,2,3,3,4,5};
    len = solution.removeDuplicates(num);

    cout << len << endl;
    return 0;

}