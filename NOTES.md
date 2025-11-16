# 📚 학습 노트 (Learning Notes)

> 문제 풀이 중 배운 개념, 자주 까먹는 내용, 유용한 팁을 정리하는 문서

**마지막 업데이트**: 2025-11-15

---

## 📑 목차

- [C++ 기초](#c-기초)
  - [배열/벡터 초기화](#배열벡터-초기화)
  - [resize vs assign](#resize-vs-assign)

---

## C++ 기초

### 배열/벡터 초기화

#### 배열 초기화

**0으로 초기화**:
```cpp
int arr[10] = {0};           // ✅ 모두 0
bool visited[10] = {false};  // ✅ 모두 false
```

**-1로 초기화**:
```cpp
// 방법 1: fill 함수 (권장)
int arr[10];
fill(arr, arr + 10, -1);

// 방법 2: 반복문
int arr[10];
for (int i = 0; i < 10; i++) {
    arr[i] = -1;
}

// 방법 3: memset (0, -1만 가능)
int arr[10];
memset(arr, -1, sizeof(arr));  // -1만 제대로 동작
```

**⚠️ 주의**: `int arr[10] = {-1};`은 첫 번째만 -1, 나머지는 0!

**2D 배열**:
```cpp
// 0으로 초기화
int arr[5][5] = {0};

// -1로 초기화 (반복문 필요)
int arr[5][5];
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        arr[i][j] = -1;
    }
}
```

#### Vector 초기화

**기본 초기화**:
```cpp
vector<int> v1(10);         // 크기 10, 모두 0
vector<int> v2(10, 0);      // 명시적으로 0
vector<int> v3(10, -1);     // 크기 10, 모두 -1
vector<bool> v4(10, false); // 크기 10, 모두 false
```

**다양한 방법**:
```cpp
// 리스트 초기화
vector<int> v1 = {1, 2, 3, 4, 5};

// resize
vector<int> v2;
v2.resize(10, -1);

// assign
vector<int> v3;
v3.assign(10, -1);

// fill
vector<int> v4(10);
fill(v4.begin(), v4.end(), -1);
```

**2D Vector**:
```cpp
// 0으로 초기화
vector<vector<int>> v1(5, vector<int>(5));

// -1로 초기화
vector<vector<int>> v2(5, vector<int>(5, -1));
```

**비교 정리**:

| 초기화 목표 | 배열 | Vector |
|------------|------|--------|
| 모두 0 | `int arr[10] = {0};` | `vector<int> v(10);` |
| 모두 -1 | `fill(arr, arr+10, -1);` | `vector<int> v(10, -1);` |
| 2D 모두 -1 | 반복문 필요 | `vector<vector<int>> v(5, vector<int>(5, -1));` |

---

### resize vs assign

#### 핵심 차이

| | `resize` | `assign` |
|---|----------|----------|
| **기존 데이터** | 유지됨 | 삭제됨 |
| **동작** | 크기만 변경 | 내용 전체 교체 |
| **용도** | 크기 조정 | 초기화/재설정 |

#### resize - 기존 데이터 유지

```cpp
vector<int> v = {1, 2, 3};

v.resize(5);         // {1, 2, 3, 0, 0} - 기존 유지
v.resize(5, -1);     // {1, 2, 3, -1, -1} - 기존 유지
v.resize(2);         // {1, 2} - 앞에서부터 2개만
```

**사용 시기**:
- 기존 데이터를 보존해야 할 때
- 동적으로 벡터 크기 조정
- 입력 크기를 받은 후 확장

```cpp
int N;
cin >> N;
vector<int> dp;
dp.resize(N + 1, 0);  // 크기 조정
```

#### assign - 전체 교체

```cpp
vector<int> v = {1, 2, 3};

v.assign(5, -1);     // {-1, -1, -1, -1, -1} - 전부 -1
v.assign(3, 0);      // {0, 0, 0} - 전부 0
```

**사용 시기**:
- 벡터를 완전히 초기화
- 이전 데이터를 모두 버려야 할 때
- 여러 테스트 케이스에서 재사용

```cpp
vector<int> dp(1000, 0);

int T;
cin >> T;
while (T--) {
    dp.assign(1000, 0);  // 매번 초기화
    // ...
}
```

#### 비교 예제

```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {1, 2, 3};

v1.resize(5, -1);  // {1, 2, 3, -1, -1}
v2.assign(5, -1);  // {-1, -1, -1, -1, -1}
```

**기억법**:
- `resize`: 크기 **재조정** (기존 유지)
- `assign`: 값 **할당** (전체 교체)

---

## 📌 업데이트 로그

| 날짜 | 카테고리 | 내용 |
|------|---------|------|
| 2025-11-15 | C++ 기초 | 배열/벡터 초기화 방법 |
| 2025-11-15 | C++ 기초 | resize vs assign 차이 |

---

**관련 문서**:
- [LOG.md](./LOG.md) - 문제 풀이 기록
- [SKILL.md](./SKILL.md) - 실력 분석
- [FOR_LLM.md](./FOR_LLM.md) - AI 추천 가이드
