// 프로그래머스 [49189] - [가장 먼 노드]
// https://school.programmers.co.kr/learn/courses/30/lessons/49189
// 무방향 그래프에서 특정 노드에서 가장 먼 노드의 갯수를 구하는 문제
// 시간복잡도: O(V + E)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 핵심 아이디어
// - 입력: 정점의 갯수 n, 간선의 정보를 담은 2차원 배열 edge
// - 출력: 1번 노드에서 가장 먼 노드 출력
// - 핵심 로직: bfs 활용, 1번 노드를 기준으로 각 정점에 대응하는 최단거리를 구한뒤 최댓값에 해당하는 갯수를 출력
int solution(int n, vector<vector<int>> edge) {
    // 그래프 구현
    vector<vector<int>> graph(n + 1);
    vector<int> distance(n + 1, -1);

    for (const auto& e : edge) {
        int a = e[0], b = e[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // bfs 구현
    queue<int> q;
    q.push(1);
    distance[1] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        // 최단거리 저장
        for (int next : graph[current]) {
            if (distance[next] == -1) {
                distance[next] = distance[current] + 1;
                q.push(next);
            }
        }
    }

    // 최단거리 중 최댓값을 구하고 해당하는 정점의 거리를 카운팅
    int max = *max_element(distance.begin(), distance.end());
    int answer = count_if(distance.begin(), distance.end(), [max](int x) {
        return x == max;
        });

    return answer;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});

    // 결과 출력
    cout << answer << endl;

    return 0;
}