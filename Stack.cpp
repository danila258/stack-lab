#include "Stack.h"
#include "StackImplementation.h"

#include <stdexcept>

Stack::Stack(StackContainer container) : _containerType(container) {
    switch (container) {

        case StackContainer::List: {
            _pimpl = static_cast<IStackImplementation*>(new List());
            break;
        }

        case StackContainer::Vector: {
            _pimpl = static_cast<IStackImplementation*>(new Vector());
            break;
        }

        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container) : _containerType(container) {
    switch (container) {

        case StackContainer::List: {
            _pimpl = static_cast<IStackImplementation*>(new List());

            for (int i = 0; i < arraySize; ++i) {
                _pimpl->push(valueArray[i]);
            }

            break;
        }

        case StackContainer::Vector: {
            _pimpl = static_cast<IStackImplementation*>(new Vector());

            for (int i = 0; i < arraySize; ++i) {
                _pimpl->push(valueArray[i]);
            }

            break;
        }

        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}

Stack::Stack(const Stack& copyStack): _containerType(copyStack._containerType) {
    *(this->_pimpl) = *(copyStack._pimpl);
}

Stack& Stack::operator=(const Stack& copyStack) {
    if (this == &copyStack) {
        return *this;
    }

    Stack moveStack(copyStack);
    *this = std::move(moveStack);

    return *this;
}

Stack::Stack(Stack&& moveStack) noexcept {
    *this = std::move(moveStack);
}

Stack& Stack::operator=(Stack&& moveStack) noexcept {
    std::swap(this->_pimpl, moveStack._pimpl);
    std::swap(this->_containerType, moveStack._containerType);

    return *this;
}

Stack::~Stack() {
    delete _pimpl;
}

void Stack::push(const ValueType& value) {
    _pimpl->push(value);
}

void Stack::pop() {
    _pimpl->pop();
}

const ValueType& Stack::top() const {
    return _pimpl->top();
}

bool Stack::isEmpty() const {
    return _pimpl->isEmpty();
}

size_t Stack::size() const {
    return _pimpl->isEmpty();
}
