// Lv.2 - 340211번 : [PCCP 기출문제] 3번 / 충돌위험 찾기
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

// 로봇 구조체
struct Robot
{
    // 현재 위치
    int loc_y = -1;
    int loc_x = -1;
    // 다음 목적지 위치
    int dest_y = 0;
    int dest_x = 0;
    // 목적지들
    vector<int> dests;
    // 다음 목적지 도달 여부
    bool b_is_dest = true;
    // 초기 위치 초기화 여부
    bool b_is_init = false;
    // 모든 목적지 도달 여부
    bool b_is_removed = false;
    int dests_size = 0;
    int move_dest_count = 1;
};

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    vector<Robot> robots(routes.size());

    // 로봇 정보 추가
    for(int i = 0; i < routes.size(); i++)
    {
        robots[i].dests = routes[i];
        robots[i].dests_size = routes[i].size();
    }

    // 로봇이 목적지까지 다 이동할 때까지, 반복
    int next_move_dest;
    int removed_robots = 0;
    while(removed_robots != routes.size())
    {
        // 좌표판 초기화
        vector<vector<int>> boards(101, vector<int>(101, 0));

        // 이동하기 시뮬레이션
        for(int i = 0; i < robots.size(); i++)
        {
            // 제거된 로봇
            if(robots[i].b_is_removed)
            {
                continue;
            }
            // 초기 위치 설정
            if(robots[i].loc_y == -1)
            {
                // 첫 위치 설정
                robots[i].loc_y = points[robots[i].dests[0] - 1][0];
                robots[i].loc_x = points[robots[i].dests[0] - 1][1];
            }
            // 다음 목적지가 있는 경우
            if(robots[i].b_is_dest && robots[i].move_dest_count != robots[i].dests_size)
            {
                robots[i].b_is_dest = false;
                next_move_dest = robots[i].move_dest_count;
                // 다음 목적지 위치 설정
                robots[i].dest_y = points[robots[i].dests[next_move_dest] - 1][0];
                robots[i].dest_x = points[robots[i].dests[next_move_dest] - 1][1];
                robots[i].move_dest_count++;
            }
            // 다음 목적지가 없는데 끝까지 이동한 경우
            else if(robots[i].b_is_dest && robots[i].move_dest_count == robots[i].dests_size)
            {
                // 제거
                robots[i].b_is_removed = true;
                removed_robots++;
                continue;
            }
            // 다음 목적지로 이동 시뮬레이션, 초기 설정인 경우에는 이동 x
            if(robots[i].b_is_init)
            {
                // Y 좌표 먼저 움직이기
                if(robots[i].dest_y != robots[i].loc_y)
                {
                    robots[i].loc_y = robots[i].dest_y > robots[i].loc_y ? robots[i].loc_y + 1 : robots[i].loc_y - 1; 
                }
                // X 좌표 다음으로 움직이기
                else
                {
                    robots[i].loc_x = robots[i].dest_x > robots[i].loc_x ? robots[i].loc_x + 1 : robots[i].loc_x - 1; 
                }

                // 목적지에 도달
                if(robots[i].dest_y == robots[i].loc_y && robots[i].dest_x == robots[i].loc_x)
                {
                    robots[i].b_is_dest = true;
                }
            }
            // 초기 설정 완료
            robots[i].b_is_init = true;
            // 보드에 위치 기록하는데 이미 있는 경우에는 충돌 경우 + 1
            boards[robots[i].loc_y][robots[i].loc_x]++;
            if(boards[robots[i].loc_y][robots[i].loc_x] == 2)
            {
                answer++;
            }

        }
    }

    return answer;
}