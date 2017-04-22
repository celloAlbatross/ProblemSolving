#include <stdio.h>
#include <iostream>

using namespace std;

int isSra(char x)
{
    if(x == 'a'){
        return 1;
    } else if( x == 'e') {
        return 1;
    } else if ( x == 'i') {
        return 1;
    } else if ( x == 'o') {
        return 1;
    } else if ( x== 'u') {
        return 1;
    }
    return 0;
}

int main()
{
    char word[31];
    int n,state=0,count=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> word;
        for(int j=0; j<31;j++){
            if(!word[j]){
                break;
            }
            if(state == 0){
                if(isSra(word[j])){
                    count++;
                    state = 1;
                }
            } else if (state == 1) {
                if(!isSra(word[j])){
                    state = 0;
                }
            }
        }
        printf("%d\n",count);
        state = 0;
        count = 0;
    }
    // printf("%s\n",word);

}