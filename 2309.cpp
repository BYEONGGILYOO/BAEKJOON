#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

bool lowupper(int a, int b){ return (a<b); }
int main()
{
    vector<int> arr(9);
    int data;

    for(int i=0; i<(int)arr.size(); i++)
    {
        scanf("%d", &data);
        arr[i]= data;
    }

    sort(arr.begin(), arr.end(), lowupper);

    int sum;
    for(int i=0; i<(int)arr.size(); i++)
    {
        for(int j=0; j<(int)arr.size(); j++)
        {
            if(i==j)
                continue;
            sum = 0;
            // sumation 7-people's tall
            for(int l=0; l<(int)arr.size(); l++)
            {
                if(l!=i && l!=j)
                    sum += arr[l];
            }

            if(sum == 100)
            {
                for(int k=0; k<(int)arr.size(); k++)
                    if(k!=i && k!=j)
                        printf("%d\n",arr[k]);
                return 0;
            }
        }
    }

    return 0;
}
