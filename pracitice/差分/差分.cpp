#include <cstdio>
#include <algorithm>
using namespace std;
//原题链接：https://sunnywhy.com/problem/625/solution/1975065684
const int MAXT = 100000 + 1;
int hash[MAXT] = {0};

int main() {
    int n, st, ed;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &st, &ed);
        hash[st]++;
        hash[ed]--;
    }
    int current = 0, maxResult = 0;
    for (int i = 0; i < MAXT; i++) {
        current += hash[i];
        maxResult = max(maxResult, current);
    }
    printf("%d", maxResult);
    return 0;
}