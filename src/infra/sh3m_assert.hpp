
#include "infra.hpp"
#include <cassert>

#pragma once


namespace SimH3Mining {


#define SH3M_ASSERT2(expr, format, ...) \
    if (!(expr)) { \
        logger.log("Assertion failed:(%s), fun %s, file %s, line %d\n", \
                   #expr, __func__, __FILE__, __LINE__); \
        logger.log("Assertion msg:" format "\n", __VA_ARGS__); \
        assert(expr); \
    }

#define SH3M_ASSERT1(expr, msg) \
    SH3M_ASSERT2(expr, msg, 0)

#define SH3M_ASSERT(expr) \
    SH3M_ASSERT2(expr, "", 0)


#define S3HM_TRACE(format, ...) \
    logger.log("Trace log: function %s, file %s, line %d. " format "\n", \
               __func__, __FILE__, __LINE__, __VA_ARGS__)


} // namespace SimH3Mining
