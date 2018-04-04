#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int num_of_coin, desired_price;
    scanf("%d%d",&num_of_coin, &desired_price);

    vector<int> coin(num_of_coin);
    vector<int> total_price(desired_price+1,0);
    total_price[0] = 1;

    for(int i=0; i<num_of_coin; i++)
    {
        scanf("%d",&coin[i]);
    }

    for(int i=0; i<num_of_coin; i++)
        for(int j=coin[i]; j<=desired_price; j++)
        {
            total_price[j] += total_price[j - coin[i]];
        }

    printf("%d\n", total_price[desired_price]);

    return 0;
}
