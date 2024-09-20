#include <iostream>
using namespace std;

// 静态链表
const int N = 100;
int head = -1, tail = -1, e[N], ne[N], idx = 0; // e[i]表示节点的值, ne[i]表示下一个节点的编号

// 头插法
void AddToHead(int val) {
    e[idx] = val;      // 存储值
    ne[idx] = head;    // 新节点的下一个节点指向当前头节点
    head = idx;        // 更新头节点为新节点
    if (tail == -1) {  // 如果是空链表，更新尾指针
        tail = idx;
    }
    idx++;             // 增加索引
}

// 尾插法
void AddToTail(int val) {
    e[idx] = val;      // 存储值
    ne[idx] = -1;      // 新节点的下一个节点为空

    if (head == -1) {
        head = idx;     // 如果链表为空，更新头指针
        tail = idx;     // 同时更新尾指针
    } else {
        ne[tail] = idx; // 将当前尾节点的下一个指向新节点
        tail = idx;     // 更新尾指针为新节点
    }

    idx++; // 更新索引
}


// 插入到第 k 个节点后
void Insert(int k, int val) {
    if (k == -1) return; // 检查 k 是否有效

    e[idx] = val;           // 存储值
    ne[idx] = ne[k];       // 新节点的下一个节点指向 k 的下一个节点
    ne[k] = idx;           // 将 k 的下一个节点指向新节点
    if (ne[idx] == -1) {   // 如果插入的是最后一个节点，更新尾指针
        tail = idx;
    }
    idx++;
}

// 删除第 k 个节点
void Delete(int k) {
    if (k == -1 || ne[k] == -1) return; // 检查 k 是否有效且是否有下一个节点

    ne[k] = ne[ne[k]]; // 将 k 的下一个节点指向 k 的下下一个节点
    if (ne[k] == -1) {  // 如果删除的是尾节点，更新尾指针
        tail = k;
    }
}

// 打印链表
void PrintList() {
    for (int i = head; i != -1; i = ne[i]) {
        cout << e[i] << " ";
    }
    cout << endl;
}

int main() {
    AddToTail(2);
    AddToTail(3);
    AddToHead(1);
    
    cout << "链表内容: ";
    PrintList(); // 输出: 1 2 3

    Insert(0, 4); // 在第一个节点后插入 4
    cout << "插入 4 后: ";
    PrintList(); // 输出: 1 4 2 3

    Delete(1); // 删除第一个节点
    cout << "删除第一个节点后: ";
    PrintList(); // 输出: 4 2 3

    return 0;
}
