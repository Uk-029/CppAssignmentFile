#include <iostream>
#define MAIN 7

#if MAIN == 1							// 참조자

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
	int& another_a = a;					// another_a 는 a 의 또다른 이름 이라고 컴파일러에게 알려주는 것과 같다.

	another_a = 5;
	std::cout << "a : " << a << std::endl;			// another_a = 5; 은 곧 a = 5;와 같은 의미를 가지므로, 5를 출력
	std::cout << "another_a : " << another_a << std::endl;
}
// 레퍼런스는 반드시 처음에 누구의 별명이 될 것인지 지정해야한다.
// 따라서 int& another_a; 은 불가능하다.
// 반면 int* p; 은 가능 (레퍼런스와 포인터의 차이)
// 레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다.
// 레퍼런스는 메모리 상에 존재하지 않을 수 도 있다. (단 예외가 있다.)
#elif MAIN == 3

int change_val(int& p) {
	p = 3;

	return 0;
}
int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(number);					// number = p; 와 같다
	std::cout << number << std::endl;
}

#elif MAIN == 4
								// 여러가지 레퍼런스 예시's
int main() {
	int x;
	int& y = x;						// y는 x의 또 다른 이름
	int& z = y;						// z는 y, 즉 x의 또 다른 이름
								// Cpp에선 참조자의 참조자를 만드는 것은 금지되어 있다.
	x = 1;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	y = 2;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	z = 3;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}

// int a, b;
// int& arr[2] = { a, b };
// 처럼 레퍼런스의 배열, 레퍼런스의 페러런스, 레퍼런스의 포인터는 불가능하다.
// (특별한 경우를 제외하면 레퍼런스는 메모리를 가지지 않지만 배열을 메모리를 가지기에 모순이 생기기 때문)
// 그렇다고 해서 그 반대인 배열들의 참조가가 불가능한 것은 아니다.

#elif MAIN == 5							// 배열의 레퍼런스

int main() {
	int arr[3] = { 1, 2, 3 };
	int(&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	return 0;
}

#elif MAIN == 6							//레퍼런스를 리턴하는 함수

int function() {						// function이 종료되고 나면 a 는 메모리에서 사라진다. -> 지역변수의 레퍼런스를 리턴할 순 없다.
	int a = 2;
	return a;
}

int main() {							// function의 a의 값이 b에 복사되었다.
	int b = function();					// b = 2;
	std::cout << b << std::endl;
}

#elif MAIN == 7							// 외부 변수의 레퍼런스를 리턴

int& function(int& a) {						// ()안에 int& a를 넣음 (없을 경우 오류 발생)
	a = 5;
	return a;
}

int main() {
	int b = 2;
	int c = function(b);
	return 0;
}
/*								// 참조자가 아닌 값을 리턴하는 함수를 참조자로 받을 경우 오류 발생
int function() {
  int a = 5;
  return a;
}

int main() {
  int& c = function();						// 함수의 리턴값은 해당 문장이 끝난 후 바로 사라지는 값이기 때문
  return 0;
}
-----------------------------------------------------------------// 하지만 예외가 존재함
int function() {
  int a = 5;
  return a;
}

int main() {
  const int& c = function();					// const가 추가됨 -> 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장
  std::cout << "c : " << c << std::endl;
  return 0;
}
*/
#endif
