int fitBits(int x, int n) {
    return !((!!(x >> (n + ~0))) + (x >> (n + ~0)));
}
