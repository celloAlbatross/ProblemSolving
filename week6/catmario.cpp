#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,m,x,y;
    cin >> n >> m;
    int stage[n+1];
    for(int i=0; i<=n;i++){
        stage[i] = 2000;
    }
    for(int i=0;i<m;i++){
        cin >> x >> y;
        if(stage[x] > y){
            stage[x] = y;
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res += stage[i];
    }
    cout << res << endl;
    for(int i=1;i<=n;i++){
        cout << i << " " << stage[i] << endl;
    }
}