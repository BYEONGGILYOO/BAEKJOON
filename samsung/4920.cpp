#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

int N;
int input[100][100];

struct point
{
    int x,y;

    point()
        :x(0), y(0)
    {}

    point(int x, int y)
        :x(x),y(y)
    {}
};

struct tetris
{
    point left_top;
    point right_bottom;
    int height;
    int width;

    point total_point[4];

    tetris(){}

    tetris(point left_top, point right_bottom, int height, int width)
        :left_top(left_top), right_bottom(right_bottom), height(height), width(width)
    {}

    void tetirs::set_total_points(int case, point start)
    {
        memset(total_point, 0, sizeof total_point);

        if(case == 0)
        {
            total_point[0] = start;
            total_point[1] = point(start.x+1, start.y);
            total_point[2] = point(start.x+2, start.y);
            total_point[3] = point(start.x+3, start.y);
        }
        else if(case == 1)
        {
            total_point[0] = start;
            total_point[1] = point(start.x, start.y+1);
            total_point[2] = point(start.x, start.y+2);
            total_point[3] = point(start.x, start.y+3);
        }
        //
        else if(case == 2)
        {
            total_point[0] = start;
            total_point[1] = point(start.x+1, start.y);
            total_point[2] = point(start.x+1, start.y+1);
            total_point[3] = point(start.x+2, start.y+1);
        }
        else if(case == 3)
        {
            total_point[0] = point(start.x+1, start.y);
            total_point[1] = point(start.x+1, start.y+1);
            total_point[2] = point(start.x, start.y+1);
            total_point[3] = point(start.x, start.y+2);
        }
        //
        else if(case == 4)
        {
            total_point[0] = start;
            total_point[1] = point(start.x+1, start.y);
            total_point[2] = point(start.x+2, start.y);
            total_point[3] = point(start.x+2, start.y+1);
        }
        else if(case == 5)
        {
            total_point[0] = point(start.x+1, start.y);
        }
    }

    void set_first_points(point start)
    {

    }
}

int main()
{
    scanf("%d", &N);

    for(int y=0; y<N; y++)
        for(int x=0; x<N; x++)
            scanf("%d", &input[y][x]);

    int max_sum = numeric_limits<int>::max();
    for(int y=0; y<N; y++)
    {
        for(int x=0; x<N; x++)
        {
        }
    }
}
