#include <iostream>
#include <vector>
#include <string>

using namespace std;

// -------------------- DUPLICATE DETECTION (Brute Force) --------------------
void detectDuplicates(const vector<string>& photos) {

    cout << "1. Duplicate Detection (Brute Force)\n\n";
    for (int i = 0; i < photos.size(); i++) {
        for (int j = i + 1; j < photos.size(); j++) {
            if (photos[i] == photos[j]) {
                cout << photos[i]
                     << " is a duplicate of "
                     << photos[j]
                     << endl;
            }
        }
    }
}

// -------------------- PHOTO ORGANIZATION (Linear Search) --------------------
void searchPhoto(const vector<string>& photos, const string& target) {

    cout << "\n-----------------------------------------\n";
    cout << "2. Photo Search (Linear Search)\n\n";
    bool found = false;
    for (int i = 0; i < photos.size(); i++) {
        if (photos[i] == target) {
            cout << target
                 << " found at position "
                 << i
                 << endl;
            found = true;
        }
    }
    if (!found)
        cout << target << " not found." << endl;
}

// -------------------- DELETE PHOTO (Immediate Deletion) --------------------
void deletePhoto(vector<string>& photos, const string& target) {

    cout << "\n-----------------------------------------\n";
    cout << "3. Photo Deletion (Immediate Deletion)\n\n";
    for (int i = 0; i < photos.size(); i++) {
        if (photos[i] == target) {
            photos.erase(photos.begin() + i);
            cout << "Deleted "
                 << target
                 << endl;
            return;
        }
    }

    cout << "Photo not found." << endl;

}

// -------------------- DISPLAY --------------------
void displayPhotos(const vector<string>& photos) {

    cout << "\nCurrent Gallery:\n\n";
    for (string photo : photos) {
        cout << photo << endl;
    }
}

// -------------------- MAIN --------------------
int main() {

    vector<string> photos = {
        "photo1.jpg",
        "photo2.jpg",
        "photo3.jpg",
        "photo2.jpg",
        "photo5.jpg",
        "photo1.jpg"
    };

    cout << "=========================================\n";
    cout << "TRADITIONAL PHOTO MANAGEMENT SYSTEM\n";
    cout << "Baseline Approach\n";
    cout << "=========================================\n\n";

    // 1. Duplicate Detection
    detectDuplicates(photos);

    // 2. Photo Search
    searchPhoto(photos, "photo3.jpg");

    // 3. Immediate Deletion
    deletePhoto(photos, "photo2.jpg");

    // Display remaining photos
    displayPhotos(photos);

    return 0;
}
