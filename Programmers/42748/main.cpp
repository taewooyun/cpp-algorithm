// 프로그래머스 [42748] - [K번째수]
// https://school.programmers.co.kr/learn/courses/30/lessons/42748
// 2차원 배열의 특정 부분을 잘라 해당 정수 배열의 특정 원소를 찾아내는 문제
// 시간복잡도: O(k log k)

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 핵심 아이디어
// - 단순 구현 문제
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto element : commands){
        priority_queue<int, vector<int>, greater<int>> pq; // 정렬을 위한 우선순위 큐
        int start = element[0]-1; //시작 지점
        int end = element[1]; // 종료 지점
        int count = element[2]; // K번째
        
        // 해당 배열 자르기
        for(int i=start; i<end; i++){
            pq.push(array[i]);
        }

        // 정렬된 원소를 K만큼 꺼내면서 K번째 원소를 꺼냄
        while(--count > 0){
            pq.pop();
        }
        
        answer.push_back(pq.top());
    }
    
    return answer;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}});

    // 결과 출력
    for(auto it : answer) cout << it << " ";
    cout << endl;

    return 0;
}