#include<stdio.h>
#define INT16_MIN -32767


int findMaxSum_sequence(int* sequence, int end, int * Memo1)
{
	int maxSum = 0;
	int currentSum = 0;
	for (int i = 0; i < end; ++i)
	{
		currentSum += sequence[i];
		if (currentSum > maxSum)
		{
			maxSum = currentSum;
			Memo1[i] = maxSum;
		}
		else
		{
			Memo1[i] = maxSum;
			if (currentSum < 0)
			{
				currentSum = 0;
			}
		}
	}
	return maxSum;
}

int findMaxSum_reverse(int* sequence, int end, int * Memo2)
{
	int maxSum = 0;
	int currentSum = 0;
	for (int i = end - 1; i >= 0; --i)
	{
		currentSum += sequence[i];
		if (currentSum > maxSum)
		{
			maxSum = currentSum;
			Memo2[i] = maxSum;
		}
		else
		{
			Memo2[i] = maxSum;
			if (currentSum < 0)
			{
				currentSum = 0;
			}
		}
	}
	return maxSum;
}

void findFirstAndSecond(int * sequence, int n, int &first, int &second)
{
	first = INT16_MIN;
	second = INT16_MIN;
	for (int i = 0; i < n; ++i)
	{
		if (sequence[i] > first)
		{
			second = first;
			first = sequence[i];
		}
		else
		{
			if (sequence[i] > second)
			{
				second = sequence[i];
			}
		}
	}
}
int main()
{
	int T = 0;
	scanf_s("%d", &T);
		while(T--)
		{
			int Memo1[50001] = { 0 };
			int Memo2[50001] = { 0 };
			int n = 0;
			int positive_count = 0;
			scanf_s("%d",&n);
			int* sequence = new int[n];
			for (int j = 0; j < n; ++j)
			{
				scanf_s("%d",&sequence[j]);
				if (sequence[j] >= 0)
				{
					positive_count++;
				}
			}
			if (positive_count <= 1)
			{
				int first = 0;
				int second = 0;
				findFirstAndSecond(sequence, n, first, second);
//				std::cout << first << " " << second << std::endl;
				printf("%d\n", first + second);
//				system("pause");
				continue;
			}
			/*for (int j = 0; j < n; ++j)
			{
				std::cout << sequence.at(j) << " ";
			}
			std::cout << std::endl;*/
			int maxSum = 0;
			findMaxSum_sequence(sequence, n, Memo1);
			findMaxSum_reverse(sequence, n, Memo2);
			for (int j = 0; j < n; ++j)
			{
				int currentSum = Memo1[j] + Memo2[j + 1];
				if (currentSum > maxSum)
				{
					maxSum = currentSum;
				}
			}
			printf("%d\n", maxSum);
			delete[] sequence;
		}
//		system("pause");
	return 0;
}