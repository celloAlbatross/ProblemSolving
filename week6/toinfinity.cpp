#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,x,y,r;
    int min;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y >> r;
        if(y < 0){
            y = -y;
        }
        if(i==0){
            min = y-r;
        }
        if(y-r < min){
            min = y-r;
        }
    }
    if(min > 0){
        cout << min << endl;
    }else{
        cout << -1 << endl;
    }
}