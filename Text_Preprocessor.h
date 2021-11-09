//
// Created by undefined on 09.11.2021.
//

#ifndef TEXTPREPROCESSOR_TEXT_PREPROCESSOR_H
#define TEXTPREPROCESSOR_TEXT_PREPROCESSOR_H

#include <bits/stdc++.h>

using namespace std;

class Text_Preprocessor {
public:
    string file_name;
    ifstream cop;
    vector<string>processedData;

    Text_Preprocessor(const string &fileName);

    void preprocess_text();

    string search_word(const std::string &str);

    virtual ~Text_Preprocessor();
};


#endif //TEXTPREPROCESSOR_TEXT_PREPROCESSOR_H
