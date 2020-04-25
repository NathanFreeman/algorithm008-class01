#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        if (nums.empty()) { return {}; }
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            if (map.find(target - nums[i]) != map.end()) {
                return {map[target - nums[i]], i};
            }
            map[target - nums[i]] = i;
        }
    }
};