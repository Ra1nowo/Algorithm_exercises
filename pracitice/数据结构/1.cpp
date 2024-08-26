#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int values[] = {1,2,3};
    cout << *min_element(values,values+3) << endl;
}