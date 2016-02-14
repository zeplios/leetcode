// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int search(int start, int end) {
    if (start + 1 == end) {
        return end;
    }
    int mid = (start & end) + ((start ^ end) >> 1);
    if (isBadVersion(mid)) {
        return search(start, mid);
    } else {
        return search(mid, end);
    }
}

int firstBadVersion(int n) {
    if (isBadVersion(1)) {
        return 1;
    }
    return search(1, n);
}
