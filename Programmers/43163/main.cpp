// 프로그래머스 [43163] - [단어 변환]
// https://school.programmers.co.kr/learn/courses/30/lessons/43163
// 주어진 단어 목록 중 한 글자씩 사용해 목표 단어에 도달하는 문제
// 시간복잡도: O(n² * m)

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 핵심 아이디어
// - 입력: 시작 단어 begin, 목표 단어 target, 단어 목록 words. 각 단어의 길이는 항상 같다
// - 출력: 최소 몇단계를 거쳐 변환할 수 있는지, 변환할 수 없는 경우에는 0을 반환
// - 핵심 로직: bfs를 활용. target에 도달하면 bfs 알고리즘의 특성상 최솟값 보장.

// 변환 가능 여부 확인
bool canConvert(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) ++diff;
    }
    return diff == 1;
}

int solution(string begin, string target, vector<string> words) {
    // target이 words에 포함되지 않을 때 변경할 수 없음
    if (find(words.begin(), words.end(), target) == words.end()) return 0;

    //bfs 구현
    queue<pair<string, int>> q;
    vector<bool> visited(words.size(), false);

    q.push({ begin, 0 });

    while (!q.empty()) {
        auto current = q.front().first;
        auto depth = q.front().second;
        q.pop();

        // 너비 우선 탐색 = 도달할 수 있는 최솟값 탐색
        if (current == target) return depth;

        for (int i = 0; i < words.size(); ++i) {
            if (!visited[i] && canConvert(current, words[i])) {
                visited[i] = true;
                q.push({ words[i], depth + 1 });
            }
        }
    }

    return 0;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });

    // 결과 출력
    cout << answer << endl;

    return 0;
}