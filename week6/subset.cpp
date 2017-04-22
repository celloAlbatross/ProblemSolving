#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    char input[1010];
    int n=0;
    for(int i=0; i<1010;i++){
        input[i] = '\0';
    }
    cin >> input;
    bool isNullSet = (input[0]=='{')&&(input[1]=='}');
    int i=0;
    while(input[i] != '\0'){
        if(input[i] == ','){
            n++;
        }
        i++;
    }
    if(isNullSet){
        printf("%d\n",1);
    }
    else if(n>0){
        n++;
        int res=1;
        for(int i=0;i<n;i++){
            res *= 2;
        }
        printf("%d\n",res);
    }else{
        printf("%d\n",2);
    }
}