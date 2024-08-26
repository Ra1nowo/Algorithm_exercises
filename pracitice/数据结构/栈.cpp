#include <iostream>
using namespace std;

const int N = 1e5;
int n;
typedef struct {
    int a[N];
    int tt = -1;
}stk;

void insert(stk &st, int e) {
    if (st.tt == N-1) return;
    st.a[++st.tt] = e;
}

void pop(stk &st) {
    st.tt--;
} 

int getTop(stk &st) {
    if (st.tt == -1) return -10000000;
    return st.a[st.tt];
}


int main() {
    cin >> n;
    int k = n;
    stk st;
    while (n--) {
        int e;
        cin >> e;
        insert(st,e);
    }
    cout << "½áÊø" << endl;
    while (k--) {
        cout << getTop(st) << " ";
        pop(st);
    }
}