这周的学习我很认真的贯彻了上周的学习计划，不追求刷题的数目，而是追求刷题的质量，最近刷的都是一些中等题，比较难。但是每道题我都愿意花一两天的时间去吃透它，虽然效率有点低，但是我也是刚刚开始，以后会越来越好的。

1. 解码方式

这道题是一道动态规划提，很有意思，最重要的是找到DP方程，但是我这方面找DP方程不是很强，还需要练习。


    class Solution {
    public:
        int numDecodings(string s) {
            if ('0' == s[0]) { // 第一位是0根本不能分
                return 0;
            }
    
            int pre = 1, cur = 1;
            for (int i = 1; i < s.size(); i++) {
                int temp = cur;
                if (s[i] == '0') {
                    if (s[i - 1] == '1' || s[i - 1] == '2') { // s[i] == 0 当1或者2的时候，肯定有是可以分的情况
                        cur = pre;
                    } else {
                        return 0;  // 前面不是1或者2，不用看了
                    }
                 // 这里前面一位是1，肯定可以分，因为10 - 19都能解码，2的话就不行了，只能是1 - 6， 为什么不是0 - 6 呢，因为0是特殊情况，已经判断了
                } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                    cur = cur + pre; // 累加情况就行了
                }
                pre = temp;
            }
            return cur;
        }
    };
 
这里我觉得的动态规划方程就是每个s[i]的前一个字符作做对应的情况对比就是他的DP方程了。。


2. 任务调度器
这道题的题解我觉得leetcode已经说的很清楚了，我最后说一下最后为什么这么return。


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
 
maxCount - 1多少行，(n + 1) 就是多少列，这里(n + 1)是因为至少有(n + 1)任务，才不会有延时，就是ABCDEA, n = 3，中间至少得有4个，下一个A才不会延时。
(n + 1)在这里也代表了列数，count是有多少个数量最多的任务类型数，A有5个，B也有5个，A和B是最多的，此时count = 2，因为执行到最后，肯定是剩下A和B两个。