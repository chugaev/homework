int conditional(int x, int y, int z) {
    x = !!x;
    x |= x << 1;
    x |= x << 2;
    x |= x << 4;
    x |= x << 8;
    x |= x << 16;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return (x & y) | (~x & z);
}
