// 这是leetcode 的核心代码模式的题 (区间并查集)
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;
// 原题链接: https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-ii/submissions/555280635/
class Solution {
public:
    int find(int x,vector<int> &p) {
        if (x != p[x]) {p[x] = find(p[x],p);}
        return p[x];
    }
    void merge(int x, int y, vector<int> &p, int &cnt) {
        int rx = find(x,p), ry = find(y,p);
        if (rx != ry) {
            p[rx] = ry;
            cnt--;
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int cnt = n-1;
        vector<int> ans;
        vector<int> p(n-1);
        iota(p.begin(),p.end(),0);
        for (int i = 0; i < queries.size(); ++i) {
            int l = queries[i][0], r = queries[i][1] - 1;
            int rl = find(l,p),rr = find(r,p);
            for (int i = rl; i < rr; i = find(i+1,p)) {
                merge(i,rr,p,cnt);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};