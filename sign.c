int sign(int x) {
    return (x >> 31) | !!(x & (~0));
}
