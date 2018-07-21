/*

有一个n*m的棋盘网格，机器人最开始在左上角，机器人每一步只能往右或者往下移动。棋盘中有些格子是禁止机器人踏入的，
该信息存放在二维数组blocked中，如果blocked[i][j]为true，那么机器人不能踏入格子(i,j)。
请计算有多少条路径能让机器人从左上角移动到右下角。

样例：

n=2,m=3
blocked:
[000]
[100]

一共有2条路径：
(0,0)->(0,1)->(0,2)->(1,2)
(0,0)->(0,1)->(1,1)->(1,2)

所以函数应该返回2。

*/

int totalPath(vector<vector<bool> > &blocked) {
    if (blocked.empty()) return 0;
    int n = blocked.size(), m = 0;
    if (blocked[0].size()) m = blocked[0].size();
    vector<vector<int> > step(n, vector<int>(m));

    for (int i = 0, can = 1; i < n; i++) {
        can = can && !blocked[i][0];
        step[i][0] = can;
    }

    for (int j = 0, can = 1; j < m; j++) {
        can = can && !blocked[0][j];
        step[0][j] = can;
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            step[i][j] = (blocked[i][j]) ? 0 : step[i-1][j] + step[i][j-1];

    return step.back().back();
}
