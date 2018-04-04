#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    scanf("%d",&test_case);

    while(test_case--)
    {
        int num_of_coin;
        scanf("%d",&num_of_coin);

        vector<int> coins_price(num_of_coin);
        for(int i=0; i<num_of_coin; i++)
            scanf("%d",&coins_price[i]);

        int total_price[10001] = {0,};
        total_price[0] = 1;
        int desired_price;
        scanf("%d",&desired_price);

        for(int i=0; i<num_of_coin; i++)
        {
            for(int j=coins_price[i]; j<=desired_price; j++)
            {
                total_price[j] += total_price[j - coins_price[i]];
            }
        }

        printf("%d\n", total_price[desired_price]);
    }
    return 0;
}
