#ifndef MAP_HPP
#define MAP_HPP

#include <memory>

namespace ft {
	template<
	    class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> >
	> class map {
        typedef Key												                key_type;
        typedef T										                        mapped_type;
        typedef ft::pair<const Key, T>                                          pair_type;
        typedef Compare                                                         key_compare;
        typedef Allocator										                allocator_type;
        typedef typename allocator_type::reference                              reference;
        typedef typename allocator_type::const_reference                        const_reference;
        typedef typename allocator_type::pointer                                pointer;
        typedef typename allocator_type::const_pointer                          const_pointer;
        typedef ft::rbt_iterator<value_type>                                    iterator;
        typedef ft::rbt_iterator<const value_type>                              const_iterator;
        typedef ft::reverse_iterator<value_type>                                reverse_iterator;
        typedef ft::reverse_iterator<const value_type>                          const_reverse_iterator;
        typedef difference_type                                                 size_type;
        typedef typename ft::iterator_traits<iterator>::difference_type         difference_type;

        typedef typename ft::pair_compare<key_type, mapped_type, key_compare>   value_compare;
        typedef typename Allocator::template rebind<node<pair_type> >::other    node_allocator_type;
        typedef red_black_tree<pair_type, value_compare, node_allocator_type>   tree_type;
        typedef typename ft::node<pair_type>                                    *p_node;

	private:
		allocator_type  _alloc;
        key_compare     _k_cmpr;
        value_compare   _v_cmpr;
        tree_type       _rbt;
        p_node          _node;
        size_type       _sz;

        pair_type add_new_pair(const Key& k) const {
            return ft::make_pair(k, mapped_type());
        }

    public:
        explicit map(const key_compare& comp = key_compare(),
                     const allocator_type& alloc = allocator_type()) {
            _alloc = alloc;
            _node = _rbt.create_node(pair_type());
            _k_cmpr = comp;
        }

        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()) {
            _alloc = alloc;
            _node = _rbt.create_node(pair_type());
            _k_cmpr = comp;
            insert(first, last);
        }

        ~map() {
            _rbt.clear(&_node->parent);
            _rbt.clear(&_node);
        }

        map& operator=(const map& other) {
            clear();
            _alloc = other._alloc;
            _node = _rbt.create_node(pair_type());
            _k_cmpr = other._k_cmpr;
            *this = other;
        }

        iterator begin() {
            return iterator(_node, _rbt.min_node(_node->parent));
        }

        const_iterator begin() const {
            return const_iterator(_node, _rbt.min_node(_node->parent));
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
            _rbt.max_size();
        }

        mapped_type &operator[](const key_type &k){
            bool res = _rbt.insert(&_node->parent, _rbt.create_node(add_new_pair(k)));
            _sz += res;
            p_node p = _rbt.find_node(_node->parent, add_new_pair(k));
            return p->value.second;
        }

        ft::Pair<iterator, bool> insert(const value_type& val) {
            bool res = _rbt.insert(&_node->parent, _rbt.create_node(val));
            _sz += res;
            p_node ptr = _rbt.find_node(_node->parent, val);
            return ft::pair<iterator, bool>(iterator(_node, ptr), res);
        }

        template <class TemplateIterator>
        void insert(TemplateIterator first, TemplateIterator last) {
            for (; first != last; ++first) {
                insert(*first);
            }
        }

        iterator insert(iterator, const value_type& val) {
            _sz += _rbt.insert(&node->parent, _rb_tree.create_node(val));
            p_node ptr = _rbt.find_node(_node->parent, val);
            return iterator(_node, ptr);
        }

        void erase(iterator pos) {
            bool res = _rbt.erase(&node->parent, *pos);
            if (res)
                --_sz;
        }

        size_type erase(const key_type& val) {
            bool res = (bool)_rbt.erase(&_node->parent, add_new_pair(val));
            if (res)
                --_sz;
            return res;
        }

        void erase(iterator first, iterator last) {
            while (first != last)
                erase(first++);
        }

        void swap(map& x) {
            ft::swap(x._node, _node);
            ft::swap(x._k_cmpr, _k_cmpr);
            ft::swap(x._v_cmpr, _v_cmpr);
            ft::swap(x._sz, _sz);
        }

        void clear() {
            _rbt.clear(&node->parent);
            _node->parent = 0;
            _sz = 0;
        }

        key_compare key_comp() const {
            return _k_cmpr;
        }

        key_compare value_comp() const {
            return _v_cmpr;
        }

        iterator  find(const key_type& val) {
            p_node ptr = _rbt.find_node(_node->parent, val);
            return iterator(_node, ptr);
        }

        const_iterator  find(const key_type& val) {
            p_node ptr = _rbt.find_node(_node->parent, val);
            return const_iterator(_node, ptr);
        }

        size_type count(const key_type& val) const {
            if (_rbt.find_node(_node->parent, add_new_pair(val)))
                return 1;
            return 0;
        }

        iterator lower_bound(const key_type& val) {
            return iterator(_node, _rbt.lower_elem(_node->parent, add_new_pair(val)));
        }

        const_iterator lower_bound(const Key& val) const {
            return const_iterator(_node, _rbt.lower_elem(_node->parent, add_new_pair(val)));
        }

        iterator upper_bound(const key_type& val) {
            p_node tmp = _rbt.lowest_elem(node_->parent, add_new_pair(val));
            iterator res(node_, tmp);
            if (tmp && tmp->value.first == val)
                ++res;
            return iterator(res);
        }

        const_iterator upper_bound(const key_type& val) const {
            p_node tmp = _rbt.lowest_elem(node_->parent, add_new_pair(val));
            iterator res(node_, tmp);
            if (tmp && tmp->value.first == val)
                ++res;
            return iterator(res);
        }

        ft::pair<iterator, iterator> equal_range(const Key& val){
            return ft::make_pair(lower_bound(val), upper_bound(val));
        }

        ft::pair<const_iterator, const_iterator> equal_range(const Key& val) const{
            return ft::make_pair(lower_bound(val), upper_bound(val));
        }

        allocator_type get_allocator() const{
            return _alloc;
        }
	};

    template<class Key, class T, class Compare, class Allocator>
    bool operator==(const map<Key, T, Compare, Allocator> &x,
                    const map<Key, T, Compare, Allocator> &y){
        return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()) && ft::equal(y.begin(), y.end(), x.begin());
    }

    template<class Key, class T, class Compare, class Allocator>
    bool operator!=(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y){
        return !(x == y);
    }

    template<class Key, class T, class Compare, class Allocator>
    bool operator<(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y){
        return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()) && x != y;
    }

    template<class Key, class T, class Compare, class Allocator>
    bool operator<=(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y){
        return x < y || x == y;
    }

    template<class Key, class T, class Compare, class Allocator>
    bool operator>(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y){
        return y < x;
    }

    template<class Key, class T, class Compare, class Allocator>
    bool operator>=(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y){
        return x > y || x == y;
    }

    template<class Key, class T, class Compare, class Allocator>
    void swap(map<Key, T, Compare, Allocator> &x, map<Key, T, Compare, Allocator> &y){
        x.swap(y);
    }
}

#endif
