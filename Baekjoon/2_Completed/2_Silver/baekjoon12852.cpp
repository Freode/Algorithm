// 실버 1 - 12852번 : 1로 만들기 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 수에 대한 정보
struct NumInfo
{
    int counts = 1000001;
    int previous = 0;
};

// 다음 수를 경우에 따라 계산
int NextNum(int inN, int seq)
{
    int result = inN;
    switch(seq)
    {
    case 1:
        result *= 3;
        break;

    case 2:
        result *= 2;
        break;

    case 3:
        result++;
        break;
    }
    return result;
}

// 정답 계산
void Calculate(vector<NumInfo> &nums, int N)
{
    for(int i = 1; i < N; i++)
    {
        for(int loop = 1; loop < 4; loop++)
        {
            int next = NextNum(i, loop);
            // 범위가 벗어난 경우는 제외
            if(next > N) continue;

            // 해당 숫자에 더 빨리 도달하는 경우에만 초기화
            if(nums[next].counts <= nums[i].counts + 1) continue;

            // 해당 숫자 정보에 이전으로 이어지는 숫자와 여기까지의 거리 기록
            nums[next].previous = i;
            nums[next].counts = nums[i].counts + 1;
        }
    }
}

// 결과 출력
void PrintResult(vector<NumInfo> &nums, int N)
{
    cout << nums[N].counts << "\n";
    
    // 가장 빠른 길을 모두 출력
    int cur = N;

    while(cur != 0)
    {
        cout << cur << " ";
        cur = nums[cur].previous;
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    vector<NumInfo> nums(N+1);
    nums[1].counts = 0;

    Calculate(nums, N);

    PrintResult(nums, N);
}