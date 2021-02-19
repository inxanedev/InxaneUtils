#pragma once

#include "io/print.hpp"

namespace inx {
    namespace data {
        template <typename T>
        class BSTNode {
            public:
                T data;
                BSTNode<T>* left;
                BSTNode<T>* right;

                BSTNode(T value) {
                    data = value;
                    left = right = nullptr;
                }

                void insert(T value) {
                    if (value < data) {
                        if (this->left == nullptr) {
                            this->left = new BSTNode<T>(value);
                        } else {
                            this->left->insert(value);
                        }
                    } else if (value > data) {
                        if (this->right == nullptr) {
                            this->right = new BSTNode<T>(value);
                        } else {
                            this->right->insert(value);
                        }
                    }
                }

                static BSTNode<T>* search(T value, BSTNode<T>* node) {
                    if (node == nullptr || node->data == value) {
                        return node;
                    } else {
                        if (value < node->data) {
                            return search(value, node->right);
                        } else if (value > node->data) {
                            return search(value, node->right);
                        }
                    }
                    // to stop compiler from complaining
                    return nullptr;
                }

                static void print(BSTNode<T>* node) {
                    if (node->left != nullptr) {
                        print(node->left);
                    }
                    inx::io::print(node->data);
                    if (node->right != nullptr) {
                        print(node->right);
                    }
                }
        };
    };
}
