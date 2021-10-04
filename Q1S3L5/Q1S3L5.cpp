#include <iostream>
#include <locale>
#include <vector>
#include <sstream>
#include <list>
#include <set>
#include "Sentence.h"

using namespace std;

template<class A>
void uniqueWords(A begin, A end) {
    set <string> st(begin, end);
    for (auto i : st) {
        cout << i << ' ';
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    {
        // #1 (типы итераторов для vector и list различны, задача функции выполнена)
        vector <string> v = {"one", "one", "1", "two", "1"};
        list <string> l = {"three", "four", "2", "2", "four", "1"};

        uniqueWords(v.begin(), v.end());
        cout << endl;
        uniqueWords(l.begin(), l.end());
        cout << endl << endl;
    }

    {
        // #2 (Реализовал свой класс sentence, где перегрузил оператор <, который позволил
        //     set'у отсортировать предложения по количеству слов)
        set <Sentence> st;
        string text = "Мёд делают пчелы. Фонари на улице плохо освещали местность. \
                       Кошка поймала мышку. Я плохо написал контрольную, и учительница \
                       поставила мне двойку. Голубцы оказались действительно вкусными, и \
                       Илья съел их до крошки.";
        stringstream ss;
        ss << text;

        while (!ss.eof()) {
            string tmp, sent = "";
            do {
                ss >> tmp;
                sent += tmp + ' ';
            } while (tmp[tmp.size() - 1] != '.');
            st.insert(Sentence(sent));
        }

        for (auto i : st) {
            cout << i << endl;
        }
    }

    return 0;
}