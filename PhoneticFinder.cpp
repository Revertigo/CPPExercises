#include "PhoneticFinder.hpp"
#include <string>
#include <sstream> 
#include <algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;
//20% threshold - if we don't have a match of at least 20 precentage, then no string will be returned.
#define THRESHOLD 20

namespace phonetic
{
    string find(string text, string word)
    {
        istringstream iss(text);//Initialize streamstring like split
        string token;
        string target = "";

        float max_match_percent = 0.0;
        //Lower case the word to search
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        while(iss >> token)
        {
            //Strings needs to be in the same length in order to be candidate
            if(token.length() == word.length())
            {
                float temp_match_percent = 0.0;
                int count_match = 0;
                //lower case token string
                transform(token.begin(), token.end(), token.begin(), ::tolower);
                for(int i = 0; i < token.length(); i++)
                {
                    if(token.at(i) == word.at(i))
                    {
                        count_match++;
                    }
                }

                temp_match_percent = ((float)((count_match)) / token.length());
                if(temp_match_percent > max_match_percent)
                {
                    target = token;
                    max_match_percent = temp_match_percent;
                }
            }
        }

        cout << "Got in here" << endl;
        if(max_match_percent < THRESHOLD)
        {
            //Let's format an output message !
            ostringstream oss;
            oss << "No such word " << word << endl;
            string output = oss.str();
            throw invalid_argument(output);
        }

        return target;
    }
}