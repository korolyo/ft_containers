#ifndef SET_HPP
# define SET_HPP

# include <memory>
# include "Utility/utility.hpp"
# include "Utility/pair.hpp"
# include "Utility/reverse_iterator.hpp"
# include "Utility/red_black_tree.hpp"
# include "Utility/rbt_iterator.hpp"
# include "Utility/iterator_traits.hpp"
# include "Utility/reverse_iterator.hpp"

namespace ft {
    template<
            class Key,
            class Compare = std::less<Key>,
            class Allocator = std::allocator<Key>
    >
    class set {
    public:
        typedef Key key_type;
        typedef key_type value_type;
        typedef Compare key_compare;
        typedef Compare value_compare;
        typedef Allocator allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ft::rbt_iterator<const value_type> const_iterator;
        typedef ft::rbt_iterator<value_type> iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef difference_type size_type;

        typedef typename ft::node<value_type> *p_node;
        typedef typename Allocator::template rebind<node<value_type> >::other node_allocator_type;
        typedef red_black_tree<value_type, value_compare, node_allocator_type> tree_type;

        explicit set(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) {
            _alloc = alloc;
            _node = _rb_tree.create_node(value_type());
            _cmpr = comp;
            _sz = 0;
        }

        template<class TemplateIterator>
        set(TemplateIterator first, TemplateIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) {
            _alloc = alloc;
            _node = _rb_tree.create_node(value_type());
            _cmpr = comp;
            _sz = 0;
            insert(first, last);
        }

        set(const set &x) {
            _alloc = x._alloc;
            _node = _rb_tree.create_node(value_type());
            _cmpr = x._cmpr;
            _sz = x._sz;
            *this = x;
        }

        ~set() {
            _rb_tree.clear(&_node->parent);
            _rb_tree.clear(&_node);
        }

        set &operator=(const set &x) {
            clear();
            _cmpr = x._cmpr;
            _alloc = x._alloc;
            insert(x.begin(), x.end());

            return *this;
        }

        iterator begin() {
            return iterator(_node, _rb_tree.min_node(_node->parent));
        }

        const_iterator begin() const {
            return const_iterator(_node, _rb_tree.min_node(_node->parent));
        }

        iterator end() {
            return iterator(_node, nullptr);
        }

        const_iterator end() const {
            return const_iterator(_node, nullptr);
        }

        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const {
            return const_reverse_iterator(end());
        }

        reverse_iterator rend() {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const {
            return const_reverse_iterator(begin());
        }

        bool empty() const {
            return !_sz;
        }

        size_type size() const {
            return _sz;
        }

        size_type max_size() const {
            _rb_tree.max_size();
        }

        ft::pair<iterator, bool> insert(const value_type &val) {
            bool res = _rb_tree.insert(&_node->parent, _rb_tree.create_node(val));
            _sz += res;
            p_node ptr = _rb_tree.find_node(_node->parent, val);

            return ft::pair<iterator, bool>(iterator(_node, ptr), res);
        }

        template<class TemplateIterator>
        void insert(TemplateIterator first, TemplateIterator last) {
            for (; first != last; ++first) {
                insert(*first);
            }
        }

        iterator insert(iterator, const value_type &val) {
            _sz += _rb_tree.insert(&_node->parent, _rb_tree.create_node(val));
            p_node ptr = _rb_tree.find_node(_node->parent, val);
            return iterator(_node, ptr);
        }

        void erase(iterator pos) {
            bool res = _rb_tree.erase(&_node->parent, *pos);
            if (res)
                --_sz;
        }

        size_type erase(const value_type &val) {
            bool res = (bool) _rb_tree.erase(&_node->parent, val);
            if (res)
                --_sz;
            return res;
        }

        void erase(iterator first, iterator last) {
            while (first != last)
                erase(first++);
        }

        void swap(set &x) {
            ft::swap(x._alloc);
            ft::swap(x._sz);
            ft::swap(x._node);
            ft::swap(x._cmpr);
        }

        void clear() {
            _rb_tree.clear(&_node->parent);
            _node->parent = 0;
            _sz = 0;
        }

        key_compare key_comp() const {
            return _cmpr;
        }

        key_compare value_comp() const {
            return _cmpr;
        }

        iterator find(const Key &val) {
            p_node ptr = _rb_tree.find_node(_node->parent, val);
            return iterator(_node, ptr);
        }

        const_iterator find(const Key &val) const {
            p_node ptr = _rb_tree.find_node(_node->parent, val);
            return const_iterator(_node, ptr);
        }

        size_type count(const Key &val) const {
            if (_rb_tree.find_node(_node->parent, val))
                return 1;
            return 0;
        }

        iterator lower_bound(const Key &val) {
            return iterator(_node, _rb_tree.lower_elem(_node->parent, val));
        }

        const_iterator lower_bound(const Key &val) const {
            return const_iterator(_node, _rb_tree.lower_elem(_node->parent, val));
        }

        iterator upper_bound(const Key &val) {
            p_node tmp = _rb_tree.lowest_elem(_node->parent, val);
            iterator res(_node, tmp);
            if (tmp && tmp->value == val)
                ++res;
            return const_iterator(res);
        }

        const_iterator upper_bound(const Key &val) const {
            p_node tmp = _rb_tree.lowest_elem(_node->parent, val);
            iterator res(_node, tmp);
            if (tmp && tmp->value == val)
                ++res;
            return const_iterator(res);
        }

        ft::pair<iterator, iterator> equal_range(const Key &val) {
            return ft::make_pair(lower_bound(val), upper_bound(val));
        }

        ft::pair<const_iterator, const_iterator> equal_range(const Key &val) const {
            return ft::make_pair(lower_bound(val), upper_bound(val));
        }

        allocator_type get_allocator() const {
            return _alloc;
        }

    private:
        tree_type _rb_tree;
        allocator_type _alloc;
        p_node _node;
        key_compare _cmpr;
        size_type _sz;
    };

    template<class Key, class Compare, class Allocator>
    bool operator==(const set<Key, Compare, Allocator> &x, const set<Key, Compare, Allocator> &y) {
        return x.size() == y.size()
               && ft::equal(x.begin(), x.end(), y.begin())
               && ft::equal(y.begin(), y.end(), x.begin());
    }

    template<class Key, class Compare, class Allocator>
    bool operator!=(const set<Key, Compare, Allocator> &x, const set<Key, Compare, Allocator> &y) {
        return !(x == y);
    }

    template<class Key, class Compare, class Allocator>
    bool operator<(const set<Key, Compare, Allocator> &x, const set<Key, Compare, Allocator> &y) {
        return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end())
               && x != y;
    }

    template<class Key, class Compare, class Allocator>
    bool operator<=(const set<Key, Compare, Allocator> &x, const set<Key, Compare, Allocator> &y) {
        return x < y || x == y;
    }

    template<class Key, class Compare, class Allocator>
    bool operator>(const set<Key, Compare, Allocator> &x, const set<Key, Compare, Allocator> &y) {
        return y < x;
    }

    template<class Key, class Compare, class Allocator>
    bool operator>=(const set<Key, Compare, Allocator> &x, const set<Key, Compare, Allocator> &y) {
        return x > y || x == y;
    }

    template<class Key, class Compare, class Allocator>
    void swap(set<Key, Compare, Allocator> &x, set<Key, Compare, Allocator> &y) {
        x.swap(y);
    }
}

#endif // SET_HPP
