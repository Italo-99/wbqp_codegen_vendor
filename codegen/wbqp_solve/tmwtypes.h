#ifndef TMWTYPES_H
#define TMWTYPES_H

/* Minimal shim for MATLAB Coder generated rtwtypes.h on deployment machines
   without MATLAB. Adjust typedef widths if your target requires different sizes. */

#include <stdint.h>
#include <stdbool.h>

typedef double      real_T;
typedef float       real32_T;
typedef int8_t      int8_T;
typedef uint8_t     uint8_T;
typedef int16_t     int16_T;
typedef uint16_t    uint16_T;
typedef int32_t     int32_T;
typedef uint32_t    uint32_T;
typedef int64_t     int64_T;
typedef uint64_t    uint64_T;
typedef bool        boolean_T;

/* MATLAB logical type alias sometimes used */
#ifndef true
# define true  (1U)
#endif
#ifndef false
# define false (0U)
#endif

#endif /* TMWTYPES_H */
