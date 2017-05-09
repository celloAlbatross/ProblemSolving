#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> iPair; 
typedef pair<int,iPair> iPairPro;


priority_queue <iPairPro> q;
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

bool isUnion(int x, int y)
{
    int tempx = getParent(x);
    int tempy = getParent(y); 
    if(arr[tempx] == arr[tempy]) {
        return true;
    } else {
        return false;
    }
}

void unionSet(int x, int y)
{
    int tempx = getParent(x);
    int tempy = getParent(y);
    if(tempx > tempy) {
        arr[tempx] = tempy;
    } else if (tempx == tempy){
        return;
    }else {
        arr[tempy] = tempx;
    }
}

int main()
{
    int n, edge, x, y,tempx,tempy, w;
   
    scanf("%d %d", &n, &edge);
    for(int i=1; i<=n; i++){
        arr[i] = i;
    }

    for(int i=0; i<edge; i++){
        scanf(" %d %d %d", &x, &y, &w);
        w = -w;
        q.push(iPairPro(w,iPair(x,y)));
    }
    int res = 0;
    while(!q.empty()) {
        x = q.top().second.first;
        y = q.top().second.second;
        w = -(q.top().first);
        if(!isUnion(x,y)) {
            res += w;
            unionSet(x,y);
            q.pop(); 
        } else {
            q.pop();
        }
    }

    printf("%d\n",res);
}