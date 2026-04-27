#pragma once

#include <cstdio>
#include <cstdlib>

#define LOG_INFO(fmt, ...)  fprintf(stderr, "[INFO] " fmt "\n", ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)  fprintf(stderr, "[WARN] " fmt "\n", ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) fprintf(stderr, "[ERR]  " fmt "\n", ##__VA_ARGS__)

#define ASSERT(cond, msg) do { \
    if (!(cond)) { LOG_ERROR("Assertion failed: %s", msg); abort(); } \
} while (0)

// Container-of helper (mirrors wlroots wl_container_of)
#define CONTAINER_OF(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))
