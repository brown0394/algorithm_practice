int solution(int X, int Y, int D) {
    // Implement your solution here
    if (X == Y) return 0;
    int target = Y - X;
    int jumps = target / D;
    if (target % D) ++jumps;
    return jumps;
}