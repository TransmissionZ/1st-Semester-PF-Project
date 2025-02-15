int Elvl2(int *s){
	char words[25][13]; //the level has 25 words each of 13 or less letters
	wordsfiling1(words, (char *)"level2.txt"); //function takes words from the file containing words of the first level
	time_t start; //in-built library function of structure time_t with variable start
	int j = 0, oldscore = 0; //
	char ch; 
	int d, l,z = 0, t; //d stores for retrying level, z for array of typed letters 
	int i,k; //i for y coordinate and k for x coordinate
	char typed[10] = ""; //array to store the letters typed by the player
	start = clock(); //in-built library function
	while (j != 24){ //loop continues till al 24 words aren't typed. 
		z = 0; //
		//char typed[10] = "";
		l = strlen(words[j]); //storing string length of each word that appears
		for (i=0, k=0; i<50; i++,k++,k++){ //i=x k=y coordinates
			t = timer(start, 65);
			if (t==1) //when timer returns 1, the level ends. 
				break;
			gotoxy(11+k, 6+i); //the words appear in addition to the coordinates of the border
			puts(words[j]); //
			Sleep(200); //to make the words appear slowly 
			ClearWord(11 + k, 6+i); 
			if (kbhit()){ //to determine if the key has been hit ot not
 				gotoxy(20+z,58); //places cursor at the specific coordinates on the screen before taking the input for the char
	     		ch = getche();
	     		if (ch == '`') //exits the level
	     			return 0;
	     		if (words[j][z] == ch){ //when the entered character matches that of the word that appears
					typed[z] = ch; //character entered stored in array
					z++; //letter stored in array
				}
				else{
					gotoxy(80,58);
					printf("WRONG LETTER! ENTER WHOLE WORD AGAIN!"); //if wrong letter is entered
					z=0;
					ClearWord(20, 58);
					Beep(900,200);
				}
			}	
			if (strcmp(typed,words[j]) == 0){ //if the wholw word matches
				ClearWord(80,58); //screee clears for the other word to appear
				ClearWord(100,58);
				ClearWord(120, 58);
				gotoxy(100,58);
				printf("Correct!");
				j++; //next word appears
				(*s)++; //addition of 1 to the initial score as the word is correct
				oldscore++;
				Sleep(200);
				memset(typed, 0, sizeof(typed)); //
				z = 0; //z becomes zero again for the new word to appear
				ClearWord(11+k, 6+i);
				ClearWord(20,58);
				Beep(300, 200);
				i = 53;
			}
			else if (i >= 49){
				gotoxy(90,30); //if the y-coordinate of the word becomes greater or equal than 49, level is failed
				printf("LEVEL 2 FAILED");
				gotoxy(100,31);
				printf("Retry? (1/0)");
				Beep(900,900);
				d = getch();
				d = d-'0';
				ClearGame();
				if (d==1){
					*s -= oldscore;
					Elvl2(s);
				}
				else{
					return 0;
				}
			}
		}	
		
		if (t == 1)
			break;
	}
	
	if (j == 24){
		gotoxy(100,31); //if all words are typed correctly
		printf("Congrats!"); //moves to next level
		gotoxy(100,32);
		printf("LEVEL 2 COMPLETED!");
		gotoxy(100,33);
		printf("Moving to level 3......");
		Beep(500,900);
		Sleep(10000);
		ClearGame();
		return 3;
	}
	else{
		gotoxy(100,30);
		printf("LEVEL 2 FAILED");
		gotoxy(100,31);
		printf("Retry? (1/0)");
		Beep(900,900);
		d = getch();
		d = d-'0';
		ClearGame();
		if (d==1){
			*s -= oldscore;
			Elvl2(s);
		}
		else{
			return 0;
		}
	}

	
}
