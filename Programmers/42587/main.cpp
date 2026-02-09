// 프로그래머스 [42587] - [프로세스]
// https://school.programmers.co.kr/learn/courses/30/lessons/42587
// 우선순위에 따라 프로세스를 실행시킬 때 특정 프로세스가 몇번째로 실행되는지 구하는문제
// 시간복잡도: O(N^2)

#include <iostream>
#include <string>
#include <queue>

using namespace std;

// 핵심 아이디어
// - 입력: 우선순위를 나타내는 priorities, 특정 위치 location
// - 출력: location에 해당하는 프로세스가 몇번 째로 실행되는지
// - 핵심 로직: 큐를 이용해 순서대로 처리하면서, 현재 가장 높은 우선순위가 아니라면 뒤로 보냄
int solution(vector<int> priorities, int location) {
    //위치와 우선순위, 가장 높은 우선순위 저장
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i = 0; i < priorities.size(); i++) {
        q.push({ i, priorities[i] });
        pq.push(priorities[i]);
    }

    
    int count = 0;

    while (!q.empty()) {
        int idx = q.front().first;
        int pri = q.front().second;
        q.pop();
        
        //해당 프로세스가 가장 높은 우선순위면 반환하고 그렇지 않으면 뒤로 보냄
        if (pq.top() == pri) {
            pq.pop();
            ++count;

            //목표 프로세스가 실행되면 count(몇 번째 인지) 반환
            if (idx == location) return count;
        }
        else {
            q.push({ idx, pri });
        }
    }
    
    return 0;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution({1, 1, 9, 1, 1, 1}, 0);

    // 결과 출력
    cout << answer << endl;

    return 0;
}