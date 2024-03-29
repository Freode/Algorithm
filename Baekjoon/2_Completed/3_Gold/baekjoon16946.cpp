// 골드 2 - 16946번 : 벽 부수고 이동하기 4
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <queue>
#include <map>

using namespace std;

// 구역 정보
struct AreaInfo
{
    int moveCounts = 0;
    bool bIsWall = false;
    bool bIsVisited = false;
    int connect_id = 0;
};

// 좌표 정보
struct PointInfo
{
    int x = 0;
    int y = 0;

    // 생성자
    PointInfo(){}
    PointInfo(int _y, int _x)
    {
        y = _y;
        x = _x;
    }
};

// 맵 입력
void InputMaps(vector<vector<AreaInfo>> &maps, int N, int M)
{
    char tempArea;
    for(int i = 0; i < N; i++)
    {

        for(int j = 0; j < M; j++)
        {
            cin >> tempArea;
            maps[i][j].bIsWall = (tempArea == '1');
        }
    }
}

// 벽 부수지 않은 상태로 이동할 수 있는 칸 기록
void CheckMoveCountsInLand(vector<vector<AreaInfo>> &maps, int N, int M)
{
    queue<PointInfo> queuePoint;
    queue<PointInfo> queueConnect;

    // 임시 변수
    int y, x;
    int count = 0;
    int connect_id = 0;
    PointInfo tempPoint;
    

    // 모든 점에 대해서 검사
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // 벽이 아니면서 현재 방문하지 않았을 때만 검사
            if(maps[i][j].bIsVisited == false && maps[i][j].bIsWall == false)
            {
                // 해당 지점이 검사 시작
                count = 1;
                connect_id++;
                queuePoint.push(PointInfo(i,j));
                queueConnect.push(PointInfo(i,j));
                
                // 해당 지점 방문 설정
                maps[i][j].bIsVisited = true;
                maps[i][j].connect_id = connect_id;

                while(queuePoint.empty() == false)
                {
                    // 4방향으로 이동
                    // 0 : 위쪽
                    // 1 : 오른쪽
                    // 2 : 아래쪽
                    // 3 : 왼쪽
                    for(int i = 0; i < 4; i++)
                    {
                        y = queuePoint.front().y;
                        x = queuePoint.front().x;
                        
                        if(i == 0){ y--; }
                        else if(i == 1){ x++; }
                        else if(i == 2){ y++; }
                        else{ x--; }

                        // 범위 안에 있을 때만 작동
                        if(y >= 0 && y < N && x >= 0 && x < M)
                        {
                            // 해당 지점이 아직 방문하지 않았고 벽이 아닐 때
                            if(maps[y][x].bIsVisited == false && maps[y][x].bIsWall == false)
                            {
                                // 해당 지점 방문 설정
                                maps[y][x].bIsVisited = true;
                                // 해당 지점을 추가 검사
                                queuePoint.push(PointInfo(y, x));
                                queueConnect.push(PointInfo(y, x));
                                // 연결 아이디 추가
                                maps[y][x].connect_id = connect_id;
                                count++;
                            }
                        }
                    }
                    // 검사한 점은 제외
                    queuePoint.pop();
                }

                // 방문했던 구역들에게 다른 구역으로 이동할 수 있는 횟수 기록
                count %= 10;
                while(queueConnect.empty() == false)
                {
                    tempPoint = queueConnect.front();
                    maps[tempPoint.y][tempPoint.x].moveCounts = count;
                    queueConnect.pop();
                }
            }
        }
    } 
}

// 해당 벽을 부수고 몇 번 이동할 수 있는지 기록
void CheckMoveCountsInWall(vector<vector<AreaInfo>> &maps, int N, int M)
{
    int x, y;
    map<int, int> current_connect_ids;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // 벽인지 확인
            if(maps[i][j].bIsWall == true)
            {
                // 자기 자신을 포함해서 4방향 검사
                maps[i][j].moveCounts = 1;
                // 0 : 위쪽
                // 1 : 오른쪽
                // 2 : 왼쪽
                // 3 : 아래쪽
                for(int k = 0; k < 4; k++)
                {
                    y = i;
                    x = j;
                    if(k == 0) { y--; }
                    if(k == 1) { x++; }
                    if(k == 2) { x--; }
                    if(k == 3) { y++; }

                    // 범위 안이면서, 해당 위치가 벽이 아닐 때만 경우 더하기
                    if(x >= 0 && x < M && y >= 0 && y < N && maps[y][x].bIsWall == false)
                    {
                        // 연결되지 않은 경우에만 추가
                        if(current_connect_ids.find(maps[y][x].connect_id) == current_connect_ids.end())
                        {
                            current_connect_ids[maps[y][x].connect_id] = 1;
                            maps[i][j].moveCounts += maps[y][x].moveCounts;
                            // 나머지 10
                            maps[i][j].moveCounts %= 10;
                        }                       
                    }
                }
                // 연결 정보 삭제
                current_connect_ids.clear();
            }
        }
    }
}

// 벽 출력
void PrintArea(vector<vector<AreaInfo>> &maps, int N, int M)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << (maps[i][j].bIsWall == true ? maps[i][j].moveCounts : 0);
        }
        cout << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, M;
    cin >> N >> M;

    // 맵
    vector<vector<AreaInfo>> maps(N, vector<AreaInfo>(M));

    // 맵 입력
    InputMaps(maps, N, M);

    // 벽이 아니면서 이어져 있는 곳 검사
    CheckMoveCountsInLand(maps, N, M);
    // 해당 벽을 부쉈을 때, 몇 칸까지 이동할 수 있는지 검사
    CheckMoveCountsInWall(maps, N, M);
    // 출력
    PrintArea(maps, N, M);
}