#include<iostream>
#include<vector>
#include<algorithm>


int findMaxSum_sequence(std::vector<int> sequence, int end)
{
	int maxSum = 0;
	int currentSum = 0;
	for (int i = 0; i < end; ++i)
	{
		currentSum += sequence[i];
		if (currentSum > maxSum)
		{
			maxSum = currentSum;
		}
		else
		{
			if (currentSum < 0)
			{
				currentSum = 0;
			}
		}
	}
	return maxSum;
}

int findMaxSum_reverse(std::vector<int> sequence, int end)
{
	int maxSum = 0;
	int currentSum = 0;
	for (int i = sequence.size() - 1; i >= end; --i)
	{
		currentSum += sequence[i];
		if (currentSum > maxSum)
		{
			maxSum = currentSum;
		}
		else
		{
			if (currentSum < 0)
			{
				currentSum = 0;
			}
		}
	}
	return maxSum;
}

int main()
{
	int T = 0;
	while (scanf_s("%d", &T) != EOF)
	{
		for (int i = 0; i < T; ++i)
		{
			int n = 0;
			scanf_s("%d",&n);
			std::vector<int> sequence(n);
			for (int j = 0; j < n; ++j)
			{
				scanf_s("%d",&sequence.at(j));
			}
			/*for (int j = 0; j < n; ++j)
			{
				std::cout << sequence.at(j) << " ";
			}
			std::cout << std::endl;*/
			int maxSum = 0;
			for (int j = 0; j < n; ++j)
			{
				int currentSum = findMaxSum_sequence(sequence, j) + findMaxSum_reverse(sequence, j + 1);
				if (currentSum > maxSum)
				{
					maxSum = currentSum;
				}
			}
			printf("%d\n", maxSum);
		}
	}
	return 0;
}