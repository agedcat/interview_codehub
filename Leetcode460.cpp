#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

struct Node
{
    int key;
    int value;
    int frenquency;
    Node(int _key,int _value,int _frequency):key(_key),value(_value),frenquency(_frequency){}
};

class LFUCache {
public:
    LFUCache(int _capacity) {
        capacity=_capacity;
        minfreq=0;
        frequency_table.clear();
        key_table.clear();
    }
    
    int get(int key) {
        if(capacity==0) return -1;
        auto it=key_table.find(key);
        if(it==key_table.end()) return -1;
        auto node=it->second;
        int val=node->value;
        int freq=node->frenquency;
        //删除操作
        frequency_table[freq].erase(node);
        if(frequency_table[freq].size()==0)
        {
            //记录freq频率的双链表没结点了
            frequency_table.erase(freq);
            if(minfreq==freq) minfreq++;
        }
        //添加结点
        frequency_table[freq+1].push_front(Node(key,val,freq+1));
        key_table[key]=frequency_table[freq+1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        auto it=key_table.find(key);
        //key表中找不到值，分缓存满和不满两种情况
        if(it==key_table.end())
        {
            //缓存已经满的情况
            if(key_table.size()==capacity)
            {
                auto it2=frequency_table[minfreq].back();
                key_table.erase(it2.key);
                frequency_table[minfreq].pop_back();
                if(frequency_table[minfreq].size()==0)
                {
                    frequency_table.erase(minfreq);
                }
            }
            //两种情况都要添加操作，所以合并在一起
            frequency_table[1].push_front(Node(key,value,1));
            key_table[key]=frequency_table[1].begin();
            minfreq=1;
        }
        else{
            //如果表中存在，需要更新frequency的值
            auto node=it->second;
            int freq=node->frenquency;
            //删除操作
            frequency_table[freq].erase(node);
            if(frequency_table[freq].size()==0)
            {
                //记录freq频率的双链表没结点了
                frequency_table.erase(freq);
                if(minfreq==freq) minfreq++;
            }
            //添加结点
            frequency_table[freq+1].push_front(Node(key,value,freq+1));
            key_table[key]=frequency_table[freq+1].begin();
        }
    }

private:
    int minfreq;
    int capacity;
    unordered_map<int,list<Node>>frequency_table;
    unordered_map<int,list<Node>::iterator>key_table;
};
