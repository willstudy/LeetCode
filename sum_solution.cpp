/*
不用循环、乘法求n个数的和
*/

class tmp{
    public:
    tmp(){++n;sum+=n;}
    static void Reset(){n=0;sum=0;}
    static unsigned int GetSum(){return sum;}
    static unsigned int n;
    static unsigned int sum;
};

unsigned int tmp::n=0;
unsigned int tmp::sum=0;

class Solution {
public:
    int Sum_Solution(int n) {
        tmp::Reset();
        tmp *a = new tmp[n];
        delete []a;
        a=NULL;
        return tmp::GetSum();
    }
};
