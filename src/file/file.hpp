#pragma once
#include <fstream>
typedef unsigned char byte;
namespace inx {
	class file {
		public:
			class ByteFileReader {
				public:
					ByteFileReader(const char* filename) {
						m_File = std::ifstream(filename, std::ios_base::binary);
						m_File.seekg(0, m_File.end);
						m_Length = (size_t)m_File.tellg();
						m_File.seekg(0, m_File.beg);
						m_Data = new byte[m_Length];
						m_File.read((char*)m_Data, m_Length);
						m_File.close();
					}
					size_t length() {
						return m_Length;
					}
					template <typename T>
					T getValue(uint32_t index) {
						T result;
						memcpy(&result, &m_Data[index], sizeof(result));
						return result;
					}
					~ByteFileReader() {
						delete[] m_Data;
					}
					byte* getRawData() {
						return m_Data;
					}
				private:
					std::ifstream m_File;
					size_t m_Length;
					byte* m_Data;
			};
	};
}
