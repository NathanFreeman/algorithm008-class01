#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (0 != nums[i]) {
                nums[pos++] = nums[i];
            }
        }

        for (int i = pos; i < nums.size(); i++) {
            nums[i] = 0;
        }

    }
};

int main() {
    vector<int> nums = {0,10,9,2,0,0,1,2};
    Solution solution;
    solution.moveZeroes(nums);
    for(int &num : nums) {
        cout << num << endl;
    }
}

