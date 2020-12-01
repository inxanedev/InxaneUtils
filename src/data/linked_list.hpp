#pragma once
namespace inx {
    namespace data {
        template <typename T>
        class LinkedListNode {
            public:
                T data;
                LinkedListNode<T>* next;
                LinkedListNode<T>* prev;            
                LinkedListNode<T>(T value) {
                    data = value;
                    next = prev = nullptr;
                }

                LinkedListNode<T>() {
                    next = prev = nullptr;
                }
        };
        
        template <typename T>
        class LinkedList {
            private:
                LinkedListNode<T>* m_Head;
                LinkedListNode<T>* m_Tail;
                uint32_t m_Size;
            public:
                LinkedListNode<T>* get_head() { return m_Head; }
                LinkedListNode<T>* get_tail() { return m_Tail; }
                uint32_t get_size() { return m_Size; }

                LinkedList<T>() {
                    m_Head = m_Tail = nullptr;
                }

                ~LinkedList<T>() {
                    for (LinkedListNode<T>* cur = m_Head; cur != nullptr;) {
                        LinkedListNode<T>* next = cur->next;
                        delete cur;
                        cur = next;
                    }
                    m_Head = nullptr;
                    m_Tail = nullptr;
                    m_Size = 0;
                }

                LinkedListNode<T>* add_node(T data) {
                    LinkedListNode<T>* node = new LinkedListNode<T>(data);
                    if (m_Size == 0) {
                        m_Head = m_Tail = node;
                    } else {
                        m_Tail->next = node;
                        node->prev = m_Tail;
                        m_Tail = m_Tail->next;
                    }
                    m_Size++;
                    return node;
                }

                void delete_node(LinkedListNode<T>* node) {
                    if (node == m_Head) {
                        m_Head->next->prev = nullptr;
                        m_Head = m_Head->next;
                    } else if (node == m_Tail) {
                        m_Tail->prev->next = nullptr;
                        m_Tail = m_Tail->prev;
                    } else {
                        node->prev->next = node->next;
                        node->next->prev = node->prev;
                    }
                    delete node;
                    m_Size--;
                }
        };
    }
}
