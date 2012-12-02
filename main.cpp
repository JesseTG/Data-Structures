/*
 * main.cpp
 *
 *  Created on: Nov 30, 2012
 *      Author: jesse
 */

#include <iostream>
#include "vector.h"
#include "list.h"
#include "tree.h"
#include "iterator.h"
using std::cout;
using std::endl;

/*
//Vector
int main()
{
    Vector<int32_t> the_vector;

    the_vector.append(16);
    the_vector.append(45);
    the_vector.append(128);
    the_vector.append(31);

    cout << "Size: " << the_vector.size() << endl;

    cout << *the_vector.getFirst() << endl << *(the_vector.getFirst() + 1) << endl << *(the_vector.getFirst() + 2) << endl;
}
*/



//List
int main()
{
    List<int> the_list;
    the_list.append(5);
    the_list.append(6);
    the_list.append(30);
    the_list.append(41);
    the_list.append(233);
    the_list.append(80);
    the_list.bubbleSort();

    Node<int>* temp = the_list.getFirst();
    while (temp != nullptr) {
        cout << temp->element << std::endl;
        temp = temp->next;
    }
}



/*
//Tree
int main()
{
    BinaryTree<int, std::string> the_tree;
    the_tree.insert(5, "france");
    the_tree.insert(7, "spain");
    the_tree.insert(30,"china");
    the_tree.insert(21, "america");
    the_tree.insert(1, "sweden");
    the_tree.insert(-4, "canada");
    the_tree.insert(6, "mongolia");
    the_tree.insert(2, "japan");

    cout << the_tree.get(5) << endl;
    cout << the_tree.get(7) << endl;
    cout << the_tree.get(30) << endl;
    cout << the_tree.get(21) << endl;
    cout << the_tree.get(1) << endl;
    cout << the_tree.get(-4) << endl;
    cout << the_tree.get(6) << endl;
    cout << the_tree.get(2) << endl;

}
*/
