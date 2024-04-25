#include <iostream>
#include <cmath>

using namespace std;

int modExpo(int a, int n, int k){
    if (n == 1) return a % k;
    else {
        int result = modExpo(a, n/2, k);
        int ans = (result * result) % k;
        if(n % 2 == 0){
            return ans;
        }
        else{
            return (ans * (a % k)) % k;
        }
    }
}

int main(){
    int a,n,k;
    cin >> a >> n >> k;
    int modular = modExpo(a, n, k);
    cout << "Modular of " << pow(a,n) << " by " << k << " :" << modular << endl;
}