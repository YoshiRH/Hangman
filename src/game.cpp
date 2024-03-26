//
// Created by yoshu on 3/26/2024.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "game.h"

void game::greet() {
    char start{};

    std::cout << "     Hangman     " << std::endl;
    std::cout << "_____________    " << std::endl;
    std::cout << "|        }       " << std::endl;
    std::cout << "|        o       " << std::endl;
    std::cout << "|        |       " << std::endl;
    std::cout << "|       /|\\     " << std::endl;
    std::cout << "|      / | \\    " << std::endl;
    std::cout << "|       / \\     " << std::endl;
    std::cout << "|      /   \\    " << std::endl;
    std::cout << "|                " << std::endl;
    std::cout << "|_____________   " << std::endl;

    std::cout << "\nPress any key to start.\n";
    std::cin >> start;
    start_game();
}

void game::start_game() {
    set_word();
    std::string hidden_searched_word(searched_word.length(),'*');

    while (tries >= 0) {
        good_guess = false;
        std::cout << "The word you have to guess is: ";
        std::cout << hidden_searched_word << std::endl;
        std::cout << "\n\n\nThere are " << hidden_searched_word.length() << " letters in the word" << std::endl;
        std::cout << "You have " << tries << " guesses left" << std::endl;
        std::cout << "Used letters: ";
        for(const auto &letter:used_letters){
            std::cout << letter << ", ";
        }

        std::cout << "\n\n\nGuess a letter: ";
        std::cin >> user_guess;

        for(int i{0}; i<searched_word.length(); i++){

            if(searched_word[i] == tolower(user_guess)){
                hidden_searched_word[i] = tolower(user_guess);
                good_guess = true;
            }

        }

        if(hidden_searched_word == searched_word){
            game_won();
            break;
        }

        if(!good_guess) {
            std::cout << "\n-------------------------------------------------------------------";
            std::cout << "\n\nSorry, " << user_guess << " is not part of the word." << std::endl;
            tries--;

            if(tries<=0){
                game_lost();
                break;
            }
        }
        else{
            std::cout << "\n-------------------------------------------------------------------";
            std::cout << "\n\nCongratulations! " << user_guess << " is one of the letter of that word." << std::endl;
        }

        used_letters.push_back(user_guess);

        draw_hangman(tries);
        }

}

void game::set_word() {
    srand(time(nullptr));
    std::ifstream word_file{"../data/Words.txt"};
    std::string word{};
    std::vector<std::string> word_list {};

    if(word_file){

        while(!word_file.eof()){
            std::getline(word_file,word);
            word_list.push_back(word);
        }

        int random_num = rand() % word_list.size();
        this->searched_word = word_list.at(random_num);

    }
    else std::cerr << "File error, can't opent he file." << std::endl;

    word_file.close();
}

void game::game_won() {
    std::cout << "\n-------------------------------------------------------------------";
    std::cout << "\n\nCongratulations! You have guessed the word: "<< searched_word << std::endl;
    std::cout << "\n\n\nPlay again?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    int chose{};
    std::cin >> chose;

    if(chose == 1){
        play_again();
    }
}

void game::game_lost() {
    std::cout << "_____________    " << std::endl;
    std::cout << "|        }       " << std::endl;
    std::cout << "|        o       " << std::endl;
    std::cout << "|        |       " << std::endl;
    std::cout << "|       /|\\     " << std::endl;
    std::cout << "|      / | \\    " << std::endl;
    std::cout << "|       / \\     " << std::endl;
    std::cout << "|      /   \\    " << std::endl;
    std::cout << "|                " << std::endl;
    std::cout << "|_____________   " << std::endl;
    std::cout << "\n\n\n\n\n\n";
    std::cout << "Game Over" << std::endl;
    std::cout << "You lost, the word you were trying to guess was: " << searched_word <<std::endl;

    std::cout << "\n\n\nPlay again?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;
    int chose{};
    std::cin >> chose;

    if(chose == 1){
        play_again();
    }
}

void game::play_again() {
    used_letters.clear();
    tries = 6;
    start_game();
}

void game::draw_hangman(const int &count) {
    switch (count) {
        case 6: {
            std::cout << "_____________    " << std::endl;
            std::cout << "|        }       " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|_____________   " << std::endl;
            std::cout << "\n\n\n\n\n\n";
            break;
        }
        case 5: {
            std::cout << "_____________    " << std::endl;
            std::cout << "|        }       " << std::endl;
            std::cout << "|        o       " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|_____________   " << std::endl;
            std::cout << "\n\n\n\n\n\n";
            break;
        }
        case 4: {
            std::cout << "_____________    " << std::endl;
            std::cout << "|        }       " << std::endl;
            std::cout << "|        o       " << std::endl;
            std::cout << "|        |       " << std::endl;
            std::cout << "|        |       " << std::endl;
            std::cout << "|        |       " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|_____________   " << std::endl;
            std::cout << "\n\n\n\n\n\n";
            break;
        }
        case 3: {
            std::cout << "_____________    " << std::endl;
            std::cout << "|        }       " << std::endl;
            std::cout << "|        o       " << std::endl;
            std::cout << "|        |       " << std::endl;
            std::cout << "|       /|       " << std::endl;
            std::cout << "|      / |       " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|_____________   " << std::endl;
            std::cout << "\n\n\n\n\n\n";
            break;
        }
        case 2: {
            std::cout << "_____________    " << std::endl;
            std::cout << "|        }       " << std::endl;
            std::cout << "|        o       " << std::endl;
            std::cout << "|        |       " << std::endl;
            std::cout << "|       /|\\     " << std::endl;
            std::cout << "|      / | \\    " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|_____________   " << std::endl;
            std::cout << "\n\n\n\n\n\n";
            break;
        }
        case 1: {
            std::cout << "_____________    " << std::endl;
            std::cout << "|        }       " << std::endl;
            std::cout << "|        o       " << std::endl;
            std::cout << "|        |       " << std::endl;
            std::cout << "|       /|\\     " << std::endl;
            std::cout << "|      / | \\    " << std::endl;
            std::cout << "|       /        " << std::endl;
            std::cout << "|      /         " << std::endl;
            std::cout << "|                " << std::endl;
            std::cout << "|_____________   " << std::endl;
            std::cout << "\n\n\n\n\n\n";
            break;
        }
        default: {
            std::cerr << "Something went wrong..." << std::endl;
        }
    }
}
