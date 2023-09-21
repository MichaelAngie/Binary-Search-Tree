#ifndef bTree_header_h
#define bTree_header_h

#include <iostream>

template <typename T>
class node
{
public:
	node() 
	{
		left = 0; right = 0;
	}
	node(const T& item) : left(0), right(0), data(item) {};
	~node();
	node(const node<T>&);
	void inorder() const;
	void bInsert(const T&);
	bool find(const T&)	 const;
	T predecessor() const;
	node<T>* bRemove(const T&);

private:
	T data;
	node<T>* left;
	node<T>* right;
};


template <typename T>
class bTree
{
public:
	bTree() : root(0) {};
	~bTree();
	bTree(const bTree<T>&);
	void swap(bTree<T>&);
	bTree<T>& operator=(bTree<T> rhs) { swap(rhs); return *this; }
	bool empty() const { return (root == 0); }
	bool full() const;
	bool find(const T&) const;
	void bInsert(const T&);
	void bRemove(const T&);
	void inorder() const;
	//void drawTree() const;

private:
	node<T>* root;
};

template <typename T>
void bTree<T>::swap(bTree<T>& rhs)
{
	node<T>* temp = root;
	root = rhs.root;
	rhs.root = temp;
}

template <typename T>
bool bTree<T>::full() const
{
	node<T>* test = new node<T>;
	if (test == 0) return true;
	else
	{
		delete test;
		return false;
	}
}
template <typename T>
bool bTree<T>::find(const T& key) const
{
	if (!root) return false;
	return root->find(key);
}

template <typename T>
bool node<T>::find(const T& key) const
{
	if (data == key) return true;
	if (key < data)
	{
		if (left) return left->find(key);
		else return false;
	}
	else
	{
		if (right) return right->find(key);
		else return false;
	}
}

template <typename T>
void bTree<T>::bInsert(const T& x)
{
	if (!root)
	{
		root = new node<T>(x);
	}
	else
	{
		root->bInsert(x);
	}
}

template <typename T>
void node<T>::bInsert(const T& x)
{
	if (x < data)
	{
		if (left) left->bInsert(x);
		else left = new node<T>(x);
	}
	else
	{
		if (x == data) return;   // ensure no duplicates
		if (right) right->bInsert(x);
		else right = new node<T>(x);
	}
}

template <typename T>
void bTree<T>::inorder() const
{
	if (root) root->inorder();
}

template <typename T>
void node<T>::inorder() const
{
	if (left) left->inorder();
	std::cout << data << " ";
	if (right) right->inorder();
}

template <typename T>
T node<T>::predecessor() const
{
	if (right) return right->predecessor();
	else return data;
}

template <typename T>
void bTree<T>::bRemove(const T& x)
{
	if (find(x)) root = root->bRemove(x);
}

template <typename T>
node<T>* node<T>::bRemove(const T& x)
{
	node<T>* temp;
	if (x == data)   // found the value
	{
		if (!left && !right)	//no subtrees
		{
			delete this;
			return 0;			//return 0?  because points to nothing?
		}

		if (!left && right)		//only right subtree
		{
			temp = right;
			right = 0;
			delete this;
			return temp;
		}

		if (left && !right)		//only left subtree
		{
			temp = left;
			left = 0;
			delete this;
			return temp;
		}

		//otherwise move to else cuz there are two children
		data = left->predecessor(); 
		left = left->bRemove(x);
	}
	else  // find the value in tree
	{
		if (x < data)
			left = left->bRemove(x);
		else
			right = right->bRemove(x);
	}
	return this;
}

template <typename T>
bTree<T>::~bTree()
{
	if (root) delete root;
}

template <typename T>
node<T>::~node()
{
	if (left) delete left;
	if (right) delete right;
}

//copy constru
template <typename T>
bTree<T>::bTree(const bTree<T>& actual) : bTree()
{
	if (actual.root)  //(need if?)
		root = new node<T>(*(actual.root));
}

template <typename T> 
node<T>::node(const node<T>& actual)
{
	data = actual.data;
	if (actual.left) left = new node<T>(*(actual.left));
	if (actual.right) right = new node<T>(*(actual.right));
}

#endif // !bTree_header.h
