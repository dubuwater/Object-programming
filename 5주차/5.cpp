#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Rectangle {
public:
	int width;
	int height;
	int getArea();
};

int Rectangle::getArea() {
	return width * height;
}

//1번 예제
int main() {
	
	string name[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "이름>>";
		getline(cin, name[i]);
	}

	string result;
	result = name[0];
	for (int j = 1; j < 5; j++)
	{
		if (result<=name[j])
		{
			result = name[j];
		}
	}

	cout << "사전에서 가장 뒤에 나오는 문자열은 " << result;
	

	//2번 예제
	/*
	vector<string> name(5);

	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ">>";
		getline(cin, name[i]);
	}

	string result;
	result = name[0];
	for (int j = 1; j < 5; j++)
	{
		if (result<=name[j])
		{
			result = name[j];
		}
	}

	cout << "사전에서 가장 뒤에 나오는 이름은 " << result;
	*/

	//3번 예제
	/*
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "사각형의 면적은 " << rect.getArea() << endl;
	*/

	//4번 예제
	/*
	string s;
	string result;
	string find;
	string replace;
	cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << endl;
	getline(cin, s, '&');

	cin.ignore();

	cout << "find: ";
	getline(cin, find);

	cout << "replace: ";
	getline(cin, replace);

	int start = 0;
	while (true)
	{
		int index = s.find(find, start);

		if (index==-1)
		{
			break;
		}
		s.replace(index, find.length(), replace);
		start = index + replace.length();
	}

	cout << s << endl;
	*/
}
