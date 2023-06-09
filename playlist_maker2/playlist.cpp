#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "playlist.h"
#include "song.h"

using namespace std;


void playlist::addSong(song title) {
    string player = title.getArtist();
    string songName = title.getName();

    if (songMap.find(player) == songMap.end()) {
        vector<string> tmpVec;
        tmpVec.push_back(songName);
        songMap[player] = tmpVec;
    } else {
        songMap[player].push_back(songName);
    }
    
}

void playlist::removeSong() {
    string player;
    cin.ignore();
    cout << "Artist: ";
    getline(cin, player);
    cout << endl;

    string songName;
    cout << "Name: ";
    getline(cin, songName);
    cout << endl;

    int size = songMap[player].size();
    vector<string> tmpVec;
    int i;

    for (i = 0; i < size; i++) {
        if (songMap[player][i] != songName) {
            tmpVec.push_back(songMap[player][i]);
        }
    }
    songMap[player].clear();
    if (tmpVec.size() == 0) {
        songMap.erase(player);
    } else {
        songMap[player] = tmpVec;
    }
}

string playlist::printVec(vector<string> strVec) {
    int i;
    stringstream ss;
    int size = strVec.size();
    for (i = 0; i < strVec.size(); i++) {
        if (i != (size - 1)) {
            ss << strVec[i] << ", ";
        } else {
            ss << strVec[i];
        }
    }
    string res = ss.str();
    return res;
}

void playlist::printPlaylist() {
    int i;

    for (auto pair: songMap) {
        //cout << pair.first << " - " << printVec(pair.second) << endl;
        if (pair.second.size() < 2) {
            cout << pair.first << " - " << pair.second[0] << endl;
        } else {
            for (i = 0; i < pair.second.size(); i++) {
                cout << pair.first << " - " << pair.second[i] << endl;
            }
        }
    }
}

void playlist::printByArtist() {
    string player;
    cout << "Artist: ";
    cin.ignore();
    getline(cin, player);
    cout << player << " - " << printVec(songMap[player]) << endl;
}
