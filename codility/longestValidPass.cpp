int solution(string &S) {
    int alphabet = 0, num = 0;
    int maxLen = -1;
    int count = 0;
    for (int i = 0, size = S.size(); i < size; ++i) {
        if ((S[i] >= 'A' && S[i] <='Z') || (S[i] >= 'a' && S[i] <= 'z')) {
            ++alphabet;
            ++count;
        }
        else if (S[i] >= '0' && S[i] <= '9') {
            ++num;
            ++count;
        }
        else {
            if (S[i] != ' ') {
                while (i < size && S[i] != ' ') ++i;
            }
            else if (!(alphabet % 2) && (num % 2) && maxLen < count) maxLen = count;
            alphabet = 0;
            num = 0;
            count = 0;
        }
    }
    if (!(alphabet % 2) && (num % 2) && maxLen < count) maxLen = count;
    return maxLen;
}