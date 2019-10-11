#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	//상수 : 변하지 않는 수, 값을 한번 지정해놓으면 바꿀 수 없다.
	//상수는 선언과 동시에 값을 지정해두어야
	const int	iAttack = 0x00000001;	//1
	const int	iArmor = 0x00000002;	//10
	const int	iHP = 0x00000004;		//100
	const int	iMP = 0x00000008;		//1000
	const int	iCritical = 0x00000010; //10000

	// 001 | 100 = 00101 | 10000 = 10101
	int iBuf = iAttack | iHP | iCritical;

	//연산자 축약형 : 연산자를 줄여서 사용할 수 있다.
	//아래를 풀어서 쓰면 iBuf = iBuf ^ iHP;
	//10101 ^ 00100 = 10001
	iBuf ^= iHP;

	//10001 ^ 00100 = 10101;
	iBuf ^= iHP;

	cout << "Attack : " << (iBuf & iAttack) << endl;
	cout << "Armor : " << (iBuf & iArmor) << endl;
	cout << "HP : " << (iBuf & iHP) << endl;
	cout << "MP : " << (iBuf & iMP) << endl;
	cout << "Critical : " << (iBuf & iCritical) << endl;

	/*
	쉬프트 연산자 : <<, >> 값 대 값을 연산하여 값으로 나오게 된다.
	이 연산자 또한 이진수 단위의 연산을 하게 된다.
	20 << 2 = 80
	20 << 3 = 160
	20 << 4 = 320
	20을 2진수로 변환한다.
	1010000
	10100000
	101000000

	20 >> 2 = 5
	20 >> 3 = 2
	20 >> 4 = 1
	101
	10
	1


	*/

	int iHigh = 187;
	int iLow = 13560;

	int iNumber = iHigh;

	//iNumber에는 187이 들어가 있다. 이 값을 <- 이 방향으로 16비트 이동시키면
	//상위 16비트에 값이 들어가게 된다.
	iNumber <<= 16;


	//하위 16비트를 채운다.
	iNumber |= iLow;

	//High 값을 출력한다.
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	//증감연산자 : ++,-- 가 있다. 1증가, 1감소이다.
	iNumber = 10;

	//전치
	++iNumber;

	//후치
	iNumber++;

	if ((iBuf & iAttack) != 0)
	{
		cout << "Attack 버프가 있습니다." << endl;
	}

	if ((iBuf & iArmor )!= 0)
	{
		cout << "Armor 버프가 있습니다." << endl;
	}

	if ((iBuf & iHP) != 0)
	{
		cout << "HP 버프가 있습니다." << endl;
	}

	if ((iBuf & iMP) != 0)
	{
		cout << "MP 버프가 있습니다." << endl;
	}
	if ((iBuf & iCritical) != 0)
	{
		cout << "Critical 버프가 있습니다." << endl;
	}

	cout << "숫자를 입력하세요 : ";
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "10~20 사이의 숫자입니다." << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "10~20 사이의 숫자입니다." << endl;
	else if (31 <= iNumber && iNumber <= 40)
		cout << "10~20 사이의 숫자입니다." << endl;
	else
		cout << "그 외의 숫자입니다." << endl;


	//난수 발생
	srand((unsigned int)time(0));

	cout << rand()%100 << endl;
	cout << rand() % 100 << endl;
	cout << (rand() % 101 + 100) << endl;
	cout << (rand() % 10000 / 100.f) << endl;


	
	int iUpgrade = 0;
	cout << "Upgrade 기본 수치를 입력하세요 : ";
	cin >> iUpgrade;

	//강화 확률을 구한다.
	float	fPercent = rand() % 10000 / 100.f;

	//강화 확률 : 업그레이드가 0~3 : 100% 성공 4~6 : 40% 7~9 : 10%
	//10~13 : 1% 14~15 : 0.01%
	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "강화 성공" << endl;
	else if (4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < 0.01f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}

	return 0;
}