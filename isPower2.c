int isPower2(int x) {
    return (!(x & (x + ~0)) | !x) & !!(x << 1);
}
