// Lv.3 - 42627번 : 디스크 컨트롤러
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 대기 큐 - 작업 번호, 요청 시각, 소요 시각
// 하드디스크 작업 X - 대기 큐에서 가장 높은 우선순위
// 우선순위 : 작업 소요 시간 짧음 / 작업 요청 시각 빠름 / 작업 번호가 작은 것
// 비선점
// 작업 마치는 시점에 바로 다른 작업 요청 -> 작업 마치자마자 대기 큐에 저장
// 우선 순위가 높은 작업을 대기 큐에 꺼내서 하드디스크에 그 작업 시킴. (이 과정의 소요시간 x)

// 반환 시간 : 작업 종료 시각 - 요청 시간
// 반환 시간 평균이 정답

// 우선순위 큐 사용
// 작업 요청 되는 시점 max : 1'000
// 작업 소요 시간 max : 1'000
// 1'000'000s까지 측정

struct Work
{
    int idx = 0;
    int start = 0;;
    int time = 0;
    
    bool operator<(const Work& other) const
    {
        if(time != other.time)
            return time > other.time;
        
        if(start != other.start)
            return start > other.start;
        
        return idx > other.idx;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size = jobs.size();
    
    // 요청 순서대로 정렬
    vector<Work> sort_jobs(size);
    for(int i = 0; i < size; i++)
    {
        sort_jobs[i] = {i, jobs[i][0], jobs[i][1]};
    }
    
    sort(sort_jobs.begin(), sort_jobs.end(), 
         [](const Work& a, const Work& b)
         {
            return a.start < b.start; 
         });
    
    // 초기 시간 여러 개 고려
    priority_queue<Work> pq;
    
    int start_idx = 0;
    int t = sort_jobs[0].start;
    
    while(start_idx < size && t == sort_jobs[start_idx].start)
    {
        pq.push(sort_jobs[start_idx]);
        ++start_idx;
    }
    
    while(pq.empty() == false)
    {
        Work cur = pq.top();
        pq.pop();
        
        // 종료 때의 계산
        t += cur.time;
        answer += (t - jobs[cur.idx][0]);
        // cout << cur.idx << " : " << t << ", " << answer << "\n"; 
        
        // 현재 종료된 시간까지의 작업 추가
        while(start_idx < size && sort_jobs[start_idx].start <= t)
        {
            pq.push(sort_jobs[start_idx]);
            ++start_idx;
        }
        
        // 만약에 비어있는 경우, 다음 요청 입력 시간까지 이동
        if(start_idx < size && pq.empty())
        {
            int next_t = sort_jobs[start_idx].start;
            
            // 같은 요청 시간 여러 개
            while(start_idx < size && next_t == sort_jobs[start_idx].start)
            {
                pq.push(sort_jobs[start_idx]);
                t = sort_jobs[start_idx].start;
                ++start_idx;
            }
        }
    }
    
    return answer / size;
}