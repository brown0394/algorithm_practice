class Solution {
public:
    int maxDiff(int num) {
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

        int checkDeci = deci;
        int checkNum = num;
        int smallFirst = first;
        int adder = 0;
        while (checkDeci > 0)
        {
            int calc = checkNum / checkDeci;
            if ( calc > 0 && calc != first )
            {
                if ( first == 1 )
                {
                    smallFirst = calc;
                }
                else
                    adder = 1; 
                break;
            }
            checkNum %= checkDeci;
            checkDeci /= 10;
        }
        if (checkDeci == 0)
            adder = 1;

        unsigned int big = 9;
        unsigned int small = 1;
        int bigFirst = first;
        while (deci > 0)
        {
            big *= 10;
            small *= 10;
            int calc = num / deci;
            if ( calc != smallFirst)
                small += calc;
            else
                small += adder;

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