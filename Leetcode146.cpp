#include<iostream>
#include<map>
#include<unordered_map>

struct DLinkedNode
{
    int key,value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0),value(0),prev(nullptr),next(nullptr){}
    DLinkedNode(int _key,int _value):key(_key),value(_value),prev(nullptr),next(nullptr){}
};

class LRUCache
{
private:
    std::unordered_map<int,DLinkedNode*>cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity):capacity(_capacity),size(0)
    {
        head=new DLinkedNode();
        tail=new DLinkedNode();
        head->next=tail;
        tail->prev=head;
    }

    int get(int key)
    {
        if(cache.count(key)>0)
        {
            DLinkedNode* cur=cache[key];
            moveToHead(cur);
            return cur->value;
        }
        return -1;
    }

    void put(int key,int value)
    {
        if(cache.count(key)>0)
        {
            DLinkedNode* cur=cache[key];
            cur->value=value;
            moveToHead(cur);
        }
        if(!cache.count(key))
        {
            DLinkedNode* node=new DLinkedNode(key,value);
            cache[key]=node;
            insertHead(node);
            size++;
            if(size>capacity)
            {
                DLinkedNode* getTail=removeTail();
                cache.erase(getTail->key);
                delete getTail;
                size--;
            }
        }

    }

    void remove(DLinkedNode* cur)
    {
        cur->prev->next=cur->next;
        cur->next->prev=cur->prev;
    }

    void insertHead(DLinkedNode* node)
    {
        node->prev=head;
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
    }

    void moveToHead(DLinkedNode* node)
    {
        remove(node);
        insertHead(node);
    }

    DLinkedNode* removeTail()
    {
        DLinkedNode* node=tail->prev;
        remove(node);
        return node;
    }

};