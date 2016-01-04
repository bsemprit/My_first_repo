/*Project Algorithm
July 1, 2015
Bianca Semprit
This is the Great Battle game. 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<ctime>

using namespace std;

int main()
{//BEGIN

	//Declare and initialize variables
	int menuChoice = 0, menu1Choice = 0, menu2Choice = 0, menu3Choice = 0, myRandom1 = 0, myRandom2 = 0, myRandom3 = 0;
	int endScoreStored = 0, score1 = 0, score2 = 0, score3 = 0, endScore = 0;
	string firstName, firstNameStored;

	//Seed random number generator
	srand(time(NULL));

	//Declare file pointer for output
	ofstream outfile;

	//Declare file pointer for input
	ifstream infile;
	
	//Intro
	cout<<"\n\nWelcome to the aftermath of the Great Battle! You have been one of the few survivors of the Great Battle.\n";
	cout<<"Your body and memories are gone, we are to create a new world. Play the game to find out who ";
	cout<<"you will be in the new world.\n\n";

	//Open "highscore.txt" for writing
	outfile.open("highscore.txt", ios::out);

	//Write endScoreStored and John into "highscore.txt"
	outfile<<"John 0"<<endl;
				
	//Close "highscore.txt" from writing
	outfile.close();

	do
	{//begin dowhile1
		/*Display Menu
		Please choose from the following choices:
		1) See Rules and Storyline
		2) Play Game
		3) Quit
		*/
		cout<<"\n\nThe Great Battle Aftermath. Would you like to play?\n";
		cout<<"Choose from the following menu:\n";
		cout<<"1) See Rules and Storyline\n2) Play Game\n3) Quit.\n";

		//Prompt for menu choice
		cout<<"\nWhat do you choose?";
		cin>>menuChoice;
		
		//Initial endscore
		endScore = 0;

		//Switch structure for Main Menu
		switch(menuChoice)
			{//begin switch
			case 1:
			//Display Rules and Storyline
			cout<<"\nWelcome to the aftermath of the Great Battle! ";
			cout<<"You have been one of the few survivors of the Great Battle.\n";
			cout<<"Your body and memories are gone, we are to create a new world. Play the game to find out who ";
			cout<<"you will be in the new world.\nYou can only choose from the menu choices given, you will not ";
			cout<<"get extra points for picking outside of the choices.\nEach choice has a certain amount of points.";
			cout<<" So try to get the highest score!\n\n";
			break;

			case 2:
			//Play Game

			//Display entrance of game
			cout<<"\nCongrats! You have begun your new life. Let's see who you want to be.\n";

			//Prompt for first name of player
			cout<<"\nWhat would you like your name to be?";
			cin>>firstName;

			//Switch structure for menu choices
			
			do
			{ //begin dowhile2
			/*Display menu1
			The world has just been revived. Everyone gets to choose their race after the Great Battle. 
			What is your choice race?
			1) Fairy
			2) Vampire
			3) Human (random number)
			*/
			cout<<"\nThe world has just been revived. Everyone gets to choose their race after the Great Battle.\n";
			cout<<"You can be any of the following races:\n";
			cout<<"1) Fairy\n2) Vampire\n3) Human\n";

			//Prompt for menu1Choice
			cout<<"\nWhat is your choice race?";
			cin>>menu1Choice;
			cout<<endl;

			//Switch structure for menu1
			switch(menu1Choice)
				{//begin switch2
				case 1:
				//Display "Wonderful you can fly and have magical powers!"
				cout<<"\nWonderful you can fly and have magical powers!\n";
				
				//Calculate score1
				score1 = 900;

				//Display score1
				cout<<"You got "<<score1<<" points for choosing to be a Fairy!\n";

				break;

				case 2:
				//Display "Wonderful you are immortal and but can't go out in the sun!"
				cout<<"\nWonderful you are immortal and but can't go out in the sun!\n";

				//Calculate score1
				score1 = 400;

				//Display score1
				cout<<"You got "<<score1<<" points for choosing to be a Vampire!\n";

				break;

				case 3:
				//Display "Wonderful you are human and but can be weaker then Vampires and Fairys!"
				cout<<"\nWonderful you are human and but can be weaker then Vampires and Fairys!\n";
				
				//Calculate score1

				myRandom1 = rand()%1000 + 1;
				score1 = myRandom1;

				//Display score1
				cout<<"You got "<<score1<<" points for choosing to be a Human!\n";

				break;

				default:
				//Display invalid.
				cout<<"\nYou must pick a race value between 1 and 3. No cheating. Please choose again, the world";
				cout<<"depends on it.\n";

				break;
				}//end switch2

			}//end dowhile2
			while(menu1Choice < 1 || menu1Choice > 3);

			do
			{//begin dowhile3
			/*Display menu2
			The world has just been revived. Everyone gets to choose their weapon after the Great Battle. 
			What is your choice weapon?
			1) Gun
			2) Magic vial (Gives extra magical powers)
			3) Strength potion (random number)
			*/
			cout<<"\nThe world has just been revived.";
			cout<<"Everyone gets to choose their weapon after the Great Battle.\n";
			cout<<"You can pick any of these weapons:\n";
			cout<<"1) Gun\n2) Magic vial\n3) Strength potion\n";

			//Prompt for menu2Choice
			cout<<"\nWhat is your choice weapon?";
			cin>>menu2Choice;
			cout<<endl;

			//Switch structure for menu2
			switch(menu2Choice)
				{//begin switch3
				case 1:
				//Display "You have an AK47, take down your enemies!"
				cout<<"\nYou have an AK47, take down your enemies!\n";
				
				//Calculate score2
				score2 = 400;

				//Display score2
				cout<<"You got "<<score2<<" points for choosing the gun!\n";

				break;

				case 2:
				//Display "This magic vial has given you the power to use magic more powerful than faires! 
				//Use wisely."
				cout<<"\nThis magic vial has given you the power to use magic more powerful than faires!";
				cout<<"Use wisely.\n";

				//Calculate score2
				score2 = 950;

				//Display score2
				cout<<"You got "<<score2<<" points for choosing the magic vial!\n";
				break;

				case 3:
				//Display "You have gained strength, depending on your race you will either be strong or weak!"
				cout<<"\nYou have gained strength, depending on your race you will either be strong or weak!\n";

				myRandom2 = rand()%1000 + 1;

				if(menu1Choice = 3 && myRandom2 >=101)
					{//begin if
					//Calculate score 2 and subtract score2 by 100
					score2 = myRandom2 - 100;
					}//end if
				else
					{//begin else
					score2 = myRandom2;
					}//end else

				//Display score2
				cout<<"You got "<<score2<<" points for choosing the potion!\n";

				break;

				default:
				//Display invalid.
				cout<<"\nYou must pick a weapon between 1 and 3. No cheating. Please choose again, the world";
				cout<<"depends on it.\n";
				break;
				}//endswitch3

			}//end do while3
			while(menu2Choice < 1 || menu2Choice > 3);
			
			do
			{//begin dowhile4
			/*Display menu3
			The world has just been revived. Everyone gets to choose their lifestyle after the Great Battle. 
			What is your choice lifestyle?
			1) Magistrate
			2) Worker
			3) Student (random number)
			*/
			cout<<"\nThe world has just been revived.";
			cout<<"Everyone gets to choose their lifestyle after the Great Battle.\n";
			cout<<"You can pick any of these lifestyles:\n";
			cout<<"1) Magistrate\n2) Worker\n3) Student\n";

			//Prompt for menu3Choice
			cout<<"\nWhat is your choice lifestyle?";
			cin>>menu3Choice;
			cout<<endl;

			//Switch structure for menu3
			switch(menu3Choice)
				{//begin switch 4
				case 1:
				//Display "You are an officer of the state. Always protect the people using your power."
				cout<<"\nYou are an officer of the state. Always protect the people using your power.\n";

				//Calculate score3
				score3 = 700;

				//Display score3
				cout<<"You got "<<score3<<" points for choosing the to be a magistrate!\n";

				break;

				case 2:
				//Display "You will work hard and be rewarded!"
				cout<<"\nYou will work hard and be rewarded!\n";
				
				//Calculate score3
				score3 = 400;

				//Display score3
				cout<<"You got "<<score3<<" points for choosing the to be a worker!\n";

				break;

				case 3:
				//Display "Thank you for helping the world learn from their mistakes! Students are invaluable."
				cout<<"\nThank you for helping the world learn from their mistakes! Students are invaluable.\n";
				
				//Calculate score3
				
				myRandom3 = rand()%1000 + 1;
				score3 = myRandom3;

				//Display score3
				cout<<"You got "<<score3<<" points for choosing the to be a student!\n";

				break;

				default:
				//Display invalid.
				cout<<"\nYou must pick a lifestyle between 1 and 3. No cheating. Please choose again, the world";
				cout<<"depends on it.\n";

				break;
				}//end switch4

			}//end do while4
			while(menu3Choice < 1 || menu3Choice > 3);

			//Calculate endScore
			endScore = score1 + score2 + score3;

			//Display endScore
			cout<<"Your highscore is: "<<endScore<<" points. Congrats for finding your place in the new world."<<endl;

			//Open "highscore.txt" for reading
			infile.open("highscore.txt", ios::in);
			
			if(!infile)
			{
			cout<<"File does not exist!\n";
			}

			//Read line by line (read in endscore will be endScoreStored)
			infile>>firstNameStored>>endScoreStored;

			//Close "highscore.txt" from reading
			infile.close();

			cout<<endScoreStored<<endl;

			if (endScore > endScoreStored)
				{//begin if

				cout<<"You have the newest highscore!";
				//Open "highscore.txt" for writing
				outfile.open("highscore.txt", ios::out);

				//Write endScore and name into "highscore.txt"
				outfile<<firstName<<" "<<endScore<<endl;
				
				//Close "highscore.txt" from writing
				outfile.close();
				}//end if
			else
				{
				cout<<"You do not have the highest score.";
				}
			
			
			break;

			case 3:
			//End Game
			cout<<"\nThank you for playing The Great Battle Aftermath!";
			cout<<" May the choices lead you in the right direction.\n";
			break;

			default:
			//Display invalid
			cout<<"\nYou must pick a menu choice between 1 and 3. No cheating. Please choose again, the world may";
			cout<<"depend on it.\n";
			break;
			}//end switch
			
	}//end dowhile1
	while(menuChoice !=3);

return 0;
}//end
