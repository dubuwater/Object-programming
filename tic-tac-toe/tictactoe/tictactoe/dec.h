#ifndef DEC_H
#define DEC_H

void introduction(); // ������ ������ �� �Ұ� �� ��Ģ ����
bool is_winner(); // ���ӿ��� �¸� ������ Ȯ��
bool filled_up();  // �������� ��� ä�������� Ȯ�� (���º� ���� üũ)
void draw(); // ���� ���� ���¸� ȭ�鿡 ���
void set_position(); // �÷��̾��� ��ġ �Է� �� ��ȿ�� �˻�
void update_board(); // ���õ� ��ġ�� ���� �÷��̾��� ��ũ�� ������Ʈ
void change_player(); // �÷��̾ �����ư��� ���� (1 �� 2)
void take_turn(); // ���� ���� �÷��̸� ���� (���� ����)
void end_game(); // ���� ���� �� ��� ��� �� �¸��� ���� ����
void reset_game();  // ������ �ʱ� ���·� �ʱ�ȭ
bool ask_restart();   // ����ڿ��� �ٽ� ���� ���θ� ���� �Լ�
void print_score();   // ���� �÷��̾��� ������ ������ ȭ�鿡 ���

// ���� ���� ���� ���� (X�� O �÷��̾��� �¸� Ƚ��)
extern int xWins;
extern int oWins;

#endif

