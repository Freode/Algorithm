// Lv.2 - 42583번 : 다리를 지나는 트럭 
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1;

    queue<int> on_bridge_time;
    int truck_delay_index = 1;
    int truck_pass_idx = 0;
    int current_weight = truck_weights[0];
    on_bridge_time.push(1);

    while(on_bridge_time.empty() == false)
    {
        time++;
        if(time - on_bridge_time.front() >= bridge_length)
        {
            current_weight -= truck_weights[truck_pass_idx];
            truck_pass_idx++;
            on_bridge_time.pop();
        }

        if(truck_delay_index < (int)truck_weights.size() && current_weight + truck_weights[truck_delay_index] <= weight)
        {
            current_weight += truck_weights[truck_delay_index];
            truck_delay_index++;
            on_bridge_time.push(time);
        }
        cout << time << " : " << current_weight << "\n";
    }

    return time;
}