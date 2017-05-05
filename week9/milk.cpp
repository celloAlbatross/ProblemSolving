#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, q, x, y,temp;
    char command;
    int array[100000];
    scanf("%d %d", &n, &q);
    array[0] = 0;
    for(int i=1; i<=n; i++){
        array[i] = i;
        // cout << array[i] << endl;
    }

    for(int i=0; i<q; i++){
        scanf(" %c %d %d", &command, &x, &y);
        if (command == 'c') {
            temp = array[y];
            array[y] = array[x];
            for(int j=1; j<=n; j++) {
                if(array[j] == temp) {
                    array[j] = array[x];
                }
                // cout << array[j] << " ";
            }
            // cout << endl;
        } else if (command == 'q'){
            if(array[x] == array[y]) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
}