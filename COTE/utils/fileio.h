#ifndef FILEIO_H
#define FILEIO_H

#include <cstdio>

// 파일 입출력 자동 리디렉션
// 제출 시 #include "utils/fileio.h" 라인을 삭제하세요
struct FileRedirect {
    FileRedirect() {
        FILE* fp;
        freopen_s(&fp, "input.txt", "r", stdin);
        freopen_s(&fp, "output.txt", "w", stdout);
    }
} _fileRedirect;

#endif // FILEIO_H
