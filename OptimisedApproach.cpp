/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

// -------------------- PHOTO STRUCTURE --------------------
struct Photo {
    string name;
    int uploadDate;
};

// -------------------- BST --------------------
struct Node {
    Photo photo;
    Node* left;
    Node* right;

    Node(Photo p) {
        photo = p;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, Photo p) {

    if (root == nullptr)
        return new Node(p);

    if (p.uploadDate < root->photo.uploadDate)
        root->left = insert(root->left, p);
    else
        root->right = insert(root->right, p);

    return root;
}

void inorder(Node* root) {

    if (root == nullptr)
        return;

    inorder(root->left);

    cout << root->photo.uploadDate
         << " - "
         << root->photo.name
         << endl;

    inorder(root->right);
}

// -------------------- MAIN --------------------
int main() {

    vector<Photo> gallery = {
        {"photo1.jpg", 20260720},
        {"photo2.jpg", 20260721},
        {"photo3.jpg", 20260719},
        {"photo2.jpg", 20260722},
        {"photo5.jpg", 20260723},
        {"photo1.jpg", 20260724}
    };

    cout << "=========================================\n";
    cout << "SMART PHOTO STORAGE MANAGEMENT SYSTEM\n";
    cout << "Optimized using ADS Techniques\n";
    cout << "=========================================\n\n";

    // =========================================
    // 1. HASH TABLE - DUPLICATE DETECTION
    // =========================================

    cout << "1. Duplicate Detection (Hash Table)\n\n";

    unordered_set<string> hashTable;

    for (Photo p : gallery) {

        if (hashTable.find(p.name) != hashTable.end()) {
            cout << p.name << " -> Duplicate Found" << endl;
        }
        else {
            hashTable.insert(p.name);
        }
    }

    // =========================================
    // 2. BST - PHOTO ORGANIZATION
    // =========================================

    cout << "\n-----------------------------------------\n";
    cout << "2. Photo Organization (Binary Search Tree)\n\n";

    Node* root = nullptr;

    for (Photo p : gallery) {
        root = insert(root, p);
    }

    cout << "Photos sorted by upload date:\n\n";
    inorder(root);

    // =========================================
    // 3. QUEUE - DELETION REQUESTS
    // =========================================

    cout << "\n-----------------------------------------\n";
    cout << "3. Batch Deletion (Queue)\n\n";

    queue<string> deleteQueue;

    deleteQueue.push("photo2.jpg");
    deleteQueue.push("photo1.jpg");

    while (!deleteQueue.empty()) {

        cout << "Deleting "
             << deleteQueue.front()
             << endl;

        deleteQueue.pop();
    }

    cout << "\nAll deletion requests completed.\n";

    return 0;
}