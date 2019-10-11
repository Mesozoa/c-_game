#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	

	int iAnswer[9] = {};
	srand((unsigned int)time(0));

	for (int i = 0; i < 9; i++)
	{
		iAnswer[i] = i + 1;
	}

	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iAnswer[idx1];
		iAnswer[idx1] = iAnswer[idx2];
		iAnswer[idx2] = iTemp;

	}

	int Answer1 = iAnswer[0];
	int Answer2 = iAnswer[1];
	int Answer3 = iAnswer[2];


	while (1)
	{
		int strike = 0;
		int ball = 0;
		int input[3] = {};


		cin >> input[0] >> input[1] >> input[2];
		if (input[0] == 0 || input[1] == 0 || input[2] == 0)
		{
			cout << "게임이 종료됩니다." << endl;
			return 1;
		}

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (input[j] == iAnswer[k])
				{
					if (j == k)
					{
						++strike;
					}
					else
					{
						++ball;
					}
				}
			}
		}

		if (strike == 3)
		{
			cout << "게임 승리" << endl;
			break;
		}
		else
		{
			cout << "Strike : " << strike << endl;
			cout << "Ball : " << ball << endl;
		}

	}

	cout << "정답 : " << Answer1 << ' ' << Answer2 << ' ' << Answer3 << endl;

	return 0;
}