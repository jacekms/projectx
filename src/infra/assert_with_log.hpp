#pragma once

//#include <cassert>
//#include "Logger.h"

#define ASSERT_WITH_LOG(loggerx, expr, msg) \
    if (!(expr)) { \
        loggerx.log("Assertion failed: (%s), function %s, file %s, line %d. Message: %s\n", \
                   #expr, __func__, __FILE__, __LINE__, msg); \
        assert(expr); \
    }

#define TRACE_WITH_LOG(loggerx, format, ...) \
    loggerx.log("Trace log: function %s, file %s, line %d. " format "\n", \
               __func__, __FILE__, __LINE__, __VA_ARGS__)

