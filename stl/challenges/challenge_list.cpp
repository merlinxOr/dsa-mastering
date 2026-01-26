#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

using namespace std;

class Song
{
    friend ostream &operator<<(ostream &os, const Song &s);
    string name;
    string artist;
    int rating;

public:
    Song() = default;
    Song(string name, string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    string get_name() const
    {
        return name;
    }
    string get_artist() const
    {
        return artist;
    }
    int get_rating() const
    {
        return rating;
    }

    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }
};

ostream &operator<<(ostream &os, const Song &s)
{
    os << setw(20) << left << s.name
       << setw(30) << left << s.artist
       << setw(2) << left << s.rating;
    return os;
}

void display_menu()
{
    cout << "\nF - Play First Song" << endl;
    cout << "N - Play Next song" << endl;
    cout << "P - Play Previous song" << endl;
    cout << "A - Add and play a new Song at current location" << endl;
    cout << "L - List the current playlist" << endl;
    cout << "===============================================" << endl;
    cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{
    cout << endl
         << song << endl;
}

void display_playlist(const list<Song> &playlist, const Song &current_song)
{
    for (auto song : playlist)
    {
        cout << song << endl;
    }
}

int main()
{

    list<Song> playlist{
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroone 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}};

    list<Song>::iterator current_song = playlist.begin();

    char option = ' ';
    string newTitle = "";
    string newArtist = "";
    int newRating = 0;

    do
    {
        display_menu();
        cin >> option;

        switch (towlower(option))
        {
        case 'f':
            current_song = playlist.begin();
            play_current_song(*current_song);
            break;

        case 'n':
            current_song++;
            if (current_song != playlist.end())
            {
                play_current_song(*current_song);
            }
            else
            {
                current_song = playlist.begin();
            }

            break;

        case 'p':
            if (current_song != playlist.begin())
            {
                current_song--;
                play_current_song(*current_song);
            }

            break;

        case 'a':

            cout << "Add new song: " << endl;
            cin.ignore();

            cout << "Title? : " << endl;
            getline(cin, newTitle);
            cout << "Artist? : " << endl;
            getline(cin, newArtist);
            cout << "Rating? : " << endl;
            cin >> newRating;

            if (newRating < 1)
            {
                newRating = 1;
            }

            if (newRating > 5)
            {
                newRating = 5;
            }

            playlist.insert(current_song, {newTitle, newArtist, newRating});
            cout << "Song added: " << newTitle << " - " << newArtist << endl;
            current_song--;

            break;

        case 'l':
            display_playlist(playlist, *current_song);

            break;

        default:
            cout << "Option not valid! Try again..." << endl;
            break;
        }

    } while (tolower(option) != 'q');

    cout
        << "Thanks for listening!" << endl;
    return 0;
}