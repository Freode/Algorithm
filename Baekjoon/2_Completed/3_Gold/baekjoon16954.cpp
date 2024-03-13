// 골드 3 - 16954번 : 움직이는 미로 탈출
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 현재 위치에 대한 정보 구조체
struct PointInfo
{
    int turn = 0;
    int x = 0;
    int y = 0;

    // 생성자
    PointInfo()
    {

    }

    PointInfo(int _y, int _x, int _turn)
    {
        turn = _turn;
        y = _y;
        x = _x;
    }
};

// 체스판에서 8턴 뒤까지 이동했을 때의 결과 반환
void MoveChess(vector<vector<vector<bool>>> &chess)
{
    // i턴
    for(int i = 1; i < 9; i++)
    {
        // 체스판 상태
        // 맨 마지막 줄부터 채움 : 기존의 맨 마지막 줄은 사라지니 7번째 줄부터 시작
        for(int n = 7; n >= 0; n--)
        {
            for(int m = 0; m < 8; m++)
            {
                // 맨 윗줄 제외
                if(n != 0)
                {
                    chess[i][n][m] = chess[i-1][n-1][m];
                }
                // 맨 윗줄
                else
                {
                    chess[i][n][m] = false;
                }
            }
        }
    }
}

// 체스판 기본값 초기화
void InitChess(vector<vector<vector<bool>>> &chess)
{
    string tempLine;

    for(int i = 0; i < 8; i++)
    {
        getline(cin, tempLine);
        for(int j = 0; j < 8; j++)
        {
            chess[0][i][j] = (tempLine[j] == '#');
        }
    }
}

// 체스판 시작
void StartChess(vector<vector<vector<bool>>> &chess)
{
    // 시작점 설정
    PointInfo startPoint = PointInfo(7, 0, 0);
    queue<PointInfo> chessQueue;
    chessQueue.push(startPoint);

    // 임시 변수
    int x, y, turn;
    PointInfo tempPoint;

    // 탈출 성공
    bool bIsExit = false;

    // BFS로 탐색
    while(chessQueue.empty() == false && bIsExit == false)
    {
        tempPoint = chessQueue.front();
        // 모든 방향 이동 및 제자리 위치
        // 0 : 제자리
        // 1 : 왼쪽 상단
        // 2 : 상단
        // 3 : 오른쪽 상단
        // 4 : 오른쪽
        // 5 : 오른쪽 하단
        // 6 : 하단
        // 7 : 왼쪽 하단
        // 8 : 왼쪽
        for(int i = 0; i < 9; i++)
        {
            x = tempPoint.x;
            y = tempPoint.y;
            turn = tempPoint.turn + 1;

            // 이동
            if(i == 1 || i == 7 || i == 8) { x--; }
            if(i == 1 || i == 2 || i == 3 ) { y--; }
            if(i == 3 || i == 4 || i == 5 ) { x++; }
            if(i == 5 || i == 6 || i == 7 ) { y++; }

            // 범위 안에 있는지 확인
            if(x >= 0 && x < 8 && y >= 0 && y < 8)
            {
                // 이동한 것이 벽이 아닐 때
                // 이동할 때도 벽이 아니어야 함.
                if(chess[turn][y][x] == false && chess[turn-1][y][x] == false)
                {
                    // 마지막 턴
                    if(turn == 8)
                    {
                        bIsExit = true;
                    }
                    // 마지막 턴이 아닐 때는 넣기
                    else
                    {
                        chessQueue.push(PointInfo(y, x, turn));
                    }
                }
            }
        }
        // 처음꺼 빼기
        chessQueue.pop();
    }
    // 출력문
    cout << (bIsExit ? "1" : "0") << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 체스판
    vector<vector<vector<bool>>> chess(9, vector<vector<bool>>(8, vector<bool>(8)));
    // 입력
    InitChess(chess);
    // 체스판 움직이기
    MoveChess(chess);
    // 체스판 시뮬레이션 시작
    StartChess(chess);
}