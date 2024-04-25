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
    }else if (chosen == select){
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


selection sort 
5 9 10 4
5 9 4 | 10
5 4 9 | 10
5 4 | 9 10
4 5 9 10

a1 a2 a3 a4 a5
a4 -> max : 4 (n-1) + 1 = n
a1 a2 a3 a5 | a4 
a2 -> max : 3 (n-2) + 1 = n-1
a1 a5 a3 | a2 a4 
a1 -> max : 2 (n-3) + 1 = n-2
a3 a5 | a1 a2 a4
a3 -> max : 1 (n-4) + 1 = n-3
a5 a3 a1 a2 a4

n + n-1 + n-2 + ... + 2 n(n+1)/2 = (n^2)/2 + n/2

2 3 4 5 6 7 8
ตรงกลางข้อมูลคืออะไร

a(5) = 8
5 
1 1 1 1 1
1 1 1 2
1 1 2 1
1 2 1 1
1 2 2
2 1 1 1
2 1 2
2 2 1


10 1 2 1
1
10
2 5
m(10) g _ _ g _ _ _ _ _
1 4 = 1
1 5 = 1
1 6 = 1
2 4 = 0
2 5 = 0
2 6 = 0
3 4 = 0
3 5 = 0
3 6 = 0


100 3 2 1
80 70 60
1 1 1
70 71 69
60         70        80
        69 70 71

1 _ 3
1 2 _ 
m * k 





