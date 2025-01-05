#include<bits/stdc++.h>

using namespace std;

class LFUCache{
    public:
    class node{
        public:
        int key;
        int value;
        int freq;
        node* next;
        node* prev;
        node(int _key, int _value){
            key = _key;
            value = _value;
            freq = 1;
        }
    };

    class dlist{
        public:
        node* head = new node(-1,-1);
        node* tail = new node(-1,-1);
        int size;

        dlist(){
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addnode(node* newnode){
            node* temp = head->next;
            newnode->next = temp;
            newnode->prev = head;
            head->next = newnode;
            temp->prev = newnode;
            size++;
        }

        void deletenode(node* delnode){
            node* delprev = delnode->prev;
            node* delnext = delnode->next;
            delprev->next = delnext;
            delnext->prev = delprev;
            size--;
        }

        node* deletetail(){
            node* delnode = tail->prev;
            deletenode(delnode);
            return delnode;
        }
    };

    int cap;
    unordered_map<int, node*> m;
    unordered_map<int, dlist*> freqm;
    int minfreq;

    LFUCache(int capacity){
        cap = capacity;
        minfreq = 0;
    }

    void updatefreq(node* currnode){
        int freq = currnode->freq;
        dlist* dl = freqm[freq];
        dl->deletenode(currnode);
        if(freq==minfreq && dl->size==0){
            minfreq++;
        }
        currnode->freq++;
        if(freqm.find(currnode->freq)==freqm.end()){
            freqm[currnode->freq] = new dlist();
        }
        dlist* newdl = freqm[currnode->freq];
        newdl->addnode(currnode);
    }

    int get(int key_){
        if(m.find(key_)!=m.end()){
            node* currnode = m[key_];
            int res = currnode->value;
            updatefreq(currnode);
            return res;
        }
        return -1;
    }

    void put(int key, int val){
        if(cap==0){
            return;
        }
        if(m.find(key)!=m.end()){
            node* currnode = m[key];
            currnode->value = value;
            updatefreq(currnode);
        }else{
            if(m.size()==cap){
                dlist* dl = freqm[minfreq];
                node* delnode = dl->deletetail();
                m.erase(delnode->key);
            }
            minfreq = 1;
            node* newnode = new node(key,value);
            m[key] = newnode;
            if(freqm.find(1)==freqm.end()){
                freqm[1] = new dlist();
            }
            dlist* dl = freqm[1];
            dl->addnode(newnode);
        }
    }
};

int main(){
    LFUCache* cache = new LFUCache(2);
    cache->put(1,1);
    cache->put(2,2);
    cout<<cache->get(1)<<endl;
    cache->put(3,3);
    cout<<cache->get(2)<<endl;
    cout<<cache->get(3)<<endl;
    cache->put(4,4);
    cout<<cache->get(1)<<endl;
    cout<<cache->get(3)<<endl;
    cout<<cache->get(4)<<endl;
    return 0;
}