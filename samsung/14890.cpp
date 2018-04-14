#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int N, L;
int input[100][100];
bool slope[100][100];

int main()
{
	scanf("%d%d", &N, &L);

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			scanf("%d", &input[y][x]);

	memset(slope, 0, sizeof slope);

	int results = 0;
	// row-wise search
	for (int y = 0; y < N; y++)
	{
		int step_cnt = 0;
		int ladder_cnt = 0;
		for (int x = 0; x < N - 1; x++)
		{
			int curr = input[y][x];
			int next = input[y][x + 1];

			if (curr == next)
				ladder_cnt++;
			else if (abs(curr - next) == 1) // if you need a ladder,
			{
				if (curr > next) // down slope
				{
					for (int i = 0; i < L; i++)
					{
						int next_x = x + 1 + i;
						if (next_x >= N)
						{
							step_cnt = -1;
							break;
						}

						if (i != 0 && input[y][next_x] != next)
						{
							step_cnt = -1;
							break;
						}

						if (slope[y][next_x]) // if already there is a ladder,
						{
							step_cnt = -1;
							break;
						}

						slope[y][next_x] = true;
					}
				}
				else // up slope
				{
					if (ladder_cnt >= (L - 1))
					{
						ladder_cnt = 0;
						for (int i = 0; i < L; i++)
						{
							int prev_x = x - i;
							if (prev_x < 0)
							{
								step_cnt = -1;
								break;
							}

							if (i != 0 && input[y][prev_x] != curr)
							{
								step_cnt = -1;
								break;
							}

							if (slope[y][x - i])
							{
								step_cnt = -1;
								break;
							}

							slope[y][x - i] = true;
						}
					}
					else
					{
						step_cnt = -1;
						break;
					}
				}
			}
			else
			{
				step_cnt = -1;
				break;
			}
			//step_cnt++;
		}
		if (step_cnt != -1)
			results++;
	}

	memset(slope, 0, sizeof slope);
	// col-wise search
	for (int y = 0; y < N; y++)
	{
		int step_cnt = 0;
 		int ladder_cnt = 0;
		for (int x = 0; x < N - 1; x++)
		{
			int curr = input[x][y];
			int next = input[x + 1][y];

			if (curr == next)
				ladder_cnt++;
			else if (abs(curr - next) == 1) // if you need a ladder,
			{
				if (curr > next) // down slope
				{
					for (int i = 0; i < L; i++)
					{
						int next_x = x + 1 + i;
						if (next_x >= N) // if array overflow
						{
							step_cnt = -1;
							break;
						}

						if (i != 0 && input[next_x][y] != next)
						{
							step_cnt = -1;
							break;
						}

						if (slope[next_x][y]) // if already there is a ladder,
						{
							step_cnt = -1;
							break;
						}

						slope[next_x][y] = true;
					}
				}
				else // up slope
				{
					if (ladder_cnt >= (L - 1))
					{
						ladder_cnt = 0;
						for (int i = 0; i < L; i++)
						{
							if (slope[x - i][y])
							{
								step_cnt = -1;
								break;
							}
							slope[x - i][y] = true;
						}
					}
					else
					{
						step_cnt = -1;
						break;
					}
				}
			}
			else
			{
				step_cnt = -1;
				break;
			}
		}
		if (step_cnt != -1)
			results++;
	}

	printf("%d\n", results);
}