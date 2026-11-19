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
