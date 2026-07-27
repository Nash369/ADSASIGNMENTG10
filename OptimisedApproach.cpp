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

// -------------------- BST NODE --------------------
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

// -------------------- INSERT INTO BST --------------------
Node* insert(Node* root, Photo p) {

    if (root == nullptr)
        return new Node(p);
    if (p.uploadDate < root->photo.uploadDate)
        root->left = insert(root->left, p);
    else
        root->right = insert(root->right, p);
    return root;
}

// -------------------- DISPLAY BST --------------------
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

// -------------------- SEARCH BST --------------------
Node* searchBST(Node* root, int targetDate) {
    if (root == nullptr)
        return nullptr;
    if (targetDate == root->photo.uploadDate)
        return root;
    if (targetDate < root->photo.uploadDate)
        return searchBST(root->left, targetDate);
    return searchBST(root->right, targetDate);
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

    // 1. HASH TABLE - DUPLICATE DETECTION

    cout << "1. Duplicate Detection (Hash Table)\n\n";
    unordered_set<string> hashTable;
    for (Photo p : gallery) {
        if (hashTable.find(p.name) != hashTable.end()) {
            cout << p.name
                 << " -> Duplicate Found"
                 << endl;
        }
        else {
            hashTable.insert(p.name);
        }
    }

    // 2. BST - PHOTO ORGANIZATION & SEARCH

    cout << "\n-----------------------------------------\n";
    cout << "2. Photo Organization & Search (Binary Search Tree)\n\n";
    Node* root = nullptr;
    for (Photo p : gallery) {
        root = insert(root, p);
    }
    cout << "Photos organized by upload date:\n\n";
    inorder(root);
    int targetDate = 20260719;
    cout << "\nSearching for upload date "
         << targetDate
         << "...\n\n";
    Node* result = searchBST(root, targetDate);
    if (result != nullptr) {
        cout << "Photo Found!\n\n";
        cout << "Photo Name : "
             << result->photo.name
             << endl;
        cout << "Upload Date: "
             << result->photo.uploadDate
             << endl;
    }
    else {
        cout << "Photo not found.\n";
    }
    
    // 3. QUEUE - BATCH DELETION

    cout << "\n-----------------------------------------\n";
    cout << "3. Batch Photo Deletion (Queue)\n\n";
    queue<string> deleteQueue;
    deleteQueue.push("photo2.jpg");
    deleteQueue.push("photo1.jpg");
    cout << "Processing deletion requests...\n\n";
    while (!deleteQueue.empty()) {
        cout << "Deleting "
             << deleteQueue.front()
             << endl;
        deleteQueue.pop();
    }
    cout << "\nAll deletion requests completed.\n";
    return 0;
}
