#pragma once
#include <unordered_map>
#include <vector>
#include <algorithm>
namespace inx {
    namespace data {
        template <typename T = int32_t> 
        class Vote {
            private:
                std::unordered_map<T, uint32_t> m_Data;
            public:
                Vote(const std::vector<T>& keys) {
                    for (const T& key : keys) m_Data.emplace(key, 0);
                }
                
                void vote(T&& key) {
                    if (m_Data.find(key) != m_Data.end()) m_Data[key]++;
                }
                void remove_vote(T&& key) {
                    if (m_Data.find(key) != m_Data.end())
                        if (m_Data[key] != 0) m_Data[key]--;
                }
                uint32_t get_votes(T&& key) {
                    return m_Data[key];
                }

                std::vector<T> top() {
                    std::vector<T> result;
                    uint32_t max = 0;
                    for (auto& pair : m_Data) {
                        if (pair.second > max) {
                            result.clear();
                            result.push_back(pair.first);
                            max = pair.second;
                        }
                        if (pair.second == max && std::find(result.begin(), result.end(), pair.first) == result.end()) result.push_back(pair.first);
                    }
                    return result;
                }

                std::vector<T> bottom() {
                    std::vector<T> result;
                    uint32_t min = 0;
                    for (auto& pair : m_Data) {
                        if (result.size() == 0) {
                            result.push_back(pair.first);
                            min = pair.second;
                        } else {
                            if (pair.second < min) result.clear();
                            else if (pair.second == min && std::find(result.begin(), result.end(), pair.first) == result.end()) result.push_back(pair.first);
                        }
                    }
                    return result;
                }
        };
    }
}
