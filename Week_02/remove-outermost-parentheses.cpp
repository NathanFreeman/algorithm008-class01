#include <string>
using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        int opened = 0;
        string res;
        // (()()) 最外面的 ( 定位为0
        // 每次加1，加到2之后1，就会发现最外面的()一定是0和1，里面的括号是1,2
        for(char c : S) {
            if(c == '(' && opened++ > 0) res +=c;
            if(c == ')' && opened-- > 1) res +=c;
        }
        return res;
    }
};

