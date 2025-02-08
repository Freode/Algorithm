// 골드 5 - 15486번 : 퇴사 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 상담 정보 구조체
struct Consult
{   
    int time = 0;
    int cur_earning = 0;
    int max_earning = 0;
};

// 각 상담별 일 수와 비용 입력
void InputConsult(vector<Consult> &inConsults, const int inSize)
{
    for(int i = 0; i < inSize; i++)
    {
        cin >> inConsults[i].time >> inConsults[i].cur_earning;
    }
}

// 해당 상담 진행 여부에 따라 각 일별로 최대 이익 계산
void CalculateConsult(vector<Consult> &inConsults, const int inSize)
{
    for(int i = 0; i < inSize; i++)
    {
        Consult cur_consult = inConsults[i];

        // 오늘 상담을 하지 않을 경우, 다음 날 이익이 더 높을 때
        inConsults[i+1].max_earning = max(inConsults[i].max_earning, inConsults[i+1].max_earning);

        // 퇴사일 이후에 상담이 끝날 경우에는 무시
        if(cur_consult.time + i > inSize) continue;

        // 해당 상담을 진행했을 때,
        // 현재까지 최대 이익 + 현재 상담 이익을 해당 날짜의 최대 이익과 비교
        int finish = cur_consult.time + i;
        inConsults[finish].max_earning = max(inConsults[finish].max_earning, cur_consult.max_earning + cur_consult.cur_earning);

    }
}

int MaxEarning(vector<Consult> &inConsults)
{
    int result = 0;
    for(const Consult &consult : inConsults)
    {
        result = max(result, consult.max_earning);
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 일 수 입력
    int N;
    cin >> N;

    // 각 상담별 일 수와 비용 입력
    vector<Consult> consults(N+1);
    InputConsult(consults, N);

    // 해당 상담 진행 여부에 따라 각 일별로 최대 이익 계산
    CalculateConsult(consults, N);

    // 가장 높은 이익을 출력
    int result = MaxEarning(consults);

    cout << result << "\n";
}
