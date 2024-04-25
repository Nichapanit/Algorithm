#include <iostream>

using namespace std;

int binomial(int n, int r){
    if(n == r || r == 0){
        return 1;
    }
    else if (r >= 1 && r <= n - 1){
        return binomial(n-1, r-1) + binomial(n-1, r);
    }
}

int main(){
    int n, r;
    cin >> n >> r;
    int ans = binomial(n, r);
    cout << "answer: " << ans << endl;
}