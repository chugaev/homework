int endianCheck() {
	union {
		int value;
		char bytes[4];
    	} test;
	test.value = 0x1;
	return test.bytes[0];
}
