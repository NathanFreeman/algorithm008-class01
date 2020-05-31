#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        int len = tasks.size();
        vector<int> map(26, 0);
        for (auto task : tasks) {
            map[task - 'A']++;
        }
        sort(map.begin(), map.end());

        int time = 0;
        while (map[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (0 == map[25]) {
                    break;
                }
                if (i < 26 && map[25 - i] > 0) {
                    map[25 - i]--;
                }
                time++;
                i++;
            }
            sort(map.begin(), map.end());
        }
        return time;
    }
};

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        int len = tasks.size();
        int count = 0, maxCount = 0;
        vector<int> map(26, 0);
        for (auto task : tasks) {
            map[task - 'A']++;
            if (map[task - 'A'] > maxCount) {
                maxCount = map[task - 'A'];
                count = 1;
            } else if (map[task - 'A'] == maxCount) {
                count++;
            }
        }
        return max(len, (maxCount - 1) * (n + 1) + count);
    }
};
