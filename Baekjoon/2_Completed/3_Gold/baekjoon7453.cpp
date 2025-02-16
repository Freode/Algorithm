// 골드 2 - 7453번 : 합이 0인 네 정수
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 배열의 크기
    int N;
    cin >> N;

    // 수 입력
    vector<vector<int>> nums(4, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cin >> nums[j][i];
        }
    }

    // 두 집합별로 미리 합하기
    vector<ll> sum_ab(N*N);
    vector<ll> sum_cd(N*N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            sum_ab[N*i + j] = nums[0][i] + nums[1][j];
            sum_cd[N*i + j] = nums[2][i] + nums[3][j];
        }
    }
    // 오름차순 정렬
    sort(sum_cd.begin(), sum_cd.end());
    sort(sum_ab.begin(), sum_ab.end());

    // 서로서로 반대되는 위치부터 시작
    ll result = 0;
    int ab_loc = 0;
    int cd_loc = sum_cd.size() - 1;
    
    // 두 그룹 중 한 그룹이라도 검사가 끝날 때까지, 진행
    while(ab_loc < sum_ab.size() && cd_loc >= 0)
    {

        int sum = sum_ab[ab_loc] + sum_cd[cd_loc];
        // 합이 0일 경우, 같은 값을 가진게 몇 개인지 확인할 필요
        if(sum == 0)
        {
            int ab_count = 1;
            int cd_count = 1;

            int next_ab_loc = ab_loc + 1;
            int next_cd_loc = cd_loc - 1;

            // A그룹에서 같은 수의 개수 찾기
            while(next_ab_loc < sum_ab.size() && sum_ab[next_ab_loc] == sum_ab[ab_loc])
            {
                next_ab_loc++;
                ab_count++;
            }

            // B그룹에서 같은 수의 개수 찾기
            while(next_cd_loc >= 0 && sum_cd[next_cd_loc] == sum_cd[cd_loc])
            {
                next_cd_loc--;
                cd_count++;
            }

            // 같은 수끼리는 검사했으니 위치 이동
            ab_loc = next_ab_loc;
            cd_loc = next_cd_loc;

            result += ab_count * cd_count;
        }
        // 합이 양수인 경우에는 B그룹의 양수 값을 줄임
        else if(sum > 0){ cd_loc--; }
        // 합이 음수인 경우에는 A그룹의 음수 값을 줄임
        else{ ab_loc++; }
    }

    cout << result << "\n";
}