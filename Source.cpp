#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
using namespace std;

void stats(string name, 
			int strength, 
			int defense, 
			int intelligence, 
			int weapons, 
			int food, 
			int medicine, 
			int distance, 
			int fatigue, 
			int partymembers);
void stats(string name, int strength, int defense, int intelligence, int weapons, int food, int medicine, int distance, int fatigue, int partymembers) {
	cout << "Name: " << name << endl;
	cout << "Strength: " << strength << endl;
	cout << "Defense: " << defense << endl;
	cout << "Intelligence: " << intelligence << endl;
	cout << "Weapons: " << weapons << endl;
	cout << "Food: " << food << endl;
	cout << "Medicine: " << medicine << endl;
	cout << "Distance Left: " << distance << endl;
	cout << "Fatigue: " << fatigue << endl;
	//cout << "Ration Plan: " << rations << endl;
	// chronic issue of "big ideas but not enough time"
	//cout << "Last Stop: " << laststop << endl;
	// if I continue to build this, then remember to declare string laststop in both the stats and the main function 
	cout << "Party Members Alive: " << partymembers << endl;
}

void death(string name, int strength, int defense, int intelligence, int weapons, int food, int medicine, int distance, int fatigue, int partymembers);
void death(string name, int strength, int defense, int intelligence, int weapons, int food, int medicine, int distance, int fatigue, int partymembers) {
	cout << "YOU DIED" << endl;
	cout << "Your stats are:" << endl;
	stats(name, strength, defense, intelligence, weapons, food, medicine, distance, fatigue, partymembers);
	//return(0);
	//this won't work b/c this is void function and what we're asking here is for a return
	//That's why we have exit();
	exit(0);
}

void hunting(int &strength, int &defense, int &intelligence, int &weapons, int &food, int &medicine);
void hunting(int &strength, int &defense, int &intelligence, int &weapons, int &food, int &medicine) {
	cout << "Hm. It doesn't look too bad outside today." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "There doesn't appear to be many zombies on this area of the trail." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Suprisingly, there are many trees and bushes too." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Maybe you could forage for food and supplies here!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Will you go and search for items?" << endl;
	string ok;
	cin >> ok;
	if (ok == "yes") {
		cout << "You decide to go and forage for food." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		random_device hunting;
		int hunt = hunting() % 3;
		switch (hunt) {
		case 0:
			cout << "While hunting, you come across a HUGE JACKPOT! HOORAY!" << endl;
			strength += 1;
			defense += 1;
			intelligence += 1;
			weapons += 2;
			food += 5;
			medicine += 3;
			break;
		case 1:
			cout << "While hunting, you come across some new supplies! Awesome!" << endl;
			strength += 1;
			defense += 1;
			weapons += 1;
			food += 3;
			medicine += 2;
			break;
		case 2:
			cout << "While hunting, you come across a few new things. Hey, better something than nothing, right?" << endl;
			weapons += 1;
			food += 2;
			medicine += 1;
			break;
		}
	}
	else {
		cout << "You decide not to go and instead continue." << endl;
	}
}

void climate(int &medicine, int &partymembers, int &strength, int &defense, int &intelligence, int &fatigue);
void climate(int &medicine, int &partymembers, int &strength, int &defense, int &intelligence, int &fatigue) {

	cout << "You have been caught in bad weather!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Do you rest, or continue forward?" << endl;
	string restOrGo;
	cin >> restOrGo;
	if (restOrGo != "continue forward") {
		cout << "You decide to not risk it and camp overnight." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "However, one of your party members falls sick." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		if (medicine >= 1) {
			cout << "You give them medicine to heal up." << endl;
			medicine -= 1;
		}
		else {
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "You don't have the medicine to heal them." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "Unfortunately, they die!" << endl;
			partymembers -= 1;
			strength -= 1;
			defense -= 1;
			intelligence -= 1;
		}
	}
	else {
		cout << "You continue on the trail." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Unfortunately, your team falls sick!" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		fatigue -= 2;
		if (medicine >= 2) {
			cout << "You all heal up." << endl;
			medicine -= 2;
		}
		else {
			cout << "You don't have the supplies to heal them." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "One of your members die!" << endl;
			partymembers -= 1;
			strength -= 1;
			defense -= 1;
			intelligence -= 1;
		}
	}
}

void theives(int &weapons, int &strength, int &defense, int &food, int &medicine, int &fatigue);
void theives(int &weapons, int &strength, int &defense, int &food, int &medicine, int &fatigue) {
	cout << "Late one night, you hear a group of people approaching your camp." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Oh no. Could it be zombies?" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "You take a peek and realize that it is not zombies. Thank god!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2500));
	cout << "On the other hand, it's a band of theives." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Huh. This could be some profound message of the true animosity of humanity and how the monsters we so fear are not manifestations of the undead, but rather, our true natures." << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "Fitzgerald would be proud of you, if he was still alive." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Anyways, enough of that. You have theives on your hands! You can either stay quiet or fight back. What do you do?" << endl;
	string theif;
	cin >> theif;
	if (theif == "fight") {
		cout << "You decide to fight!" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		if (weapons > 1) {
			cout << "You look for your weapons, only to realize that...oh no! You don't have any!" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "In your attempt, the theives find you and attack!" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "After taking your supplies, the theives leave, but you're in bad condition." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "Huh. Maybe the morality of humans an still remain once the bounds of civilization have evaporated." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "But you're in too much pain to really think about philosophy." << endl;
			strength -= 1;
			defense -= 1;
			weapons -= 1;
			food -= 1;
			medicine -= 1;
			fatigue -= 3;
		}
		else {
			cout << "You pick up your weapons and fight back!" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "There's a long and hard fight, but you finally win!" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "You pretend that the dead bodies of the theives aren't strewn across your camp and you go to bed, tired, but safe." << endl;
			this_thread::sleep_for(chrono::milliseconds(3500));
			cout << "It crosses your mind that this is sort of 'Lord of the Flies'-esque...." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "But you're too proud of yourself to really think about philosophy." << endl;
			strength += 1;
			defense += 1;
			weapons += 1;
			fatigue -= 2;
			food += 1;
			medicine += 1;
		}
	}
	else {
		cout << "You hold your breath and allow the theives to take whatever they want." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "After what feels like forever, they finally leave." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Still shaking, you look outside and find that much of your supplies has been lost." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		weapons -= 2;
		food -= 3;
		medicine -= 2;
		fatigue -= 1;
	}
}

void badfood(int &medicine, int &fatigue);
void badfood(int &medicine, int &fatigue) {

	cout << "You and your team accidentally eat bad food!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "You all feel quite sick." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	if (medicine < 2) {
		cout << "You don't have the supplies to heal up." << endl;
		fatigue -= 3;
	}
	else {
		cout << "Luckily, you have medicine and feel better." << endl;
		medicine -= 2;
		fatigue -= 1;
	}
}


void found(int &food, int &medicine, int &weapons, int &strength, int &defense, int &intelligence, int&partymembers);
void found(int &food, int &medicine, int &weapons, int &strength, int &defense, int &intelligence, int&partymembers) {
	cout << "Oh? Looks like you've run into someone!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "It's another human being! Turns out they're also going to Oregon! Will you bring them along?" << endl;
	string newmember;
	cin >> newmember;
	if (newmember != "no") {
		cout << "Are you sure? Bringing in a new person can increase your strength, defense, and intelligence, but will reduce your food, medicine, and weapons." << endl;
		this_thread::sleep_for(chrono::milliseconds(4000));
		string sure;
		cin >> sure;
		if (sure == "yes") {
			cout << "Great! A new person has joined your team!" << endl;
			food += 1;;
			medicine -= 1;
			weapons -= 1;
			strength += 1;
			defense += 1;
			intelligence += 1;
			partymembers += 1;
		}
	}
	else {
		cout << "You sadly tell them that they cannot join you. They angrily leave." << endl;
	}
}


void ZOMBIES(int &intelligence, int &food, int &weapons, int &strength, string name, int defense, int medicine, int distance, int fatigue, int partymembers);
void ZOMBIES(int &intelligence, int &food, int &weapons, int &strength, string name, int defense, int medicine, int distance, int fatigue, int partymembers) {

	cout << "Oh no! You've run into a swarm of zombies!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "What will you do? Attack, or run?" << endl;
	string zombie;
	cin >> zombie;
	if (zombie != "attack") {
		cout << "You decide to run." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		if (intelligence < 3) {
			cout << "You try to outsmart the zombies, but they catch you." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			death(name, strength, defense, intelligence, weapons, food, medicine, distance, fatigue, partymembers);
		}
		else {
			cout << "You escape unharmed. Nice!" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "You also got 1 food!" << endl;
			intelligence += 1;
			food += 1;
		}
	}
	else {
		cout << "You decide to attack." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		if ((weapons < 2) && (strength < 1)) {
			cout << "You try to attack, but the zombies overpower you!" << endl;
			death(name, strength, defense, intelligence, weapons, food, medicine, distance, fatigue, partymembers);
		}
		else {
			cout << "You fight back and kill the zombies!" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "You also get 1 food!" << endl;
			strength += 1;
			food += 1;
		}
	}
}

void delayScroll(int delayMS, int lineCount);
void delayScroll(int delayMS, int lineCount) {

	for (int i = 0; i < lineCount; i++) {

		cout << "\n" << endl;
		this_thread::sleep_for(chrono::milliseconds(delayMS));
	}
}

int main() {
	random_device rd;
	int date = 5;
	cout << "Hello!" << "\n" << "\n" << "Welcome to....." << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	delayScroll(50, 21);
	cout << "The Organ Trail!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "No, that wasn't spelt incorrectly." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Welcome to the Organ Trail!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Would you like an introduction? Type 'y' or 'n'" << endl;
	char intro;
	cin >> intro;
	if (intro == 'y') {
		cout << "The year is 2560. Zombies have taken over the world." << endl;
		this_thread::sleep_for(chrono::milliseconds(2500));
		cout << "Approximately 7238 people worldwide remain amoung the masses of the undead, crawling on the surface." << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "Guess what?" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "..." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "You're one of them." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Not to worry! Mother Nature's overpopulation control requires for some of your species to remain." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "So, it's not IMPOSSIBLE, right?" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "..." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Right?" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "..." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ANYWAYS, you need to do your best to survive." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "\nJune " << date << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "\nIt's a beautiful morning in your underground bunker! The sky is bleak, the zombies are groaning, and your will to live is rapidly diminishing!" << endl;
		this_thread::sleep_for(chrono::milliseconds(4000));
		cout << "You have a hearty breakfast of dirt and expired soup. While you ponder your mortality amongst this desolate land, there's a knock at the door." << "\nA knock?" << "\nIs someone out there?" << endl;
		this_thread::sleep_for(chrono::milliseconds(4000));
		cout << "Open it? Type 'yes' or 'no'." << endl;
		string response1;
		cin >> response1;
		if (response1 != "yes") {
			cout << "Nice job, loser." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "You failed the most basic rule of RPGs. You have to take risks!" << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "I take it you don't have many friends?" << endl;
			return (0);
		}
		cout << "You open the door. Outside, there's a letter. You open it. It says- " << endl;
		this_thread::sleep_for(chrono::milliseconds(2500));
		cout << " _________________________________________________________" << endl;
		cout << "|                                                         |" << endl;
		cout << "|    Dear to whomever can read this,                      |" << endl;
		cout << "|             Hello. My name is ////////. I am one of the |" << endl;
		cout << "|       last humans on earth. And you are most likely one |" << endl;
		cout << "|       too, considering that you can read this. Unfortu- |" << endl;
		cout << "|       nately, if the zombies have learned how to read,  |" << endl;
		cout << "|       then this whole thing is a disaster, but if this  |" << endl;
		cout << "|       has been delivered to you, then I'm 95% sure that |" << endl;
		cout << "|       you're a human.                                   |" << endl;
		cout << "|       Anyways.....                                      |" << endl;
		cout << "|       This letter is to inform you that the human race  |" << endl;
		cout << "|       has aquired a gated community in Oregon County.   |" << endl;
		cout << "|       We've been working on it since the Apolcalypse.   |" << endl;
		cout << "|       It's got food to last another century, weapons for|" << endl;
		cout << "|       defense, and every reasource and comfort of the   |" << endl;
		cout << "|       good ol' human era. We're trying to get all remai-|" << endl;
		cout << "|       ning humans to come together. Please, if you can, |" << endl;
		cout << "|       come to Oregon County. We need you.               |" << endl;
		cout << "|       And you need us.                                  |" << endl;
		cout << "|                                                         |" << endl;
		cout << "|---------------------------------------------------------|" << endl;
		this_thread::sleep_for(chrono::milliseconds(15000));
		cout << "Whoa." << endl;
		cout << "A gated community? Food? Weapons? Human contact?" << endl;
		cout << "Sounds pretty good." << endl;
		this_thread::sleep_for(chrono::milliseconds(2500));
		cout << "Will you go? Type 'yes' or 'no'." << endl;
		string response2;
		cin >> response2;
		if (response2 != "yes") {
			cout << "Wow. Okay, idiot." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "I thought we were getting somewhere." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "You're the biggest disspointment next to bluberry flavored poptarts." << endl;
			this_thread::sleep_for(chrono::milliseconds(2000));
			cout << "Try again, nuthead." << endl;
			return(0);
		}
	}
	cout << "Okay, great!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Okay, before we begin, let's get some basic questions out of the way." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	int strength = 0;
	int defense = 0;
	int intelligence = 0;
	int weapons = 0;
	int food = 0;
	int medicine = 0;
	int distance = 2000;
	int fatigue = 10;
	int rations = 1;
	int partymembers = 1;
	string name;
	int dead = 0;
	cout << "What's your name?" << endl;
	cin >> name;
	cout << "Oh, hello " << name << "!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "What was your profession before the Apolcalypse?" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	int job;
	cout << "Type 1 if you were a doctor, 2 if you were a programmer, 3 if you did manual labor, or 4 if you were unemployed." << endl;
	cin >> job;
	if (job == 1) {
		strength += 1;
		defense += 1;
		intelligence += 5;
		food += 3;
		medicine += 4;
		weapons += 2;
		cout << "Wow! You must be glad you didn't need to pay back student loans, right?" << endl;
	}
	if (job == 2) {
		strength += 1;
		defense += 1;
		defense += 4;
		intelligence += 5;
		food += 3;
		weapons += 2;
		cout << "Nice! Coding is really fun, isn't it?" << endl;
	}
	if (job == 3) {
		strength += 5;
		defense += 4;
		intelligence += 1;
		food += 3;
		weapons += 2;
		cout << "Cool! You must've been ready for the Apocalypse." << endl;
	}
	if ((job != 2) && (job != 1) && (job != 3)) {
		strength += 1;
		defense += 1;
		intelligence -= 3;
		food += 2;
		weapons += 2;
		cout << "Hm. Dissapointing." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Was it an art degree?" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Or the economy?" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
	}
	cout << "Okay, great! It's time to pack your things and begin the journey!\n" << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "June 6" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "\nIt's 3:00 AM. You grab your meager belongings and begin the journey." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	//cout << "What pace do you decide on? A light one, a fast one, or a gruelling one?" << endl;
	//this_thread::sleep_for(chrono::milliseconds(2000));
	//cout << "A light one will cover less distance but makes you less fatigued. A fast one will cover some more distance, but makes you feel more fatigued. A gruelling one is fast and has no breaks, but will cause the most fatigue." << endl;
	//this_thread::sleep_for(chrono::milliseconds(2000));
	//cout << "Type 1 for light, 2 for fast, and 3 for gruelling."<< endl;
	//int pace;
	//int speed;
	//cin >> speed;
	//if (speed == 1) {
	//	fatigue -= 1;
	//	pace -= 10;
	//}
	//if (speed == 2) {
	//		fatigue -= -3;
	//		pace -= 15;
	//	}
	//	if (speed == 3) {
	//		fatigue -= 5;
	//	pace -= 20;
	//	}
	cout << "You're walking when you find a fork in the path. There are 2 signs, each pointing in a different direction." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "The one pointing to the right says 'WAY TO INDEPENDENCE, MISSOURI'. The one pointing to the left is blank." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Which do you choose? Left, or right?" << endl;
	string fork;
	cin >> fork;
	if (fork != "left") {
		cout << "You turn right. That seems safe, right? There's a sign after all." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "You continue for a few miles. You're feeling pretty confident! There have been no signs of zombies so far." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "It's only after you walk for another mile do you realize something is horribly wrong." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Out of nowhere, a group of zombies jump out of the bush and eat you!" << endl;
		death(name, strength, defense, intelligence, weapons, food, medicine, distance, fatigue, partymembers);
	}
	cout << "You turn " << fork << " . You're no coward. Like Robert Frost, you too, take the road less travelled." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Or was that Twain?" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "It's been so long since you've read anything." << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Anyways, off you go!" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	while ((fatigue>-15) && (food>-6) && (partymembers>0)) {
		cout << "\nWould you like to check your stats? Type 'y' or 'n'." << endl;
		char check;
		cin >> check;
		if (check == 'y') {
			stats(name, strength, defense, intelligence, weapons, food, medicine, distance, fatigue, partymembers);
		}
		this_thread::sleep_for(chrono::milliseconds(3800));
		distance -= 5;
		food -= partymembers;
		cout << "\nIt's the next day." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "What crazy situations will you run into today?\n" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		int chance = rd() % 6;
		switch (chance) {
		case 0:
			climate(medicine, partymembers, strength, defense, intelligence, fatigue);
			break;
		case 1:
			theives(weapons, strength, defense, food, medicine, fatigue);
			break;
		case 2:
			badfood(medicine, fatigue);
			break;
		case 3:
			found(food, medicine, weapons, strength, defense, intelligence, partymembers);
			break;
		case 4:
			ZOMBIES(intelligence, food, weapons, strength, name, defense, medicine, distance, fatigue, partymembers);
			break;
		case 5:
			hunting(strength, defense, intelligence, weapons, food, medicine);
			break;
		}

	}
	if (distance < 1960) {
		cout << "Congrats! You've finally reached Independence, Missouri!" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Now, on the REAL Oregon Trail, this is where your journey technically begins!" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Unfortunately, this also the end of this game." << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "FOR NOW, AT LEAST" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "Stay away from zombies everyone! See ya!" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		return (0);
	}
	cout << "Oh no! Your stats have dropped below the possible amount to survive!" << endl;
	death(name, strength, defense, intelligence, weapons, food, medicine, distance, fatigue, partymembers);

}








void rationplan();
void rationplan() {
	cout << "Now, let's decide on ration plans." << endl;
}