#pragma once

#include "time_format.h"
#include "duration.h"
namespace inx {
    namespace benchmarking {
        template <time_format _CastTo>
        duration time_format_cast(const duration& to_cast) {
            if (_CastTo == time_format::MICROSECONDS)
                return to_cast * 1000;
            else if (_CastTo == time_format::MILLISECONDS)
                return to_cast / 1000;
        }
    }
}
