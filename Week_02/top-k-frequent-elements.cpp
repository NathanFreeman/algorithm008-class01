#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        // 先做频率统计
        unordered_map<int, int> counts;
        for (auto num : nums) {
            counts[num]++;
        }

        //做优先队列
        priority_queue<pair<int, int>> pq;
        // 存储结果
        vector<int> result;
        for (auto it = counts.begin(); it != counts.end(); it++) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > counts.size() - k) {
                // 此时优先队里面已经满了，需要弹出一些数据
                result.push_back(pq.top().second);
                pq.pop();
            }
        }
        return result;
    }
};

