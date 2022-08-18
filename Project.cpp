#include"LinkRedBlackTree.h"

#include <windows.h>
int main()
{
    int val = 0;
    int tempUser = 0;
    RedBlackTree<int> obj;
    HelperFunction objFun;
    char* operationTask = new char[25]{ '\0' };
    while (1)
    {
        objFun.mainMenu();
        cout.width(33); cout << "-->";
        cin >> tempUser;
        if (tempUser == 1)
        {
            char operationTask[25] = { "Insertion" };
            objFun.selectedBox(tempUser);
            cout << "*Enter a value to insert in a RED - Black Tree: ";
            cin >> val;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(256, '\n');
                cout << "*Invalid data cannot be inserted.\n";
                objFun.failBox(operationTask);
                continue;
            }
            objFun.sucessBox(operationTask);
            obj.insert(val);
            cout << "The " << val << " is inserted into RED - Black Tree.\n";
        }
        else if (tempUser == 2)
        {
            char operationTask[25] = { "Deletion" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                cout << "Enter a value to delete from RED - Black Tree: ";
                cin >> val;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Invalid data cannot be deleted.\n";
                    objFun.failBox(operationTask);
                    continue;
                }
                if (obj.search(val) == true)
                {
                    obj.deleteAValue(val);
                    cout << "The " << val << " is deleted from the RED - Black Tree.\n";
                    objFun.sucessBox(operationTask);
                }
                else
                {
                    cout << "The " << val << " is not present in the RED - Black Tree.\n";
                    objFun.failBox(operationTask);
                }
            }
            else
            {
                cout << "RED - Black Tree is empty, so any value cannot be deleted from Tree.\n";
                objFun.failBox(operationTask);
            }
        }
        else if (tempUser == 3)
        {
            char operationTask[25] = { "Searching" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                cout << "Enter a value to search in a Tree: ";
                cin >> val;
                if (obj.search(val))
                {
                    objFun.sucessBox(operationTask);
                    cout << "This value " << val << " is found...!\n";
                }
                else
                {
                    cout << "This value " << val << " is not found...!\n";
                    objFun.failBox(operationTask);
                }
            }
            else
            {
                cout << "Tree is empty, so cannot be search.\n";
                objFun.failBox(operationTask);
            }

        }
        else if (tempUser == 4)
        {
            char operationTask[25] = { "Inorder" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                cout << "Inorder Traversal: ";
                obj.inorder();
                objFun.sucessBox(operationTask);
            }
            else
            {
                cout << "Tree is empty, so cannot be print.\n";
                objFun.failBox(operationTask);
            }
        }
        else if (tempUser == 5)
        {
            char operationTask[25] = { "Preorder" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                cout << "Preorder Traversal: ";
                obj.preorder();
                objFun.sucessBox(operationTask);
            }
            else
            {
                cout << "Tree is empty, so cannot be print.\n";
                objFun.failBox(operationTask);
            }
        }
        else if (tempUser == 6)
        {
            char operationTask[25] = { "Postorder" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                cout << "Postorder Traversal: ";
                obj.postorder();
                objFun.sucessBox(operationTask);
            }
            else
            {
                cout << "Tree is empty, so cannot be print.\n";
                objFun.failBox(operationTask);
            }
        }
        else if (tempUser == 7)
        {
            char operationTask[25] = { "MyInorder" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                cout << "MyInorder Traversal: ";
                obj.selfInorder();
                objFun.sucessBox(operationTask);
            }
            else
            {
                cout << "Tree is empty, so cannot be print.\n";
                objFun.failBox(operationTask);
            }
        }
        else if (tempUser == 8)
        {
            char operationTask[25] = { "MyPreorder" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                cout << "MyPreorder Traversal: ";
                obj.selfPreorder();
                objFun.sucessBox(operationTask);
            }
            else
            {
                cout << "Tree is empty, so cannot be print.\n";
                objFun.failBox(operationTask);
            }
        }
        else if (tempUser == 9)
        {
            char operationTask[25] = { "MyPostorder" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                cout << "MyPostorder Traversal: ";
                obj.selfPostOrder();
                objFun.sucessBox(operationTask);
            }
            else
            {
                cout << "Tree is empty, so cannot be print.\n";
                objFun.failBox(operationTask);
            }
        }
        else if (tempUser == 10)
        {
            char operationTask[25] = { "TreeDestroyed" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                cout << "Tree has been destroyed.\n";
                obj.destroyRBTree();
                objFun.sucessBox(operationTask);
            }
            else
            {
                cout << "Tree is empty, so cannot be Destroyed.\n";
                objFun.failBox(operationTask);
            }
        }
        else if (tempUser == 11)
        {
            char operationTask[25] = { "SmallerDeletion" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                cout << "Enter a value  to delete its smaller: ";
                cin >> val;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Invalid data cannot be deleted.\n";
                    continue;
                }
                if (obj.search(val) == true)
                {
                    obj.deleteGreaterThanX(val);
                    objFun.sucessBox(operationTask);
                }
                else
                {
                    cout << "The " << val << " is not present in the RED - Black Tree.\n";
                    objFun.failBox(operationTask);

                }
            }
            else
            {
                cout << "Tree is empty, so cannot be deletion.\n";
                objFun.failBox(operationTask);

            }
        }
        else if (tempUser == 12)
        {
            char operationTask[25] = { "FindParent" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                objFun.sucessBox(operationTask);
                cout << "Enter a child to find its parent: ";
                cin >> val;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Invalid data cannot be Find its Parent.\n";
                    continue;
                }
                if (obj.getParentValue(val))
                {
                    cout << "Parent of " << val << " :" << (obj.getParentValue(val)) << endl;
                    if (obj.getRoot(obj.parentNode(val))->colour =='B')
                    {
                        cout << "Colour of Parent : Black.\n";
                    }
                    else
                    {
                        cout << "Colour of Parent : Red.\n";
                    }
                }
                else
                {
                    cout << "This Value " << val << " has no Parent.\n";
                    objFun.failBox(operationTask);
                }
            }
            else
            {
                cout << "Tree is empty, so cannot be Find its Parent.\n";
                objFun.failBox(operationTask);
            }

        }
        else if (tempUser == 13)
        {
            char operationTask[25] = { "ReadingFile" };
            objFun.selectedBox(tempUser);
            if (obj.readFile())
            {
                cout << "Data has been read from file.\n";
                objFun.sucessBox(operationTask);
            }
            else
            {
                cout << "Data is not read from file...!";
                objFun.failBox(operationTask);
            }
        }
        else if(tempUser==15)
        {
            char operationTask[25] = { "DisplayedTree" };
            objFun.selectedBox(tempUser);
            if (!obj.emptyTree())
            {
                obj.displayTree();
                objFun.sucessBox(operationTask);
            }
            else
            {
                cout << "Tree is empty, so cannot be Find its Displayed.\n";
                objFun.failBox(operationTask);
            }

        }
        else if(tempUser==14)
        {
            objFun.selectedBox(tempUser);
            char operationTask[25] = { "Exit" };
            objFun.sucessBox(operationTask);;
            break;
        }
        else
        {
            objFun.failInput();
        }
    }
}
