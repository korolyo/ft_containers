#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include <iterator>
# include "cstddef"
# include "utility.hpp"
# include "node.hpp"

namespace ft {
    template<typename T>
    class rbt_iterator {
    public:
        typedef typename std::iterator<std::bidirectional_iterator_tag, T> rbt_it;
        typedef typename rbt_it::iterator_category iterator_category;
        typedef typename rbt_it::value_type value_type;
        typedef typename rbt_it::difference_type difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef ft::node<typename ft::switch_const<T>::type> *p_node;

        rbt_iterator() : _root(nullptr), _node(nullptr) {}

        explicit rbt_iterator(const p_node &root, const p_node &node) : _root(root), _node(node) {}

        rbt_iterator(const rbt_iterator &src) {
            *this = src;
        }

        ~rbt_iterator() {}

        rbt_iterator &operator=(const rbt_iterator &src) {
            if (this == &src)
                return *this;
            _node = src._node;
            _root = src._root;
            return *this;
        }

        reference &operator*() {
            return _node->value;
        }

        pointer operator->() const {
            return &(_node->value);
        }

        rbt_iterator &operator++() {
            if (!_node)
                return *this;
            else if (_node->right)
                _node = minimal_node(_node->right);
            else if (_node == maximal_node(_root->parent))
                _node = 0;
            else {
                while (_node->parent->right == _node)
                    _node = _node->parent;
                _node = _node->parent;
            }
            return *this;
        }

        rbt_iterator operator++(int) {
            rbt_iterator temp = *this;
            ++(*this);
            return temp;
        }

        rbt_iterator &operator--() {
            if (!_node)
                _node = maximal_node(_root->parent);
            else if (_node->left)
                _node = maximal_node(_node->left);
            else {
                while (_node->parent->left == _node)
                    _node = _node->parent;
                _node = _node->parent;
            }
            return *this;
        }

        rbt_iterator operator--(int) {
            rbt_iterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const rbt_iterator &it) const {
            return (it._node == _node);
        }

        bool operator!=(const rbt_iterator &it) const {
            return (it._node != _node);
        }

        operator rbt_iterator<const T>() const {
            return rbt_iterator<const T>(_root, _node);
        }

    private:
        p_node _root;
        p_node _node;

        p_node minimal_node(p_node node_) const {
            if (node_) {
                while (node_->left)
                    node_ = node_->left;
            }
            return node_;
        }

        p_node maximal_node(p_node node_) const {
            if (node_) {
                while (node_->right)
                    node_ = node_->right;
            }
            return node_;
        }
    };
}

#endif // RBT_ITERATOR_HPP
