#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    unordered_map<string, int> aniMap;
    aniMap["Ox"] = 1;
    aniMap["Tiger"] = 2;
    aniMap["Rabbit"] = 3;
    aniMap["Dragon"] = 4;
    aniMap["Snake"] = 5;
    aniMap["Horse"] = 6;
    aniMap["Goat"] = 7;
    aniMap["Monkey"] = 8;
    aniMap["Rooster"] = 9;
    aniMap["Dog"] = 10;
    aniMap["Pig"] = 11;
    aniMap["Rat"] = 12;
    unordered_map<string, int> map;
    map["Bessie"] = 1201;
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word)
        {
            words.push_back(word);
        }

        string first = words[0]; // Cow whose year needs to be found
        string last = words[7];
        string dir = words[3];
        string animal = words[4]; // Reference cow

        int aniVal = aniMap[animal]; // Value of animal zodiac

        int refYear = map[last];

        int delta = 0;
        if (dir == "previous")
        {
            delta = (refYear % 12 - aniVal + 12) % 12;
            if (delta == 0) delta = 12;
            map[first] = refYear - delta;
        }
        else
        {
            delta = (aniVal - refYear % 12 + 12) % 12;
            if (delta == 0) delta = 12;
            map[first] = refYear + delta;
        }
    }

    cout << abs(map["Bessie"] - map["Elsie"]);
    return 0;
}
