#ifndef DEC_H
#define DEC_H

void introduction(); // 게임을 시작할 때 소개 및 규칙 설명
bool is_winner(); // 게임에서 승리 조건을 확인
bool filled_up();  // 게임판이 모두 채워졌는지 확인 (무승부 여부 체크)
void draw(); // 현재 보드 상태를 화면에 출력
void set_position(); // 플레이어의 위치 입력 및 유효성 검사
void update_board(); // 선택된 위치를 현재 플레이어의 마크로 업데이트
void change_player(); // 플레이어를 번갈아가며 변경 (1 ↔ 2)
void take_turn(); // 실제 게임 플레이를 관리 (게임 루프)
void end_game(); // 게임 종료 후 결과 출력 및 승리자 점수 누적
void reset_game();  // 게임을 초기 상태로 초기화
bool ask_restart();   // 사용자에게 다시 시작 여부를 묻는 함수
void print_score();   // 현재 플레이어의 누적된 점수를 화면에 출력

// 전역 점수 변수 선언 (X와 O 플레이어의 승리 횟수)
extern int xWins;
extern int oWins;

#endif

