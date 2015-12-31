int logicalShift(int x, int n) {
    int a = 1 << 31;
    int b = a & x;
    b >>= 31;
    b &= 1;
    b <<= (31  + (~n + 1));
    x &= ~a;
    x >>= n;
    return x | b;
}

