// Android/gnustl compat: this old libstdc++ build has no std::to_string
#pragma once
#include <string>
#include <cstdio>
namespace std {
inline string to_string(int v) { char b[32]; snprintf(b, sizeof b, "%d", v); return b; }
inline string to_string(unsigned v) { char b[32]; snprintf(b, sizeof b, "%u", v); return b; }
inline string to_string(long v) { char b[32]; snprintf(b, sizeof b, "%ld", v); return b; }
inline string to_string(unsigned long v) { char b[32]; snprintf(b, sizeof b, "%lu", v); return b; }
inline string to_string(long long v) { char b[32]; snprintf(b, sizeof b, "%lld", v); return b; }
inline string to_string(unsigned long long v) { char b[32]; snprintf(b, sizeof b, "%llu", v); return b; }
inline string to_string(float v) { char b[64]; snprintf(b, sizeof b, "%f", v); return b; }
inline string to_string(double v) { char b[64]; snprintf(b, sizeof b, "%f", v); return b; }
inline string to_string(long double v) { char b[64]; snprintf(b, sizeof b, "%Lf", v); return b; }
}
#include <cstdlib>
#include <type_traits>
namespace std {
#define COMPAT_ONLY_STRING class S, class = typename enable_if<is_same<S, string>::value>::type
template<COMPAT_ONLY_STRING> inline long stol(const S& s, size_t* p = 0, int b = 10) { char* e; long v = strtol(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
template<COMPAT_ONLY_STRING> inline unsigned long stoul(const S& s, size_t* p = 0, int b = 10) { char* e; unsigned long v = strtoul(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
template<COMPAT_ONLY_STRING> inline long long stoll(const S& s, size_t* p = 0, int b = 10) { char* e; long long v = strtoll(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
template<COMPAT_ONLY_STRING> inline unsigned long long stoull(const S& s, size_t* p = 0, int b = 10) { char* e; unsigned long long v = strtoull(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
template<COMPAT_ONLY_STRING> inline int stoi(const S& s, size_t* p = 0, int b = 10) { char* e; long v = strtol(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return (int)v; }
template<COMPAT_ONLY_STRING> inline double stod(const S& s, size_t* p = 0) { char* e; double v = strtod(s.c_str(), &e); if (p) *p = e - s.c_str(); return v; }
template<COMPAT_ONLY_STRING> inline float stof(const S& s, size_t* p = 0) { char* e; float v = (float)strtod(s.c_str(), &e); if (p) *p = e - s.c_str(); return v; }
#undef COMPAT_ONLY_STRING
}
