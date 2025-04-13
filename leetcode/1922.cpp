class Solution {
    long long getPow(long long n, int x)
    {
        if ( n == 1 )
            return x;
        if ( n == 0 )
            return 1;
        long long val = getPow(n >> 1, x);

        if (n % 2 == 1)
            return (((val * val) % 1000000007) * x) % 1000000007;
        return (val * val) % 1000000007;
    }
public:
    int countGoodNumbers(long long n) {
        long long half = n >> 1;
        long long a = getPow(half, 4);
        long long b = 0;
        if (n % 2 == 1)
            b = getPow(half + 1, 5);
        else
            b = getPow(half, 5);
        return (a * b) % 1000000007;
    }
};