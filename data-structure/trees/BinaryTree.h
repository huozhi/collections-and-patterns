// Binary Tree

#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class tree_iterator;

template <class T>
struct node {
private:
	typedef node<T> __self;
public:
	T data;
	node *left;
	node *right;
};

template <class T>
class bin_tree {
private:
	typedef node<T> _node;
	_node *root;
public:
	typedef tree_iterator<T> iterator;
public:
	bin_tree() {
		root = (_node *)NULL;
	}

	~bin_tree() {
		clear();
	}

	iterator tree_root() {
		return tree_iterator<T>(root);
	}

	void insert(T _data) {
		if (root)
			insert(root, _data);
		else {
			root = new _node;
			root->data = _data;
			root->left = NULL;
			root->right = NULL;
		}
	}

	_node *find(T _key) {
		return find(root, _key);
	}

	int count() const {
		int __cnt = 0;
		queue<_node *> trav_q;
		_node *tmp = root;
		while (tmp) {
			++__cnt;
			if (tmp->left)
				trav_q.push(tmp->left);
			if (tmp->right)
				trav_q.push(tmp->right);
			if (trav_q.empty())
				return __cnt;
			tmp = trav_q.front();
			trav_q.pop();
		}
		return __cnt;
	}

private:

	void clear() {
		clear(root);
	}

	void clear(_node *_leaf) {
		if (_leaf) {
			clear(_leaf->left);
			clear(_leaf->right);
			delete _leaf;
		}
	}

	void insert(_node *_leaf, T _data) {
		if (_data < _leaf->data) {
			if (_leaf->left != NULL)
				insert(_leaf->left, _data);
			else {
				_leaf->left = new _node;
				_leaf->left->data = _data;
				_leaf->left->left = NULL;
				_leaf->left->right = NULL;
			}
		}
		else if (_data >= _leaf->data) {
			if (_leaf->right != NULL)
				insert(_leaf->right, _data);
			else {
				_leaf->right = new _node;
				_leaf->right->data = _data;
				_leaf->right->left = NULL;
				_leaf->right->right = NULL;
			}
		}
	}

	_node *find(_node *_leaf, T _key) {
		if (!_leaf)
			return NULL;
		else {
			if (_key == _leaf->data)
				return _leaf;
			else if (_key < _leaf->data)
				return find(_leaf->left, _key);
			else
				return find(_leaf->right, _key);
		}
	}
};

template <class T>
class tree_iterator {
private:
	typedef tree_iterator<T> __self;
	typedef node<T> _node;
	stack<_node *> iter_stack;
	queue<_node *> iter_queue;
	_node *_cur;
public:
	tree_iterator(_node *_position) :_cur(_position) {}

	~tree_iterator() {}

	void level_order_traversal() {
		level_order_traversal(_cur);
	}

	void in_order_traversal() {
		in_order_traversal(_cur);
	}

	T& operator*() {
		return ((_node *)_cur)->data;
	}

	bool operator!=(_node *_pointer) const {
		return _cur != _pointer;
	}

	__self operator++(int) {
		while (_cur) {
			iter_stack.push(_cur);
			_cur = _cur->left;
		}
		if (!iter_stack.empty()) {
			_cur = iter_stack.top();
			iter_stack.pop();
			
			__self temp = *this;
			_cur = _cur->right;
			return temp;			
		}
		return __self(NULL);
	}

	__self& operator++() {
		while (_cur) {
			iter_stack.push(_cur);
			_cur = _cur->left;
		}
		if (iter_stack.empty()) {
			*this = __self(NULL);
			return *this;
		}

		_cur = iter_stack.top();
		iter_stack.pop();

		return *this;
	}

private:

	void in_order_traversal(_node *_current) {
		if (_current == NULL)
			return;
		in_order_traversal(_current->left);
		cout << _current->data << endl;
		in_order_traversal(_current->right);
	}

	void level_order_traversal(_node *level) {
		while (level) {
			if (level->left)
				iter_queue.push(level->left);
			if (level->right)
				iter_queue.push(level->right);
			if (iter_queue.empty()) {
				cout << level->data << endl;
				break;
			}
			cout << level->data << endl;
			level = iter_queue.front();
			iter_queue.pop();
		}
	}
};

