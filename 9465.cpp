#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

bool deleted(map<pair<int,int>, bool>& board, int row, int col)
{
    if(board.first.first-1 >= 0)
        board.second = true;
    if(board.first.first+1 <= row)
        board.find(make_pair(board.first))
}

int main(int argc, char** argv)
{
    const int row = 2;

    int test_case;
    scanf("%d",&test_case);

    vector<vector<int>> arr(test_case);
    vector<int> col(test_case);

    for(int i=0; i<test_case; i++)
    {
        scanf("%d",&col[i]);
        arr[i] = vector<int>(row*col[i],0);
        for(int y=0; y<row; y++)
        {
            for(int x=0; x<col[i]; x++)
            {
                scanf("%d", &arr[i][row*y + x]);
            }
        }
    }

    // compute
    for(int i=0; i<test_case; i++)
    {
        for(int y=0; y<row; y++)
        {
            for(int x=0; x<col[i]; x++)
            {
                
            }
        }
    }
}
