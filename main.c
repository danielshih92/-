//hw2-2.c
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define randomize() srand((unsigned)time(NULL))

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {
	//five star character
	float times = 1000000.0; //Set the number of draws
	randomize(); //sets the starting point for producing a series of pseudo-random integers
	int k;
	int count; //This variable will record the number of executions
	float get5star = 0; //This variable can record the number of times the five-star character is drawn
	float get4star = 0; //This variable can record the number of times the four-star character is drawn
	float get5up = 0; //This variable can record the number of times the five-star up character is drawn
	int attempt = 1; //This vriable can record how many tries does the player did before getting the chraceter
	int if_up=0;// this variable can record whether you got a five-star character last time
	
	for (count = 1; count <= times; count++) {
		if (attempt <= 73) {
			attempt++; // the value will +1 when you try
			k = rand() % 1000; // k is a random number 0~999
			if (k <= 2 && if_up == 0) {
				get5star++; // get five star chracter
				attempt = 1;// initialzed the variable
				if_up = 1; // 
			}
			else if(k >= 3 && k <= 5 && if_up == 0){
				get5up++;
				attempt = 1;
			}
			else if(k <= 5 && if_up == 1){
				get5up++;
				attempt = 1;
				if_up = 0;
			}
		}
		else {
			attempt++; // the value will +1 when you try
			k = rand() % 1000; // k is a random number 0~999
			if (k <= ((attempt - 74) * 60 + 5)) //when the time you attempt +1, the chance you will get the character will +6%
			{
					k = rand()%2; // this variable can help accomplish the chance of 50%
					if(k == 0 && if_up ==0){
						get5star++;
						attempt = 1;
						if_up = 1;
					}
					else{
						get5up++;
						attempt = 1;
						if_up = 0;
					}
			}
			
		}
	} // Use the for loop to simulate the card drawing situation
	//problem1
	printf("五星角色抽%.f次中了%.f次，所以中獎的機率為:%.3f%%\n", times, get5star+get5up, ((get5star+get5up) / times)*100); // output the result of five-star character			
	printf("其中，你抽到了%.f次的五星UP角，因此抽中五星UP角色的機率為%.3f%%", get5up,(get5up/times)*100);

	// four star character
	printf("\n-------------------------------------------------\n");
	
	//intialized
	attempt = 1;
	if_up = 0;
	
	
	
	float get4up = 0;// This variable can record the number of times the four-star up character is drawn
	
	for (count = 1; count <= times; count++) {
		if (attempt <= 8) {
			attempt++; // the value will +1 when you try
			k = rand() % 1000; // k is a random number 0~999
			if (k <= 50) {
				k = rand()%2; // this variable can help accomplish the chance of 50% ( k = 0 or 1)
				if(k == 0 && if_up == 0){
					get4star++; // get four star chracter
					if_up = 1; // change the value of the variable so that next time you  will definiely get 4 star up chracter
				}
				else{
					get4up++; // get four star up character
					if_up = 0; // intitalized the variable
				}
				attempt = 1; // initialized the variable
			}
		}
		else if (attempt == 9) {
			attempt++; // the value will +1 when you try
			k = rand() % 1000; // k is a random number 0~999
			if (k <= 561)// the chance is 56.2%
			{
				k = rand()%2;
				if(k == 0 && if_up == 0){
					get4star++; // get four star chracter
					if_up = 1; // change the value of the variable so that next time you  will definiely get 4 star up chracter
				}
				else{
					get4up++; // get four star up character
					if_up = 0; // intitalized the variable
				}
				attempt = 1; // initialized the variable
			}
		}
		else if (attempt > 9) {
			k = rand() % 1000; // k is a random number 0~999
			if (k <= 993) // the chance is 99.4%
			{
				k = rand()%2;
				if(k == 0 && if_up == 0){
					get4star++; // get four star chracter
					if_up = 1; // change the value of the variable so that next time you  will definiely get 4 star up chracter
				}
				else{
					get4up++; // get four star up character
					if_up = 0; // intitalized the variable
				}
				attempt = 1; // initialized the variable
			}
		}
	}
	
	int sunnysnow = 0;
	int no_danger_sugar = 0;
	int cat_tail = 0;
	
	for (count = 1; count <= get4up; count++){
		k = rand()%3;
		if(k == 0){
			sunnysnow++;
		}
		else if(k == 1){
			no_danger_sugar++;
		}
		else{
			cat_tail++;
		}
	}// this for loop can help simulate the real 4 star up character you get


		//problem2
		printf("\n"); //change line
		printf("四星物品抽%.f次中了%.f次，所以中獎的機率為:%.3f%%", times, get4star+get4up, ((get4star+get4up) / times)*100); // output the result of four-star character
		printf("\n其中，你抽到了%.f次的四星UP角，因此抽中四星UP角色的機率為%.3f%%\n", get4up,(get4up/times)*100);
		printf("詳細的抽中UP角色如下:\n");
		printf("晴霜的標繪．米卡(冰): %d次\n",sunnysnow); 
		printf("無害甜度．砂糖(風):   %d次\n",no_danger_sugar); 
		printf("貓尾特調．迪奧娜(冰): %d次\n",cat_tail); 
		return 0;
	}
