// 프로그래머스 [17682] - [2018 KAKAO BLIND RECRUITMENT [1차] 다트 게임]
// https://school.programmers.co.kr/learn/courses/30/lessons/문제번호
// 다트게임의 결과로 주어진 문자를 규칙에 따라 처리하여 점수를 출력하는 문제
// 시간복잡도: O(N)

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

// 핵심 아이디어
// - 입력: 3번의 기회, 기회 1번 당 점수, 제곱수, (옵션)으로 이루어져 있음
// - 규칙: 제곱수(S, D, T)는 각각 점수에 1, 2, 3을 제곱함, 옵션은 *(해당 점수, 직전의 점수를 2배), #(해당 점수에 -1 을 곱함)으로 이루어져 있으며 존재하지 않을 수도 있음
// - 예시: 2D3S3T# = 2² + 3¹ + 3³*-1 = -20점
// - 출력: 해당 게임의 결과 점수를 출력
// - 핵심 로직: 문자열을 순회하며 규칙에 맞게 인덱스를 조절하여 처리, 점수가 10일 경우를 유의
int solution(string dartResult) {
    int answer = 0;
    
    vector<int> scores;
    int i = 0;
    // 문자열 순회
    while (i < dartResult.size()) 
    {
        // 기회 마다 점수 저장
        int score = 0;

        // 점수 처리
        if (dartResult[i] == '1' && dartResult[i + 1] == '0')
        {
            score = 10;
            i += 2;
        }
        else
        {
            score = dartResult[i] - '0';
            i += 1;
        }
        // 제곱수 처리
        switch (dartResult[i])
        {
            case 'S':
                score = pow(score, 1);
                break;
            case 'D':
                score = pow(score, 2);
                break;
            case 'T':
                score = pow(score, 3);
                break;
            default:
                break;
        }
        i += 1;

        // 옵션 처리
        if (i < dartResult.size() && (dartResult[i] == '*' || dartResult[i] == '#')) {
            switch (dartResult[i]) 
            {
                case '*':
                    score *= 2;
                    if (!scores.empty()) scores.back() *= 2;
                    break;
                case '#':
                    score *= -1;
                default: 
                    break;
            }
            i += 1;
        }
        scores.push_back(score);
    }

    // 총 점수 구하기
    for (int s : scores) 
    {
        answer += s;
    }
    
    return answer;
}

int main() {
    // 테스트 케이스 실행
    auto answer = solution("1D#2S*3S");

    // 결과 출력
    cout << answer << endl;

    return 0;
}