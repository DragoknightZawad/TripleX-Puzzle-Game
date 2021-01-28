#include <iostream>
#include<ctime> 
void introduction(int Difficulty)
{  std::cout<<"\n";
   std::cout << R"(  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.    .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |  | .--------------. |
| |  _________   | || |  _______     | || |     _____    | || |   ______     | || |   _____      | || |  _________   | |  | |  ____  ____  | |
| | |  _   _  |  | || | |_   __ \    | || |    |_   _|   | || |  |_   __ \   | || |  |_   _|     | || | |_   ___  |  | |  | | |_  _||_  _| | |
| | |_/ | | \_|  | || |   | |__) |   | || |      | |     | || |    | |__) |  | || |    | |       | || |   | |_  \_|  | |  | |   \ \  / /   | |
| |     | |      | || |   |  __ /    | || |      | |     | || |    |  ___/   | || |    | |   _   | || |   |  _|  _   | |  | |    > `' <    | |
| |    _| |_     | || |  _| |  \ \_  | || |     _| |_    | || |   _| |_      | || |   _| |__/ |  | || |  _| |___/ |  | |  | |  _/ /'`\ \_  | |
| |   |_____|    | || | |____| |___| | || |    |_____|   | || |  |_____|     | || |  |________|  | || | |_________|  | |  | | |____||____| | |
| |              | || |              | || |              | || |              | || |              | || |              | |  | |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |  | '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'    '----------------' 
       
)" << '\n';
 std::cout<<"You are an assassin breaking into a Level "<<Difficulty<<" templer stronghold.. there is a piece of eden located there..you need to hack their security to reach it...";
 std::cout<< "\n";
 std::cout<<"You need to enter the correct codes to continue..."<<"\n";

}
bool PlayGame(int Difficulty)
{
    introduction(Difficulty);
    
   
     int CodeA = rand()% Difficulty+Difficulty;
     int CodeB = rand()% Difficulty+Difficulty;
     int CodeC =rand()% Difficulty+Difficulty;
   //declare 3 number code
    int CodeSum = CodeA+CodeB+CodeC;
    int CodeProduct = CodeA*CodeB*CodeC;
    //Print sum and product
    std::cout<<"\n";
    std::cout<<"+ There are three numbers in the code"<<"\n";
    std::cout<<"+ The code add upto: "<<CodeSum<<"\n";
    std::cout<<"+ The codes multiply to give: "<<CodeProduct<<"\n";
   //Store player guess
    int GuessA,GuessB,GuessC;
     std::cin>>GuessA>>GuessB>>GuessC;
     /*
    std::cout<<"Enter 1st Number: ";
    std::cin>>GuessA;
    std::cout<<"Enter 2nd Number: ";
    std::cin>>GuessB;
    std::cout<<"Enter 3rd Number: ";
    std::cin>>GuessC;
    std::cout<<"\n";
    */
    int GuessSum = GuessA+GuessB+GuessC;
    int GuessProduct=GuessA*GuessB*GuessC;
   

   //Check if the players guess is correct
    if(GuessSum==CodeSum && GuessProduct==CodeProduct)
    {
        std::cout<<"\n \n Great you can now move on next level ";
        return true;
    }
    else
    {
        std::cout<<"\n \n Hacking failed,Try again";
        return false;
    }
    
   

}
int main()
{   
    srand(time(NULL)); //Create new random sequence based on time of day
    
    int LevelDifficulty=1;
    const int MaxLevel=5;
    while(LevelDifficulty<=MaxLevel) //Loop the game untill all levels completed
    {
        
    bool bLevelComplete =PlayGame(LevelDifficulty);

    std::cin.clear();//clears any error
    std::cin.ignore();//discards the buffering
    if (bLevelComplete)
    {
        //increase the level difficulty
     
        ++LevelDifficulty;
         system ("CLS");
    }
    
    }
    //return 
    std::cout<<"\n\n\n *******Congratulation you completed all the level and the piece of eden is yours";
    return 0;
}