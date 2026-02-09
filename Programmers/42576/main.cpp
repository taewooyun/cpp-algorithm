// 프로그래머스 [42576] - [완주하지 못한 선수]
// https://school.programmers.co.kr/learn/courses/30/lessons/42576
// 해시를 사용하여 참가자 명단에서 완주자를 제거하고 남은 한 명을 찾는 문제
// 시간복잡도: O(n)

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 핵심 아이디어
// - 참가자 명단을 해시로 저장
// - 완주자를 해시에서 차감
// - 명단에 포함된 횟수가 함께 저장되면서 중복 상황에도 만족
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> hashMap;

    // 참가자 명단을 해시에 기록 (이름별 등장 횟수 저장)
    for (string name : participant) {
        hashMap[name]++;
    }

    // 완주자 명단을 해시에서 차감 (완주한 사람 제거)
    for (string name : completion) {
        hashMap[name]--;
    }

    // 값이 1 이상인 사람이 완주하지 못한 사람
    for (auto it : hashMap) {
        if (it.second > 0) {
            answer = it.first;
        }
    }

    return answer;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"});
    
    // 결과 출력
    cout << answer << endl;

    return 0;
}