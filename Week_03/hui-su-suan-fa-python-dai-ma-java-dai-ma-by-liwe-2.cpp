#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> sol;
    vector<int> nums;
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.empty()) { return {}; }
        if (nums.size() == 1) { return {{nums[0]}}; }
        sort(nums.begin(), nums.end());
        this->nums = nums;
        vector<bool> used(nums.size(), false);
        dfs(used);
        return res;
    }

private:
    void dfs(vector<bool> used) {
        if (sol.size() == nums.size()) {
            res.push_back(sol);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if(used[i] || (i>0 && !used[i-1] && nums[i] == nums[i-1])){//用过了
                continue;
            }
            sol.push_back(nums[i]);
            used[i] = true;
            dfs(used);
            sol.pop_back();
            used[i] = false;
        }

    }
};

