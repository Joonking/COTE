# COTE - 코딩테스트 프로젝트

> C++을 사용한 체계적인 코딩테스트 학습 및 문제 풀이 아카이브 프로젝트

[![C++](https://img.shields.io/badge/C++-20-blue.svg)](https://isocpp.org/)
[![Problems](https://img.shields.io/badge/Solved-1165+-green.svg)](./LOG.md)
[![Rider](https://img.shields.io/badge/IDE-Rider-orange.svg)](https://www.jetbrains.com/rider/)

**현재 진행도**: 중급 레벨 | 1,165+ 문제 풀이 완료

---

## 🎯 프로젝트 특징

- **자동화된 입출력**: 파일 기반 테스트로 빠른 디버깅
- **체계적 아카이빙**: 번호순/난이도별/알고리즘별 3중 분류
- **실력 분석**: 알고리즘별 강/약점 자동 추적
- **AI 지원**: LLM 기반 맞춤형 문제 추천

---

## 📁 프로젝트 구조

```
COTE/
├── 📄 README.md              # 프로젝트 소개 (이 파일)
├── 📄 LOG.md                 # 날짜별 문제 풀이 기록
├── 📄 SKILL.md               # 알고리즘별 실력 분석
├── 📄 FOR_LLM.md             # AI 문제 추천 가이드
│
└── COTE/
    ├── current.cpp           # 현재 풀고 있는 문제
    ├── template.cpp          # 문제 템플릿
    └── archive/              # 풀이 완료 아카이브 (1,165개+)
        └── BaekJoon/
            ├── ByNumber/     # 문제 번호순
            ├── ByClass/      # CLASS 1~6
            └── ByAlgorithm/  # DP, DFS/BFS, 그리디 등
```

**전체 구조는**: [상세 폴더 구조 보기](./FOR_LLM.md#디렉토리-구조)

## 🚀 빠른 시작

### 1. 새 문제 풀기
```bash
1. template.cpp → current.cpp 복사
2. 예제 입력을 input.txt에 작성
3. current.cpp에서 코딩
4. F5 실행 → output.txt 확인
```

### 2. 제출하기
```cpp
#include "utils/fileio.h"  // ← 이 줄만 삭제하고 제출!
```

### 3. 아카이빙
```bash
문제 풀이 완료 → archive/BaekJoon/ByNumber/1463_1로만들기.cpp
```

**자세한 사용법**: 프로젝트를 처음 시작한다면 [사용 가이드](./FOR_LLM.md)를 참고하세요.

---

## 📊 학습 현황

### 알고리즘별 강점
| 알고리즘 | 문제 수 | 평가 |
|---------|--------|------|
| 문자열 | 34개 | ⭐⭐⭐⭐⭐ |
| 정렬 | 29개 | ⭐⭐⭐⭐⭐ |
| DFS/BFS | 23개 | ⭐⭐⭐⭐ |

### 현재 집중 학습 중
- **DP** (12개 → 목표 50개)
- **이분탐색** (4개 → 목표 20개)
- **백트래킹** (2개 → 목표 15개)

**상세 분석**: [SKILL.md](./SKILL.md) | **풀이 기록**: [LOG.md](./LOG.md)

---

## 📚 문서 가이드

| 문서 | 설명 | 대상 |
|------|------|------|
| [README.md](./README.md) | 프로젝트 소개 및 빠른 시작 | 처음 사용자 |
| [LOG.md](./LOG.md) | 날짜별 문제 풀이 기록 | 진행 상황 추적 |
| [SKILL.md](./SKILL.md) | 알고리즘별 강/약점 분석 | 학습 방향 설정 |
| [NOTES.md](./NOTES.md) | 학습 노트 및 개념 정리 | 복습 및 참고 |
| [FOR_LLM.md](./FOR_LLM.md) | AI 문제 추천 가이드 | AI 어시스턴트용 |

---

## 💻 기술 스택

- **언어**: C++20
- **IDE**: JetBrains Rider
- **플랫폼**: Windows (x64)
- **주요 사이트**: [백준](https://www.acmicpc.net/), [프로그래머스](https://programmers.co.kr/)

## 🤝 기여 및 피드백

이 프로젝트는 개인 학습용이지만, 비슷한 구조로 학습하고 싶으신 분들은 자유롭게 Fork 해주세요!

---

**Happy Coding! 🎯**
