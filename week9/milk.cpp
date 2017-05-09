#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int arr[100001];

int getParent(int data)
{
    if(arr[data] == data) {
        return data;
    }else {
        int a = getParent(arr[data]);
        arr[data] = a;
        return a;
    }
}

int main()
{
    int n, q, x, y,tempx,tempy;
    char command;
   
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++){
        arr[i] = i;
    }

    for(int i=0; i<q; i++){
        scanf(" %c %d %d", &command, &x, &y);
        tempx = getParent(x);
        tempy = getParent(y);
        if (command == 'c') {
            
            if(tempx > tempy) {
                arr[tempx] = tempy;
            } else if (tempx == tempy){
                continue;
            }else {
                arr[tempy] = tempx;
            }
        } else if (command == 'q'){
            if(arr[tempx] == arr[tempy]) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
}