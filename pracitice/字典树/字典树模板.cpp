#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 10000 * 2;
int trie[MAXN][256], idx = 0;    
int f[MAXN];              
// ????????https://sunnywhy.com/problem/624
void insert(vector<int> ip) {
    int p = 0;                          
    for (int i = 0; i < ip.size(); i++) {  
        if (trie[p][ip[i]] == 0) {      
            trie[p][ip[i]] = ++idx;     
        }
        p = trie[p][ip[i]];           
    }
    f[p] = true;                   
}


bool search(vector<int> ip) {
    int p = 0;                            
    for (int i = 0; i < ip.size(); i++) {   
        p = trie[p][ip[i]];            
        if (p == 0) {                     
            return false;
        }
        if (f[p]) {                   
            return true;
        }
    }
    return true;                            
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        vector<int> ip;
        string ipStr;
        for (int j = 0; j < 4; j++) {      
            cin >> ipStr;
            if (ipStr != "*") {            
                ip.push_back(stoi(ipStr));
            }
        }
        insert(ip);                        
    }
    for (int i = 0; i < q; i++) {
        vector<int> ip;
        string ipStr;
        for (int j = 0; j < 4; j++) {
            cin >> ipStr;
            ip.push_back(stoi(ipStr));      
        }
        cout << (search(ip) ? "Yes\n" : "No\n");   
    }
    return 0;
}