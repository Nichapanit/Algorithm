#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void shootCount(vector<int> &ps_gun, vector<int> &ps_mons, vector<int> &power_mons, int w, int total,int start_gun, int k,int n,int m, set<int> &result ){
    if(start_gun < k){
        int start = ps_gun[start_gun] - w <= 0 ? 0 : ps_gun[start_gun] - w;
        int last = ps_gun[start_gun] + w > n ? n - 1 : ps_gun[start_gun] + w;
        for(int i = start; i <= last; i++){
            for(int j = 0; j < m; j++){
                if(i == ps_mons[j] && power_mons[j] != 0){
                    total += 1;
                    power_mons[j] -= 1;
                }
            }
            shootCount(ps_gun, ps_mons, power_mons, w, total ,start_gun + 1, k, n, m, result);
        }
        start_gun -= 1;
    }else{
        result.insert(total);
    }
}

int main(){
    int n,m,k,w;
    int all_power;
    set<int> result;
    cin >> n >> m >> k >> w;
    vector<int> ps_mons(m);
    vector<int> ps_gun(k);
    vector<int> power_mons(m);
    for(int i = 0; i < m; i++){
        cin >> ps_mons[i];
    }
    for(int i = 0; i < m; i++){
        cin >> power_mons[i];
        all_power += power_mons[i];
    }
    for(int i = 0; i < k; i++){
        cin >> ps_gun[i];
    }
    shootCount(ps_gun, ps_mons, power_mons, w, 0, 0, k, n, m, result);
    auto it = result.end();
    it--;
    cout << all_power-(*it);
}