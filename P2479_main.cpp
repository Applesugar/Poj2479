#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int T = 0;
	while (std::cin >> T)
	{
		for (int i = 0; i < T; ++i)
		{
			int n = 0;
			std::cin >> n;
			std::vector<int> sequence(n);
			for (int j = 0; j < n; ++j)
			{
				std::cin >> sequence.at(j);
			}
			for (int j = 0; j < n; ++j)
			{
				std::cout << sequence.at(j) << " ";
			}
			std::cout << std::endl;
		}
	}
	return 0;
}