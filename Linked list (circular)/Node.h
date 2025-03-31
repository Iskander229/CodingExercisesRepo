#ifndef Node_H
#define Node_H
template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(const T& data) : data(data), next(nullptr) {}
};
#endif // Node_H