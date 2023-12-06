

#include <iostream>
#include <cstring>
#include <fstream>
#include "graph1.h"
#include "WordGame.h"

using namespace std;


WordGame::WordGame()
{
  this->fileName = " ";
  this->word = " ";
}


string WordGame::getFileName()
{

  return fileName;
}
void WordGame::setFileName(string fn)
{

  this->fileName = fn;
}
void WordGame::setWord(int rand_no)
{
  int counter = 0;
  string word;

  fstream in_file(fileName, ios::in);
  //test in_file to make sure it is open correctly
  if(!in_file)
  {
    cout << fileName << " is not opened correctly " << endl;
    exit(-1);
  }

  while(true)
  {
    in_file >> word;

    if(in_file.eof())
    {
      break;
    }

    if(counter == rand_no)
    {
      this->word = word;
      break;
    }

    counter++;
  }


}
string WordGame::getWord()
{

  return word;

}
void WordGame::draw()
{
 int i =0;
  int x = 100;
  int y =  200;

  for (i = 0; i < word.length(); i++)
  {
    // draw rect
    drawRect(x, y,32,32);

    x += 33;
  }
  Sleep(2000);


}
int WordGame::play()
{
  int i =0;
  int ii = 0;
  int j =0;
  int jj = 1;
  int x =100;
  int x1 = 100;
  int x2 = 100;
  int y = 200;
  char letter = '_';
  int score =0;
  int fullscore =0;
  int freescore=0;
  string fn = "_.bmp";
  string guess;
  
  letter = word[0];
  fn[0] = letter;
  displayBMP(fn, x1, y);

 fullscore = 10*word.length();

  for (i = 0; i < word.length(); i++)
  {
    if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
      { 
        letter = word[i];
        fn[0] = letter;
        
        // draw the fn
         displayBMP(fn, x1, y);
       }

  
    x1 += 32;
   }

  gout << setPos(100, 120) << "Guess number: " << j + 1 << endg;
  cout << "Guess # " << j + 1 << endl;
  cout << "What is the word? ";
  cin >> guess;

  for ( j = 0; j < word.length(); j++)
    {
    
    

       if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')
       { 
         freescore += 10;
          x2+=32;  
       }


     else
        {

            if (word[j] == guess[j])
              {
              letter = word[j];
              fn[0] = letter;
              displayBMP(fn, x2, y);
                 score += 10;
                 x2+=32;
  
              
               }
           
 
            if (word[j] != guess[j])
               {
                  
                  
                   while ((word[word.length() - jj] == 'a' || word[word.length() - jj] == 'e' || word[word.length() - jj] == 'i' || word[word.length() - jj] == 'o' || word[word.length() - jj] == 'u'))
                   {
                     jj++;
                   }
                   ii++;
                   gout << setPos(100, 105) << "!!!INCORRECT!!!";
                  

                   if (ii % 2 != 0)
                    {
                     letter = word[j];
                     fn[0] = letter;
                     displayBMP(fn, x2, y);
                     x2 += 32;
                    }       
              
               

                   else
                    {                     

                      letter = word[word.length()-jj];
                      fn[0] = letter;
                      displayBMP(fn, 100+ 32*(word.length()-jj), y);
                      x2 += 32;
                    jj++;
                    }           
                  
                   gout << setPos(100, 120) << "Guess number: " << ii+1 << endg;
                   cout << "Guess # " << ii+1 << endl;
                   cout << "What is the word? ";
                   cin >> guess;
               } 
           
         if (score + freescore == fullscore)
         {
           gout << setPos(100, 135) << "Score: " << score << endg;
           gout << setPos(100, 120) << "Number of Guesses: " << ii + 1 << endg;
           gout << setPos(100, 105) << "!!!Correct!!!" << endg;
           gout << setPos(100, 85) << "Total Score: " << fullscore - freescore  << endg;
           break;
         }

       if ((j == word.length() - 1)&&(score + freescore != fullscore))
       {

               if (word[j] == guess[j])
               {
                 gout << setPos(100, 135) << "Score: " << score << endg;
                 gout << setPos(100, 120) << "Number of Guesses: " << ii + 1 << endg;
                 gout << setPos(100, 105) << "!!!Correct!!!" << endg;
                 gout << setPos(100, 85) << "Total Score: " << fullscore - freescore << endg;
                 break;
               }
               else
               {

                 gout << setPos(100, 135) << "Score: " << score << endg;
                 gout << setPos(100, 120) << "CORRECT ANSWER: " << word << endg;
                 gout << setPos(100, 105) << "!!!GAME OVER!!!" << endg;
                 gout << setPos(100, 85) << "Total Score: " << fullscore-freescore << endg;
                break;
               }
                for (int k = 0; k < word.length(); k++)
                {
                  letter = word[k];
                  fn[0] = letter;

                  // draw the fn
                  displayBMP(fn, x, y);
                  x += 32;
                }

       }

     }

    }      

   
       
  return score;
  }
