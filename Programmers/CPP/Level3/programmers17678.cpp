// Lv.3 - 17678번 : [1차] 셔틀버스
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Bus
{
    vector<int> people;
    int dt_h = 0;
    int dt_m = 0;
    bool b_is_full = false;
};

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    vector<Bus> buses(n);
    // 버스 출발 시간 입력
    for(int i = 0; i < n; i++)
    {
        buses[i].people.resize(m);
        buses[i].dt_h = 9 + (t * i / 60);
        buses[i].dt_m = (t * i % 60);
    }

    // 크루 도착 시간 오름차순
    sort(timetable.begin(), timetable.end());

    // 크루 도착 시간 입력
    int idx = 0;
    int bus_num = 0;
    int time = 0;
    for(int i = 0; i < timetable.size(); i++)
    {
        // 시간 계산
        time = stoi(timetable[i].substr(0, 2)) * 100 + stoi(timetable[i].substr(3));
        // 버스 도착시간 전에 크루가 도착할 경우
        if(time <= buses[bus_num].dt_h * 100 + buses[bus_num].dt_m)
        {
            buses[bus_num].people[idx] = time;
            idx++;

            // 다음 차량으로 넘기기
            if(idx == m)
            {
                idx = 0;
                buses[bus_num].b_is_full = true;
                // 마지막 버스인지 확인
                if(bus_num + 1 >= n)
                {
                    break;
                }
                bus_num++;
            }
        }
        // 다음 버스가 있는지 확인
        // 없으면, for문 종료
        else
        {
            if(bus_num + 1 < n)
            {
                bus_num++;
                idx = 0;
                // 현재 순서 다시 검사
                i--;
                // 아래 코드는 m이 1인 경우 for문의 첫 번째 조건문에서 바로 다음 버스로 넘기질 못함.
                // buses[bus_num].people[idx] = time;
                // idx++;
            }
            else
            {
                break;
            }
        }
    }
    
    // 마지막 버스 확인
    // 모두 다 탄 경우
    int player_time = 0;
    if(buses[n - 1].b_is_full)
    {
        player_time = buses[n - 1].people[m - 1];
        // 시간, 분 계산
        player_time += (player_time % 100 == 0) ? -41 : -1;
    }
    // 자리가 있는 경우
    else
    {
        player_time = buses[n - 1].dt_h * 100 + buses[n - 1].dt_m;
    }

    // 시간:분 형식으로 변환
    int hour = player_time / 100;
    answer += ( hour < 10 ? "0" + to_string(hour) : to_string(hour));
    answer += ":";
    int min = player_time % 100;
    answer += ( min < 10 ? "0" + to_string(min) : to_string(min));

    return answer;
}
