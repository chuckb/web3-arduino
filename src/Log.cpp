//
// Created by Okada, Takahiro on 2018/02/04.
// Adapted to std C++ by Chuck Benedict on 2022/04/07.
//

#include "Log.h"
#include <iostream>

using namespace std;

void Log::print(const char* s) {
#ifdef DEBUGLOG
  cout << s;
#endif
}
void Log::println(const char* s) {
#ifdef DEBUGLOG
  cout << s << endl;
#endif
}