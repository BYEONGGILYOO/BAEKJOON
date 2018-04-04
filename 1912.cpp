#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
    int n;
    scanf("%d",&n);
    if(n < 1 && n > 100000)
        return 1;

    vector<int> arr(n), sumarr(n,0);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    //initialize to first elements at array
    int max = sumarr[0] = arr[0];
    for(int i=1; i<n; i++)
    {
        if(sumarr[i-1] > 0 && arr[i] + sumarr[i-1] > 0)
            sumarr[i] = arr[i] + sumarr[i-1];
        else // reset
            sumarr[i] = arr[i];

        if(max < sumarr[i])
            max = sumarr[i];
    }

    printf("%d\n", max);

    return 0;
}
