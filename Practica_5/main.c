#include <stdio.h>
#include <stdlib.h>

#define mazeRowSize 18
#define mazeColumnSize 18

const int maze[mazeRowSize][mazeColumnSize] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0 },
        { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0 },
        { 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 },
        { 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };
    
/** 
 * Box Type.
 * 1 - free ( libre )
 * 2 - wall ( Muro )
 * 3 - way ( Camino )
 * 4 - imposible ( imposible )
*/

int boxes[mazeRowSize][mazeColumnSize];

void showMaze();

void showBoxes();

int wayBacktracking( int x, int y, int exitVector[] );

int getMazeColumnValue( int column );

int main() {
    
    // Show the predefined maze.
    showMaze();
    printf("\n");
    
    // Get coordenates of the enter and exit way of the maze. 
    int enterVector[2] = { getMazeColumnValue( 0 ), 0 };
    int exitVector[2]  = { getMazeColumnValue( mazeColumnSize - 1 ), mazeColumnSize - 1 };
    
    printf(" - Enter Coordenate: ( Row: %d, Column: %d)\n", enterVector[0], enterVector[1]);
    printf(" - Exit Coordenate:  ( Row: %d, Column: %d)\n", exitVector[0], exitVector[1]);
    printf("\n");
    
    // Do the backtracking 
    int isPossible = wayBacktracking( enterVector[0], enterVector[1], exitVector );
    if( isPossible == 1 ) 
        printf("El laberinto se puede completar.\n");
    else 
        printf("El laberinto es imposible \n");
    printf("\n");
    // Show the complete Way.
    showBoxes();
    
    return 0;
}

int wayBacktracking( int x, int y, int exitVector[] ) {
    
    if( boxes[x][y] != 1 || x < 0 || y < 0 || x > (mazeColumnSize - 1) || y > (mazeRowSize - 1) ) {
        // Here we check if the pointer pass the limit of the maze
        return 0;
    }
    else {
        boxes[x][y] = 3;
        if( x == exitVector[0] && y == exitVector[1] ) {
            return 1;
        }
        else {
            int b = wayBacktracking( x + 1, y, exitVector ) || 
                    wayBacktracking( x, y + 1, exitVector ) ||
                    wayBacktracking( x - 1, y, exitVector ) ||
                    wayBacktracking( x, y - 1, exitVector );
                    
            if( b == 0 ) {
                boxes[x][y] = 4;
            }
            return b;
        }
    }
    
    
}

int getMazeColumnValue( int column ) {
    int i;
    
    for( i = 0; i < mazeRowSize; i++ ) {
        if( maze[ i ][ column ] == 1 ) 
            return i;
    }
}

void showMaze() {
    printf("El laberinto es: \n");
    printf("\n");
    
    int i, j;
    
    for( i = 0; i < 18; i++ ) {
        for( j = 0; j < 18; j++ ) {
            // Muestra | si es pared.
            if( maze[i][j] == 0 ) {
                printf(" # ");
                boxes[i][j] = 2;
            }
                
            // Muestra . si es camino.
            else {
                boxes[i][j] = 1;
                printf(" . ");
            }
        }
        printf("\n");
    }
}
void showBoxes() {
    int i, j;
    
    for( i = 0; i < 18; i++ ) {
        for( j = 0; j < 18; j++ ) {
            // Muestra C si es el camino recorrido
            if( boxes[i][j] == 3 )
                printf(" C ");
            // Muestra . si paso por el camino pero no pudo completar el recorrido.
            else if( boxes[i][j] == 4 )
                printf(" . ");
            // Muestra # si es pared
            else 
                printf(" # ");
        }
        printf("\n");
    }
}
