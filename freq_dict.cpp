#include "freq_dict.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <boost/functional/hash.hpp>

using namespace std;

map<string, size_t> d_map;
unordered_map<string, size_t> d_un_map;
vector< pair<string, size_t> > d_vect;
list< pair<string, size_t> > d_list;
set< pair<string, size_t> > d_set;
typedef std::pair<std::string, int> Pair;
unordered_set< pair<string, size_t>, boost::hash<Pair> > d_un_set;

//class parser {
//    string read_text(const char* filein, int mode)
//    {
//        std::ifstream fin(filein);
//        std::string word;
//
//        while (fin >> word)
//        {
//            return word;
//        }
//    
//        fin.close();
//    }
//
//    void write_result(const char* fileout)
//    {
//        std::ofstream fout(fileout);
//
//
//
//        fout.close();
//    }
//};

void dict_map::add_dict(const char* filename)
{
	ifstream fin(filename);
    string word;
	while (fin >> word)
	{
	    d_map[word]++;
	}
	fin.close();
}

void dict_map::get_dict(const char* filename)
{
	ofstream fout(filename);
	fout << "Time - " << clock() << " sec" << endl;
	
	for (const auto& item : d_map)
	{
		fout << item.first << " - " << item.second << endl;
	}
	fout.close();
}

void dict_unordered_map::add_dict(const char* filename)
{
	ifstream fin(filename);
    string word;
	while (fin >> word)
	{
		d_un_map[word]++;
	}
	fin.close();
}

void dict_unordered_map::get_dict(const char* filename)
{
	ofstream fout(filename);
	fout << "Time - " << clock() << " sec" << endl;

	for (const auto& item : d_un_map)
	{
		fout << item.first << " - " << item.second << endl;
	}
	fout.close();
}

void dict_vector::add_dict(const char* filename)
{
    ifstream fin(filename);
    string word;
    while (fin >> word)
    {
        auto pp = find_if(d_vect.begin(), d_vect.end(), [word](const pair<string, size_t>& element) {
            return element.first == word;
            });
        if (pp == d_vect.end())
        {
            d_vect.push_back(make_pair(word, 1));
        }
        else
        {
            (*pp).second++;
        }
    }
    fin.close();
}

void dict_vector::get_dict(const char* filename)
{
    ofstream fout(filename);
    fout << "Time - " << clock() << " sec" << endl;

    for (const auto& item : d_vect)
    {
        fout << item.first << " - " << item.second << endl;
    }
    fout.close();
}

void dict_list::add_dict(const char* filename)
{
    ifstream fin(filename);
    string word;
    while (fin >> word)
    {
        auto pp = find_if(d_list.begin(), d_list.end(), [word](const pair<string, size_t>& element) {
            return element.first == word;
            });
        if (pp == d_list.end())
        {
            d_list.push_back(make_pair(word, 1));
        }
        else
        {
            (*pp).second++;
        }
    }
    fin.close();
}

void dict_list::get_dict(const char* filename)
{
    ofstream fout(filename);
    fout << "Time - " << clock() << " sec" << endl;

    for (const auto& item : d_list)
    {
        fout << item.first << " - " << item.second << endl;
    }
    fout.close();
}

void dict_set::add_dict(const char* filename)
{
    ifstream fin(filename);
    string word;
    while (fin >> word)
    {
        auto pp = find_if(d_set.begin(), d_set.end(), [word](const pair<string, size_t>& element) {
            return element.first == word;
            });
        if (pp == d_set.end())
        {
            d_set.insert(make_pair(word, 1));
        }
        else
        {
            d_set.insert(make_pair(word, 1 + (*pp).second));
            d_set.erase(pp);
        }
    }
    fin.close();
}

void dict_set::get_dict(const char* filename)
{
    ofstream fout(filename);
    fout << "Time - " << clock() << " sec" << endl;

    for (const auto& item : d_set)
    {
        fout << item.first << " - " << item.second << endl;
    }
    fout.close();
}

void dict_unordered_set::add_dict(const char* filename)
{
    ifstream fin(filename);
    string word;
    while (fin >> word)
    {
        auto pp = find_if(d_un_set.begin(), d_un_set.end(), [word](const pair<string, size_t>& element) {
            return element.first == word;
            });
        if (pp == d_un_set.end())
        {
            d_un_set.insert(make_pair(word, 1));
        }
        else
        {
            d_un_set.insert(make_pair(word, 1 + (*pp).second));
            d_un_set.erase(pp);
        }
    }
    fin.close();
}

void dict_unordered_set::get_dict(const char* filename)
{
    ofstream fout(filename);
    fout << "Time - " << clock() << " sec" << endl;

    for (const auto& item : d_un_set)
    {
        fout << item.first << " - " << item.second << endl;
    }
    fout.close();
}
