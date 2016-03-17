#include<iostream>
#include<math.h>
using namespace std;

#define n 16
#define m 12
int x = 5, y = 5;
int movedir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};//lrud
typedef enum {wood , stone} material;
typedef struct{
    int x,y;
    bool isWall;
    material type;
}field;
field playground[n][m];
void display(){

    int i,j;
    for (int j=0; j<m; j++){

        for (int i=0; i<n; i++){
            if(i==x&&j ==y){
                cout<<"O";
            }else if(playground[i][j].isWall==true){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            playground[i][j].x=i;
            playground[i][j].y=j;
            playground[i][j].isWall=(i==0||i==(n-1)||(j==0&&i!=3) ||j==(m-1));
            if (playground[i][j].isWall && !(i==3 && j==0))
                playground [i][j].type=stone;
            else
                playground [i][j].type=wood;
        }
    }

    char dir;
    cin>>dir;
    display();
    while(dir!='q'){
        char dirnum;
        switch(dir)
        {
            case 'l':
                dirnum = 0;
                break;
            case 'r':
                dirnum = 1;
                break;
            case 'u':
                dirnum = 2;
                break;
            case 'd':
                dirnum = 3;
                break;
        }
        if(playground[x+movedir[dirnum][0]][y+movedir[dirnum][1]].isWall==false){
            x += movedir[dirnum][0];
            y += movedir[dirnum][1];
        }
        cin>>dir;
        display();
    }

}
