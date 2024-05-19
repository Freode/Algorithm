// Lv.2 - 42583번 : 다리를 지나는 트럭 
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1;
    // 변수들
    queue<int> on_bridge_time;
    // 대기 트럭 번호
    int truck_delay_index = 1;
    // 다리 지나가는 트럭 중 가장 빠른 트럭의 번호
    int truck_pass_idx = 0;
    // 현재 다리 위의 트럭 총 무게
    int current_weight = truck_weights[0];
    // queue 검사
    on_bridge_time.push(1);
    while(on_bridge_time.empty() == false)
    {
        // 시간 증가
        time++;
        // 현재 트럭이 다 지나갔을 경우 (1초에 한 대씩 다리에서 탈출)
        if(time - on_bridge_time.front() >= bridge_length)
        {
            current_weight -= truck_weights[truck_pass_idx];
            truck_pass_idx++;
            on_bridge_time.pop();
        }
        // 대기 중이던 가장 빠른 트럭이 지나갈 수 있는 경우
        if(truck_delay_index < (int)truck_weights.size() && current_weight + truck_weights[truck_delay_index] <= weight)
        {
            current_weight += truck_weights[truck_delay_index];
            truck_delay_index++;
            on_bridge_time.push(time);
        }
    }

    return time;
}