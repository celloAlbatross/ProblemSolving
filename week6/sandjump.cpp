#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int r,s,t,mod;
    cin >> r >> s >> t;
    mod = s+t;
    int n,jump;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> jump;
        if(jump < r){
            cout << "no" << endl;   
        } else {
            jump -= r;
            jump %= mod;
            // cout << "jump_mod: " << jump << endl;
            
            // cout << "jump: " << jump << endl;
            if(jump >= 0){
                if(jump <= s || jump == mod){
                    cout << "yes" << endl;
                } else {
                    cout << "no" << endl;
                }
            } else {
                cout << "no" << endl;
            }
        }
    }
}