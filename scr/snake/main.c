#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define true 1

#define LENGTH_SCREEN 12
#define HIGHT_SCREEN 12

#define AIR ' '
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
        printf("%c", ENDLINE);
    }
    /*for(int i = 0; i < HIGHT_SCREEN; ++i) //another output
        printf("%s\n", screen[i]);*/
    Sleep(200);
}

void controlling(short *direction)
{
    switch(getch())
    {
        case 'a': *direction = LEFT;
            break;
        case 'w': *direction = UP;
            break;
        case 'd': *direction = RIGHT;
            break;
        case 's': *direction = DOWN;
            break;
    }
}

struct objSnake
{
    int length_snake;
    short direction_view;

    int snake_position_x;
    int snake_position_y;


};

int main()
{
    generate_map();
    struct objSnake snake = {1, RIGHT, LENGTH_SCREEN/2, HIGHT_SCREEN/2};;

    while(true){
        controlling(&snake.direction_view);
        printf("%d", snake.direction_view);
        time_line();
    }

    return 0;
}
