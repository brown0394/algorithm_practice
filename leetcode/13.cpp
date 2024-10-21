class Solution {
public:
    int romanToInt(string s) {
        int val = 0;
        char last = 0;
        int lastIdx = 0;
        for (int i = 0, len = s.size(); i < len; ++i) {
            switch (s[i]) {
                case 'I' : {++val; last = 'I'; lastIdx = i; break;}
                case 'V' : {val += 5; if (last == 'I') {val -= 2;} break;}
                case 'X' : {
                    val += 10; 
                    if (last == 'I') {
                        val -= 2;
                    } else {
                        last = 'X';
                        lastIdx = i;
                    }
                    break;
                }
                case 'L' : {val += 50; if (last == 'X') {val -= 20;} break;}
                case 'C' : {
                    val += 100; 
                    if (last == 'X') {
                        val -= 20;
                    } else {
                        last = 'C';
                        lastIdx = i;
                    }
                    break;
                }
                case 'D' : {val += 500; if (last == 'C') {val -= 200;} break;}
                case 'M' : {val += 1000; if (last == 'C') {val -= 200;}break;}
            }
            if (lastIdx != i) {
                last = 0;
                lastIdx = i;
            }
        }
        return val;
    }
};