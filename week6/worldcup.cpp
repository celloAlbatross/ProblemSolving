#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct WorldCup
{
    string name;
    int score;
    // int diff;
    int shoot;
    int wasShooted;

    WorldCup(string name="", int shoot=0, int wasShooted=0, int score=0)
        : name(name) , shoot(shoot), wasShooted(wasShooted), score(score) {}
};

bool comp(WorldCup a,WorldCup b){
    if (a.score == b.score){
        if((a.shoot - a.wasShooted) == (b.shoot - b.wasShooted)){
            return a.shoot > b.shoot;
        }
        return (a.shoot - a.wasShooted) > (b.shoot - b.wasShooted);
    }
    return a.score > b.score;
}

int main()
{
    WorldCup team[4];
    string x;
    for(int i=0;i<4;i++){
        cin >> x;
        team[i].name = x;
    }

    int goal;
    int score[4][4];

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin >> goal;
            team[i].shoot += goal;
            team[j].wasShooted += goal;
            score[i][j] = goal;
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i!=j){
                if(score[i][j] == score[j][i]){
                    team[i].score += 1;
                    team[j].score += 1;
                } else if (score[i][j] > score[j][i]) {
                    team[i].score += 3;
                } else {
                    team[j].score += 3;
                }
            }
        }
    }

    for(int i=0;i<4;i++){
        team[i].score /= 2;
    }
    
    sort(team,team+4,comp);
    for(int i=0;i<4;i++){
        cout << team[i].name << " " << team[i].score << endl;
    }
}