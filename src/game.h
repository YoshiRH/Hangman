//
// Created by yoshu on 3/26/2024.
//
#include <string>
#include <vector>

#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H


class game {
private:
    int tries{6};
    char user_guess{};
    bool good_guess{false};
    std::string searched_word {};
    std::vector<char> used_letters;

public:
    void greet();
    void start_game();
    void game_lost();
    void game_won();
    void set_word();
    void draw_hangman(const int &count);
    void play_again();

    //getters
    int get_tries() const {return tries;}
    bool get_good_guess() const {return good_guess;}
    char get_user_guess() const {return user_guess;}
    std::string get_searched_word() {return searched_word;}
};


#endif //HANGMAN_GAME_H
