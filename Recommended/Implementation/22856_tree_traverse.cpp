#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* end_node;
vector<Node*> visited;
int ans = 0;
bool flag = true;

class Tree
{
public:

    Node* CreateNode()
    {
        Node* newNode = new Node;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    bool GetData(Node* node, int& data){
        if(node == nullptr) return false;
        data = node->data;
        return true;
    }

    bool SetData(Node* node, int data){
        if(node == nullptr) return false;
        node->data = data;
        return true;
    }

    void RemoveNode(Node* node){
        if(node == nullptr) return;
        RemoveNode(node->left);
        RemoveNode(node->right);
        delete node;
    }

    bool GetLeftNode(Node* parent, Node** node){
        if(parent == nullptr || parent->left == nullptr){
            *node = nullptr;
            return false;
        }
        *node = parent->left;
        return true;
    }

    bool GetRightNode(Node* parent, Node** node){
        if(parent == nullptr || parent->right == nullptr){
            *node = nullptr;
            return false;
        }
        *node = parent->right;
        return true;
    }

    bool SetLeftNode(Node* parent, Node* child){
        if(parent== nullptr || child == nullptr) return false;
        if(parent->left != nullptr) RemoveNode(parent->left);

        parent->left = child;
        return true;
    }

    bool SetRightNode(Node* parent, Node* child){
        if(parent== nullptr || child == nullptr) return false;
        if(parent->right != nullptr) RemoveNode(parent->right);

        parent->right = child;
        return true;
    }

    void PreorderPrint(Node* node){
        if(node == nullptr) return;
        cout << node->data << '\n';
        PreorderPrint(node->left);
        PreorderPrint(node->right);
    }

    void InorderPrint(Node* node){
        if(node == nullptr) return;
        InorderPrint(node->left);
//        cout << node->data << '\n';
        end_node = node;
        InorderPrint(node->right);
    }

    void PostorderPrint(Node* node){
        if(node == nullptr) return;
        PostorderPrint(node->left);
        cout << node->data << '\n';
        PostorderPrint(node->right);
    }
};

void PseudoTraverse(Node* node){

    visited.push_back(node);

    if(node->left != nullptr and
        find(visited.begin(), visited.end(),
         node->left) == visited.end()){
        ans++;
        PseudoTraverse(node->left);
        if(flag)ans++;
    }
    if(node->right != nullptr and
    find(visited.begin(), visited.end(),
         node->right) == visited.end()){
        ans++;
        PseudoTraverse(node->right);
        if(flag) ans++;
    }
    if(node == end_node){
        flag = false;
        return;
    }
}

Node* findNodeByData(vector<Node*>& nodes, int data) {
    for (Node* node : nodes) {
        if (node->data == data) return node;
    }
    return nullptr;
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Tree* tree = new Tree();
    vector<Node*> node_list;

    Node* RootNode = tree->CreateNode();
    tree->SetData(RootNode, 1);
    node_list.push_back(RootNode);

    int N; cin >> N;

    for(int i=0; i<N; i++){
        int n, a, b;
        cin >> n >> a >> b;
        Node* parentNode = findNodeByData(node_list, n);

        if(a!=-1){
            Node* LeftNode = tree->CreateNode();
            tree->SetData(LeftNode, a);
            node_list.push_back(LeftNode);
            tree->SetLeftNode(parentNode, LeftNode);
        }
        if(b!=-1) {
            Node *RightNode = tree->CreateNode();
            tree->SetData(RightNode, b);
            node_list.push_back(RightNode);
            tree->SetRightNode(parentNode, RightNode);
        }
    }

    tree->InorderPrint(node_list[0]);
//    cout << end_node->data;
    PseudoTraverse(node_list[0]);
    cout << ans;
}
