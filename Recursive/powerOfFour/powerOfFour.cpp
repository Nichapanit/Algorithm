#include <iostream>
#include <cmath>

using namespace std;

bool powerOfFour(int n, int power){
    if(pow(4,power) == n){
        return true;
    }
    else{
        if(pow(4,power) > n){
            return false;
        }
        else{
            bool a = powerOfFour(n, power+1);
            cout << "answer at " << power << " is " << a << endl;
            return a;
        } 
    }
}

int main(){
    int n;
    cin >> n;
    cout << powerOfFour(n,0);
}