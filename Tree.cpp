#include <iostream>
using namespace std;

class Tree{
public:
    string name;
    Tree *left;
    Tree *right;

    Tree(string a, Tree* b, Tree* c){
        name = a;
        left = b;
        right = c;
    }

};

Tree* Insert(Tree *root, string name);
bool Search(Tree *root, string name);
Tree *Delete(Tree *root, string name);
Tree *DeleteNode(Tree *root);
Tree *FindMin(Tree *root);
void Traversal(Tree *root);


int main(){
    Tree *root = NULL;

    while (1){
        string input;
        cin >> input;

        if (input.compare("Insert") == 0)
        {
            string name;
            cin >> name;
            root = Insert(root, name);
        }
        else if (input.compare("search") == 0){
            string name;
            cin >> name;
            cout << (Search(root, name) ? "yes" : "no") << endl;
            
        }
        else if (input.compare("delete") == 0){
            string name;
            cin >> name;
            root = Delete(root, name);
        }
        else if (input.compare("print") == 0){
            Traversal(root);
        }


    }
}

Tree* Insert(Tree *root, string name){
    if (root == NULL)
    {
        root = new Tree(name, NULL,  NULL);
    }
    else if (root->name.compare(name) > 0){
        root->left = Insert(root->left, name);
    }
    else if (root->name.compare(name) < 0){
        root->right = Insert(root->right, name);
    }
    return root;
}

bool Search(Tree *root, string name){
    if (root == NULL)
    {
        return false;
    }
    else if (root->name.compare(name) == 0){
        return true;
    }
    else if (root->name.compare(name) > 0){
        Search(root->left, name);
    }
    else if (root->name.compare(name) < 0){
        Search(root->right, name);
    }
}

Tree *Delete(Tree *root, string name){
    if (root->name.compare(name) == 0)
    {
        root = DeleteNode(root);
    }
    else if (root->name.compare(name) > 0){
        root->left = Delete(root->left, name);
    }
    else if (root->name.compare(name) < 0){
        root->right = Delete(root->right, name);
    }
    return root;
}

Tree *DeleteNode(Tree *root){
    if (root->right == NULL){
        return root->left;
    }
    else if (root->left == NULL){
        return root->right;
    }
    else {
        Tree *a = FindMin(root->right);
        root->name = a->name;
        root->right = Delete(root->right, a->name);
        return root;
    }
}

Tree *FindMin(Tree *root){
    if (root->left == NULL) return root;
    else return FindMin(root->left);
}

void Traversal(Tree *root){
    if (root == NULL) return;
    Traversal(root->left);
    cout << root->name << endl;
    Traversal(root->right);
}