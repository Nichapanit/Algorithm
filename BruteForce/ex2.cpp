#include <iostream>
#include <vector>

using namespace std;

void perm(int size, vector<int> &v1,vector<int> &v3, int index, vector<bool> &v2){
    if (index < size){
        for(int i = 0; i < size; i++){
            if(v2[i] == false){
                v1[index] = v3[i];
                v2[i] = true;
                perm(v1.size(), v1,v3,index+1,v2);
                v2[i] = false;
            }
        }
    }else {
        for (int i = 0; i < size; i++){
            cout << v1[i];
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> data(n);
    vector<bool> used(n);
    for (int i = 0; i < data.size(); i++){
        cin >> data[i];
    }
    vector<int> data2(data);
    perm(n, data, data2, 0, used);
}