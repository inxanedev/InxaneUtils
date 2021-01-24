#pragma once
#include "basic_timer.h"

namespace inx {
    namespace benchmarking {
        template <typename _Function, time_format _TimeFormat = time_format::MILLISECONDS>
        void TimeFunction(_Function func) {
            BasicTimer<_TimeFormat> timer;
            timer.start();
            func();
            timer.stop("[inx::benchmarking::TimeFunction]");
        }
        template <typename _Function, time_format _TimeFormat = time_format::MILLISECONDS>
        void TimeFunction(_Function func, duration& output_variable) {
            BasicTimer<_TimeFormat> timer;
            timer.start();
            func();
            timer.stop(output_variable);
        }

    }
}
