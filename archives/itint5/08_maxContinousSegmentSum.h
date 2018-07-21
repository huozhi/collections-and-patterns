/*

有一个包含n个元素的数组arr，计算最大的子段和（允许空段）

*/

int maxConsSum(const vector<int> &arr) {
    if (arr.empty()) return 0;
    int maxv = 0, curv = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        if (curv > 0)
            curv += arr[i];
        else
            curv = arr[i];
        maxv = max(maxv, curv);
    }
    return maxv;
}