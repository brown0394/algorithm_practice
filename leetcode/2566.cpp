class Solution {
public:
    int minMaxDifference(int num) {

        int deci = 100000000;
        int first = 0;
        while (deci > 0 && first == 0)
        {
            first = num / deci;
            num %= deci;
            deci /= 10;
        }
        if (first == 0)
            return 0;
        
        unsigned int big = 9;
        unsigned int small = 0;
        int bigFirst = first;
        while (deci > 0)
        {
            big *= 10;
            small *= 10;
            int calc = num / deci;
            if ( calc != first)
                small += calc;

            if ( calc == bigFirst )
                big += 9;
            else
            {
                if ( bigFirst == 9 )
                {
                    bigFirst = calc;
                    big += 9;
                }
                else
                    big += calc;
            }
            num = num % deci;
            deci /= 10;
        }
        return big - small;
    }
};