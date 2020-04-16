#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = 0, maxRight = 0;
        int left = 0, right = height.size() - 1;
        int result = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                }else{
                    result += maxLeft - height[left];
                }
                left++;
            }else{
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                }else{
                    result += maxRight - height[right];
                }
                right--;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution solution;
    cout << solution.trap(height) << endl;
    return 0;
}