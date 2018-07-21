/*
 * deps[id]表示任务id所依赖的任务
 * 如果存在合法的任务完成序列，返回true，否则返回false
 * 合法的任务序列请存放在参数result中（已经分配空间，不需要push_back）
 *

 Solution: 将原前继graph构造为后继graph，toplogical sort

*/

typedef int JobID;

bool jobSchedule(const map<JobID, vector<JobID> > &deps, int n,
                                   vector<JobID> &result) {
    
    queue<JobID> que;
    int indgree[n + 1]; // id from 1 to n
    for (int i = 0; i <= n; i++) indgree[i] = 0;
    map<JobID, vector<JobID> > jobs;
    map<JobID, vector<JobID> >::const_iterator iter;
    for (iter = deps.begin(); iter != deps.end(); iter++) {
        JobID id = iter->first;
        const vector<JobID> &relay = iter->second;
        int len = relay.size();
        // store graph by succeed
        for (int i = 0; i < len; i++) {
            jobs[ relay[i] ].push_back(id);
        }
        indgree[id] = len;
    }
    
    for (int id = 1; id <= n; id++)
        if (indgree[id] == 0) que.push(id);

    int i = 0;
    while (!que.empty()) {
        JobID id = que.front(); que.pop();
        result[i++] = id;
        if (jobs.find(id) == jobs.end())
            continue;
        const vector<JobID> &succeed = jobs[id];
        for (int k = 0; k < (int)succeed.size(); k++) {
            --indgree[ succeed[k] ];
            if (indgree[ succeed[k] ] == 0) {
                que.push(succeed[k]);
            }
        }
    }
    return i == n;
}