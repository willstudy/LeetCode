/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

思路：
同矩阵遍历字符串思路一致，排除一些无法访问的点的时候要注意一些情况。
*/
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *flag = new bool[rows*cols];//记录是否已经访问过
        memset(flag, false, rows*cols*sizeof(bool));//初始化
        int count = 0;//统计访问总数
        movingCount(threshold, rows, cols, flag, 0, 0, count);//左上角开始
        return count;
    }
    void movingCount(int threshold, int rows, int cols, bool* flag,
                     int i, int j, int& count){
        int index = i * cols + j;
        if(i < 0 || j < 0 || i >= rows || j >= cols || flag[index])
            return;//边界判断
        int sum = getSum(i) + getSum(j);
        if(sum > threshold)//阈值判断
            return;
        flag[index] = true;//记录该节点
        ++count;
        movingCount(threshold, rows, cols, flag, i-1, j, count);//递归访问
        movingCount(threshold, rows, cols, flag, i+1, j, count);//上下左右
        movingCount(threshold, rows, cols, flag, i, j-1, count);
        movingCount(threshold, rows, cols, flag, i, j+1, count);
        return;
    }
    int getSum(int n){//数字各位求和
        int sum = 0;
        for(int m = 1; m <= n; m *= 10){
            sum += (n/m) % 10;
        }
        return sum;
    }
};
