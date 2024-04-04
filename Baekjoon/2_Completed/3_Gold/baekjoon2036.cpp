// 골드 4 - 2036번 : 수열의 점수
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 0은 하나 남은 음수랑 곱할 때, 유리함.
// 1이 아닌 이상 곱하기가 유리함.
// 음수는 두 개일 경우에는 곱하기, 한 개일 경우에는 더하기가 유리함.

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int n;
    cin >> n;

    vector<long long> plus_num;
    vector<long long> minus_num;
    long long result = 0;

    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp > 0) { plus_num.push_back(temp); }
        else { minus_num.push_back(temp); }
    }

    // 정렬
    sort(plus_num.begin(), plus_num.end(), greater<int>());
    sort(minus_num.begin(), minus_num.end());

    // 음수 계산
    for(int i = 0; i < (int)minus_num.size(); i+=2)
    {
        // 남은 수가 2개일 경우
        if((int)minus_num.size() - i >= 2)
        {
            result += minus_num[i] * minus_num[i + 1];
        }
        // 남은 수가 1개일 경우
        else
        {
            result += minus_num[i];
        }
    }

    // 양수 계산
    for(int i = 0; i < (int)plus_num.size(); i+=2)
    {
        // 남은 수가 2개일 경우
        if((int)plus_num.size() - i >= 2)
        {
            // 2개의 수 중 하나라도 1이라면 더하기
            if(plus_num[i] == 1 || plus_num[i+1] == 1)
            {
                result += (plus_num[i] + plus_num[i+1]);
            }
            // 그렇지 않다면 곱하기
            else
            {
                result += plus_num[i] * plus_num[i+1];
            }
        }
        // 남은 수가 1개일 경우
        else
        {
            result += plus_num[i];
        }
    }

    // 결과 출력
    cout << result << "\n";
}