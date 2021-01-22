#include <memory>
#include <array>
#include <cstdio>
#include <string>

namespace inx {
    namespace shell {
        std::string read_stdout(const char* command) {
            std::string result;
            std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command, "r"), pclose);

            std::array<char, 128> buffer;
            while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
                result += buffer.data();
            }
            return result;
        }

        std::string read_stdout(const std::string& command) {
            return read_stdout(command.c_str());
        }
    }
}
