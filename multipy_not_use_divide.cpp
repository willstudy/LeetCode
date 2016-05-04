/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法

思路：
顺序保存1, 1*a[0], 1*a[0]*a[1], ...., a[0]*...*a[n-2]的值
逆序保存 1, 1*a[n-1], 1*a[n-1]*a[n-2], ..., 1*a[n-1]*a[n-2]*...*a[2]

然后两者相乘就行了
*/

class Solution {
public:
  vector<int> multiply(const vector<int>& A) {
  vector<int> result;
  int size = A.size();
  if( size == 0 )
    return result;
  result.push_back(1);
  for(int i=0;i<sz-1;i++)
   result.push_back(result.back()*A[i]);
  int tmp=1;
  for(int i=size-1;i>=0;i--)
  {
   result[i]=result[i]*tmp;
   tmp=tmp*A[i];
  }
  return result;
  }
};
