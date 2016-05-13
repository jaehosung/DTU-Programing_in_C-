#include <iostream>
#include <stdlib.h>
using namespace std;

typedef enum { wood, stone } Material;
typedef struct {
	int x;
	int y;
	bool isWall;
	Material material;
}Maze;

char getMaze(Material material){
	switch(material){
		case wood :
			return ' ';
		case stone :
			return '#';
		default :
			return '?';
	}
}


int main(){
	int x;
	int y;
	int i,j;
	cin>>x>>y;
	Maze maze[x][y];
	for(i = 0; i < x; i++){
		for(j = 0; j<y; j++){
			maze[i][j].isWall= (i==0||i==x-1||j==0||j==y-1||rand()%4==0);
			if(maze[i][j].isWall){
				maze[i][j].material=stone;
			}else{
				maze[i][j].material=wood;
			}
		}
	}

	for(i = 0; i < x; i++){
		for(j = 0; j<y; j++){
			cout<<getMaze(maze[i][j].material);
		}
		cout<<endl;
	}
	return 0;
}
