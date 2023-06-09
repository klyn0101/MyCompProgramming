#include <iostream>
#include <vector>
using namespace std;

/* next combination */
int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main() {
    int n = 5;  // {0, 1, 2, 3, 4} の部分集合を考える
    int k = 3;
    
    int bit = (1<<k)-1;  // bit = {0, 1, 2}
    for (;bit < (1<<n); bit = next_combination(bit)) {
        /* ここに処理を書く */
        
    }
}