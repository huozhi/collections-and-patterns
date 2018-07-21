vector<int> ufs; // union fint set

void init(int N) {
    ufs.resize(N);
    for (int i = 0; i < N; i++)
        ufs[i] = i;
}

void removeNum(int x) {
    if (x < 0 || x >= ufs.size()) return;
    ufs[x] = query(x + 1);
}

int query(int x) {
    if (x < 0 || x >= ufs.size()) return -1;
    if (ufs[x] == x || ufs[x] == -1)
        return ufs[x];
    int next = query(ufs[x]);
    ufs[x] = next;
    return next;
}
