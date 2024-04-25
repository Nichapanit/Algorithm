#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSort(vector<int> &v, int start, int stop){
    if(start + 1 == stop){
        if(v[start] > v[stop]){
            swap(v[start],v[stop]);
        }
    }else{
        
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 1; i <=n; i++){
        cin >> v[i];
    }

}