class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        // 定义一个(m+1)x(n+1)的二维数组,并且初始化为0
        //用来存储子问题的解
        vector<vector<int>> path(m+1, vector<int>(n+1, 0));
        path[1][1] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (path[i-1][j]) //如果该路径存在
                    path[i][j] += path[i-1][j];
                if (path[i][j-1])
                    path[i][j] += path[i][j-1];
            }
        }
        return path[m][n];
    }
};
