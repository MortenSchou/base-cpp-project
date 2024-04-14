#ifndef NON_PEDANTIC_ABSL_HASH_H
#define NON_PEDANTIC_ABSL_HASH_H

// All code that needs absl::hash should include this file instead of <absl/hash/hash.h>
// This allows us to compile with -Wpedantic without being spammed by warnings from Abseil.
// In the case of Abseil, these warnings are false positives, and the Abseil team has decided to not support -Wpedantic.
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include <absl/hash/hash.h>
#pragma GCC diagnostic pop
#else
#include <absl/hash/hash.h>
#endif

#endif //NON_PEDANTIC_ABSL_HASH_H
