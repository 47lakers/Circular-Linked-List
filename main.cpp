//
//  main.cpp
//  Circular Linked List
//
//  Created by Ira Xavier Porchia on 5/8/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
using namespace std;

class node{
    friend class circular;
private:
    int _data;
    node *_next;
public:
    node():
    _data(-1),
    _next(nullptr){}
    
    node(int data):
    _data(data),
    _next(nullptr){}
};

class circular{
private:
    node *_head;
public:
    circular():
    _head(nullptr){}
    
    ~circular(){
        clear();
    }
    
//    void clear(){
//        if(_head == nullptr){
//            return;
//        }
//        if(_head->_next == _head){
//            _head->_next = nullptr;
//            delete _head;
//            return;
//        }
//        node *temp = _head->_next;
//        node *p;
//        _head->_next = nullptr;
//        while(temp != _head){
//            p = temp;
//            temp = temp->_next;
//            p->_next = nullptr;
//            delete p;
//        }
//    }
//
//    void prepend(int data){
//        if(_head == nullptr){
//            _head = new node(data);
//            _head->_next = _head;
//        }
//        node *temp = new node(data);
//        temp->_next = _head->_next;
//        _head->_next = temp;
//    }
//
//    void traverse(){
//        node *p = _head->_next;
//        while(p != _head){
//            cout << p->_data << " ";
//            p = p->_next;
//        }
//        cout << endl;
//    }
//
//    void append(int data){
//        if(_head == nullptr){
//            _head = new node(data);
//            _head->_next = _head;
//        }
//        node *temp = _head->_next;
//        _head->_next = new node(data);
//        _head = _head->_next;
//        _head->_next = temp;
//    }
//
//    void head(){
//        cout << _head->_data << endl;
//    }
//
//        void remove(int data){
//            node *p = _head->_next;
//            node *q = _head->_next;
//            while(p->_next != _head){
//                if(_head->_next->_data == data){
//                    _head->_next = _head->_next->_next;
//                    return;
//                }else if(p->_data == data){
//                    q->_next = p->_next;
//                    return;
//                }
//                q = p;
//                p = p->_next;
//            }
//            if(_head->_data == data){
//                _head = q;
//                q->_next = q->_next->_next;
//                return;
//            }
//        }
    
    void clear(){
        if(_head == nullptr){
            return;
        }
        node *p = _head->_next;
        node *temp;
        _head->_next = nullptr;
        while(p != _head){
            temp = p;
            p = p->_next;
            temp->_next = nullptr;
            delete temp;
        }
        delete _head;
    }
    
    void prepend(int data){
        if(_head == nullptr){
            _head = new node();
            _head->_next = new node(data);
            _head->_next->_next = _head;
            return;
        }
        node *p = _head->_next;
        _head->_next = new node(data);
        _head->_next->_next = p;
    }
    
    void traverse(){
        node *p = _head->_next;
        while(p != _head){
            cout << p->_data << " ";
            p = p->_next;
        }
        cout << endl;
    }
    
    void append(int data){
       if(_head == nullptr){
            _head = new node();
            _head->_next = new node(data);
            _head->_next->_next = _head;
            return;
        }
        node *p = _head->_next;
        while(p->_next != _head){
            p = p->_next;
        }
        p->_next = new node(data);
        p->_next->_next = _head;
    }
    
    void remove(int data){
        if(data == -1 || _head == nullptr){
            return;
        }
        node *p = _head->_next;
        node *q = _head;
        while(p != _head){
            if(p->_data == data){
                q->_next = p->_next;
                p->_next = nullptr;
                return;
            }
            q = p;
            p = p->_next;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    circular list;
    list.prepend(50);
    list.prepend(100);
    list.prepend(150);
    list.prepend(200);
    list.prepend(250);
    list.prepend(300);
    list.prepend(350);
    list.prepend(400);
    list.prepend(450);
    list.append(5);
    list.append(10);
    list.append(15);
    list.append(20);
    list.append(25);
    list.append(35);
    list.append(40);
    list.append(45);
    list.traverse();
//    list.head();
    list.remove(450);
    list.traverse();
//    list.head();
    return 0;
}
