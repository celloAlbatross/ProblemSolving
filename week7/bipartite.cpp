#include <iostream>
#include <vector>
#include <stdio.h>
#include <list>

using namespace std;

#define MAX_N 100000

int n,m,res=0,previous=0;
bool isBi = true;
vector<int> adj[MAX_N];
int deg[MAX_N];
int group[MAX_N];
int levels[MAX_N];


void read_input()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) {
        deg[i] = 0;
        adj[i].clear();
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

void find_levels(int s)
{
    list<int> next_level;
    for(int u=0; u<n; u++) {
        levels[u] = -1;
    }
    next_level.push_back(s);
    levels[s] = 0;
    
    while(! next_level.empty()) {
        list<int> current_level = next_level;
        next_level.clear();
    
        for(list<int>::iterator i = current_level.begin();
            i != current_level.end(); i++) {
        int u = *i;
    
            for(vector<int>::iterator j = adj[u].begin();
                j != adj[u].end(); j++) {
                int v = *j;
        
                if(levels[v] == -1) {
                    levels[v] = levels[u] + 1;
                    next_level.push_back(v);
                } else if( levels[v] % 2 == levels[u] %2) {
                    isBi = false;
                }
            }
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
        find_levels(0);
        if(isBi){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    
}