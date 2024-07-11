#include <iostream>
#define MAIN 5

#if MAIN == 1										// 변수 선언 방식 (C와 동일)

int main() {
	int i;
	char c;
	double d;
	float f;
}

#elif MAIN == 2										// 배열이나 포인터를 정의하는 방식 (C와 동일)

int main() {
	int arr[10];
	int* parr = arr;
	int i;
	int* pi = &i;
}

#elif MAIN == 3										// for문 (C와 동일)

int main() {
	int i;
	for (i = 0; i < 10; i++) {
		std::cout << i << std::endl;
	}
													// 0~9까지 수 나열
	int sum = 0;
	for (i = 1; i <= 10; i++) {
		sum += i;
	}
	std::cout << "합은 : " << sum << std::endl;
													// 0~10까지의 수 총합
}

#elif MAIN == 4										// while문 및 if - else문 (C와 동일)

int main() {
	int lucky_number = 7;
	std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;

	int user_input;

	while (1) {
		std::cout << "입력 : ";
		std::cin >> user_input;						// cin : C에서의 scanf (%c, %d 등 자료형 구분을 할 필요 없음)
		if (lucky_number == user_input) {
			std::cout << "맞추셨습니다~~" << std::endl;
			break;
		}
		else {
			std::cout << "다시 생각해보세요~" << std::endl;
		}
  }
}

#elif MAIN == 5										// switch문 (C와 동일)

int main() {
	int user_input;
	std::cout << "인적 사항을 열람합니다.(1~3사이의 번호를 입력하시오.)" << std::endl;
	std::cout << "1. 이름 " << std::endl;
	std::cout << "2. 성별 " << std::endl;
	std::cout << "3. 소속 " << std::endl;
	std::cout << "입력 : ";
	std::cin >> user_input;

	switch (user_input) {
	case 1:
		std::cout << "전정욱" << std::endl;
		break;

	case 2:
		std::cout << "남성" << std::endl;
		break;

	case 3:
		std::cout << "한국공학대학교" << std::endl;
		break;

	default:
		std::cout << "잘못된 번호입니다." << std::endl;
		break;
	}
}

#endif