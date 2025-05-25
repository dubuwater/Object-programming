#include <iostream>
#include "dec.h"

// ���� ���� ����: ���� ����, ���� �÷��̾�, ��ġ �Է�, �÷��̾ �¸� Ƚ��
using namespace std;
string board[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
int player = 1;
int position = 0;
int xWins = 0;
int oWins = 0;

// ���� ���� �� ����ڿ��� ���� ����� ��Ģ �ȳ�
void introduction()
{
	cout << "Press [Enter] to begin: ";
	getchar(); // ȭ�� ���� (����� �Է� ���)
	cout << "\n";

	cout << "\n";
	cout << "***********\n";
	cout << "Tic-Tac-Toe\n";
	cout << "***********\n";

	cout << "Player 1) X\n";
	cout << "Player 2) O\n";

	cout << "The 3x3 grid is shown below:\n\n";

	cout << "     |     |      \n";
	cout << "  1  |  2  |  3   \n";
	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";
	cout << "  4  |  5  |  6   \n";
	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";
	cout << "  7  |  8  |  9   \n";
	cout << "     |     |      \n\n";

}


// ���� ���� ���¿��� �¸� ������ �˻�
bool is_winner()
{
	bool winner = false; // �ʱ� ���� false�� ����
	// ����, ����, �밢�� �¸� ���� Ȯ��, ��ĭ ���� Ȯ��
	//���� �˻�
	if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ")
	{
		winner = true;
	}
	else if ((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ")
	{
		winner = true;
	}

	else if ((board[6] == board[7]) && (board[7] == board[8]) && board[6] != " ")
	{
		winner = true;
	}

	//���� �˻�

	else if ((board[0] == board[3]) && (board[3] == board[6]) && board[0] != " ")
	{
		winner = true;
	}

	else if ((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " ")
	{
		winner = true;
	}

	else if ((board[2] == board[5]) && (board[5] == board[8]) && board[2] != " ")
	{
		winner = true;
	}

	//�밢�� �˻�

	else if ((board[0] == board[4]) && (board[4] == board[8]) && board[0] != " ")
	{
		winner = true;
	}

	else if ((board[2] == board[4]) && (board[4] == board[6]) && board[2] != " ")
	{
		winner = true;
	}

	return winner;

}

// ���尡 �� á���� Ȯ���Ͽ� ���º� ���� �Ǵ�
bool filled_up()
{
	bool filled = true; // �ʱⰪ�� true�� ����

	for (int i = 0; i < 9; i++) //��� ĭ�� ��ȸ�ϸ鼭
	{
		if (board[i] == " ") //��ĭ�� �ִٸ�
		{
			filled = false; //false�� ����
		}
	}

	return filled; //filled ����
}


// ���� ���� ���¸� ���
void draw()
{
	cout << "     |     |      \n";
	cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";
	cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
	cout << "_____|_____|_____ \n";
	cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
	cout << "     |     |      \n";
	cout << "\n";

}


// �÷��̾ ���� ��ġ�� �Է��ϰ�, �Է� ���� ��ȿ�� �˻�
void set_position()
{
	cout << "Player " << player << "'s turn (Enter: 1-9)";   //1-9 (Enter: (1-9))
	while (!(cin >> position)) //����ڷκ��� �Է��� �޾� position�� ����, ���ڰ� �ƴ϶�� �ݺ��� ����
	{
		cout << "Please enter a valid number between (1-9)" << endl;
		cin.clear();  //���� �÷��� �ʱ�ȭ
		cin.ignore(); //���ۿ� �����ִ� ���� �Է��� ����
	}
	cout << endl;

	while (board[position - 1] != " ") //�ش� ��ġ�� �̹� ��� ���̸� �ٽ� �Է� �䱸
	{
		cout << "Oops, that position is already filled\nTry again\n";
		cout << "Player " << player << "'s Turn (Enter 1-9): ";
		cin >> position;
		cout << "\n";
	}

}

// ���õ� ��ġ�� �÷��̾��� ��ũ(X/O)�� ���带 ������Ʈ
void update_board()
{

	if (player % 2 == 1) { //�÷��̾ 1�̶��
		board[position - 1] = "X";   //1-9        0-8
	}
	else //�÷��̾ 2���
	{
		board[position - 1] = "O";
	}
}

// �÷��̾� �� ���� (1 <-> 2)
void change_player() {
	if (player == 1) { //�÷��̾ 1�̶��
		player++; //2�� �ٲٰ�
	}
	else { //�÷��̾ 2���
		player--; //1�� �ٲ۴�
	}
}

// ���� ������ ���� �ֿ� ���� (���� ���Ǳ��� �ݺ�)
void take_turn()
{
	while (!is_winner() && !filled_up()) // ���ڰ� ���� ���尡 ���� �� ���� �ʴٸ� �ݺ�
	{
		//invoking the functions
		set_position(); // �÷��̾ ĭ ����
		update_board(); // ĭ ���� �� ���� ���� ����
		change_player(); // �÷��̾� ��ü
		draw(); // ���� ���� ���
	}
}

// ���� ���� �� ��� ��� �� �¸��� ���� ����
void end_game()
{
	if (is_winner()) // ���ڰ� �ִٸ�

	{	// change_player�� �̹� ȣ���!
		int winnerPlayer = (player == 1) ? 2 : 1; //������ �ٵϵ��� ���� �÷��̾�(=�̱� ���)
		cout << "Player " << winnerPlayer << " (" << (winnerPlayer == 1 ? "X" : "O") << ") wins!" << endl; // ���ڰ� �ִٴ� �޽��� ���
		if (winnerPlayer == 1) //winnerPlayer�� 1�̸�
			xWins++; // Player 1(X)�� ����(xWins)�� 1 �ø���
		else
			oWins++; //�ƴϸ� Player 2(O)�� ����(oWins)�� 1 �ø�
	}
	else if (filled_up()) // ���ºζ��(���� ���� ���尡 �� á�ٸ�)
	{
		cout << "There is a tie!" << endl; // ���ºζ�� �޽��� ���
	}
}

// �÷��̾��� ������ ���� ���
void print_score()
{
	cout << "\n���� ������:\n";
	cout << "Player 1 (X): " << xWins << endl;
	cout << "Player 2 (O): " << oWins << endl;
	cout << endl;
}

// ����ڿ��� ����� ���� Ȯ��
bool ask_restart()
{
	char response; //����� �����ϴ� ����
	while (true)
	{
		cout << "������ �ٽ� �����Ͻðڽ��ϱ�? (Y/N): ";
		cin >> response;
		if (response == 'Y' || response == 'y')
			return true;
		else if (response == 'N' || response == 'n')
			return false;
		else
			cout << "Y �Ǵ� N���� �Է����ּ���." << endl;
	}
}

// ���� ���� �ʱ�ȭ
void reset_game()
{
	for (int i = 0; i < 9; ++i) //��� ĭ�� ��ȸ�ϸ鼭
		board[i] = " "; // ��ĭ���� �ʱ�ȭ
	player = 1; //�÷��̾� �ʱ�ȭ
	position = 0; //��ġ �ʱ�ȭ
}