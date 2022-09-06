#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>
using namespace std;
string dictformat(string word)
{
    string intext = "";
    for(int i = 0; i < word.length(); i++)
    {
        if(word[i] >= 'А' && word[i] <= 'Я') word[i] = word[i] - 'А' + 'а';
        if(word[i] >= 'A' && word[i] <= 'Z') word[i] = word[i] - 'A' + 'a';
        if(word[i] != '!' && word[i] != '?' && word[i] != ',' && word[i] != ';' && word[i] != '.' && word[i] != ':' && word[i] != '—' && word[i] != '«' && word[i] != '(' && word[i] != ')' && word[i] != '»')
        {
            intext += word[i];
        }
    }
    return intext;
}
int editorialdistance(string S, string T)
{
    int nS = S.length(), nT = T.length();
    int DP[nS+1][nT+1];
    for(int i = 0; i <= nS; i++) for(int j = 0; j <= nT; j++)
    {
        if(i == 0 || j == 0) DP[i][j] = max(i, j);
        else
        {
            int k = 0;
            if(S[i-1] != T[j-1]) k = 1;
            DP[i][j] = min(DP[i-1][j-1] + k, min(DP[i-1][j]+1, DP[i][j-1]+1));
        }
    }
    return DP[nS][nT];
}
int main()
{
    ifstream f1in ("dict1.txt");
    f1in.is_open();
    map<string, int> dict;
    vector<string> dictword;
    setlocale(LC_ALL, "Russian");
    vector<string> text;
    vector<string> originaltext;
    string word;
    while(f1in >> word)
    {
        int quantity;
        f1in >> quantity;
        dict[word] = quantity;
        dictword.push_back(word);
    }
    f1in.close();
    ifstream f2in ("brain278.txt");
    f2in.is_open();
    while(f2in >> word)
    {
        originaltext.push_back(word);
        if(dictformat(word) != "") text.push_back(dictformat(word));
    }
    f2in.close();
    ofstream f3out ("answer.txt");
    int quantitywordforms = text.size();
    set<string> wordforms;
    for(int i = 0; i < originaltext.size(); i++) if(dictformat(originaltext[i]) != "") wordforms.insert(dictformat(originaltext[i]));
    int differentquantitywordforms = 0;
    for(auto q: wordforms) differentquantitywordforms++;
    int differentquantitywordformsindict = 0;
    for(auto q: wordforms) if(dict[q]) differentquantitywordformsindict++;
    vector<int> errorwords;
    for(int i = 0; i < originaltext.size(); i++)
    {
        if(dict[dictformat(originaltext[i])] == 0 && dictformat(originaltext[i]) != "") errorwords.push_back(i);
    }
    f3out << "Количество словоформ: " << quantitywordforms << endl << "Количество различных словоформ: " << differentquantitywordforms << endl << "Количество различных словоформ, которые есть в словаре: " << differentquantitywordformsindict << endl;
    if(errorwords.size())
    {
        f3out << "В словаре нет " << errorwords.size() << " слов из текста, вероятно некоторые слова введены неправильно." << endl;
        if(errorwords.size() > 1)
        {
            f3out << "Проверьте эти слова на правильность: ";
            for(int i = 0; i < errorwords.size() - 1; i++) f3out << dictformat(originaltext[errorwords[i]]) << ", ";
            f3out << dictformat(originaltext[errorwords[errorwords.size() - 1]]) << "."<< endl;
        }
        else
        {
            f3out << "Проверьте слово " << dictformat(originaltext[errorwords[0]]) << " на правильность." << endl;
        }
        for(int i = 0; i < errorwords.size(); i++)
        {
            string newword = "";
            string errorword = dictformat(originaltext[errorwords[i]]);
            for(int j = 0; j < dictword.size(); j++)
            {
                string cur = dictword[j];
                if(editorialdistance(cur, errorword) < 3 && (dict[cur] > dict[newword] && editorialdistance(cur, errorword) == editorialdistance(newword, errorword) || editorialdistance(cur, errorword) < editorialdistance(newword, errorword))) newword = cur;
            }
            if(newword != "")
            {
                f3out << "Вероятно, нужно заменить '" << errorword << "' на '" << newword << "', исправив " << editorialdistance(newword, errorword) << " ошибк";
                if(editorialdistance(newword, errorword) == 1) f3out <<"у";
                if(editorialdistance(newword, errorword) == 2) f3out <<"и";
                if(originaltext[errorwords[i]] == dictformat(originaltext[errorwords[i]])) originaltext[errorwords[i]] = newword;
                string s;
                s = newword;
                char k = originaltext[errorwords[i]][originaltext[errorwords[i]].size() - 1];
                if(originaltext[errorwords[i]][0] >= 'А' && originaltext[errorwords[i]][0] <= 'Я') s[0] += 'А' - 'а';
                else if(originaltext[errorwords[i]][0] >= 'A' && originaltext[errorwords[i]][0] <= 'Z') s[0] += 'A' - 'a';
                else if((k < 'a' || k > 'z') && (k < 'а' || k > 'я')) s += k;
                originaltext[errorwords[i]] = s;
            }
            else f3out << "Слову '" << errorword << "' не было найдено замены в словаре, поэтому предложить ничего нельзя";
            f3out << "." << endl;
        }
    }
    else f3out << "Все слова из текста введены правильно и найдены в словаре" << endl;
    wordforms.clear();
    for(int i = 0; i < originaltext.size(); i++) if(dictformat(originaltext[i]) != "") wordforms.insert(dictformat(originaltext[i]));
    differentquantitywordforms = 0;
    for(auto q: wordforms) differentquantitywordforms++;
    differentquantitywordformsindict = 0;
    for(auto q: wordforms) if(dict[q]) differentquantitywordformsindict++;
    f3out << "Количество словоформ в исправленном тексте: " << quantitywordforms << endl << "Количество различных словоформ в исправленном тексте: " << differentquantitywordforms << endl << "Количество различных словоформ в исправленном тексте, которые есть в словаре: " << differentquantitywordformsindict << endl;
    f3out << endl;
    for(int i = 0; i < originaltext.size(); i++) f3out << originaltext[i] << " ";
}
