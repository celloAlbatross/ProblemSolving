#include <iostream>

using namespace std;

int n,m;

char map[110][110];

bool check(int a, int b){
    return (map[a][b] != '#') && (map[a][b] != '\0') && (map[a][b] != '.');
}

void doCommand(char command,int k)
{
    int i,j;
    if(command == 'L'){
        j=0;
        // cout << k << " " << j << endl;
        while(check(k,j)){
             map[k][j] = '.';
             j++;
        }
        
    } else if(command == 'R') {
        j = n-1;
        while(check(k,j)){
             map[k][j] = '.';
             j--;
        }
    } else if(command == 'U') {
        i=0;
        while(check(i,k))
        {
            map[i][k] = '.';
            i++;
        }
    } else if(command == 'D') {
        i=n-1;
        while(check(i,k))
        {
            map[i][k] = '.';
            i--;
        }
    } else if(command == 'A') {
        j=0;
        // for(int m=0;m<n;m++)
        while(map[k][j] != '\0'){
            if(map[k][j] != '#')
                map[k][j] = 'x';
            j++;
        }
    } else if(command == 'B') {
        i=0;
        while(map[i][k] != '\0'){
            if(map[i][k] != '#')
                map[i][k] = 'x';
            i++;
        }
    }
}

void printMap()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main()
{
    for(int i=0;i<110;i++){
        for(int j=0;j<110;j++){
            map[i][j] = '\0';
        }
    }
    cin >> n >> m;
    
    char x;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> x;
            map[i][j] = x;
        }
    }
    // printMap();

    int k;
    char command;
    for(int i=0;i<m;i++){
        cin >> command >> k;
        doCommand(command, k-1);
    }
    printMap();

}