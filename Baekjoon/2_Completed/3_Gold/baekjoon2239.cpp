// 골드 4 - 2239번 : 스도쿠
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> g_areas;

void inputData()
{
    g_areas = vector<vector<int>>(9, vector<int>(9, 0));

    string input;
    for(int i = 0; i < 9; i++)
    {
        cin >> input;

        for(int j = 0; j < 9; j++)
        {
            g_areas[i][j] = (int)(input[j] - '0');
        }
    }
}

// 스도쿠 퍼즐에 채울 수 있는 숫자 구하기
void isCheck(const int inY, const int inX, vector<int>& inPossible)
{
    vector<bool> nums = vector<bool>(10, false);

    // 세로
    for(int nextY = 0; nextY < 9; nextY++)
    {
        nums[g_areas[nextY][inX]] = true;
    }

    // 가로
    for(int nextX = 0; nextX < 9; nextX++)
    {
        nums[g_areas[inY][nextX]] = true;
    }

    // 정사각형
    int areaY = inY / 3;
    int areaX = inX / 3;
    for(int numY = areaY * 3; numY < (areaY * 3 + 3); numY++)
    {
        for(int numX = areaX * 3; numX < (areaX * 3 + 3); numX++)
        {
            nums[g_areas[numY][numX]] = true;
        }
    }

    // 가능 리스트 반환
    for(int i = 1; i < 10; i++)
    {
        if(nums[i] == false)
            inPossible.push_back(i);
    }
}

bool find(const int inY, const int inX)
{
    // 정답을 발견한 경우
    if(inY == 9)
        return true;

    bool result = false;

    // 다음 위치 미리 계산
    int nextY = inY;
    int nextX = inX + 1;

    if(nextX == 9)
    {
        nextY = inY + 1;
        nextX = 0;
    }

    // 현재 자리에 0이 아니라면, 다음 자리를 검사
    if(g_areas[inY][inX] != 0)
    {
        result = find(nextY, nextX);
        // 정답을 발견한 경우, true 반환
        if(result == true)
            return true;

        // 정답이 없으므로, false 반환
        return false;
    }

    // 현재 자리에 0이라면, 검사 후 다음 자리를 검사
    vector<int> possibles;
    isCheck(inY, inX, possibles);

    // 가능한 숫자가 없으면, 불가능하다고 반환
    if(possibles.empty() == true)
        return false;

    for(const int& possible : possibles)
    {
        // 가능한 숫자로 교체 후, 다음 검사
        g_areas[inY][inX] = possible;
        result = find(nextY, nextX);

        // 정답을 발견한 경우, 반환
        if(result == true)
            return true;

        // 정답이 아닌 경우이므로, 다시 0으로 변환
        g_areas[inY][inX] = 0;
    }

    // 정답을 발견하지 못한 경우
    return false;
}

void printResult()
{
    for(int y = 0; y < 9; y++)
    {
        for(int x = 0; x < 9; x++)
        {
            cout << g_areas[y][x];
        }
        cout << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    inputData();
    find(0, 0);
    printResult();
}