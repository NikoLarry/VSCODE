#include <iostream>
#include "node.h"	
#include "sq_stack.h"
#include "lk_stack.h"
#include "sq_list.h"
#include "lk_list.h"
#include "circ_queue.h"
#include "lk_queue.h"

using namespace std;


//用于记录坐标位置
typedef struct
{
    int x;
    int y;
}PosType;


/// <summary>
/// 打印迷宫信息
/// </summary>
/// <param name="maze">存储迷宫信息的二维动态数组</param>
/// <param name="rows">迷宫的行数</param>
/// <param name="cols">迷宫的列数</param>
void print_maze(int** maze, int rows, int cols)
{
    cout << "迷宫:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}


/// <summary>
/// 打印路径信息
/// </summary>
/// <param name="maze">存储迷宫信息的二维动态数组</param>
/// <param name="rows">迷宫的行数</param>
/// <param name="cols">迷宫的列数</param>
/// <param name="start">迷宫的起点</param>
/// <param name="end">迷宫的终点</param>
/// <param name="direc">存储机器人移动信息的一维动态数组中</param>
void print_road(int** maze, int rows, int cols, PosType start, PosType end, int* direc)
{

    //复制迷宫
    char** maze_with_road = new char* [rows]; // 创建一个指向rows个int指针的指针数组
    for (int i = 0; i < rows; i++) {
        maze_with_road[i] = new char[cols];   // 创建每个行的指针，指向cols个int
        for (int j = 0; j < cols; j++) {
            maze_with_road[i][j] =maze[i][j]+'0';
        }
    }

    int q = 0;
    int x = start.x;
    int y = start.y;
    maze_with_road[x][y] = '*';
    while (direc[q] != -1)
    {
        switch (direc[q]) {
        case 1:
            y++;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            x--;
            break;
        default:
            cout << "direction error" << endl;
            break;
        }
        if (maze[x][y] == 1 || q > rows * cols) {
            cout << "road error" << endl;
        }
        maze_with_road[x][y] = '*';
        q++;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze_with_road[i][j] << ' ';
        }
        cout << endl;
    }
}



/// <summary>
/// 求得一条从起点到终点的通路
/// </summary>
/// <param name="maze">存储迷宫信息的二维动态数组</param>
/// <param name="rows">迷宫的行数</param>
/// <param name="cols">迷宫的列数</param>
/// <param name="start_point">迷宫的起点</param>
/// <param name="end_point">迷宫的终点</param>
/// <returns>存储机器人移动信息，保存到一维动态数组中</returns>
int* search(int** maze, int rows, int cols, PosType start_point, PosType end_point)
{
    // 实验相关要求
    //1、用结构体PosType存储机器人的位置信息
    //2、机器人前进方向（东为1，南为2，西为3，北为4）：
    //   向东移动：y=y+1
    //   向南移动：x=x+1
    //   向西移动：y=y-1
    //   向北移动：x=x-1
    //3、输出结果为找到的从起点到终点的通路上，机器人移动的方向信息，最后用-1表示结束。
    // 输出结果示例()：
    //   * 标记了找到的从起点（1,1）到终点（4,4）的一条通路
    // 
    //                  1 1 1 1 1 1
    //                  1 * * * 0 1
    //                  1 0 1 * 1 1
    //                  1 0 0 * * 1
    //                  1 0 1 0 * 1
    //                  1 1 1 1 1 1
    // 
    //   那么，输出的一维动态数组内容应为：  1  1  2  2  1  2  -1，末尾的-1是结束的标识符。

    ////////////////////////////////////////////////////////////////////////////
    //------------------------------------start---------------------------------
    //请补全相关代码
    PosType node;
    SqStack<PosType> S;
    node.x = start_point.x;
    node.y = start_point.y;
    int dir[4]={1,2,3,4};
    int find = 0;
    int m,j;
    int *direc = new int[100];
    S.Push(start_point);
    m = 0;
    j = 0;
    while(!S.Empty())
    {   
        PosType next;
        if(node.x==end_point.x && node.y==end_point.y)
            {
                direc[m] = -1;
                //printf("%d",direc[m]);
                break;
            } 
        if(!find)
        {     
            switch (dir[j])
            {   
                case 1:
                    next.x=node.x;
                    next.y=node.y+1;
                    break;
                case 2:
                    next.x=node.x+1;
                    next.y=node.y;
                    break;
                case 3:
                    next.y=node.y-1;
                    next.x=node.x;
                    break;
                case 4:
                    next.x=node.x-1;
                    next.y=node.y;
                    break;
                default:
                    break;
            }
            if(maze[next.x][next.y]!=0)
            {
                j++;
                if(j==4)
                {
                    S.Pop();
                    S.Top(next);
                    node.x = next.x;
                    node.y = next.y;
                    m--;
                    j = 0;
                }
                find = 0;
            }
            else
            {
                find = 1;
            }
        } 
        if(find)
        {
            node.x = next.x;
            node.y = next.y;
            S.Push(next);
            maze[next.x][next.y] = -1;
            direc[m] = dir[j];
            //printf("%d",direc[m]);
            m++;
            find = 0;
            j = 0;
        }     
    }
    //------------------------------------end-----------------------------------
    ////////////////////////////////////////////////////////////////////////////
    //以下操作可以帮助你检查算法是否准确，最后评测时请注释掉。
    //打印迷宫信息
    //print_maze(maze1, rows, cols);
    //打印路径信息
	print_road(maze, rows, cols, start_point, end_point, direc);
	return direc;
}



