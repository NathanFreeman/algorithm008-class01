#include <deque>
#include <vector>

using namespace std;

class SlideQueue {
    deque<pair<int, int>> s_queue;

public:
    void push(int val) {
        int count = 0; //判断多少个回合后被删
        while (!s_queue.empty() && s_queue.back().first < val) {
            count += s_queue.back().second + 1; // 第二个回合删除
            s_queue.pop_back();
        }
        s_queue.emplace_back(val, count);
    }

    int max() {
        return s_queue.front().first;
    }

    void pop() {
        if (s_queue.front().second > 0) {
            s_queue.front().second--; // 为了中间的能够撑过两个回合
            return;
        }
        s_queue.pop_front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        k = min(k, (int) nums.size());
        vector<int> max;
        SlideQueue queue;

        int i = 0;
        for (; i < k - 1; ++i) {   // 除了数组的第一个元素经过一次滑动后会马上删除，其余的元素是会在滑动窗口停留两次
            queue.push(nums[i]);
        }

        for (; i < nums.size(); ++i) {
            queue.push(nums[i]);
            max.push_back(queue.max());
            queue.pop();
        }
        return max;
    }
};