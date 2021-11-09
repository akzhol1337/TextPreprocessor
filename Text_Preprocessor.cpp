//
// Created by undefined on 09.11.2021.
//

#include "Text_Preprocessor.h"
#include <bits/stdc++.h>

using namespace std;

void Text_Preprocessor::preprocess_text() {
    ifstream cop;
    cop.open(file_name);

    string data;
    vector<string>all_data;
    while(cop){
        getline(cop, data);
        //cout << data << "\n";
        all_data.push_back(data);
    }
    vector<string>processed_data;
    for(auto const &to : all_data){
        string final_str;
        for(int i = 0; i < (int)to.size(); i++){
            if(to[i] == 'a' && to[i-1] == ' ' && to[i+1] == ' '){
                i++;
                continue;
            }
            if(to.substr(i, 2) == "an" && to[i+2] == ' ' && to[i-1] == ' '){
                i += 2;
                continue;
            }
            if(to.substr(i, 3) == "the" && to[i+3] == ' ' && to[i-1] == ' ') {
                i+=3;
                continue;
            }
            if(to.substr(i, 2) == "in" && to[i+2] == ' ' && to[i-1] == ' ') {
                i += 2;
                continue;
            }
            if(to.substr(i, 2) == "on" && to[i+2] == ' ' && to[i-1] == ' ') {
                i += 2;
                continue;
            }
            if(to.substr(i, 2) == "at" && to[i+2] == ' ' && to[i-1] == ' ') {
                i += 2;
                continue;
            }
            if(to.substr(i, 5) == "since" && to[i+5] == ' ' && to[i-1] == ' ') {
                i += 5;
                continue;
            }
            if(to.substr(i, 3) == "ago" && to[i+3] == ' ' && to[i-1] == ' ') {
                i += 3;
                continue;
            }
            if(to.substr(i, 6) == "before" && to[i+6] == ' ' && to[i-1] == ' ') {
                i += 6;
                continue;
            }
            if(to.substr(i, 2) == "to" && to[i+2] == ' ' && to[i-1] == ' ') {
                i += 2;
                continue;
            }
            if(to.substr(i, 2) == "by" && to[i+2] == ' ' && to[i-1] == ' ') {
                i += 2;
                continue;
            }
            final_str += tolower(to[i]);
        }
        //cout << final_str << "\n";
        processed_data.push_back(final_str);
    }
    processedData = processed_data;
    cop.close();
}

string Text_Preprocessor::search_word(const std::string &str) {
    for(auto to : processedData){
        if(to.find(str) != string::npos){
            return to;
        }
    }
    return "Word is not found";
}

Text_Preprocessor::Text_Preprocessor(const string &fileName) : file_name(fileName) {}
