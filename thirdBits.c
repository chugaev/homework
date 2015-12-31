int thirdBits() {
    int a = (0x24 << 24) | (0x92 << 16);
    int b = (0x49 << 8) | (0x24);
    return a|b;
}
