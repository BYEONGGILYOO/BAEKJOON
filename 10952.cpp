#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
    int a, b;

    while(1)
    {
        scanf("%d %d", &a, &b);
        if(a==0 && b==0)
            break;
        printf("%d\n\n",a+b);
    }
    return 0;
}
