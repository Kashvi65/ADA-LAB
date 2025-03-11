int climbStairs(int n) {
    int frst = 0, next = 1;
    for (int i = 0; i < n; i++) {
        int temp = frst;
        frst = next;
        next = frst + temp;
    }
    return next;
}
