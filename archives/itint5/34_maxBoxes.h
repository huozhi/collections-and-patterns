/*

有n块积木，每块积木有体积vol和重量weight两个属性，用二元组(vol, weight)表示。
积木需要搭成竖直的塔状，上面积木的体积和重量必须都比它下面的积木小。问最多可以搭多少个积木。

样例：

有7个积木boxes:
    [(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110), (80, 12)]
最多可以搭6个积木，从上到下分别为：
    (56, 90), (60, 95), (65, 100), (68, 110), (70, 150), (75, 190)

所以函数应该返回6。

*/

struct Box {
  int vol, weight;
};

struct cmp {
    bool operator() (const Box& a, const Box& b) {
        if (a.vol == b.vol) return a.weight < b.weight;
        return a.vol < b.vol
    }
};

int maxBoxes(vector<Box> &boxes) {
    if (boxes.empty()) return 0;
    sort(boxes.begin(), boxes.end(), cmp());

    int cnt = 1;
    int n = boxes.size();
    int lis[n]; // longest increasing sequence
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (boxes[i].vol > boxes[j].vol && boxes[i].weight > boxes[j].weight) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        cnt = max(cnt, lis[i]);
    }
    return cnt;
}