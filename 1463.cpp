#include <iostream>
#include <cstdio>
#include <vector>

#define _MIN(a,b) a<b ? a : b

using namespace std;

int main(int argc, char** argv)
{
    int q;
    scanf("%d",&q);

    vector<int> arr(q+1,0);

    for(int i=2; i<(int)arr.size(); i++)
    {
        arr[i] = arr[i-1] + 1;
        if(i%3 == 0)
            arr[i] = _MIN(arr[i], arr[i/3]+1);
        if(i%2 == 0)
            arr[i] = _MIN(arr[i], arr[i/2]+1);
    }
    printf("%d\n", arr[q]);

    return 0;
}
