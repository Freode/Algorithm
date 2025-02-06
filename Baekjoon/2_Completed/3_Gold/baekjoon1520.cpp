// 골드 3 - 1520번 : 내리막 길
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 구역에 대한 비용과 경우의 수
struct AreaSimple
{
    int cost = 0;
    int cases = 0;
};

// 구역에 대한 좌표 정보도 포함
struct AreaComplex
{
    AreaSimple areaSimple;
    int y = -1;
    int x = -1;

    AreaComplex(int y, int x, int cost) : y(y), x(x), areaSimple{cost, 0} {}
};

// 구역 정보 입력
void InputArea(vector<vector<AreaSimple>> &inAreas, vector<AreaComplex> &inCheckSequences)
{
    for(int i = 0; i < inAreas.size(); i++)
    {
        for(int j = 0; j < inAreas[0].size(); j++)
        {
            cin >> inAreas[i][j].cost;
            // 0,0 에서는 반드시 추가
            // 제일 왼쪽 위보다 비용이 더 낮은 경우에만 추가
            if((i == 0 && j == 0) || inAreas[i][j].cost < inAreas[0][0].cost) 
            inCheckSequences.push_back(AreaComplex(i, j, inAreas[i][j].cost));
        }
    }
}

// 구역 검사 순서 정렬
void SortAreaInfoByCost(vector<AreaComplex> &inCheckSequence)
{
    // 비용 기준의 내림차순으로 정렬
    // 단, 시작은 항상 왼쪽 위이기에 begin() + 1에서부터 정렬
    sort(inCheckSequence.begin() + 1, inCheckSequence.end(), [](const AreaComplex &A, const AreaComplex &B)
    {
        return A.areaSimple.cost > B.areaSimple.cost;
    });
}

// 범위 안인지 확인
bool IsIn(int inY, int inX, int inBoardY, int inBoardX)
{
    return inY >= 0 && inX >= 0 && inY < inBoardY && inX < inBoardX;
}

// 구역 검사
void CheckAreaBySeq(vector<vector<AreaSimple>> &inAreas, const vector<AreaComplex> &inCheckSequence)
{
    // 방향에 의한 변환값 미리 설정
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, 1, 0, -1};

    int sizeX = inAreas[0].size();
    int sizeY = inAreas.size();

    // 비용이 낮은 구역별로 검사 진행
    for(const AreaComplex &eachArea : inCheckSequence)
    {
        int curY = eachArea.y;
        int curX = eachArea.x;

        // 방향별 검사
        for(int dir = 0; dir < 4; dir++)
        {
            // 검사 지점
            int nextY = eachArea.y + dy[dir];
            int nextX = eachArea.x + dx[dir];

            // 범위 밖은 무시
            if(IsIn(nextY, nextX, sizeY, sizeX) == false) continue;

            // 현재 지점보다 높거나 같은 경우에도 무시
            if(inAreas[curY][curX].cost <= inAreas[nextY][nextX].cost) continue;

            // 해당 지점에 여기까지 올 수 있는 경우의 수를 더해줌
            inAreas[nextY][nextX].cases += inAreas[curY][curX].cases;
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 구역 크기 입력 및 할당
    int M, N;
    cin >> M >> N;

    vector<vector<AreaSimple>> areas(M, vector<AreaSimple>(N));
    vector<AreaComplex> checkSequence;

    // 구역 정보 입력
    InputArea(areas, checkSequence);

    // 구역 검사 순서 정렬
    SortAreaInfoByCost(checkSequence);

    // 구역 검사
    areas[0][0].cases = 1;
    CheckAreaBySeq(areas, checkSequence);

    // 결과 출력
    cout << areas[M-1][N-1].cases << "\n";
}