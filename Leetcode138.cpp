#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Node* copyRandomList(Node* ad){
//     if(ad == nullptr) return nullptr;

//     map<Node*, Node*> copy;
//     Node* curNode = ad;
    
//     while(curNode != nullptr){
//         Node* copyNode = new Node(curNode->val);
//         copy[curNode] = copyNode;
//         curNode = curNode->next;
//     }

//     curNode = ad;
//     Node* virtualHead = new Node(-1);
//     virtualHead->next = copy[curNode];
//     while(curNode != nullptr){
//         copy[curNode]->next = copy[curNode->next];
//         copy[curNode]->random = copy[curNode->random];
//         curNode = curNode->next;
//     }

//     return virtualHead->next;
// }

Node* copyRandomList(Node* ad){
    if(ad == nullptr) return nullptr;
    
    Node* curNode = ad;
    while(curNode != nullptr){
        Node* copyNode = new Node(curNode->val);
        copyNode->next = curNode->next;
        curNode->next = copyNode;
        curNode = curNode->next->next;
    }

    curNode = ad;
    while(curNode != nullptr){
        if(curNode->random != nullptr){
            curNode->next->random = curNode->random->next;
        }
        curNode = curNode->next->next;
    }

    curNode = ad;
    Node* virtualHead = new Node(-1);
    virtualHead->next = curNode->next;
    Node* curCopyNode = virtualHead->next;
    while(curNode != nullptr){
        curNode->next = curNode->next->next;
        if(curNode->next != nullptr){
            curCopyNode->next = curNode->next->next;
        }
        curNode = curNode->next;
        curCopyNode = curCopyNode->next;
    }

    return virtualHead->next;
}