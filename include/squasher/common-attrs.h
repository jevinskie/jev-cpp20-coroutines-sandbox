#pragma once

#ifndef SQUASHER_HONOR_INLINE
#define SQUASHER_HONOR_INLINE 1
#endif

#define SQUASHER_EXPORT __attribute__((visibility("default")))
#if SQUASHER_HONOR_INLINE
#define SQUASHER_INLINE __attribute__((always_inline))
#else
#define SQUASHER_INLINE
#endif
#define SQUASHER_NOINLINE __attribute__((noinline))
#define SQUASHER_LIKELY(cond) __builtin_expect((cond), 1)
#define SQUASHER_UNLIKELY(cond) __builtin_expect((cond), 0)
#define SQUASHER_BREAK() __builtin_debugtrap()
#define SQUASHER_ALIGNED(n) __attribute__((aligned(n)))
#define SQUASHER_ASSUME_ALIGNED(ptr, n) __builtin_assume_aligned((ptr), n)
#define SQUASHER_UNREACHABLE() __builtin_unreachable()
