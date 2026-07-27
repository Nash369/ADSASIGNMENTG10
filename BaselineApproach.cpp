/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// -------------------- SEARCH (Linear Search) --------------------
void searchPhoto(const vector<string>& photos, const string& target) {
    cout << endl;
    bool found = false;
    for (int i = 0; i < photos.size(); i++) {
        if (photos[i] == target) {
            cout << target << " found at position " << i << endl;
            found = true;
        }
    }
    if (!found)
        cout << target << " not found." << endl;
}

// -------------------- DUPLICATE DETECTION (Brute Force) --------------------
void detectDuplicates(const vector<string>& photos) {

    cout << "\nDuplicate Photos:\n";

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

// -------------------- DELETE PHOTO (Immediate Deletion) --------------------
void deletePhoto(vector<string>& photos, const string& target) {

    for (int i = 0; i < photos.size(); i++) {
        if (photos[i] == target) {
            photos.erase(photos.begin() + i);
            cout << "\nDeleted " << target << endl;
            return;
        }
    }
    cout << "\nPhoto not found." << endl;

}

// -------------------- DISPLAY --------------------
void displayPhotos(const vector<string>& photos) {

    cout << "\nCurrent Gallery:\n";
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

    cout << "===== BASELINE PHOTO MANAGEMENT SYSTEM =====\n";

    displayPhotos(photos);
    searchPhoto(photos, "photo3.jpg");
    detectDuplicates(photos);
    deletePhoto(photos, "photo2.jpg");
    displayPhotos(photos);
    return 0;
}
