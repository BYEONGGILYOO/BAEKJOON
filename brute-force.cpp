#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    int n, arr[1000];
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }

    int result = 0;

    /*
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i!=j)
                result = max(result, arr[i]+arr[j]);
                */
    sort(arr, arr+n);

    printf("%d\n", arr[n-1] + arr[n-2]);

    return 0;
}
