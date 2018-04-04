#include <iostream>
#include <cstdio>

int triple_num(int n)
{
    return n*(n+1)/2;
}

bool eureka_theorem(int n)
{
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            for(int k=1; k<n+1; k++)
            {
                if(n==triple_num(i)+triple_num(j)+triple_num(k))
                    return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv)
{
    int n;
    scanf("%d",&n);

    for(int i=1; i<n+1; i++)
    {
        int test_set;
        scanf("%d",&test_set);
        printf("%d\n",eureka_theorem(test_set));
    }

    return 0;
}
