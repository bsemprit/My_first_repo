/*Final Project
August 5, 2015
Bianca Semprit
This is the Nightmare game. 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<ctime>


using namespace std;

struct Player
{
	//properties (name, score, weapon, system, whatAreYouDoing)
	string name;
	int score, weapon, system, whatAreYouDoing;

	//constructor
	Player()
	{
		score = 0, weapon = 0, whatAreYouDoing = 0, system = 0;
	}
};


//functions

//purpose: display main menu.
int DisplayMainMenu();

//purpose: Display the Storyline and Rules
void DisplayRules();

//purpose: Display code weapon menu and get results.
int CodeWeapon(int&);

//purpose: Display system menu and get results.
int System(int&);

//purpose: Display WhatAreYouDoing menu and get results.
int WhatAreYouDoing(int&);

//purpose: Choose to open the front door.
bool FrontDoor(int&);

//purpose: 8 digit code to open the front door
void EightDigitCode();

//purpose: Display InsideDoor menu and get results.
int InsideDoor(int&);

//purpose: If Door127.0.0.1 is picked display text and add points.
void Door127001(int&);

//purpose: If Gaming is picked display menu and get results.
void Gaming(int&);

//purpose: If CFO is picked display menu and get results.
void CFO(int&);

//purpose: If CEOOffice is picked display menu and get results.
void CEOOffice(int);

void ReadInScores(string[], int[]);

void WriteScores();

void CompareScores(string[], int[], string, int);

void UpdateScoreFile(string[], int[]);



int main()
{


//Declare and initialize variables
Player player1;
int highScores[3];
int menuChoice = 0, insideDoorOption = 0;
string firstName, highScoreNames[3], yesOrNoChoice;

//Seed random number generator
srand(time(NULL));

WriteScores();

//Intro
cout<<"\n\nTHIS IS YOUR NIGHTMARE. ARE YOU READY TO PLAY? PLEASE CHOOSE RULES TO WRAP YOUR HEAD AROUND THIS CONCEPT.\n\n";

//prompt for firstName
cout<<"\nBut first, enter your first name: ";
cin>>firstName;

do
{
	menuChoice = DisplayMainMenu();
		if(menuChoice == 1)
		{
			DisplayRules();
		}
		else if(menuChoice == 2)
		{	
			ReadInScores(highScoreNames, highScores);

			player1.weapon = CodeWeapon(player1.score);

			//Display score and weapon
			cout<<"\nYour score so far is: "<<player1.score<<endl;

			player1.system = System(player1.score);

			//Display score and weapon
			cout<<"\nYour score so far is: "<<player1.score<<endl;		

			player1.whatAreYouDoing = WhatAreYouDoing(player1.score);

			//Display score and weapon
			cout<<"\nYour score so far is: "<<player1.score<<endl;

			yesOrNoChoice = FrontDoor(player1.score);

			//Display score and weapon
			cout<<"\nYour score so far is: "<<player1.score<<endl;

			EightDigitCode();

			do
			{
			insideDoorOption = InsideDoor(player1.score);

				//Which door do you pick?
				//1. Door 127.0.0.1
				//2. CFO
				//3. Gaming
				//4. Exit

				if(insideDoorOption == 1)
					{
					Door127001(player1.score);
					//Display score and weapon
					cout<<"\nYour score so far is: "<<player1.score<<endl;
					}

				else if(insideDoorOption == 2)
					{
					CFO(player1.score);
					//Display score and weapon
					cout<<"\nYour score so far is: "<<player1.score<<endl;
					}

				else if(insideDoorOption == 2)
					{
					Gaming(player1.score);
					//Display score and weapon
					cout<<"\nYour score so far is: "<<player1.score<<endl;
					}

				else
				{
					cout<<"\n\nYou hear a loud booming voice as if coming from everywhere yell 'YOU CANNOT LEAVE, TRY AGAIN.'\n"; 
					cout<<"You guess you have to pick another option."<<endl;
				}
			}while(insideDoorOption == 4);

			CEOOffice(player1.score);

			//Display score and weapon
			cout<<"\nYour ending score is: "<<player1.score<<endl;
			
			CompareScores(highScoreNames, highScores, firstName, player1.score);

			UpdateScoreFile(highScoreNames, highScores);

		}

		else if(menuChoice == 3)

			cout<<"\n\nYou wake up from your dream, dazed you look at the clock and it says 4 am. ";
			cout<<"\nYou're computer starts up by itself and the message 'Congrats' is shown before it dissapears and the computer shuts down again. ";

		else
		
			cout<<"\n\nSorry you can't play or exit without picking a number 1-3. Try again and let's play a game!";

}
while(menuChoice !=3);

return 0;
}



//function definitions

//purpose: display main menu.
int DisplayMainMenu()
{
	int menuChoiceTemp = 0;

	//Display Menu
	cout<<"\n\nMAIN MENU\n\n";
	cout<<"Please choose from the following choices:\n1) See Rules and Storyline\n2) Play Game\n3) Quit\n\n";

	//Prompt for menuChoiceTemp
	cin>>menuChoiceTemp;

	return menuChoiceTemp;
}

//purpose: Display the Storyline and Rules
void DisplayRules()
{
	//Display Rules and Storyline
	cout<<"\n\nYou are a hacker, through and through, but you fell asleep yesterday while coding and had a nightmare. This is your nightmare. Or is it?\n";
	cout<<"In front of you is a sheet of paper stating:\n";
	cout<<" ██░ ██  ▄▄▄       ▄████▄   ██ ▄█▀▓█████  ██▀███  \n";
	cout<<"▓██░ ██▒▒████▄    ▒██▀ ▀█   ██▄█▒ ▓█   ▀ ▓██ ▒ ██▒\n";
	cout<<"▒██▀▀██░▒██  ▀█▄  ▒▓█    ▄ ▓███▄░ ▒███   ▓██ ░▄█ ▒\n";
	cout<<"░▓█ ░██ ░██▄▄▄▄██ ▒▓▓▄ ▄██▒▓██ █▄ ▒▓█  ▄ ▒██▀▀█▄  \n";
	cout<<"░▓█▒░██▓ ▓█   ▓██▒▒ ▓███▀ ░▒██▒ █▄░▒████▒░██▓ ▒██▒\n";
	cout<<" ▒ ░░▒░▒ ▒▒   ▓▒█░░ ░▒ ▒  ░▒ ▒▒ ▓▒░░ ▒░ ░░ ▒▓ ░▒▓░\n";
	cout<<" ▒ ░▒░ ░  ▒   ▒▒ ░  ░  ▒   ░ ░▒ ▒░ ░ ░  ░  ░▒ ░ ▒░\n";
	cout<<" ░  ░░ ░  ░   ▒   ░        ░ ░░ ░    ░     ░░   ░ \n";
	cout<<" ░  ░  ░      ░  ░░ ░      ░  ░      ░  ░   ░     \n";
	cout<<"	          ░                               \n";
	cout<<"We need you. We are sending you on a journey to free the source code in Microsoft. They can't stay hidden forever.\n";
	cout<<"Open Source for the win. We're counting on you. Three other people have been sent but they didn't succeed and were captured,\n"; 
	cout<<"they just didn't have enough points to get out of the final door. All you have to do is get a score better then them and you won't get caught!\n";
}

void WriteScores()
{
	//declare a file pointer for output
	ofstream outfile;	

	//Open "highscore.txt" for writing
	outfile.open("highscore.txt", ios::out);

	//Write score and names into "highscore.txt"
	outfile<<"Victoria 1500"<<endl;
	outfile<<"Bibi 1000"<<endl;
	outfile<<"John 500"<<endl;

				
	//Close "highscore.txt" from writing
	outfile.close();
}



void ReadInScores(string tempNames[], int tempScores[])
{
	//declare a file pointer for input
	ifstream infile;
	
	//open file "highscore.txt" for input
	infile.open("highscore.txt", ios::in);
	
	//for loop to read in data
	for(int i = 0; i < 3; i++)
	{
		infile>>tempNames[i]>>tempScores[i];
	}

	//Close "highscore.txt" from reading
	infile.close();
		
}

void CompareScores(string tempNames[], int tempScores[], string userName, int userScore)
{
	//check greater than highest score
	if(userScore > tempScores[0])
	{	//move down second into third place
		tempScores[2] = tempScores[1];
		tempNames[2] = tempNames[1];
		//move down first place into second place
		tempScores[1] = tempScores[0];
		tempNames[1] = tempNames[0];
		//replace first place
		tempScores[0] = userScore;
		tempNames[0] = userName;
	}
	//check greater than second place
	else if(userScore > tempScores[1])
	{	//move down second into third place
		tempScores[2] = tempScores[1];
		tempNames[2] = tempNames[1];
		
		//replace second place
		tempScores[1] = userScore;
		tempNames[1] = userName;
	}
	//check greater than third place
	else if(userScore > tempScores[2])
	{
		//replace third place
		tempScores[2] = userScore;
		tempNames[2] = userName;
	
	}
	
}

void UpdateScoreFile(string tempNames[], int tempScores[])
{	//declare a file pointer for output
	ofstream outfile;

	//open file "highscores.txt" for output
	outfile.open("highscore.txt", ios::out);

	//for loop to write the values in arrays to files
	for(int i = 0; i < 3; i++)
	{
		//write data: 
		outfile<<tempName[i]<<" "<<tempScores[i];
	}

	//close file
	outfile.close();
} 


//purpose: Display front door menu and get results.
int CodeWeapon(int &Points)
{
	int Weapon = 0;

	do
	{
	//Display CodeWeapon menu

	cout<<"\n\nPick your code weapon:\n1. C\n2. C++\n3. PHP\n4. HTML\n"

	//Prompt for Weapon
	cout<<"\nEnter your option: \n"
	cin>>Weapon;

	if (Weapon == 1)
		Points += 100;
	else if (Weapon == 2)
		Points += 400;
	else if (Weapon == 3)
		Points += 300;
	else if (Weapon == 4)
		Points += rand()%100 + 1;
	else
		cout<<"\n\nYou have slightly woken up because you didn't answer the question. You drift back to sleep and make another choice.\n\n";
	}
	while(Weapon < 1 || Weapon > 4);
	
	return Weapon;
}

//purpose: Display system menu and get results.
int System(int &Points)
{
	int SystemOption = 0;

	do
	{
	//Display SystemOption menu

	cout<<"\n\nPick your system:\n1. Linux\n2. Windows\n3. Mac\n4. Android\n\n";

	//Prompt for SystemOption
	cout<<"\nEnter your option: \n"
	cin>>SystemOption;

	if (SystemOption == 1)
		cout<<"\nYes! You have Linux Mint running!\n";
		Points += 300;
	else if (SystemOption == 2)
		cout<<"\nOh...Turns out that someone has hacked your Windows and you have to reload your system from your backup drive. Tsk. Tsk.\n";
		Points += 0;
	else if (SystemOption == 3)
		cout<<"\nYour Mac is solid\n";
		Points += 300;
	else if (SystemOption == 4)
		cout<<"\nHmm.... Are you sure? This could be a amazing or completely fail.\n";
		Points += rand()%1000 + 1;
	else
		cout<<"\n\nYou have slightly woken up because you didn't answer the question. You drift back to sleep and make another choice.\n\n";
	
	}
	while(SystemOption < 1 || SystemOption > 4);
	
	return SystemOption;
}

//purpose: Display WhatAreYouDoing menu and get results.
int WhatAreYouDoing(int &Points)
{
	int WhatAreYouDoingOption = 0;

	do
	{
	//Display WhatAreYouDoing menu

	cout<<"\n\nWhat do you want to do?\n1. Bring a Friend\n2. Carry reference book\n3. Run away\n\n";

	//Prompt for WhatAreYouDoingOption 
	cout<<"\nEnter your option: \n"
	cin>>WhatAreYouDoingOption;

	if (WhatAreYouDoingOption == 1)
		cout<<"\nBonus! Your friend Tom joins you!\n";
		Points += 300;
	else if (WhatAreYouDoingOption == 2)
		cout<<"\nReally? You should know this by now.\n";
		Points += 50;
	else if (WhatAreYouDoingOption == 3)
		cout<<"\nYou try to run away.\n";
		Points += rand()%1000 + 1;
			if (Points < 500)
			cout<<"\nYou turn around and there's a note on the floor saying: Loser! Get back to work."; 
			cout<<"\nYou think someone left it but it makes you turn around.\n";
			if (Points >= 500)
			cout<<"\nNice job! You remember that you had to get a snack and after buying one you feel energized. Now back to the program.\n";
				
	else
		cout<<"\n\nYou have slightly woken up because you didn't answer the question. You drift back to sleep and make another choice.\n\n";
	
	}
	while(WhatAreYouDoingOption < 1 || WhatAreYouDoingOption > 4)
	
	return WhatAreYouDoingOption;
}

//purpose: Choose to open the front door.
bool FrontDoor(int &Points)
{
	string OpenDoor;
	int yesOrNo = 0;

	do
	{
	cout<<"\n\nYou reach the front door and attempt to break in. It's an 8 digit code, sounds hard. \n";
	cout<<"\nYou pull your stuff ready to crack the door. Do you want to open the door?\n";
	
	//Prompt for yesOrNo
	cout<<"\nYes or no?\n";
	cin>>OpenDoor;
	
	
	if (OpenDoor == "yes" || OpenDoor == "no")
		yesOrNo++;
	else 
		cout<<"\nA paper falls from the sky. It says: Please enter yes or no with no spaces.\n";

	}
	while(yesOrNo == 0);

	//Display yesOrNo
	cout<<yesOrNo<<endl;


	if (OpenDoor == "yes")
		cout<<"\nAwesome! You try to open the door.\n";
		Points += 100;
		return true;
	if (OpenDoor == "no")
		cout<<"\nYou try to turn around but something stops you so you try to open the door.\n";
		Points -= 100;
		return false;

}

//purpose: 8 digit code to open the front door
void EightDigitCode()
{
	int answer1 = 0;
	float answer234 = 0.0, answer5678 = 0.0;
	
	cout<<"\nYou think to yourself, great so far I've got great amount of points, I can break this easily!\n";
	cout<<"\nAs you approach the key entry and hook up your sytem, your computer gives you simplified questions to find each number in the code.\n";
		
			do
			{
			cout<<"\nWhat is 1 + 1? (*2*)\n";
			cin>>answer1;
			
			if (answer1 !=2)
				 cout<<"\nYour computer freezes for a second and asks you to repeat the answer, sorry you got it wrong.\n\n";

			}
			while(answer1 !=2);

			do
			{
			cout<<"\nWhat are the first 3 digits in pi? (*3.14*)\n";
			cin>>answer234;
			
			if (answer234 !=3.14)
				 cout<<"\nYour computer freezes for a second and asks you to repeat the answer, sorry you got it wrong.\n";
			}
			while(answer234 !=3.14);

			do
			{
			cout<<"\nWhat are the first 4 digits of e? (*2.718*)\n";
			cin>>answer5678;
			
			if (answer5678 !=2.718)
				 cout<<"\nYour computer freezes for a second and asks you to repeat the answer, sorry you got it wrong.\n";
			}
			while(answer5678 !=2.718);
	
		//Display code 23142718
		cout<<"\nThe code is 23142718! You have opened the door! You go inside Microsoft.\n\n";
}

//purpose: Display InsideDoor menu and get results.
int InsideDoor(int &InDoor)
{
	do
	{
	cout<<"\n\nWhich door do you pick?\n1. Door 127.0.0.1\n2. CFO\n3. Gaming\n4. Exit\n";

	//Prompt for InDoor
	cout<<"\nEnter your option: \n"
	cin>>InDoor;

	if(InDoor < 1 || InDoor > 4)
		cout<<"\nYou look around and spin for a few minutes. Sounds boring lets try this again. \n";
	}
	while(InDoor < 1 || InDoor > 4);

	return InDoor;
}

//purpose: If Door127.0.0.1 is picked display menu and get results.
void Door127001(int &Points)
{
	cout<<"\n\nYou go in and find a computer. Getting on you try unsuccessfully to hack into the computer. After looking around on the computer,";
	cout<<"\nyou find a page caclled the "Tale of a clueless Hacker" and realize you've been duped. You've been hacking your own computer! ";
	cout<<"\nYou look down at your computer screen and then back up but the computer you were hacking has dissapeared. You realize you've been on your own";
	cout<<"\ncomputer the whole time. You get up and walk out.\n";

	cout<<"\nBonus! You got 200 points!!!\n"
	
	Points += 200;

	cout<<"\nWhen you walk out, suddenly the door takes you into the CEO's office.\n";

}

//purpose: If Gaming is picked display menu and get results.
void Gaming(int &Points)
{
	int GamingOption = 0;

	do
	{
	cout<<"\n\nWant to play a game?\n1. Forza Motorsport 5 on Xbox One\n2. Clash of Clans on Android\n3. Destiny on Playstation 4";
	cout<<"\n4. Super Smash Bros. on Nintendo 3DS";

	//Prompt for GamingOption
	cout<<"\nEnter your option: \n"
	cin>>GamingOption;

	if (GamingOption == 1)
		Points *= .5;
		cout<<"\nYou've lost half your points! Microsoft knows you're playing! Your phone goes off and shows you the message: ";
		cout<<"\nCEO's Office. You head there.";
	else if (GamingOption == 2)
		Points += 400;
		cout<<"\nGoogle is on your side! They tell you after playing for an hour that the source code is in the CEO's office. You head there.";
	else if (GamingOption == 3)
		Points += 300;
		cout<<"\nNice pick! You play for an hour but your phone goes off and shows you the message: CEO's Office. You head there.";
	else if (GamingOption == 4)
		Points += rand()%100 + 1;
		cout<<"\nCool! You play for a few minutes but your phone goes off and shows you the message: CEO's Office. You head there.";
	else 
		cout<<"\nYou can't pick a game so you sit for ten minutes. You really want to play a game now, you try again to play.";
	}
	while(GamingOption < 1 || GamingOption > 4);

}

//purpose: If CFO is picked display menu and get results.
void CFO(int &Points)
{
	int CFOOption = 0;

	do
	{
		cout<<"\n\nBonus! There's a hoodie, thick book and cat in the CFO's office. Which do you pick up?\n1. Hoodie\n2. Thick Book\n3. Cat";

		//Prompt for CFOOption
		cout<<"\nEnter your option: ";
		cin>>CFOOption;
	
	if (CFOOption == 1)
		{
		Points += 100;
		cout<<"\nAwesome! You're warm! You reach into the pocket and find a note. It says: The source code is in the CEO's office - Hood. You head there.";
		}
	else if (CFOOption == 2)
		{
		Points += 200;
		cout<<"\nYou pick up the book titled Quantum Physics. You open the first page and read the joke inside.";
		cout<<"\nWhat do computers and air conditioners have in common? They both become useless when you open windows. ";
		cout<<"\nYou laugh and flip to the last page and see a note slip out. It says: ";
		cout<<"\nThe source code is in the CEO's office - AntiWindows. You head there.";
		}
	else if (CFOOption == 3)
	{
		Points += 300;
		cout<<"\nYou pet the cat. The cats collar lights up and you follow the cat to a door labeled CEO's office. You enter.";
	}
	else 
		cout<<"\nYou can't decide so you sit for ten minutes. You really want to choose now, you try again.";
	}
	while(CFOOption < 1 || CFOOption > 3);

}

//purpose: If CEOOffice is picked display menu and get results.
void CEOOffice(int Points)
{
	cout<<"\nYou're in the CEO's office! There's a few computers and you head to one. You hack in using the Hackathon Method. ";
                                                                                                                                                            
                                                                                                                                                            
cout<<"\n SSSSSSSSSSSSSSS                                                                                                                  !!!  !!!  !!!  !! ";    
cout<<"\nSS:::::::::::::::S                                                                                                                !!:!!!!:!!!!:!!!!:!!";    
cout<<"\nS:::::SSSSSS::::::S                                                                                                                !:::!!:::!!:::!!:::!";    
cout<<"\nS:::::S     SSSSSSS                                                                                                                !:::!!:::!!:::!!:::!";
cout<<"\nS:::::S            uuuuuu    uuuuuu      cccccccccccccccc    cccccccccccccccc    eeeeeeeeeeee        ssssssssss       ssssssssss   !:::!!:::!!:::!!:::!";
cout<<"\nS:::::S            u::::u    u::::u    cc:::::::::::::::c  cc:::::::::::::::c  ee::::::::::::ee    ss::::::::::s    ss::::::::::s  !:::!!:::!!:::!!:::!";
cout<<"\n S::::SSSS         u::::u    u::::u   c:::::::::::::::::c c:::::::::::::::::c e::::::eeeee:::::eess:::::::::::::s ss:::::::::::::s !:::!!:::!!:::!!:::!";
cout<<"\n  SS::::::SSSSS    u::::u    u::::u  c:::::::cccccc:::::cc:::::::cccccc:::::ce::::::e     e:::::es::::::ssss:::::ss::::::ssss:::::s!:::!!:::!!:::!!:::!";
cout<<"\n    SSS::::::::SS  u::::u    u::::u  c::::::c     cccccccc::::::c     ccccccce:::::::eeeee::::::e s:::::s  ssssss  s:::::s  ssssss !:::!!:::!!:::!!:::!";
cout<<"\n       SSSSSS::::S u::::u    u::::u  c:::::c             c:::::c             e:::::::::::::::::e    s::::::s         s::::::s      !:::!!:::!!:::!!:::!";
cout<<"\n            S:::::Su::::u    u::::u  c:::::c             c:::::c             e::::::eeeeeeeeeee        s::::::s         s::::::s   !!:!!!!:!!!!:!!!!:!!";
cout<<"\n            S:::::Su:::::uuuu:::::u  c::::::c     cccccccc::::::c     ccccccce:::::::e           ssssss   s:::::s ssssss   s:::::s  !!!  !!!  !!!  !!!";
cout<<"\nSSSSSSS     S:::::Su:::::::::::::::uuc:::::::cccccc:::::cc:::::::cccccc:::::ce::::::::e          s:::::ssss::::::ss:::::ssss::::::s               ";
cout<<"\nS::::::SSSSSS:::::S u:::::::::::::::u c:::::::::::::::::c c:::::::::::::::::c e::::::::eeeeeeee  s::::::::::::::s s::::::::::::::s  !!!  !!!  !!!  !!!  ";
cout<<"\nS:::::::::::::::SS   uu::::::::uu:::u  cc:::::::::::::::c  cc:::::::::::::::c  ee:::::::::::::e   s:::::::::::ss   s:::::::::::ss  !!:!!!!:!!!!:!!!!:!! ";
cout<<"\n SSSSSSSSSSSSSSS       uuuuuuuu  uuuu    cccccccccccccccc    cccccccccccccccc    eeeeeeeeeeeeee    sssssssssss      sssssssssss     !!!  !!!  !!!  !!!  ";
                                                                                                                                                            
                                                                                                                                                            
cout<<"\nYou have hacked into Microsoft! A few seconds pass and you hit the BUTTON and viola! ";
cout<<"\nMicrosoft's entire source code is now on GitHub and a few other repositories and forums."; 
cout<<"\nSuddenly you hear sirens go off and flashing lights! You run to the door and find that there are gates slowing lowering over the exit. ";
cout<<"\nThere is a key pad that you enter your points. It seems like it will get you out. You enter your score.";

	if(Points > 2000)
		cout<<"\nYou got out safely!! ";

cout<<"\n   _____                            _         _       _   _                 _  ";
cout<<"\n  / ____|                          | |       | |     | | (_)               | | ";
cout<<"\n | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __  ___| | ";
cout<<"\n | |    / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \/ __| | ";
cout<<"\n | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \__ \_| ";
cout<<"\n  \_____\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_|___(_) ";
cout<<"\n                     __/ |                                                     ";
cout<<"\n __     __          |___/       ___       _                                    ";
cout<<"\n \ \   / /          \ \        / (_)     | |                                   ";
cout<<"\n  \ \_/ /__  _   _   \ \  /\  / / _ _ __ | |                                   ";
cout<<"\n   \   / _ \| | | |   \ \/  \/ / | | '_ \| |                                   ";
cout<<"\n    | | (_) | |_| |    \  /\  /  | | | | |_|                                   ";
cout<<"\n    |_|\___/ \__,_|     \/  \/   |_|_| |_(_)         ";



	else
		cout<<"\nYour points weren't high enough to get you out. Sadly, you got caught. The source code is out there but you aren't. ";
		cout<<"\nThankfully you get no time in jail, but they make you work for Microsoft as punishment. You become famous for hacking in. ";
                                             
}
