#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueues(n, string(n, '.'));
        solveNQueens(res, nQueues, 0, n);
        return res;
    }

private:
    void solveNQueens(vector<vector<string>> &res, vector<string> &nQueues, int row, int &n) {
        if (row == n) {
            res.push_back(nQueues);
            return;
        }

        for (int col = 0; col != n; ++col) {
            if (isValid(nQueues, row, col, n)) {
                nQueues[row][col] = 'Q';
                solveNQueens(res, nQueues, row + 1, n);
                nQueues[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string> &nQueues, int row, int col, int &n) {
        for (int i = 0; i != row; ++i) {
            if (nQueues[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j > 0; --i, --j) {
            if (nQueues[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (nQueues[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};