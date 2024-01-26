#include <iostream>
#include <vector>

using namespace std;

void comb(int select, int chosen, vector<int> &v1, vector<int> &v2, int start){
    if(chosen < select && start < v2.size()-chosen){
        for (int i = start; i < v2.size(); i++){
            v1[chosen] = v2[i];
            comb(select, chosen+1, v1, v2, start+1);
            start = start +1;
        }
    }else{
        cout << select << ": ";
        for(int i = 0; i < select; i++){
            cout << v1[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n ; i++){
        cin >> v1[i];
    }
    vector<int> v2(v1);
    for (int i = 0; i <= n; i++){
        comb(i,0,v1,v2,0);
    }
}