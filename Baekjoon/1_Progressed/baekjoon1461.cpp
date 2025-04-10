// 골드 4 - 1461번 : 도서관
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 세준 위치 0
// 각 책의 위치 -> 걸음 수 1칸 : 거리 1
// 최소 걸음 수
// 마지막에 가져다 놓은 책에서 다시 돌아올 필요 x
// 한 번에 최대 M권 책 들기 가능

// 정렬해서
// 음수와 양수를 따로 분리해서 관리 -> 양수와 음수가 같은 그룹에 있으면, 새로운 책을 채울 수 있어서 무시
// 각 그룹의 마지막부터 M권 묶기
// 거리가 가장 먼 책을 마지막에 놓기 -> 돌아오는거 생략 가능

// 7 2
// -39 -37 / -29 -28 / -6 / 2 11
// 39 + 29*2(58) + 6*2(12) + 11*2(22) = 131

// 8 3
// -45 -26 -18 / -9 -4 / 22 40 50
// 45*2(90) + 9*2(18) + 50 = 158

// 6 2
// -1 / 3 / 4 5 / 6 11
// 2 + 6 + 10 + 11 = 29

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 현재 일 N, 최대 사용 횟수 K
    int N, K;
    cin >> N >> K;

    // 책 정보 입력 - 책 위치 0이 아님
    vector<int> books = vector<int>(N);

    // 위치 입력
    for(int& book : books)
        cin >> book;

    // 책 위치 오름차순 정렬
    sort(books.begin(), books.end());

    vector<int> groups;
    groups.reserve(50);

    // 그룹 선택
    int count = 0;
    int length = 0;
    int idx = 0;
    bool b_first_change = true;
    for(int i = 0; i < N; i++)
    {
        // 처음으로 양수가 바뀌면, 초기화 후에 제일 마지막으로 이동
        if(books[idx] > 0 && b_first_change)
        {
            b_first_change = false;
            groups.push_back(length);
            count = 0;
            length = 0;
            idx = N-1;
            i--;
            continue;
        }

        length = max(length, abs(books[idx]));
        count++;
        idx = b_first_change ? idx + 1 : idx - 1;

        // 그룹에 최대 수용 가능한 책만큼 포함된 경우
        if(count == K)
        {
            groups.push_back(length);
            length = 0;
            count = 0;
        }
    }
    // 마지막 그룹 추가
    groups.push_back(length);

    // 그룹 정렬
    sort(groups.begin(), groups.end());

    // 마지막 그룹을 제일 마지막에 둠.
    int result = 0;
    for(const int& group : groups)
    {
        result += (2 * group);
    }
    result -= groups[groups.size()-1];

    cout << result << "\n";
}