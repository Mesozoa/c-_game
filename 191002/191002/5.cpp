#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	//��� : ������ �ʴ� ��, ���� �ѹ� �����س����� �ٲ� �� ����.
	//����� ����� ���ÿ� ���� �����صξ��
	const int	iAttack = 0x00000001;	//1
	const int	iArmor = 0x00000002;	//10
	const int	iHP = 0x00000004;		//100
	const int	iMP = 0x00000008;		//1000
	const int	iCritical = 0x00000010; //10000

	// 001 | 100 = 00101 | 10000 = 10101
	int iBuf = iAttack | iHP | iCritical;

	//������ ����� : �����ڸ� �ٿ��� ����� �� �ִ�.
	//�Ʒ��� Ǯ� ���� iBuf = iBuf ^ iHP;
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
	����Ʈ ������ : <<, >> �� �� ���� �����Ͽ� ������ ������ �ȴ�.
	�� ������ ���� ������ ������ ������ �ϰ� �ȴ�.
	20 << 2 = 80
	20 << 3 = 160
	20 << 4 = 320
	20�� 2������ ��ȯ�Ѵ�.
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

	//iNumber���� 187�� �� �ִ�. �� ���� <- �� �������� 16��Ʈ �̵���Ű��
	//���� 16��Ʈ�� ���� ���� �ȴ�.
	iNumber <<= 16;


	//���� 16��Ʈ�� ä���.
	iNumber |= iLow;

	//High ���� ����Ѵ�.
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	//���������� : ++,-- �� �ִ�. 1����, 1�����̴�.
	iNumber = 10;

	//��ġ
	++iNumber;

	//��ġ
	iNumber++;

	if ((iBuf & iAttack) != 0)
	{
		cout << "Attack ������ �ֽ��ϴ�." << endl;
	}

	if ((iBuf & iArmor )!= 0)
	{
		cout << "Armor ������ �ֽ��ϴ�." << endl;
	}

	if ((iBuf & iHP) != 0)
	{
		cout << "HP ������ �ֽ��ϴ�." << endl;
	}

	if ((iBuf & iMP) != 0)
	{
		cout << "MP ������ �ֽ��ϴ�." << endl;
	}
	if ((iBuf & iCritical) != 0)
	{
		cout << "Critical ������ �ֽ��ϴ�." << endl;
	}

	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "10~20 ������ �����Դϴ�." << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "10~20 ������ �����Դϴ�." << endl;
	else if (31 <= iNumber && iNumber <= 40)
		cout << "10~20 ������ �����Դϴ�." << endl;
	else
		cout << "�� ���� �����Դϴ�." << endl;


	//���� �߻�
	srand((unsigned int)time(0));

	cout << rand()%100 << endl;
	cout << rand() % 100 << endl;
	cout << (rand() % 101 + 100) << endl;
	cout << (rand() % 10000 / 100.f) << endl;


	
	int iUpgrade = 0;
	cout << "Upgrade �⺻ ��ġ�� �Է��ϼ��� : ";
	cin >> iUpgrade;

	//��ȭ Ȯ���� ���Ѵ�.
	float	fPercent = rand() % 10000 / 100.f;

	//��ȭ Ȯ�� : ���׷��̵尡 0~3 : 100% ���� 4~6 : 40% 7~9 : 10%
	//10~13 : 1% 14~15 : 0.01%
	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "��ȭ ����" << endl;
	else if (4 <= iUpgrade && iUpgrade <= 6)
	{
		if (fPercent < 40.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (7 <= iUpgrade && iUpgrade <= 9)
	{
		if (fPercent < 10.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (10 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent < 1.f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent < 0.01f)
			cout << "��ȭ ����" << endl;
		else
			cout << "��ȭ ����" << endl;
	}

	return 0;
}