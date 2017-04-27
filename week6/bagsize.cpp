#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, a, b, minSize,input;
    int w[1000];
    cin >> n >> a >> b;
    minSize = a;
    for(int i=0;i<n;i++){
        cin >> input;
        w[i] = input;
        if((input > minSize) && (minSize <= b)){
            minSize = input;
        }
    }
    int x=0;
    int bag;
    int temp,min=20000,wBag=0,goodSize,loseWeight;
    for(int i=minSize;i<=b;i++){
        bag = i;
        wBag = 0;
        for(int j=0;j<n;j++){
            if((bag-w[j]) >= 0 ){
                bag -= w[j];
                if((bag == 0) && (j != n-1)){
                    bag = i;
                }
            }else{
                wBag += bag;
                    bag = i;
                bag -= w[j];
            }
            if(j==(n-1)){
                    wBag += bag;
                }
        }
        if(wBag < min){
            min = wBag;
            goodSize = i;
        }
    }
    cout << goodSize << endl;
}