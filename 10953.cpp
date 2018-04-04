#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char a[3];
        scanf("%s",a);
        printf("%d\n",a[0]+a[2]-(48*2));
    }
    return 0;
}
