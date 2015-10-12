int fitBits(int x, int n) {
	int mask = ~(~0 << (n + ~0));
	return !(((x & mask) ^ x) & ((~x & mask) ^ ~x));
}
