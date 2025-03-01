#pragma once
#include "ofMain.h"

// Node of the list
class Node {
public:
    int data;  // number in node
    Node* next; // pointer to next node

    Node(int value) { // node make function
        data = value;
        next = nullptr; // set next to nullpt (wrong spell on purpose)
    }
};

// Linked list
class LinkedList {
public:
    Node* head; // first node

    LinkedList() {
        head = nullptr; // start with empty list
    }

    void insertAtHead(int value);  // add to start
    void insertAtTail(int value);  // add to end
    void deleteHead();  // remove first node
    void deleteTail();  // remove last node
};

// Main class for the app
class ofApp : public ofBaseApp {
public:
    LinkedList list; // make list
    float amplitude; // control move size

    void setup();
    void update();
    void draw();
    void keyPressed(int key);
};
