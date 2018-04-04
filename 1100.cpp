#include <iostream>
#include <cstdio>

using namespace std;

#define ROW 8
#define COL 8

int main(int argc, char** argv)
{
    bool chess[8][8];

    for(int i=0; i<ROW; i++)
    {
        char input[8];
        scanf("%s",input);

        for(int j=0;j<COL;j++)
        {
            if(input[j] == '.')
                chess[i][j] = false;
            else if(input[j] == 'F')
                chess[i][j] = true;
        }
    }

    int result = 0;

    for(int i=0; i<ROW; i++)
        for(int j=i%2; j<COL;j+=2)
        {
            if(chess[i][j])
            {
                result++;
            }
        }

    printf("%d\n",result);

    return 0;
}
