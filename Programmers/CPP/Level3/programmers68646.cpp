// Lv.3 - 68646번 : 풍선 터트리기
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

// 최종으로 남는 경우
// 현재 숫자 기준으로 왼쪽 구간과 오른쪽 구간의 최솟값이 모두 현재 숫자보다 크거나, 1개만 커야함.
// 즉, 왼쪽 구간과 오른쪽 구간의 최솟값이 모두 현재 숫자보다 작은 경우는 불가능.

// 0 -16 26 65 -2 58 -92 -71 -68 -61 -33 0
// 0   1  2  3  4
// -1  0  1  2  3

int solution(vector<int> a) {
    int answer = 0;
    int size = a.size();
    
    vector<int> left_mins = vector<int>(size + 2, numeric_limits<int>::max());
    vector<int> right_mins = vector<int>(size + 2, numeric_limits<int>::max());
    
    for(int i = 0; i < size; i++)
    {
        left_mins[i + 1] = min(left_mins[i], a[i]);
        right_mins[size - i] = min(right_mins[size - i + 1], a[size - i - 1]);
    }
    
    for(int idx = 0; idx < size; idx++)
    {
        if((a[idx] > left_mins[idx] && a[idx] > right_mins[idx + 2]) == false)
            ++answer;
    }
    
    return answer;
}