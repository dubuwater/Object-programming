#include <iostream>
#include "Ram.h"
using namespace std;

Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; i++)
	{
		mem[i] = 0;
	}
}

Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}

char Ram::read(int address) {
	if (address<0&&address>size-1)
	{
		cout << "주소가 범위를 벗어남" << endl;
	}
	return mem[address];
}

void Ram::write(int address, char value) {
	mem[address] = value;
}
