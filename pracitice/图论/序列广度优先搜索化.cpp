#include <iostream>
#include <queue>
using namespace std;

// https://leetcode.cn/problems/jump-game-iii/description/

const int N = 5e4 + 10;
bool vis[N];
int arr[N];

int main() {
    bool flag = true;
    int n, start;
    cin >> n >> start;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    vis[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (arr[u] == 0) cout << "Yes"<< endl; break;
        int l = u - arr[u], r = u + arr[u];
        if (l >= 0 && !vis[l]) q.push(l), vis[l] = true;;
        if (r <= n-1 && !vis[r]) q.push(r), vis[r] = true; 
    }
    cout << "No" << endl;
    return 0;
}