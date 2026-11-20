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
namespace std {
inline long stol(const string& s, size_t* p = 0, int b = 10) { char* e; long v = strtol(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
inline unsigned long stoul(const string& s, size_t* p = 0, int b = 10) { char* e; unsigned long v = strtoul(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
inline long long stoll(const string& s, size_t* p = 0, int b = 10) { char* e; long long v = strtoll(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
inline unsigned long long stoull(const string& s, size_t* p = 0, int b = 10) { char* e; unsigned long long v = strtoull(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
inline int stoi(const string& s, size_t* p = 0, int b = 10) { return (int)stol(s, p, b); }
inline double stod(const string& s, size_t* p = 0) { char* e; double v = strtod(s.c_str(), &e); if (p) *p = e - s.c_str(); return v; }
inline float stof(const string& s, size_t* p = 0) { return (float)stod(s, p); }
}
#include <cstdlib>
namespace std {
inline long stol(const string& s, size_t* p = 0, int b = 10) { char* e; long v = strtol(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
inline unsigned long stoul(const string& s, size_t* p = 0, int b = 10) { char* e; unsigned long v = strtoul(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
inline long long stoll(const string& s, size_t* p = 0, int b = 10) { char* e; long long v = strtoll(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
inline unsigned long long stoull(const string& s, size_t* p = 0, int b = 10) { char* e; unsigned long long v = strtoull(s.c_str(), &e, b); if (p) *p = e - s.c_str(); return v; }
inline int stoi(const string& s, size_t* p = 0, int b = 10) { return (int)stol(s, p, b); }
inline double stod(const string& s, size_t* p = 0) { char* e; double v = strtod(s.c_str(), &e); if (p) *p = e - s.c_str(); return v; }
inline float stof(const string& s, size_t* p = 0) { return (float)stod(s, p); }
}
