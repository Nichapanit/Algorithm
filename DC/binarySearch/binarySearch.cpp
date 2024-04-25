#include <iostream>
#include <vector>

using namespace std;
int find1pos(vector<int> &a, int start, int stop, int target){
    if (start == stop){
        if (a[start] == target) return start;
    }
    else{
        int mid = (stop+start)/2;
        if(target <= a[mid]){
            return find1pos(a, start, mid, target);
        }
        else{
            return find1pos(a, mid+1, stop, target);
        }
    }
}

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++ ){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cout << "Number at " << i << " : " << a[i] << endl;
    }
    int pos = find1pos(a, 1, n, t);
    cout << "First position of target " << t << " is : " << pos << endl;
}
