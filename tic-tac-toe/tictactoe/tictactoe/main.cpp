#include <iostream>
#include "dec.h"
using namespace std;
int main()
{
    // 전체 게임을 관리하는 루프 (사용자가 게임 종료를 선택할 때까지 반복)
    do
    {
        introduction(); // 게임 안내
        take_turn(); // 실제 게임 플레이
        end_game(); // 결과 출력 및 점수 관리
        print_score(); // 점수판 출력
        if (!ask_restart()) // 다시 시작 여부 확인 후 종료 또는 반복
            break; //종료
        reset_game(); // 게임 상태 초기화
    } while (true);
    cout << "게임을 종료합니다.\n";
	return 0;
}
