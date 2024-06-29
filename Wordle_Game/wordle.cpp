#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int len = 5;

    ifstream fin;
    fin.open("words.txt");
    if (!fin)
    {
        cout << "File not found!" << endl;
        return 0;
    }

    vector<string> words;

    // Reading words from file
    string temp;
    while (fin >> temp) words.push_back(temp);
    fin.close();

    // Randomly selecting a word
    srand(time(0));
    string word = words[rand() % words.size()];

    bool flag = true;

    for (int i = 1; i <= 6; i++)
    {
        map<char, int> freq;
        for (auto &x : word)
            freq[x]++;
        cout << "Attempt " << i << ": ";
        string curr;
        cin >> curr;

        if(curr.size() != len){
            cout << "Please enter a word of length 5." << endl;
            i--;
            continue;
        }

        if(find(words.begin(), words.end(), curr) == words.end()){
            cout << "Words not found in dictionary!" << endl;
            i--;
            continue;
        }

        int color[len] = {0}; // 0: None, 1: Green, 2: Yellow
        for(int i=0; i<len; i++){
            if(curr[i] == word[i]){
                color[i] = 1;
                freq[curr[i]]--;
            }
        }

        cout << "Result: ";
        for (int i = 0; i < len; i++)
        {
            char ch = curr[i];
            if (ch != word[i] && freq[ch] != 0)
            {
                color[i] = 2;
                freq[ch]--;
            }
        }

        for (int i = 0; i < len; i++)
        {
            if (color[i] == 1)
                cout << "\033[1;32m" << curr[i] << "\033[0m";
            else if (color[i] == 2)
                cout << "\033[1;33m" << curr[i] << "\033[0m";
            else
                cout << curr[i];
        }

        cout << endl;
        if (curr == word)
        {
            cout << "You have guessed the word correctly!" << endl;
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "You have failed to guess the word!" << endl;
        cout << "The correct word was: " << word << endl;
    }
    
}