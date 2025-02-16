// 골드 4 - 3151번 : 합이 0
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll find_case(vector<int> &in_base, vector<int> &in_search)
{
    ll result = 0;

    // 기준 배열에서 하나씩 검사
    for(const int& each : in_base)
    {
        int left = 0;
        int right = in_search.size() - 1;

        int sum, left_cnt, right_cnt, next_left, next_right;
        // 찾는 배열에서 두 개씩 찾기
        while(left < right)
        {
            sum = each + in_search[left] + in_search[right];
            
            left_cnt = 1;
            right_cnt = 1;

            next_left = left + 1;
            next_right = right - 1;

            if(sum == 0)
            { 
                // 값이 같을 경우, 중복인 경우를 계산
                if(in_search[left] == in_search[right])
                {
                    int dup = right - left + 1;
                    result += dup * (dup - 1) / 2;

                    break;
                }
                // 여기서는 항상 left < right 만족
                else
                {
                    // 왼쪽 경계에서 같은 수의 개수 세기
                    while(in_search[left] == in_search[next_left])
                    {
                        left_cnt++;
                        next_left++;
                    }
                    // 오른쪽 경계에서 같은 수의 개수 세기
                    while(in_search[right] == in_search[next_right])
                    {
                        right_cnt++;
                        next_right--;
                    }
                    
                    // 경우 계산
                    result += left_cnt * right_cnt;
                    left = next_left;
                    right = next_right;
                }
            }
            // 왼쪽 기준을 오른쪽으로 한 칸 이동
            else if(sum < 0) left++;
            // 오른쪽 기준을 왼쪽으로 한 칸 이동
            else right--;
        }
    }

    return result; 
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력 개수
    int N;
    cin >> N;

    vector<int> under_zero;
    vector<int> over_and_zero;
    int zero_count = 0;
    ll result = 0;

    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        // 0을 기준으로 나누기
        if(temp < 0) under_zero.push_back(temp);
        else over_and_zero.push_back(temp);

        if(temp == 0) zero_count++;
    }
    sort(under_zero.begin(), under_zero.end());
    sort(over_and_zero.begin(), over_and_zero.end());

    // 0개가 3개 이상일 때, 0으로만 구성 가능
    if(zero_count >= 3)
    {
        result = zero_count * (zero_count-1) * (zero_count-2) / 6;
    }

    // 양수 2개, 음수 1개
    result += find_case(under_zero, over_and_zero);

    // 양수 1개, 음수 2개
    result += find_case(over_and_zero, under_zero);

    cout << result << "\n";
}