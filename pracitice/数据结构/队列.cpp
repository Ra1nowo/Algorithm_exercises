#include <iostream>
using namespace std;

const int N = 10;

typedef struct {
    int a[N];
    int hh = 0,tt = 0;
}queue;

bool isempty(queue q) {
    return q.hh == q.tt;
}

void insert(queue &q,int e) {
    q.a[q.tt++] = e;
}

void pop(queue &q) {
    q.hh++;
}

int main() {
    queue q;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        insert(q,e);
    }
    pop(q);
    for (int i = q.hh; i < q.tt; ++i) cout << q.a[i] << " ";
}