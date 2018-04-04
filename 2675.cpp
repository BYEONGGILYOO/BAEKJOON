#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
    int n;
    scanf("%d",&n);

    while(n--)
    {
        int r;
        char s[20];
        scanf("%d %s",&r,s);

        int s_size = strlen(s);
        for(int i=0; i<s_size; i++)
        {
            for(int j=0;j<r;j++)
            {
                printf("%c",s[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
