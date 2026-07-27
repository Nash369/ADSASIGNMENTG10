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

int main() {
    // Sample photo names
    vector<string> photos = {
        "photo1.jpg",
        "photo2.jpg",
        "photo3.jpg",
        "photo2.jpg",
        "photo5.jpg",
        "photo1.jpg"
    };

    cout << "Duplicate Photos Found:\n\n";

    // Compare every photo with every other photo
    for (int i = 0; i < photos.size(); i++) {
        for (int j = i + 1; j < photos.size(); j++) {

            if (photos[i] == photos[j]) {
                cout << photos[i]
                     << " is a duplicate of "
                     << photos[j] << endl;
            }

        }
    }

    return 0;
}