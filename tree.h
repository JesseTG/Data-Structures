#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>

template<class K, class E>
struct TreeNode
{
    TreeNode() : parent(nullptr), left(nullptr), right(nullptr) {};
    TreeNode(TreeNode<K, E>* p, TreeNode<K, E>* l, TreeNode<K, E>* r, K& k, E& e) :
        parent(p), left(l), right(r), key(k), element(e) {};

    bool isLeaf() const { return (left == nullptr) && (right == nullptr); }

    TreeNode<K, E>* parent;
    K key                 ;
    E element             ;
    TreeNode<K, E>* left  ;
    TreeNode<K, E>* right ;



};

template<class K, class E>
class BinaryTree
{
    public:
        BinaryTree() : root(nullptr) {};
        //BinaryTree()
       ~BinaryTree();

        bool hasKey(const K&)     const;
        bool hasElement(const E&) const;
        E& get(const K& key) const
            { return search(key, root)->element; }

        void insert(const K&, const E&);
        void remove(const K&);



        E& operator[](const K&) const;


        /*E& operator[](const K)
            {
                return
            }  //Changes the given key's element*/

    private:
        TreeNode<K, E>* root;

        TreeNode<K, E>* search(const K&, TreeNode<K, E>*) const;


        void _insert(const K&, const E&, TreeNode<K, E>*);
};

template<class K, class E>
BinaryTree<K, E>::~BinaryTree()
{


}

template<class K, class E>
void BinaryTree<K, E>::insert(const K& key, const E& element)
{
    if (root == nullptr) {
    //If we don't have a root element yet...
        root          = new TreeNode<K, E>;
        root->key     = key;
        root->element = element;
    }
    else {
        _insert(key, element, root);
    }
}

template<class K, class E>
void BinaryTree<K, E>::remove(const K& key)
{
    TreeNode<K, E>* node = search(key, root);
    if (node == nullptr) return;

    std::cout << "bye bye\n";

    if (node->isLeaf()) {
        delete node;

        std::cout << int(node == nullptr) << '\n';
    }


}

template<class K, class E>
void BinaryTree<K, E>::_insert(const K& key, const E& element, TreeNode<K, E>* node)
{
    if (node->key == key) {
    //If the tree already has this key...
        node->element = element;  //Then reassign it.
        return;
    }

    TreeNode<K, E>* newnode = (key < node->key) ? node->left : node->right;
    //Pick the next node to check based on how the keys compare.

    if (newnode == nullptr) {
    //If there is no child node in this direction...
        newnode          = new TreeNode<K, E>(node, key, element, nullptr, nullptr);
        std::cout << "Adding child\n";
    }
    else {
        std::cout << "Recursing deeper.\n";
        _insert(key, element, newnode);
    }
}

template<class K, class E>
TreeNode<K, E>* BinaryTree<K, E>::search(const K& key, TreeNode<K, E>* node) const
//key: Look for the element with this key
//node: The node to start searching from
{
    if (node == nullptr) {
    //If our parent node doesn't actually have this child...
        return nullptr;
    }
    else if (node->key == key) {
    //If this node's key is equal to the desired key...
        return node;
    }
    else {
    //If the desired key compares less than this node's key...
        return search(key, (key < node->key) ? node->left : node->right);
    }
}

template<class K, class E>
bool BinaryTree<K, E>::hasKey(const K& key) const
{
    return search(key) != nullptr;
}

/*template<class K, class E>
bool BinaryTree<K, E>::hasElement(const E& element) const
{
    return false;
    //Not Implemented!
}*/



#endif // TREE_H_INCLUDED
