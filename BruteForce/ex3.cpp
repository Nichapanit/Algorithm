#include <iostream>
#include <vector>

using namespace std;

void perm(int want, vector<int> &v1, vector<int> &v2, int index, vector<bool> &v3){
    if (index < want){
        for(int i = 0; i < v2.size(); i++){
            if(v3[i] == false){
                v1[index] = v2[i];
                v3[i] = true;
                perm(want, v1,v2,index+1,v3);
                v3[i] = false;
            }
        }
    }else {
        for (int i = 0; i < want; i++){
            cout << v1[i];
        }
        cout << endl;
    }
}

int main(){
    int n,w;
    cin >> n;
    vector<int> data(n);
    vector<bool> used(n);
    for (int i = 0; i < data.size(); i++){
        cin >> data[i];
    }
    vector<int> data2(data);
    cin >> w;
    perm(w, data, data2, 0, used);
}