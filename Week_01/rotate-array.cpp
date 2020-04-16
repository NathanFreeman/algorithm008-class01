#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int len = nums.size();
        k %= len;
        reverse(&nums[0], &nums[len]);
        reverse(&nums[0], &nums[k]);
        reverse(&nums[k], &nums[len]);
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    Solution solution;
    solution.rotate(nums,k);
    for (int num : nums){
        cout << num << endl;
    }
    return 0;
}

