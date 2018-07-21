/**

有2个大小为n和m的有序数组（升序）a和b，实现2个函数arrayUnion和arrayIntersect计算它们的并集和交集，结果也必须有序。

结果集中元素不重复

提示：时间复杂度O(n+m)，空间复杂度O(1)。

*/

vector<int> arrayUnion(vector<int> &a, vector<int> &b) {
    vector<int> result;
    auto first = a.begin(), second = b.begin();
    while (first != a.end() || second != b.end()) {
        int value;
        if (first == a.end())
            value = *second++;
        else if (second == b.end())
            value = *first++;
        else
            value = (*first < *second) ? *first++ : *second++;
        if (result.empty() || result.back() != value)
            result.push_back(value);
    }
    return result;
}

vector<int> arrayIntersect(vector<int> &a, vector<int> &b) {
    vector<int> result;
    auto first = a.begin(), second = b.begin();
    while (first != a.end() && second != b.end()) {
        if (*first < *second) {
            ++first;
        }
        else if (*second < *first) {
            ++second;
        }
        else {
            if (result.empty() || *first != result.back())
                result.push_back(*first);
            ++first; ++second;
        }
    }
    return result;
}