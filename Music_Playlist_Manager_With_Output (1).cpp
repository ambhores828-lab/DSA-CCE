#include <iostream>
#include <string>
#include <limits>
using namespace std;
class Node {
public:
    string title, artist;
    Node* prev;
    Node* next;
    Node(string t, string a) : title(t), artist(a), prev(nullptr), next(nullptr) {}
};
class MusicPlaylist {
private:
    Node* head;
    Node* current;
public:
    MusicPlaylist() : head(nullptr), current(nullptr) {}
    ~MusicPlaylist() {
        Node* q = head;
        while (q != nullptr) { Node* p = q; q = q->next; delete p; }
    }
    void addSong(const string& title, const string& artist) {
        Node* p = new Node(title, artist);
        if (head == nullptr) { head = p; current = p; }
        else {
            Node* q = head;
            while (q->next != nullptr) q = q->next;
            q->next = p; p->prev = q;
        }
        cout << "Song added successfully: " << title << "\n";
    }
    void deleteSong(const string& title) {
        Node* q = head;
        while (q != nullptr && q->title != title) q = q->next;
        if (q == nullptr) { cout << "Song not found.\n"; return; }
        Node* p = q;
        if (p == head) head = p->next;
        if (p->prev != nullptr) p->prev->next = p->next;
        if (p->next != nullptr) p->next->prev = p->prev;
        if (current == p) current = (p->next != nullptr) ? p->next : p->prev;
        delete p;
        cout << "Song deleted successfully: " << title << "\n";
    }
    void displayForward() const {
        Node* q = head;
        if (!q) { cout << "Playlist is empty.\n"; return; }
        cout << "\nPlaylist (forward):\n";
        while (q) { cout << q->title << " - " << q->artist << "\n"; q = q->next; }
    }
    void displayReverse() const {
        Node* q = head;
        if (!q) { cout << "Playlist is empty.\n"; return; }
        while (q->next) q = q->next;
        cout << "\nPlaylist (reverse):\n";
        while (q) { cout << q->title << " - " << q->artist << "\n"; q = q->prev; }
    }
    void playCurrent() const {
        if (!current) cout << "Playlist is empty. Add a song first.\n";
        else cout << "Now playing: " << current->title << " - " << current->artist << "\n";
    }
    void playNext() {
        if (!current) cout << "Playlist is empty.\n";
        else if (!current->next) cout << "This is the last song; no next song.\n";
        else { current = current->next; playCurrent(); }
    }
    void playPrevious() {
        if (!current) cout << "Playlist is empty.\n";
        else if (!current->prev) cout << "This is the first song; no previous song.\n";
        else { current = current->prev; playCurrent(); }
    }
    void playCompletePlaylist() const {
        Node* q = head;
        if (!q) { cout << "Playlist is empty.\n"; return; }
        cout << "\nPlaying complete playlist:\n";
        while (q) { cout << "Playing: " << q->title << " - " << q->artist << "\n"; q = q->next; }
    }
    void repeatAll(int repetitions) const {
        if (!head) { cout << "Playlist is empty.\n"; return; }
        if (repetitions <= 0) { cout << "Repetitions must be at least 1.\n"; return; }
        for (int i = 1; i <= repetitions; ++i) {
            Node* q = head;
            cout << "\nRepetition " << i << ":\n";
            while (q) { cout << "Playing: " << q->title << " - " << q->artist << "\n"; q = q->next; }
        }
    }
    void showCurrent() const { playCurrent(); }
};
int main() {
    MusicPlaylist playlist;
    int choice = 0;
    do {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n"
             << "1. Add Song\n2. Delete Song\n3. Display Playlist\n"
             << "4. Display Playlist in Reverse\n5. Play Current Song\n"
             << "6. Play Next Song\n7. Play Previous Song\n"
             << "8. Play Complete Playlist\n9. Repeat All\n"
             << "10. Show Current Song\n11. Exit\nEnter choice: ";
        if (!(cin >> choice)) { cout << "Invalid input. Exiting.\n"; break; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string title, artist; int repetitions;
        switch (choice) {
        case 1:
            cout << "Enter song title: "; getline(cin, title);
            cout << "Enter artist name: "; getline(cin, artist);
            playlist.addSong(title, artist); break;
        case 2:
            cout << "Enter exact song title to delete: "; getline(cin, title);
            playlist.deleteSong(title); break;
        case 3: playlist.displayForward(); break;
        case 4: playlist.displayReverse(); break;
        case 5: playlist.playCurrent(); break;
        case 6: playlist.playNext(); break;
        case 7: playlist.playPrevious(); break;
        case 8: playlist.playCompletePlaylist(); break;
        case 9:
            cout << "Enter number of repetitions: ";
            if (cin >> repetitions) { cin.ignore(numeric_limits<streamsize>::max(), '\n'); playlist.repeatAll(repetitions); }
            else { cout << "Invalid repetition count.\n"; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
            break;
        case 10: playlist.showCurrent(); break;
        case 11: cout << "Exiting Music Playlist Manager.\n"; break;
        default: cout << "Invalid choice. Please select 1 to 11.\n";
        }
    } while (choice != 11);
    return 0;
}

/*
SAMPLE OUTPUT:

===== MUSIC PLAYLIST MANAGER =====
1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter choice: 1
Enter song title: Numb
Enter artist name: Linkin Park
Song added successfully: Numb

Enter choice: 1
Enter song title: Believer
Enter artist name: Imagine Dragons
Song added successfully: Believer

Enter choice: 3
Playlist (forward):
Numb - Linkin Park
Believer - Imagine Dragons

Enter choice: 6
Now playing: Believer - Imagine Dragons

Enter choice: 8
Playing complete playlist:
Playing: Numb - Linkin Park
Playing: Believer - Imagine Dragons

Enter choice: 9
Enter number of repetitions: 2

Repetition 1:
Playing: Numb - Linkin Park
Playing: Believer - Imagine Dragons

Repetition 2:
Playing: Numb - Linkin Park
Playing: Believer - Imagine Dragons

Enter choice: 11
Exiting Music Playlist Manager.
*/
