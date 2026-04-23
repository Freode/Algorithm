// Lv.3 - 70130번 : 스타 수열
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    
    int size = a.size();
    
    // 숫자 분포도
    vector<int> nums = vector<int>(size, 0);
    for(const int& each_a : a)
    {
        nums[each_a]++;
    }
    
    // 숫자 분포도에 따라서 앞에서부터 검사
    int answer = 0;
    
    // 기준 숫자
    for(int base = 0; base < size; base++)
    {
        // 계산 생략
        if((nums[base] * 2) <= answer)
            continue;
        
        int count = 0;
        // 배열 인덱스별로 검사
        for(int idx = 0; idx < size - 1; idx++)
        {
            // 한 쌍의 값이 다르면서, 현재 기준값과 교집합을 이룸
            if((a[idx] == base || a[idx + 1] == base) && (a[idx] != a[idx + 1]))
            {
                count++;
                idx++;
            }
        }
        answer = max(answer, count << 1);
    }
    
    return answer;
}