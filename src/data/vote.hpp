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

                T top() {
                    return (*std::max_element(m_Data.begin(), m_Data.end(), [](auto& a, auto& b) {
                        return a.second < b.second;
                    })).first;
                } 
                T bottom() {
                    return (*std::max_element(m_Data.begin(), m_Data.end(), [](auto& a, auto& b) {
                        return a.second > b.second;
                    })).first;
                }
        };
    }
}
