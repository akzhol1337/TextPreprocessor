#include <bits/stdc++.h>
#include "Text_Preprocessor.h"

using namespace std;

int main() {
    Text_Preprocessor *textPreprocessor = new Text_Preprocessor("../Task_1.txt");

    textPreprocessor->preprocess_text();

    cout << textPreprocessor->search_word("supermassive");

}
