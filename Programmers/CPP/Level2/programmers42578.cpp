// Lv.2 - 42578번 : 의상 
// 작성자 : jeonghoe22

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, int> cloth_counts;
    // 옷 종류에 따라 하나씩 증가
    for(const vector<string>& cloth : clothes)
    {
        cloth_counts[cloth[1]]++;
    }
    
    // 옷 조합 수
    answer = 1;
    for(const auto& each : cloth_counts)
    {
        answer *= (each.second + 1);
    }
    
    // 모두 다 안 입는 경우 제외
    answer--;
    
    return answer;
}