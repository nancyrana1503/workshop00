// Name: Nancy Rana
// Seneca email: nrana18@myseneca.ca
// Seneca Student ID: 149951238
// Date: 6 June 2025
// dictionary.h

#pragma once
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H
#include <string>
namespace seneca
{
    enum class PartOfSpeech {
        Unknown,
        Noun,
        Pronoun,
        Adjective,
        Adverb,
        Verb,
        Preposition,
        Conjunction,
        Interjection,
    };

    struct Word {
        std::string m_word{};
        std::string m_definition{};
        PartOfSpeech m_pos = PartOfSpeech::Unknown;
    };

    class Dictionary {
        Word* m_words;
        int m_capacity;
        int m_size;
        static int readWordsNumber(const char* filename);

        static PartOfSpeech getPartOfSpeech(const std::string& pos)
        {
            if (pos == "n." || pos == "n. pl.") {
                return PartOfSpeech::Noun;
            }
            else if (pos == "adv.") {
                return PartOfSpeech::Adverb;
            }
            else if (pos == "a.") {
                return PartOfSpeech::Adjective;
            }
            else if (pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.") {
                return PartOfSpeech::Verb;
            }
            else if (pos == "prep.") {
                return PartOfSpeech::Preposition;
            }
            else if (pos == "pron.") {
                return PartOfSpeech::Pronoun;
            }
            else if (pos == "conj.") {
                return PartOfSpeech::Conjunction;
            }
            else if (pos == "interj.") {
                return PartOfSpeech::Interjection;
            }
            else {
                return PartOfSpeech::Unknown;
            }
        }
        static std::string toString(PartOfSpeech pos) {
            switch (pos) {

            case PartOfSpeech::Noun:
                return "noun";
            case PartOfSpeech::Pronoun:
                return "pronoun";
            case PartOfSpeech::Adjective:
                return "adjective";
            case PartOfSpeech::Adverb:
                return "adverb";
            case PartOfSpeech::Verb:
                return "verb";
            case PartOfSpeech::Preposition:
                return "preposition";
            case PartOfSpeech::Conjunction:
                return "conjunction";
            case PartOfSpeech::Interjection:
                return "interjection";
            default:
                return "unknown";
            }
        }

    public:
        Dictionary();
        Dictionary(const char* filename);
        Dictionary(const Dictionary& other);
        Dictionary& operator=(const Dictionary& other);

        Dictionary(Dictionary&& other) noexcept;
        Dictionary& operator=(Dictionary&& other) noexcept;
        ~Dictionary();

        void searchWord(const char* word);
    };
}
#endif 