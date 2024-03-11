int solution(int N) {
    // Implement your solution here
    int check = 1;
    bool open = false;
    int count = 0, max = 0;
    for (int i = 0; i < 31; ++i) {
        if (check & N) {
            if (open) {
                if (max < count) max = count;
                count = 0;
            }
            else open = true;
        }
        else {
            if (open) ++count;
        }
        check <<= 1;
    }
    return max;
}