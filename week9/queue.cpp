#include <iostream>
#include <queue>

using namespace std;

typedef pair<int,int> iPair;
typedef pair<int,iPair> iPairPro;

priority_queue <iPairPro> q;

int main()
{
    q.push(iPairPro(1,iPair(2,3)));
    q.push(iPairPro(4,iPair(5,6)));
    cout << q.top().second.second << endl;
    // q.pop();
    cout << q.top().second.second << endl;
    q.pop();
}