#include <stdio.h>
#include <Windows.h>

#define true 1

#define LENGTH_SCREEN 12
#define HIGHT_SCREEN 12

#define AIR '.'
#define WALL '#'
#define ENDLINE '\n'

#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3

char screen[HIGHT_SCREEN][(LENGTH_SCREEN)];

void generate_map(void)
{
    for(int i = 0; i < HIGHT_SCREEN; ++i){
        for(int j = 0; j < LENGTH_SCREEN; ++j)
            screen[i][j] = AIR;
            //screen[i][LENGTH_SCREEN+1] = '\0';    //for another output
    }
    for(int i = 0; i < LENGTH_SCREEN; ++i)
        screen[0][i] = WALL;
    for(int i = 0; i < LENGTH_SCREEN; ++i)
        screen[HIGHT_SCREEN-1][i] = WALL;
    for(int i = 0; i < HIGHT_SCREEN; ++i)
        screen[i][0] = WALL;
    for(int i = 0; i < HIGHT_SCREEN; ++i)
        screen[i][0] = WALL;
    for(int i = 0; i < HIGHT_SCREEN; ++i)
        screen[i][LENGTH_SCREEN-1] = WALL;
}

void time_line(void)
{
    system("cls");
    for(int i = 0; i < HIGHT_SCREEN; ++i){
        for(int j = 0; j < LENGTH_SCREEN; ++j)
            printf("%c ", screen[i][j]);
            printf("\n");
    }
    /*for(int i = 0; i < HIGHT_SCREEN; ++i) //another output
        printf("%s\n", screen[i]);*/
    Sleep(200);
}

/*struct obj_snake
{
    int length_snake = 1;
    short direction_view = LEFT;

    int snake_position_x = LENGTH_SCREEN/2;
    int snake_position_y = HIGHT_SCREEN/2;


};*/

int main()
{
    generate_map();

    while(true){
        time_line();
    }

    return 0;
}
