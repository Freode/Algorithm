// Lv.3 - 150365번 : 미로 탈출 명령어
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

void search(int &y_size, int &x_size, int cur_y, int cur_x, int &dest_y, int &dest_x, int &k, string direction, vector<string> &results)
{
    // 첫 정답이 이미 사전 순으로 가장 빠르므로 반환
    if(results.size() != 0)
    {
        return;
    }
    // 범위를 벗어난 경우 제외
    if(!(cur_y > 0 && cur_x > 0 && cur_y <= y_size && cur_x <= x_size))
    {
        return;
    }

    // 목적지에 도달하지 못하는 경우 제외
    // 총 거리 - 현재까지 이동한 거리 - 남은 거리가 홀수인 경우에는 도달 불가능
    int distance = abs(dest_y - cur_y) + abs(dest_x - cur_x);
    if(distance + direction.length() > k || (k - direction.length() - distance) % 2 == 1)
    {
        return;
    }

    // 목적지 도달한 경우
    if(cur_x == dest_x && cur_y == dest_y && k == direction.length())
    {
        results.push_back(direction);
        return;
    }

    // 목적지에 도달하지 못한 경우
    // 아래 이동
    search(y_size, x_size, cur_y + 1, cur_x, dest_y, dest_x, k, direction + "d", results);
    // 왼쪽 이동
    search(y_size, x_size, cur_y, cur_x - 1, dest_y, dest_x, k, direction + "l", results);
    // 오른쪽 이동
    search(y_size, x_size, cur_y, cur_x + 1, dest_y, dest_x, k, direction + "r", results);
    // 위쪽 이동
    search(y_size, x_size, cur_y - 1, cur_x, dest_y, dest_x, k, direction + "u", results);
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";

    vector<string> results;

    search(n, m, x, y, r, c, k, "", results);

    // 불가능한 이동
    if(results.size() == 0)
    {
        answer = "impossible";
    }
    // 이동 가능한 것 중, 사전 순으로 가장 빠른 것
    else
    {
        answer = results[0];
    }

    return answer;
}