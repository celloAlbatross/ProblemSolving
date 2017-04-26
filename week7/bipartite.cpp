#include <iostream>
#include <vector>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define MAX_N 100000

int n,m,res=0,previous=0;
bool isBi = true;
vector<int> adj[MAX_N];
int deg[MAX_N];
int group[MAX_N];

void read_input()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) {
        deg[i] = 0;
    }
    for(int i=0; i<m ;i++){
        int u,v;
        scanf("%d %d",&u, &v); u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
        
    }
}

bool visited[MAX_N];
void init()
{
    for(int i=0; i<n; i++){
        visited[i] = false;
        group[i] = -2;
    }
    
    isBi = true;
    previous = 0;
}

void dfs(int u)
{
    visited [u] = true;
    if(group[u] == -2){
        group[u] = 1;
        previous = 1;
    }
    
    for(int i=0; i<deg[u]; i++) {
        int v = adj[u][i];
       if(group[u] == 1){
           if(group[v] == 1){
               isBi = false;
           }else{
               group[v] = 2;
           }
       } else if(group[u] == 2) {
           if(group[v] == 2){
               isBi = false;
           }else{
               group[v] = 1;
           }
       }
        if (!visited[v]) {
            dfs(v); 
        }
    }
}

int main()
{
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        init();
        read_input();
        dfs(0);
        if(isBi){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    
}