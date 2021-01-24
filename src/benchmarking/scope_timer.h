#pragma once
#include "basic_timer.h"

namespace inx {
    namespace benchmarking {
        template <time_format _TimeFormat = time_format::MILLISECONDS>
        class ScopeTimer {
            public:
                ScopeTimer(duration* output_variable = nullptr) {
                    output = output_variable;
                    internal_timer.start();
                }
                ~ScopeTimer() {
                    if (output == nullptr)
                        internal_timer.stop("[inx::benchmarking::ScopeTimer]");
                    else
                        internal_timer.stop(*output);
                }
            private:
                BasicTimer<_TimeFormat> internal_timer;
                duration* output;
        };
    }
}
