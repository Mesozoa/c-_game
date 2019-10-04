#include <iostream>
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

	return 0;
}