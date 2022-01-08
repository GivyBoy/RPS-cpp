#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>


int scoreAI = 0;
int userScore = 0;
char uChoice;
char cChoice;


void getInfo(std::string& nameOfUser, int& numOfRounds);
char getComputerOption();
char getUserOption();
void getWinner(int& scoreAI, int& userScore, char& uChoice, char& cChoice);


int main()
{   

    std::string nameOfUser;
    int numOfRounds;
    std::vector<char> OPTIONS = {'r', 'p', 's'};
    std::string equiv[3] = {"r for Rock", "p for Paper", "s for Scissors"};
    
    

    getInfo(nameOfUser, numOfRounds);

    std::cout << "Let's lay down some ground rules before we begin. Ensure that you follow these rules!" << std::endl;
    std::cout <<  "Below are the equivalencies: " << std::endl;

    for (auto i: equiv)
    {
        std::cout << "Use " << i << std::endl;
    }

    int rounds = 0;
    
    while (rounds < numOfRounds){

        uChoice = getUserOption();
        cChoice = getComputerOption();

        getWinner(scoreAI, userScore, uChoice, cChoice);

        rounds++;

    }

    if (userScore > scoreAI){

        std::cout << "You win, " << nameOfUser << ". The score is " << userScore << ":" << scoreAI << std::endl;
    }

    else if (userScore < scoreAI){

        std::cout << "The computer wins!"<< ". The score is " << scoreAI << ":" << userScore <<  std::endl;
    }
    else{

        std::cout << "You tied with the Computer"<< ". The score is " << userScore << ":" << scoreAI <<  std::endl;
    }


    return 0;

}



void getInfo(std::string& nameOfUser, int& numOfRounds){

    std::cout << "Hello, User! Please enter your name here: ";
    std::cin >> nameOfUser;

    std::cout << "Hello, " << nameOfUser << "!"<< " How many rounds do you want to play? Enter the number here: ";
    std::cin >> numOfRounds;

}

char getComputerOption(){

    int num = (rand() % 3) + 1;

    if (num == 1) {
        return 'r';
    }
    else if (num == 2){
        return 'p';
    }
    else{
        return 's';
    }
}

char getUserOption(){

    char user;


    std::cout << "Enter your choice ('r' for rock, 'p' for paper, and 's' for Scissors) here: ";

    std::cin >> user;

    while (user != 'r' && user != 'p' && user != 's'){
        std::cout << "Please enter one of the following options only. " << std::endl;
        std::cout << "(r) for rock " << std::endl << "(p) for paper" << std::endl << "(s) for scissors " << std::endl;
        std::cin >> user;
    }

    return user;

}

void getWinner(int& scoreAI, int& userScore, char& uChoice, char& cChoice){

    if (uChoice == 'r' && cChoice == 'p') {
        std::cout << "Computer Wins! Paper wraps Rock."<< std::endl;
        scoreAI++;
        
    }
    else if (uChoice == 'p' && cChoice == 's') {
        std::cout << "Computer Wins! Scissors cut Paper."<< std::endl;
        scoreAI++;
        
    }
    else if (uChoice == 's' && cChoice == 'r') {
        std::cout << "Computer Wins! Rock smashes Scissors."<< std::endl;
        scoreAI++;
        
    }
    else if (uChoice == 'r' && cChoice == 's') {
        std::cout << "You Win! Rock smashes Scissors."<< std::endl;
        userScore++;
        
    }
    else if (uChoice == 'p' && cChoice == 'r') {
        std::cout << "You Win! Paper wraps Rock."<< std::endl;
        userScore++;
        
    }
    else if (uChoice == 's' && cChoice == 'p') {
        std::cout << "You Win! Scissors cut Paper."<< std::endl;
        userScore++;
    }
    else{
        std::cout << "Tie. Play again win the Game." << std::endl;
    }

}