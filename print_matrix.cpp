/*
    顺时针打印二维数组

    思想：用左上和右下的坐标定位出一次要旋转打印的数据，一次旋转打印结束后，
    往对角分别前进和后退一个单位。提交代码时，主要的问题出在没有控制好后两个
    for循环，需要加入条件判断，防止出现单行或者单列的情况。
 */
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> res;

        // 输入的二维数组非法，返回空的数组
        if (row == 0 || col == 0)  return res;

        // 定义四个关键变量，表示左上和右下的打印范围
        int left = 0, top = 0, right = col - 1, bottom = row - 1;
        while (left <= right && top <= bottom)
        {
            // left to right
            for (int i = left; i <= right; ++i)  res.push_back(matrix[top][i]);
            // top to bottom
            for (int i = top + 1; i <= bottom; ++i)  res.push_back(matrix[i][right]);
            // right to left
            if (top != bottom)
            for (int i = right - 1; i >= left; --i)  res.push_back(matrix[bottom][i]);
            // bottom to top
            if (left != right)
            for (int i = bottom - 1; i > top; --i)  res.push_back(matrix[i][left]);
            left++,top++,right--,bottom--;
        }
        return res;
    }
};
