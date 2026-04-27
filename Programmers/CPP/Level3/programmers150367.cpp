// Lv.3 - 150367번 : 표현 가능한 이진트리
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <utility>

using namespace std;

// 10^15 = 2^50
// log(50)번에 하나 검사 완료

// 존재 여부, 0또는 1
pair<bool,bool> divide(const string& bin_number, int start, int end)
{
    // 0 또는 1을 확인 (start가 mid)
    if(start == end)
        return {true, bin_number[start] == '1'};
    
    // 구간 나누기
    int mid = (start + end) >> 1;
    
    pair<bool,bool> left = divide(bin_number, start, mid - 1);
    pair<bool,bool> right = divide(bin_number, mid + 1, end);
    
    bool is_valid = left.first && right.first;
    // 중앙이 0이면, 아래도 모두 0이어야 함.
    if(bin_number[mid] == '0' && (left.second || right.second))
    {
        is_valid = false;
    }
    
    bool has_one = left.second || right.second || bin_number[mid] == '1';
    
    return {is_valid, has_one};
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    answer.reserve(numbers.size());
    
    for(long long number : numbers)
    {
        // 바이너리로 변환
        string bin_number = "";
        while(number > 0)
        {
            bin_number = char('0' + (number % 2)) + bin_number;
            number /= 2;
        }
        
        // 포화 이진트리로 만들기 (2^k - 1)
        int bin_len = bin_number.size();
        int k = 1;
        
        while((1 << k) - 1 < bin_len)
            ++k;
        
        int target = (1 << k) - 1;
        for(int loc = bin_len; loc < target; loc++)
            bin_number = '0' + bin_number;
        
        // 분할 정복으로 검사
        pair<bool,bool> check = divide(bin_number, 0, bin_number.size() - 1);
        
        int result = check.first ? 1 : 0;
        answer.push_back(result);
    }
    
    return answer;
}