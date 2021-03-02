#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <time.h>


using namespace std;

size_t getIntGreaterThan(size_t x);
int randWithin(int begin, int end);
void randFill(vector<vector<char>>& field, vector<pair<int, int>>& pos, char sign, int n);

int main()
{
    // Settings
    const char dest = '$';
    const char obst = '@';
    const char freePlace = '#';
    const char path = '+';
    const int destNum = 2;
    //srand(static_cast<unsigned int>(time(0)));

    // Welcome
    string welcomeMsg;
    welcomeMsg += "This program finds a path between two points on a 2D field if such the path exists.\n";
    welcomeMsg += "$ - destination, @ - obstacle, # - free place, + - path.\n";
    cout << welcomeMsg;
    cout << '\n';

    // Enter field sizes
    cout << "Enter field width. ";
    size_t w = getIntGreaterThan(1);
    cout << "Enter field height. ";
    size_t h = getIntGreaterThan(1);
    cout << '\n\n';

    // Create empty field
    vector<vector<char>> field;
    for (size_t i = 0; i < h; i++) {
        vector<char> line(w, freePlace);
        field.push_back(line);
    }

    // Create a vector of available positions
    vector<pair<int, int>> pos;
    for (size_t i = 0; i < h; i++)
        for (size_t j = 0; j < w; j++)
            pos.push_back(make_pair(i, j));

    // Add destinations
    randFill(field, pos, dest, destNum);

    // Add obstacles
    const int obstNum = randWithin(0, field.size() - 2);
    randFill(field, pos, obst, obstNum);

    // Output field
    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w; j++)
            cout << field[i][j] << ' ';
        cout << '\n';
    }

    // Find path)
}

size_t getIntGreaterThan(size_t x) {
    cout << "Enter an integer greater than " << x << ": ";
    size_t res;
    do {
        cin >> res;
        if (res <= x)
            cout << "Your integer isn't greater than " << x << ". Try again: ";
    } while (res <= x);
    return res;
}

int randWithin(int begin, int end) {
    return begin + rand() % (end - begin + 1);
}

void randFill(vector<vector<char>>& field, vector<pair<int, int>>& pos, char sign, int n) {
    for (int i = 0; i < n; i++) {
        int randNum = randWithin(0, static_cast<int>(pos.size() - 1));
        pair<int, int> p = pos.at(static_cast<size_t>(randNum));
        field.at(p.first).at(p.second) = sign;
        pos.erase(pos.begin() + randNum);
    }
}