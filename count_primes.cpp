/*
Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
int countPrimes(int n) {
    bool prime[n+2]={0};
    int i,k,count=0;;
    for(i=2;i<n;i++){
        if(prime[i])
            continue;
        count++;
        for(k=1;(k*i)<=n;k++){
            prime[k*i]=1;
        }
    }
    return count;
}
};

/*
Miller-Rabin(n):
	If (n <= 2) Then
		If (n == 2) Then
			Return True
		End If
		Return False
	End If

	If (n mod 2 == 0) Then
		// n为非2的偶数，直接返回合数
		Return False
	End If

	// 我们先找到的最小的a^u，再逐步扩大到a^(n-1)

	u = n - 1; // u表示指数
	while (u % 2 == 0)
		u = u / 2
	End While // 提取因子2

	For i = 1 .. S // S为设定的测试次数
		a = rand_Number(2, n - 1) // 随机获取一个2~n-1的数a
		x = a^u % n
		While (u < n)
			// 依次次检查每一个相邻的 a^u, a^2u, a^4u, ... a^(2^k*u)是否满足二次探测定理
			y = x^2 % n
			If (y == 1 and x != 1 and x != n - 1)	// 二次探测定理
				// 若y = x^2 ≡ 1(mod n)
				// 但是 x != 1 且 x != n-1
				Return False
			End If
			x = y
			u = u * 2
		End While
		If (x != 1) Then	// Fermat测试
			Return False
		End If
	End For
	Return True
值得一提的是，Miller-Rabin每次测试失误的概率是1/4；进行S次后，失误的概率是4^(-S)。

小Hi：那么小Ho，你能计算出这个算法的时间复杂度么？

小Ho：恩，每一次单独的MR测试，需要O(log n)的时间。一共要进行S次MR测试，也就是O(Slog n)。

小Hi：没错，这样就能够在很短的时间内完成质数的测试了。当然如果你还是不放心，可以把S的值设定的更高一点。

小Ho：好！这样就能够顺利的找到大质数了。
*/
const int testnum = 8; //随机算法判定次数，一般8~10就够了
// 计算ret = (a*b)%c a,b,c < 2^63

long long mult_mod (long long a,long long b,long long mod)
{
    a %= mod;
    b %= mod;
    long long ans = 0;
    long long temp = a;

    while (b)
    {
        if (b & 1)
        {
            ans += temp;
            if (ans > mod)
                ans -= mod;//直接取模慢很多
        }

        temp <<= 1;
        if (temp > mod)
            temp -= mod;
        b >>= 1;
    }

return ans;
}

long long pow_mod (long long a,long long n,long long mod)
{
    long long ans = 1;
    long long temp = a % mod;
    while (n)
    {
        if (n & 1)
            ans = mult_mod (ans, temp, mod);

        temp = mult_mod (temp, temp, mod);
        n >>= 1;
    }

return ans;
}

// 通过 a^(n-1)=1(mod n)来判断n是不是素数
// n-1 = x*2^t 中间使用二次判断
// 是合数返回true, 不一定是合数返回false
bool check (long long a, long long n, long long x, long long t)
{
    long long ans = pow_mod (a, x, n);
    long long last = ans;

    for(int i = 1; i <= t; i++)
    {
        ans = mult_mod (ans, ans, n);
        if(ans == 1 && last != 1 && last != n - 1)
            return true;//合数

        last = ans;
    }

    if(ans != 1)
        return true;

    else
        return false;
}

//**************************************************
// Miller_Rabin算法
// 是素数返回true,(可能是伪素数)
// 不是素数返回false
//**************************************************
bool Miller_Rabin (long long n)
{
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    if ((n&1) == 0)
        return false;//偶数

    long long x = n - 1;
    long long t = 0;

    while ((x&1) == 0)
    {
        x >>= 1; t++;
    }

    srand (time (NULL));

    for (int i = 0; i < testnum; i++)
    {
        long long a = rand () % (n - 1) + 1;
        if (check (a, n, x, t))
            return false;
    }

return true;
}

int main()
{
  int t;
	scanf ("%d", &t);
	while (t--)
	{
	  LL n;
	  scanf ("%lld", &n);
	  if (Miller_Rabin (n)) puts ("Yes");
	  else puts ("No");
	}
    return 0;
}
