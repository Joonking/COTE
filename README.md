# COTE - 코딩테스트 프로젝트

Rider를 위한 최적화된 코딩테스트 연습 프로젝트입니다.

## 📁 프로젝트 구조

```
COTE/
├── COTE.sln                    # Visual Studio 솔루션 파일
├── README.md                   # 사용 가이드
├── SKILL_ANALYSIS.md           # 코딩 실력 분석 문서
├── .gitignore                  # Git 무시 설정
│
└── COTE/
    ├── current.cpp             # 현재 풀고 있는 문제 (빌드 대상)
    ├── template.cpp            # 새 문제 시작 시 복사용 템플릿
    ├── input.txt               # 테스트 입력 파일
    ├── output.txt              # 실행 결과 출력 파일
    │
    ├── utils/
    │   └── fileio.h            # 파일 입출력 자동화 헤더
    │
    └── archive/                # 풀이 완료된 문제 아카이브 (빌드 제외)
        ├── BaekJoon/
        │   ├── ByNumber/       # 문제 번호순 정리
        │   ├── ByClass/        # CLASS별 정리
        │   │   ├── CLASS1/
        │   │   ├── CLASS2/
        │   │   ├── CLASS3/
        │   │   ├── CLASS4/
        │   │   ├── CLASS5/
        │   │   └── CLASS6/
        │   └── ByAlgorithm/    # 알고리즘별 정리
        │       ├── DFS-BFS/
        │       ├── DP/
        │       ├── Greedy/
        │       ├── BruteForce/
        │       ├── String/
        │       ├── Sort/
        │       ├── DataStructure/
        │       ├── Graph/
        │       ├── Math/
        │       ├── Implement/
        │       ├── BinarySearch/
        │       ├── Backtracking/
        │       ├── TwoPointer/
        │       ├── Tree/
        │       └── Others/
        │
        ├── Programmers/
        │   ├── ByLevel/        # 레벨별 정리
        │   │   ├── Level0/
        │   │   ├── Level1/
        │   │   ├── Level2/
        │   │   └── Level3/
        │   └── ByCategory/     # 카테고리별 정리
        │       ├── HighScoreKit/
        │       ├── Challenge/
        │       └── Practice/
        │
        ├── HackerRank/         # HackerRank 문제
        │
        └── Exam/               # 실전 코딩테스트
            ├── Company/        # 기업별
            └── Contest/        # 대회별
```

## 🚀 사용 방법

### 1️⃣ 새 문제 시작하기

1. `template.cpp`의 내용을 `current.cpp`에 복사
2. 문제에서 제공하는 예제 입력을 `input.txt`에 작성
3. `current.cpp`에서 코드 작성
4. 실행하면 결과가 `output.txt`에 자동으로 저장됨

### 2️⃣ 문제 풀이

**current.cpp 기본 구조:**
```cpp
#include "utils/fileio.h"  // 제출 시 삭제
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 여기에 코드 작성

    return 0;
}
```

- `cin`, `cout`을 평소처럼 사용하면 됨
- `input.txt`에서 자동으로 입력을 받고, `output.txt`로 자동 출력
- 디버깅 시 콘솔이 아닌 `output.txt` 파일 확인

### 3️⃣ 문제 제출하기

코드 제출 시 **첫 줄만 삭제**:
```cpp
#include "utils/fileio.h"  // 이 줄만 삭제!
```

나머지 코드는 그대로 제출하면 됩니다.

### 4️⃣ 풀이 완료된 문제 아카이브

문제를 다 풀었으면:
1. `current.cpp`를 적절한 아카이브 폴더로 복사
2. 파일명 형식: `문제번호_문제제목.cpp`

**백준(BaekJoon) 분류 방법:**
- `ByNumber/`: 문제 번호순으로 정리 (예: `1000_A+B.cpp`)
- `ByClass/CLASS1/`: CLASS 단계별 학습용 (예: `1000_A+B.cpp`)
- `ByAlgorithm/DP/`: 알고리즘별 복습용 (예: `1463_1로만들기.cpp`)

**프로그래머스(Programmers) 분류 방법:**
- `ByLevel/Level1/`: 레벨별 정리
- `ByCategory/HighScoreKit/`: 고득점 Kit 문제

**장점:**
- 세 가지 관점으로 문제를 정리 가능 (번호/난이도/알고리즘)
- 중복 저장해도 무방 (용량보다 검색성이 중요)
- archive 폴더는 빌드에서 자동 제외
- 이전 풀이를 쉽게 검색하고 참조 가능
- Git으로 풀이 이력 관리 가능

**추천 정리 방법:**
1. 필수: `ByNumber/` - 모든 문제를 번호순으로 보관
2. 선택: 학습 목적이면 `ByClass/` 또는 `ByAlgorithm/`에 추가 복사

## ⚙️ 프로젝트 설정

### 빌드 설정
- **빌드 대상:** `current.cpp`만 빌드됨
- **빌드 제외:** `template.cpp`, `archive/` 폴더 전체
- **C++ 표준:** C++20
- **플랫폼:** x64, Win32 모두 지원

### 파일 입출력 (utils/fileio.h)
```cpp
// freopen_s를 사용하여 stdin/stdout을 파일로 리디렉션
// main 함수 실행 전에 자동으로 적용됨
```

## 💡 팁

### 빠른 작업 플로우
1. 문제 번호와 제목 확인
2. `input.txt`에 예제 입력 복사
3. `current.cpp`에서 코딩
4. F5로 실행 → `output.txt` 확인
5. 정답이면 제출, 아니면 수정 후 재실행
6. 완료 후 `archive/`로 복사

### 디버깅
- 중간 과정을 확인하려면 `cout`으로 출력
- 모든 출력이 `output.txt`에 기록됨
- 브레이크포인트는 평소처럼 사용 가능

### 여러 테스트 케이스
`input.txt`를 수정하면서 여러 테스트 케이스를 빠르게 검증할 수 있습니다.

## 📝 주의사항

1. **제출 전 필수 확인**
   - `#include "utils/fileio.h"` 라인 삭제했는지 확인
   - 불필요한 디버그 출력 제거

2. **파일 경로**
   - `input.txt`, `output.txt`는 실행 파일과 같은 디렉토리에 있어야 함
   - Rider에서 실행하면 자동으로 올바른 위치에서 실행됨

3. **Git 사용 시**
   - `output.txt`는 `.gitignore`에 추가 권장
   - `x64/`, `Debug/`, `Release/` 폴더도 무시 권장

## 🔧 문제 해결

### "파일을 열 수 없습니다" 오류
- `input.txt` 파일이 `COTE/COTE/` 폴더에 있는지 확인
- 작업 디렉토리 설정 확인

### 빌드 오류
- C++20 표준이 설정되어 있는지 확인
- Visual Studio 2022 또는 최신 버전 사용 권장

### archive 폴더의 파일이 빌드됨
- 프로젝트를 다시 로드하거나 Rider 재시작
- `.vcxproj` 파일에 `<ExcludedFromBuild>true</ExcludedFromBuild>` 추가

## 📚 참고

- 백준: https://www.acmicpc.net/
- 프로그래머스: https://programmers.co.kr/
- HackerRank: https://www.hackerrank.com/

---

**Happy Coding! 🎯**
