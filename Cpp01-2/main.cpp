#include <iostream>
#define MAIN 5

#if MAIN == 1										// ���� ���� ��� (C�� ����)

int main() {
	int i;
	char c;
	double d;
	float f;
}

#elif MAIN == 2										// �迭�̳� �����͸� �����ϴ� ��� (C�� ����)

int main() {
	int arr[10];
	int* parr = arr;
	int i;
	int* pi = &i;
}

#elif MAIN == 3										// for�� (C�� ����)

int main() {
	int i;
	for (i = 0; i < 10; i++) {
		std::cout << i << std::endl;
	}
													// 0~9���� �� ����
	int sum = 0;
	for (i = 1; i <= 10; i++) {
		sum += i;
	}
	std::cout << "���� : " << sum << std::endl;
													// 0~10������ �� ����
}

#elif MAIN == 4										// while�� �� if - else�� (C�� ����)

int main() {
	int lucky_number = 7;
	std::cout << "�� ��� ���� ���߾� ������~" << std::endl;

	int user_input;

	while (1) {
		std::cout << "�Է� : ";
		std::cin >> user_input;						// cin : C������ scanf (%c, %d �� �ڷ��� ������ �� �ʿ� ����)
		if (lucky_number == user_input) {
			std::cout << "���߼̽��ϴ�~~" << std::endl;
			break;
		}
		else {
			std::cout << "�ٽ� �����غ�����~" << std::endl;
		}
  }
}

#elif MAIN == 5										// switch�� (C�� ����)

int main() {
	int user_input;
	std::cout << "���� ������ �����մϴ�.(1~3������ ��ȣ�� �Է��Ͻÿ�.)" << std::endl;
	std::cout << "1. �̸� " << std::endl;
	std::cout << "2. ���� " << std::endl;
	std::cout << "3. �Ҽ� " << std::endl;
	std::cout << "�Է� : ";
	std::cin >> user_input;

	switch (user_input) {
	case 1:
		std::cout << "������" << std::endl;
		break;

	case 2:
		std::cout << "����" << std::endl;
		break;

	case 3:
		std::cout << "�ѱ����д��б�" << std::endl;
		break;

	default:
		std::cout << "�߸��� ��ȣ�Դϴ�." << std::endl;
		break;
	}
}

#endif