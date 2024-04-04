// 골드 4 - 17141번 : 연구소 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 구역 정보
struct Info
{
    int state = 0;
    bool b_is_visited = false;
    int turn_count = 0;
};

// 위치
struct Location
{
    int y = 0;
    int x = 0;

    // 생성자
    Location(){}
    Location(int _y, int _x){ y = _y; x = _x; }
};

int Simulate(vector<vector<Info>> &maps, vector<Location> &selection_virus, int N);

// 맵 입력
void InputMap(vector<vector<Info>> &maps, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> maps[i][j].state;
        }
    }
}

// 바이러스 위치 선택
int SelectVirus(vector<vector<Info>> &map, vector<Location> &virus_locs, vector<Location> &selection_virus, int N, int current_idx ,int layer)
{
    int min_time = 10000;
    int temp_time = 0;

    // 마지막 바이러스 위치까지 선정 완료
    if(layer == 0)
    {
        return Simulate(map, selection_virus, N);
    }
    else
    {
        for(int i = current_idx + 1; i < (int)virus_locs.size(); i++)
        {

            selection_virus.push_back(virus_locs[i]);
            temp_time = SelectVirus(map, virus_locs, selection_virus, N, i, layer - 1);
            // selection_virus.erase(selection_virus.end()) 로 하니깐 잘못된 메모리 접근으로 인한 오류 발생
            if((int)selection_virus.size() > 0){ selection_virus.pop_back(); }

            if(temp_time != -1 && temp_time < min_time)
            {
                min_time = temp_time;
            }
        }
    }
    return min_time;
}

// 바이러스 놓을 수 있는 모든 위치에 바이러스 놓아보기
int AllVirusSimulate(vector<vector<Info>> &map, int N, int M)
{
    // 바이러스 놓을 수 있는 위치 모두 찾기
    vector<Location> virus_locs;
    vector<Location> selection_virus;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j].state == 2) { virus_locs.push_back(Location(i,j)); }
        }
    }
    int min_time = SelectVirus(map, virus_locs, selection_virus, N, -1, M);

    if(min_time == 10000) { return -1; }
    else { return min_time; }
}


// 기록 초기화
void InitMap(vector<vector<Info>> &maps, int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            maps[i][j].b_is_visited = false;
            maps[i][j].turn_count = 0;
        }
    }
} 

// 범위 안에 존재하는지 확인
bool IsInBorder(Location loc, int N)
{
    return loc.x >= 0 && loc.y >= 0 && loc.x < N && loc.y < N;
}

// 현재 위치를 방문하지 않았는지 확인
bool IsVisted(vector<vector<Info>>&maps, Location loc)
{
    return maps[loc.y][loc.x].b_is_visited;
}

// 현재 위치가 벽인지 확인
bool IsWall(vector<vector<Info>>&maps, Location loc)
{
    return maps[loc.y][loc.x].state == 1;
}

// 현재 시뮬레이션에서 바이러스가 퍼지는 최댓값 반환
int MaxSperadVirusTime(vector<vector<Info>> &maps, int N)
{
    int max_time = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            // 벽이 아님
            if(maps[i][j].state != 1)
            {
                // 벽이 아닌데 방문을 못한 경우이므로 -1 반환
                if(maps[i][j].b_is_visited == false) { return -1; }
                // 최댓값 갱신 가능
                else if (maps[i][j].turn_count > max_time){ max_time = maps[i][j].turn_count; }
            }
        }
    }
    return max_time;
}

// 시뮬레이션 시작
int Simulate(vector<vector<Info>> &maps, vector<Location> &selection_virus, int N)
{
    InitMap(maps, N);

    // 바이러스 시작 위치 넣기
    queue<Location> loc_queue;
    
    for(Location& select : selection_virus)
    {
        loc_queue.push(select);
        maps[select.y][select.x].b_is_visited = true;
    }

    // 방향 
    vector<Location> direct(4);
    // 상
    direct.push_back(Location(-1,0));
    // 하
    direct.push_back(Location(1,0));
    // 좌
    direct.push_back(Location(0,-1));
    // 우
    direct.push_back(Location(0,1));

    Location cur_check_loc;
    // BFS 시작
    while(loc_queue.empty() == false)
    {
        for(Location& dir : direct)
        {
            cur_check_loc = loc_queue.front();
            cur_check_loc.y += dir.y;
            cur_check_loc.x += dir.x;

            // 범위 안에 존재하면서 방문하지 않았으면서 벽이 아닐 때
            if(IsInBorder(cur_check_loc, N) && IsVisted(maps, cur_check_loc) == false && IsWall(maps, cur_check_loc) == false)
            {
                maps[cur_check_loc.y][cur_check_loc.x].b_is_visited = true;
                maps[cur_check_loc.y][cur_check_loc.x].turn_count = maps[loc_queue.front().y][loc_queue.front().x].turn_count + 1;
                loc_queue.push(cur_check_loc);
            }
        }
        loc_queue.pop();
    }

    return MaxSperadVirusTime(maps, N);
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 맵 크기 입력
    int N, M;
    cin >> N >> M;

    // 맵 입력
    vector<vector<Info>> maps(N, vector<Info>(N));
    InputMap(maps, N);

    // 시뮬레이션 시작
    int result = AllVirusSimulate(maps, N, M);

    // 출력
    cout << result << "\n";
}