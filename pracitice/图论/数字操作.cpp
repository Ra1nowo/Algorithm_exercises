#include <iostream>
#include <queue>
using namespace std;
// https://sunnywhy.com/problem/318
const int N = 1e5 + 10;
bool vis[N];
int n;

int bfs(int n) {
    int cnt = 0;
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int curr = q.front();
            q.pop();
            if (curr == n) return cnt;
            int upn1 = curr+1;
            int upn2 = 2 * curr;
            if (upn1 <= n && !vis[upn1]) {
                q.push(curr+1);
                vis[curr+1] = true;
            }
            if (upn2 <= n && !vis[upn2]) {
                q.push(2*curr);
                vis[2*curr] = true;
            }
        }
        cnt++;
    }
    return -1;
}



int main() {
    cin >> n;
    int cnt = bfs(n);
    cout << cnt << endl;
    return 0;
}