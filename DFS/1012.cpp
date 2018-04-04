#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <cstring>

using namespace std;

class Graph
{
    public:
        bool adj_matrix[51][51];
        bool visited[51][51];
        int cal_matrix[4][2];
        int components;
        int row, col;

        Graph(int row, int col)
            :components(0), row(row), col(col)
        {
            memset(adj_matrix, 0, sizeof(adj_matrix));
            memset(visited, 0, sizeof(adj_matrix));
            cal_matrix[0][0] = 0, cal_matrix[0][1] = 1;
            cal_matrix[1][0] = 0, cal_matrix[1][1] = -1;
            cal_matrix[2][0] = 1,  cal_matrix[2][1] = 0;
            cal_matrix[3][0] = -1,  cal_matrix[3][1] = 0;
        }

        void addEdge(int v1, int v2)
        {
            adj_matrix[v1][v2] = true;
        }

        void dfs_all()
        {
            for(int x=0; x<col; x++)
            {
                for(int y=0; y<row; y++)
                {
                    if(!visited[x][y] && adj_matrix[x][y])
                    {
                        visited[x][y] = true;
                        components++;
                        dfs(x,y);
                    }
                }
            }
        }

    private:
        void dfs(int curr_x, int curr_y)
        {
            for(int i=0; i<4; i++)
            {
                int xx = curr_x + cal_matrix[i][0];
                int yy = curr_y + cal_matrix[i][1];

                if(xx >= 0 && yy >= 0 && xx < this->col && yy < this->row)
                {
                    if(adj_matrix[xx][yy] && !visited[xx][yy])
                    {
                        visited[xx][yy] = true;
                        dfs(xx,yy);
                    }
                }
            }
        }
};

int main(int argc, char** argv)
{
    int test_case;
    scanf("%d", &test_case);

    for(int i=0; i<test_case; i++)
    {
        int row, col, num;
        scanf("%d %d %d", &col, &row, &num);
        Graph data(row, col);

        for(int j=0; j<num; j++)
        {
            int y, x;
            scanf("%d %d", &x, &y);
            data.addEdge(x, y);
        }
        usleep(10000);
        data.dfs_all();
        cout << data.components << endl;
    }
    return 0;
}
