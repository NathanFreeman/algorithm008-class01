#include <deque>
#include <vector>

using namespace std;

class Monoquque {
    deque<pair<int, int>> m_deque;

public:
    void push(int val) {
        int count = 0;
        while (!m_deque.empty() && m_deque.back().first < val) {
            count += m_deque.back().second + 1;
            m_deque.pop_back();
        }
        m_deque.emplace_back(val, count);
    }

    int max() {
        return m_deque.front().first;
    }

    void pop() {
        if (m_deque.front().second > 0) {
            m_deque.front().second--;
            return;
        }
        m_deque.pop_front();
    }
};

class Solution {
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> results;
        Monoquque mq;

        k = min(k, (int) nums.size());
        int i = 0;

        for (; i < k; ++i) {
            mq.push(nums[i]);
            results.push_back(mq.max());
            mq.pop();
        }
        return results;
    }
};