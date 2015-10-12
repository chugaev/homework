int addOk(int a, int b) {
	int s = a + b;
	return !((a >> 31 ^ s >> 31) & (b >> 31 ^ s >> 31));
}
