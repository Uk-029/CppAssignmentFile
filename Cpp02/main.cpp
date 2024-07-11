#include <iostream>
#define MAIN 7

#if MAIN == 1												// ������

int change_val(int* p) {
	*p = 3;

	return 0;
}
int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
}

#elif MAIN == 2	

int main() {
	int a = 3;
	int& another_a = a;										// another_a �� a �� �Ǵٸ� �̸� �̶�� �����Ϸ����� �˷��ִ� �Ͱ� ����.

	another_a = 5;
	std::cout << "a : " << a << std::endl;					// another_a = 5; �� �� a = 5;�� ���� �ǹ̸� �����Ƿ�, 5�� ���
	std::cout << "another_a : " << another_a << std::endl;
}
// ���۷����� �ݵ�� ó���� ������ ������ �� ������ �����ؾ��Ѵ�.
// ���� int& another_a; �� �Ұ����ϴ�.
// �ݸ� int* p; �� ���� (���۷����� �������� ����)
// ���۷����� �� �� ������ �Ǹ� ����� �ٸ� ���� ������ �� �� ����.
// ���۷����� �޸� �� �������� ���� �� �� �ִ�. (�� ���ܰ� �ִ�.)
#elif MAIN == 3

int change_val(int& p) {
	p = 3;

	return 0;
}
int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(number);										// number = p; �� ����
	std::cout << number << std::endl;
}

#elif MAIN == 4
															// �������� ���۷��� ����'s
int main() {
	int x;
	int& y = x;												// y�� x�� �� �ٸ� �̸�
	int& z = y;												// z�� y, �� x�� �� �ٸ� �̸�
															// Cpp���� �������� �����ڸ� ����� ���� �����Ǿ� �ִ�.
	x = 1;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	y = 2;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	z = 3;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}

// int a, b;
// int& arr[2] = { a, b };
// ó�� ���۷����� �迭, ���۷����� �䷯����, ���۷����� �����ʹ� �Ұ����ϴ�.
// (Ư���� ��츦 �����ϸ� ���۷����� �޸𸮸� ������ ������ �迭�� �޸𸮸� �����⿡ ����� ����� ����)
// �׷��ٰ� �ؼ� �� �ݴ��� �迭���� �������� �Ұ����� ���� �ƴϴ�.

#elif MAIN == 5												// �迭�� ���۷���

int main() {
	int arr[3] = { 1, 2, 3 };
	int(&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	return 0;
}

#elif MAIN == 6												//���۷����� �����ϴ� �Լ�

int function() {											// function�� ����ǰ� ���� a �� �޸𸮿��� �������. -> ���������� ���۷����� ������ �� ����.
	int a = 2;
	return a;
}

int main() {												// function�� a�� ���� b�� ����Ǿ���.
	int b = function();										// b = 2;
	std::cout << b << std::endl;
}

#elif MAIN == 7												// �ܺ� ������ ���۷����� ����

int& function(int& a) {										// ()�ȿ� int& a�� ���� (���� ��� ���� �߻�)
	a = 5;
	return a;
}

int main() {
	int b = 2;
	int c = function(b);
	return 0;
}
/*															// �����ڰ� �ƴ� ���� �����ϴ� �Լ��� �����ڷ� ���� ��� ���� �߻�
int function() {
  int a = 5;
  return a;
}

int main() {
  int& c = function();										// �Լ��� ���ϰ��� �ش� ������ ���� �� �ٷ� ������� ���̱� ����
  return 0;
}
------------------------------------------------------------// ������ ���ܰ� ������
int function() {
  int a = 5;
  return a;
}

int main() {
  const int& c = function();								// const�� �߰��� -> ��� ���۷����� ���ϰ��� �ް� �Ǹ� �ش� ���ϰ��� ������ ����
  std::cout << "c : " << c << std::endl;
  return 0;
}
*/
#endif