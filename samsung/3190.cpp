#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int N, K, L;
vector<pair<int, int>> apple;
vector<pair<int, char>> info;
int snake_size = 1;
vector<pair<int, int>> snake_points;
int snake_dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
// dir 0:right, 1:down, 2:left, 3:top
void move(pair<int, int> start, int dir, pair<int, int>& moved)
{
	moved.first = start.first + snake_dir[dir][0];
	moved.second = start.second + snake_dir[dir][1];
}
int main()
{
	// input
	// N: board size, K: the num of apple
	scanf("%d\n%d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		int r, c;
		scanf("%d %d", &r, &c);
		apple.push_back(make_pair(r-1, c-1));
	}
	// L: the num of changing direction
	scanf("%d", &L);
	for (int i = 0; i < L; i++)
	{
		int time;
		char dir;
		scanf("%d %c", &time, &dir);
		info.push_back(make_pair(time, dir));
	}
	snake_points.push_back(make_pair(0, 0));

	int processing_time = 0;
	int curr_dir = 0;
	while (1)
	{
		pair<int, int> next_point;
		move(*snake_points.rbegin(), curr_dir, next_point);
		// if next point is wall
		if (next_point.first >= N || next_point.second >= N ||
			next_point.first < 0 || next_point.second < 0)
			break;
		// if next point is snake
		vector<pair<int, int>>::iterator snake_itr = snake_points.begin();
		for (; snake_itr != snake_points.end(); ++snake_itr)
		{
			if (snake_itr->first == next_point.first
				&& snake_itr->second == next_point.second)
				break;
		}

		// eatting apple,
		vector<pair<int, int>>::iterator apple_itr = apple.begin();
		for (; apple_itr != apple.end(); ++apple_itr)
		{
			if (apple_itr->first == next_point.first
				&& apple_itr->second == next_point.second)
			{
				snake_size++;
				snake_points.push_back(next_point);
				apple.erase(apple_itr);
				break;
			}
			else
			{
				snake_points.erase(snake_points.begin());
				snake_points.push_back(next_point);
				break;
			}
		}

		// next_direction
		vector<pair<int, char>>::iterator info_itr = info.begin();
		if (info_itr != info.end())
		{
			if (info_itr->first == processing_time)
			{
				if (info_itr->second == 'D') // cw rotation
				{
					curr_dir++;
					if (curr_dir == 4)
						curr_dir = 0;
				}
				else if (info_itr->second == 'L') // ccw rotation
				{
					curr_dir--;
					if (curr_dir == -1)
						curr_dir = 3;
				}
				info.erase(info_itr);
			}
		}
		processing_time++;
	}

	printf("%d\n", processing_time);
	system("pause");
	return 0;
}