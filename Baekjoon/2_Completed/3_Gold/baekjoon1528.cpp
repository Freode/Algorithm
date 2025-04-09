// 골드 3 - 1528번 : 금민수의 합
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

// 금민수 : 4와 7로만 이루어진 수
// 입력 N -> 금민수의 합으로 나타냄
//1~1'000'000

// 방법이 여러 개 -> 사전순으로 가장 앞서는 것
// 금민수의 합 표현 불가능 -> -1로 출력

// 앞선다는 의미
// 1. 수의 개수가 더 적은 것
// 2. ai != bi가 성립하는 가장 작은 i에 대해 ai < bi가 성립

// 해결
// 1. 4와 7로 구성된 수 미리 구하기
// 2. 목표값에서 큰 값부터 빼서 구하기
// 3. 만약에, 해당 값의 데이터가 있으면, 바로 return
// 4. 없으면, 재귀로 이동
// 5. 각 수에는 {prev, count}를 저장
// 6. 해당 수 - prev이 간격을 의미 -> 만약에 count가 같다면, 간격이 적은 것으로 하기

const int MAX_VALUE = numeric_limits<int>::max();

struct Info
{
    int prev = 0;
    int count = MAX_VALUE;
};

vector<Info> g_nums;
vector<int> g_checks;

// 금민수 수 구하기
void calculateChecks(const int& depth, string number)
{
    // check 숫자에 추가
    if(depth == 0)
    {
        g_checks.push_back(stoi(number));
        return;
    }

    // 더 밑으로 이동
    int add = 4;
    for(int i = 0; i < 2; i++)
    {
        add += (3* i);
        char c = add + '0';
        calculateChecks(depth - 1, number + c);
    }
}

// 1~6자리의 금민수 수 모두 구하기
void allDigitChecks()
{
    for(int i = 1; i <= 6; i++)
    {
        calculateChecks(i, "");
    }
}

// 더 좋은 경우 찾기
void findBest(Info& result, const Info& compare)
{
    // 기존에 데이터가 없으면, 0이여도 최고의 경우
    if(compare.count == -1)
    {
        if(result.count == MAX_VALUE)
            result = compare;
    }
    
    // 기존 결과가 경우의 수가 0이라면, 항상 비교가 최고의 경우
    else if(result.count == -1)
        result = compare;
    // 갯수가 같으면, 간격이 더 작은 값으로 변경
    else if(result.count == compare.count)
        result.prev = max(result.prev, compare.prev);
    // 갯수가 다르면, 갯수가 더 작은 값으로 변경
    else if(compare.count < result.count)
        result = compare;
}

void simulate(const int idx, const int top)
{
    Info result;

    int nextTop = top;
    // 현재 수에서 다음 수로 이동 가능 한 경우를 모두 이동
    for(int i = top; i >= 0; i--)
    {
        // 현재 검사하는 수보다 비교 수가 더 큰 경우는 무시
        if(g_checks[i] > idx)
        {
            nextTop--;
            continue;
        }

        Info temp;
        int interval = idx - g_checks[i];
        // 간격이 0일 때는 그대로 반환
        if(interval == 0)
        {
            g_nums[idx] = {0, 1};
            return;
        }
        // 해당 수가 존재하는 경우, 계산 무시
        else if(g_nums[interval].count != MAX_VALUE)
            temp = {interval, g_nums[interval].count};

        // 더 이동 가능
        else 
        {
            int next = idx - g_checks[i];
            simulate(next, nextTop);
            temp = {next, g_nums[next].count};
        }
        // 시뮬레이션 성공했을 때, 경우 하나 추가
        temp.count = (temp.count != -1) ? temp.count + 1 : temp.count;
        findBest(result, temp);
    }
    g_nums[idx] = result;
}

vector<int> result;

// 결과 출력
void findResult(const int N)
{
    // 불가능
    if(g_nums[N].count == -1)
        result.push_back(-1);

    else
    {
        int num = g_nums[N].prev;
        // num이 0이 아니면, 계속 추적
        if(num != 0)
            findResult(num);

        result.push_back(N - num);
    }
}

// 결과 출력
void printResult()
{
    sort(result.begin(), result.end());

    for(const int& each : result)
        cout << each << " ";
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력 N
    int N;
    cin >> N;

    g_nums = vector<Info>(max(4, N+1));
    for(int i = 0; i < 4; i++)
        g_nums[i].count = -1;

    allDigitChecks();

    if(N >= 4)
        simulate(N, g_checks.size()-1);

    findResult(N);
    printResult();
}
