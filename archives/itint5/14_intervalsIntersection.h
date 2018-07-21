/*
struct Interval {
    int start;   //区间左端点
    int end;   //区间右端点
};
*/

// intervals包含n个区间
// 结果存放到isIntersected中(已分配空间,不需要push_back)
// isIntersected[i]表示第i个区间是否与其它区间相交

struct cmp {
    bool operator ()(const pair<int, Interval>& x, const pair<int, Interval>& y) {
        return x.second.start < y.second.start;
    }
};

void intersected(vector<Interval> &intervals, vector<bool> &isIntersected) {
    if (intervals.empty()) return;
    int n = intervals.size();
    pair<int, Interval> all[n];
    for (int i = 0; i < n; i++) {
        all[i] = make_pair(i, intervals[i]);
    }
    sort(all, all+n, cmp());
    int maxrp = all[0].second.end; // max right end point
    isIntersected[ all[0].first ] = false;
    int prev = all[0].first;
    
    for (int i = 1; i < n; i++) {
        if (all[i].second.start <= maxrp) {
            isIntersected[ all[i].first ] = isIntersected[prev] = true;
        }
        if (all[i].second.end >= maxrp) {
            prev = all[i].first;
            maxrp = all[i].second.end;
        }
    }
}