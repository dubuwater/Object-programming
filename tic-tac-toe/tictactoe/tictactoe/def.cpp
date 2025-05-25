#include <iostream>
#include "dec.h"

// 전역 변수 선언: 게임 보드, 현재 플레이어, 위치 입력, 플레이어별 승리 횟수
using namespace std;
string board[9] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };
int player = 1;
int position = 0;
int xWins = 0;
int oWins = 0;

// 게임 시작 시 사용자에게 게임 방법과 규칙 안내
void introduction()
{
	cout << "Press [Enter] to begin: ";
	getchar(); // 화면 정지 (사용자 입력 대기)
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


// 현재 보드 상태에서 승리 조건을 검사
bool is_winner()
{
	bool winner = false; // 초기 값을 false로 설정
	// 가로, 세로, 대각선 승리 조건 확인, 빈칸 여부 확인
	//가로 검사
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

	//세로 검사

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

	//대각선 검사

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

// 보드가 꽉 찼는지 확인하여 무승부 여부 판단
bool filled_up()
{
	bool filled = true; // 초기값은 true로 설정

	for (int i = 0; i < 9; i++) //모든 칸을 순회하면서
	{
		if (board[i] == " ") //빈칸이 있다면
		{
			filled = false; //false를 저장
		}
	}

	return filled; //filled 리턴
}


// 현재 보드 상태를 출력
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


// 플레이어가 보드 위치를 입력하고, 입력 값의 유효성 검사
void set_position()
{
	cout << "Player " << player << "'s turn (Enter: 1-9)";   //1-9 (Enter: (1-9))
	while (!(cin >> position)) //사용자로부터 입력을 받아 position에 저장, 숫자가 아니라면 반복문 실행
	{
		cout << "Please enter a valid number between (1-9)" << endl;
		cin.clear();  //오류 플래그 초기화
		cin.ignore(); //버퍼에 남아있는 오류 입력을 지움
	}
	cout << endl;

	while (board[position - 1] != " ") //해당 위치가 이미 사용 중이면 다시 입력 요구
	{
		cout << "Oops, that position is already filled\nTry again\n";
		cout << "Player " << player << "'s Turn (Enter 1-9): ";
		cin >> position;
		cout << "\n";
	}

}

// 선택된 위치에 플레이어의 마크(X/O)로 보드를 업데이트
void update_board()
{

	if (player % 2 == 1) { //플레이어가 1이라면
		board[position - 1] = "X";   //1-9        0-8
	}
	else //플레이어가 2라면
	{
		board[position - 1] = "O";
	}
}

// 플레이어 턴 변경 (1 <-> 2)
void change_player() {
	if (player == 1) { //플레이어가 1이라면
		player++; //2로 바꾸고
	}
	else { //플레이어가 2라면
		player--; //1로 바꾼다
	}
}

// 게임 진행을 위한 주요 루프 (종료 조건까지 반복)
void take_turn()
{
	while (!is_winner() && !filled_up()) // 승자가 없고 보드가 가득 차 있지 않다면 반복
	{
		//invoking the functions
		set_position(); // 플레이어가 칸 선택
		update_board(); // 칸 선택 후 보드 상태 갱신
		change_player(); // 플레이어 교체
		draw(); // 보드 상태 출력
	}
}

// 게임 종료 후 결과 출력 및 승리자 점수 누적
void end_game()
{
	if (is_winner()) // 승자가 있다면

	{	// change_player가 이미 호출됨!
		int winnerPlayer = (player == 1) ? 2 : 1; //마지막 바둑돌을 놓은 플레이어(=이긴 사람)
		cout << "Player " << winnerPlayer << " (" << (winnerPlayer == 1 ? "X" : "O") << ") wins!" << endl; // 승자가 있다는 메시지 출력
		if (winnerPlayer == 1) //winnerPlayer가 1이면
			xWins++; // Player 1(X)의 점수(xWins)를 1 올리고
		else
			oWins++; //아니면 Player 2(O)의 점수(oWins)를 1 올림
	}
	else if (filled_up()) // 무승부라면(승자 없이 보드가 꽉 찼다면)
	{
		cout << "There is a tie!" << endl; // 무승부라는 메시지 출력
	}
}

// 플레이어의 누적된 점수 출력
void print_score()
{
	cout << "\n현재 점수판:\n";
	cout << "Player 1 (X): " << xWins << endl;
	cout << "Player 2 (O): " << oWins << endl;
	cout << endl;
}

// 사용자에게 재시작 여부 확인
bool ask_restart()
{
	char response; //대답을 저장하는 변수
	while (true)
	{
		cout << "게임을 다시 시작하시겠습니까? (Y/N): ";
		cin >> response;
		if (response == 'Y' || response == 'y')
			return true;
		else if (response == 'N' || response == 'n')
			return false;
		else
			cout << "Y 또는 N으로 입력해주세요." << endl;
	}
}

// 게임 상태 초기화
void reset_game()
{
	for (int i = 0; i < 9; ++i) //모든 칸을 순회하면서
		board[i] = " "; // 빈칸으로 초기화
	player = 1; //플레이어 초기화
	position = 0; //위치 초기화
}