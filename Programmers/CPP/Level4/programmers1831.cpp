// Lv.4 - 1831번 : 4단 고음
// 작성자 : jeonghoe22(최정호)

// 1. *의 개수가 0개일 때, +가 존재하면, 올바르지 않은 경우
// 2. *의 개수가 1개 이상일 때, +는 존재해도 됨.
// 3. *의 개수가 1개 이상일 때, +가 2번 나오면 * 개수는 1개 차감
// 4. +가 더 이상 없는데도 *가 존재하면, 올바르지 않은 경우

// 3단 고음 파트 계산 : 3단 고음 파트가 a개일 때
// 1. 음높이의 최대값은 *++ 파트를 순서대로 a개만큼 계산한 것
// 2. 음높이의 최소값은 *를 a개만큼 먼저 사용하고 나머지를 +로 계산
// 2번은 전의 값 * 3 - (4n - 6)
// 3. a개의 최소값과 a-1개의 최대값의 차이가 계속 커지므로 항상 a개 파트를 사용

// a파트 최대 개수는 19개 -> 2^(19*3-1)는 - 시간 초과

// 역으로 구하기
// 맨 처음은 항상 *, 맨 마지막 2개는 항상 +
// 0. 시작은 항상 n-2에서 검사하고 마지막에 3으로 남는 경우를 계산
// 1. n % 3 == 0, 3으로 나누는 경우와 -1의 경우 두 가지로 진행
// 2. 그렇지 않은 경우는 -1만 진행
// 3. -1을 한 경우 -> + 개수 증가
// 4. 3으로 나눈 경우 -> + 개수를 2개 감소하되 + 개수가 음수는 불가능
// 

int search(int loc, int ast_num, int plus_num, long long value, int n)
{
    int cases = 0;
    // 위치보다 더 나아간 경우
    if(loc < 1)
    {
        return 0;
    }
    // 목적지 도달
    // 조건 만족
    if(value == n && loc == 1 && ast_num == 1 && plus_num == 2)
    {
        return 1;
    }
    // * 추가
    if(value % 3 == 0 && plus_num >= 2 && value > 3)
    {
        cases += search(loc - 1, ast_num - 1, plus_num - 2, value / 3, n);
    }
    // + 추가
    if(value > 3)
    {
        cases += search(loc - 1, ast_num, plus_num + 1, value - 1, n);
    }

    return cases;
}

int solution(int n) {
    int answer = 0;

    int min_3_count = 1;
    long long min_3_num = 5;

    // a 파트 최소 사용 개수 구하기
    while(min_3_num <= n)
    {
        min_3_count++;
        min_3_num = min_3_num * 3 - (4 * min_3_count - 6);
    }
    min_3_count--;

    // 정답 구하기
    answer = search(min_3_count * 3 - 2, min_3_count, 2, n - 2, 3);

    return answer;
}