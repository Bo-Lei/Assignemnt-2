#include "ofApp.h"

// Add a new node at the start
void LinkedList::insertAtHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode; // now new node is first
}

// Add a new node at the end
void LinkedList::insertAtTail(int value) {
    Node* newNode = new Node(value);
    if (!head) { // if list empty, make new node first
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) { // go to last node
        temp = temp->next;
    }
    temp->next = newNode; // add new node after last node
}

// Remove first node
void LinkedList::deleteHead() {
    if (!head) return; // if empty, do nothing
    Node* temp = head;
    head = head->next; // move head to next node
    delete temp; // delete old first node
}

// Remove last node
void LinkedList::deleteTail() {
    if (!head) return; // if empty, do nothing
    if (!head->next) { // if only 1 node, delete it
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next) { // go to second last node
        temp = temp->next;
    }
    delete temp->next; // delete last node
    temp->next = nullptr; // no more last node
}

// Start program
void ofApp::setup() {
    ofSetWindowTitle("Linked List Visualizer"); // set window name
    ofSetFrameRate(60); // make screen update 60 times in 1 sec
    amplitude = 10; // start move size
}

// Update, but we dont need change anything
void ofApp::update() {
    // nothing here because homework did not ask for it
}

// Draw the linked list
void ofApp::draw() {
    ofBackground(50);  // make background dark
    Node* temp = list.head;
    int x = 50; // start drawing at x=50
    int y = 200; // y is always 200

    while (temp) {
        ofDrawCircle(x, y, 20);  // make a circle
        ofDrawBitmapString(ofToString(temp->data), x - 5, y + 5); // put number in circle
        if (temp->next) {
            ofDrawLine(x + 20, y, x + 80, y); // draw line to next node
        }
        x += 80; // move right for next node
        temp = temp->next; // go to next node
    }
}

// When user press a key
void ofApp::keyPressed(int key) {
    if (key == 'q') { // 'q' key - add node to start
        list.insertAtHead(ofRandom(1, 100));
    }
    else if (key == 'w') { // 'w' key - add node to end
        list.insertAtTail(ofRandom(1, 100));
    }
    else if (key == 'a') { // 'a' key - remove first node
        list.deleteHead();
    }
    else if (key == 's') { // 's' key - remove last node
        list.deleteTail();
    }
    else if (key == 'z') { // 'z' key - make move bigger
        amplitude += 2;
    }
    else if (key == 'x') { // 'x' key - make move smaller
        amplitude = max(2.0f, amplitude - 2); // dont go below 2
    }
}
