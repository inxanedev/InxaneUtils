#pragma once
#include <chrono>
#include <iostream>
#include <cstdint>
#include <string>
#include "time_format.h"
#include "duration.h"
namespace inx {
    namespace benchmarking {
        template <time_format _TimeFormat = time_format::MILLISECONDS>
        class BasicTimer {
            public:
                void start() {
                    start_point = std::chrono::high_resolution_clock::now();
                }
                void stop(const char* prefix = "[inx::benchmarking::BasicTimer]") {
                    _stop_clock();
                    std::cout << prefix << " Timer took " <<  get_duration() << get_literal() << "." << std::endl;
                }
                void stop(duration& output_variable) {
                    _stop_clock();
                    output_variable = get_duration();
                }
            private:
                std::chrono::time_point<std::chrono::high_resolution_clock> start_point;
                std::chrono::time_point<std::chrono::high_resolution_clock> end_point;
                duration get_duration() {
                    std::chrono::duration dur = end_point - start_point;
                    if (_TimeFormat == time_format::MILLISECONDS)
                        return std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
                    else if (_TimeFormat == time_format::MICROSECONDS) 
                        return std::chrono::duration_cast<std::chrono::microseconds>(dur).count();
                }
                std::string get_literal() {
                    if (_TimeFormat == time_format::MILLISECONDS) return "ms";
                    else if (_TimeFormat == time_format::MICROSECONDS) return "us";
                }
                void _stop_clock() {
                    end_point = std::chrono::high_resolution_clock::now();
                }
        };
    }
}
