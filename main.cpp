#include <bits/stdc++.h>
#include "Text_Preprocessor.h"

using namespace std;



int main() {

    // ------------------------------ TASK1 ---------------------------------

    Text_Preprocessor *first_task = new Text_Preprocessor("../Task_1.txt");

    first_task->preprocess_text();

    cout << first_task->search_word("supermassive");
    string ans = first_task->search_word("supermassive");
    cout << ans;

    delete first_task;


    // ------------------------------ TASK2 ---------------------------------

    fstream cop;
    cop.open("../Task_2.txt");
    string strLine;
    float total = 0;
    int count = 0;
    vector<float>task2_numbers;

    while(getline(cop, strLine)) {
        count++;
        float cur = stof(strLine);
        task2_numbers.push_back(cur);
        total += cur;
    }

    float avg = total / (count*1.0);

    auto thread_one = [](const vector<float>&numbers, float average) {
        ofstream str("../Thread_1.txt");
        for(auto to : numbers){
            if(to > average){
                str << to_string(to) << "\n";
            }
        }

        str.close();
    };

    auto thread_two = [](const vector<float>&numbers, float average) {
        ofstream str("../Thread_2.txt");
        for(auto to : numbers){
            if(to < average){
                str << to_string(to) << "\n";
            }
        }
        str.close();
    };

    thread th(thread_one, task2_numbers, avg);
    thread th1(thread_two, task2_numbers, avg);

    th.join();
    th1.join();






}
