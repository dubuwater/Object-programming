#include <iostream>
#include "dec.h"
using namespace std;
int main()
{
    // ��ü ������ �����ϴ� ���� (����ڰ� ���� ���Ḧ ������ ������ �ݺ�)
    do
    {
        introduction(); // ���� �ȳ�
        take_turn(); // ���� ���� �÷���
        end_game(); // ��� ��� �� ���� ����
        print_score(); // ������ ���
        if (!ask_restart()) // �ٽ� ���� ���� Ȯ�� �� ���� �Ǵ� �ݺ�
            break; //����
        reset_game(); // ���� ���� �ʱ�ȭ
    } while (true);
    cout << "������ �����մϴ�.\n";
	return 0;
}
