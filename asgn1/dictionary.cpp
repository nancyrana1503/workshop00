// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 6 June 2025
// dictionary.cpp

#include <iostream>    
#include <fstream>     
#include <iomanip>     
#include <sstream>     
#include "settings.h"  
#include "dictionary.h"
using namespace std;
namespace seneca {

    // consructor to initialize members to null or zero
    Dictionary::Dictionary() : m_words(nullptr), m_capacity(0), m_size(0) {}

    // constructor to load dictionary data from file
    Dictionary::Dictionary(const char* filename) : m_words(nullptr), m_capacity(0), m_size(0) {
        
        m_capacity = readWordsNumber(filename);
        ifstream file(filename);  
        if (m_capacity == 0 || !file) return;
        m_words = new Word[m_capacity];  
        string line;

        while (getline(file, line) && m_size < m_capacity) {
            istringstream iss(line);
            string word, posStr, definition;

            if (getline(iss, word, ',') && getline(iss, posStr, ',') && getline(iss, definition)) {
                m_words[m_size].m_word = word;
                m_words[m_size].m_pos = getPartOfSpeech(posStr);
                m_words[m_size].m_definition = definition;
                ++m_size;
            }
        } }

    //copy constructor to deep copy dictionary instance
    Dictionary::Dictionary(const Dictionary& other) : m_words(nullptr), m_capacity(other.m_capacity), m_size(other.m_size) {
        if (m_capacity) {
            m_words = new Word[m_capacity];
            for (int i = 0; i < m_size; ++i) {
                m_words[i] = other.m_words[i];
            }
        } }

    // copy assignment to handle self-assignment and deep copy
    Dictionary& Dictionary::operator=(const Dictionary& other) {
        if (this != &other) {
            delete[] m_words;  
            m_capacity = other.m_capacity;
            m_size = other.m_size;

            if (m_capacity) {
                m_words = new Word[m_capacity];
                for (int i = 0; i < m_size; ++i) {
                    m_words[i] = other.m_words[i];
                }
            }
            else { m_words = nullptr; }
        } return *this;
    }

    // constructor to transfer ownership of resources
    Dictionary::Dictionary(Dictionary&& other) noexcept : m_words(other.m_words), m_capacity(other.m_capacity), m_size(other.m_size) {
        other.m_words = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
    }

    //assignment operator to transfer ownership and avoids deep copy
    Dictionary& Dictionary::operator=(Dictionary&& other) noexcept {
        if (this != &other) {
            delete[] m_words;  
            m_words = other.m_words;
            m_capacity = other.m_capacity;
            m_size = other.m_size;
            other.m_words = nullptr;
            other.m_capacity = 0;
            other.m_size = 0;
        }return *this;
    }

    // dstructor to free the allocated memory
    Dictionary::~Dictionary() {
        delete[] m_words;
    }

    //function to read number of lines in file
    int Dictionary::readWordsNumber(const char* filename) {
        ifstream file(filename);
        return file ? count(istreambuf_iterator<char>(file), istreambuf_iterator<char>(), '\n') : 0;
    }

    //search a word in dictionary and print its definition
    void Dictionary::searchWord(const char* word) {
        bool found = false;
        
        for (int i = 0; i < m_size; ++i) {
            if (m_words[i].m_word == word) {
                if (!found) {
                    cout << m_words[i].m_word << " -";
                    found = true;
                }
                else {
                    cout << setw(m_words[i].m_word.size() + 2) << setfill(' ') << " -";
                }

                if (g_settings.m_verbose && m_words[i].m_pos != PartOfSpeech::Unknown) {
                    cout << " (" << toString(m_words[i].m_pos) << ")";
                }

                cout << " " << m_words[i].m_definition << endl;

                if (!g_settings.m_show_all)
                    return;
            } }

        // if word is not found in the dictionary
        if (!found) {
            cout << "Word '" << word << "' was not found in the dictionary." << endl;
        }
    }
    }
