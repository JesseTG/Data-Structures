/*
 * main.cpp
 *
 *  Created on: Nov 30, 2012
 *      Author: jesse
 */

#include <iostream>
#include "list.h"
#include "tree.h"
using std::cout;
using std::endl;


//List
int main()
{
    List<int> the_list;
    List<int> other   ;
    the_list.append(5);
    the_list.append(6);
    the_list.append(30);
    the_list.append(41);
    the_list.append(233);
    the_list.append(80);
    the_list.swap(1, 4);

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
