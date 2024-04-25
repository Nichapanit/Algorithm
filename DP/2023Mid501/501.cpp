#include <iostream>
#include <vector>

using namespace std;

int main(){
    int p, q, k, n;
    cin >> p >> q >> k >> n;
    vector<int> B(n);
    for(int i = 1; i <= n; i++){
        if(i <= k) B[i] = 0;
        else{
            B[i] = B[i-p] + B[i-q] + 1;
        }
    }
    for (int i = 1; i <= n; i++){
        cout << B[i] << " ";
    }
}