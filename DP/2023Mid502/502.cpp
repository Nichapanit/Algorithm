#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    set<pair<int, int>> E;
    for(int i = 0; i < k; i++){
        int a,b;
        cin >> a >> b;
        pair<int,int> p(a,b);
        E.insert(p);
    }
    vector<int> A(k);
    for (int i = 1; i <= k; i++){
        cin >> A[i];
    }
    int B[k+1][n+1];
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            if(j == 0) B[i][0] = 0;
            else{
                int min = 100000;
                for(pair<int,int> tmp:E){
                    if(tmp.second == i){
                        min = (2*B[i][j/2] + A[tmp.first]) <= min ? (2*B[i][j/2] + A[tmp.first]) : min;
                    }
                }
                B[i][j] = min;
            }
        }
    }
    for(int i = 1; i <= k; i++){
        for(int j = 0; j <= n; j++){
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << B[k][n];
}