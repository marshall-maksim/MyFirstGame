/* First simple game */

#include <stdio.h>
#include <locale.h>
#include <conio.h>      //для getch()
#include <stdlib.h>		//для rand() и RAND_MAX

int main(void){
	setlocale(LC_ALL, "Rus");
	char screen[20][31];       //игровое поле
	int x, y;
	int score = -1;				//счет (-1 инкрементируется в 0 при первой генерации координат цели)
	int xDog = 10, 				//текущиемкоординаты героя
		yDog = 10,				//
		bfr_xDog,				//предыдущие координаты героя
		bfr_yDog,				//
		xPurpose = xDog,		//координаты цели (при первой инициализации равны координатам 
		yPurpose = yDog;		//героя для правильного запуска их последующей генерации)
	char key;	
	int i;				//нажатая клавиша
	
	do{
		/*Инициализация границ игрового поля*/
		sprintf(screen[0], "#############################");          
		for(i = 1; i<20; i++){
			sprintf(screen[i], "#                           #");
		}
		sprintf(screen[19], "#############################");
		
		/*Задание координат героя*/
		bfr_xDog = xDog;
		bfr_yDog = yDog;
		if(key == 'w') xDog--;
		if(key == 's') xDog++;
		if(key == 'a') yDog--;
		if(key == 'd') yDog++;
		if(screen[xDog][yDog] == '#'){
			xDog = bfr_xDog;
			yDog = bfr_yDog;
		}
		
		screen[xDog][yDog] = '@';
		
		/*Задание координат цели*/
		if(xPurpose == xDog && yPurpose == yDog){
			score++;
			srand(time(NULL));
			xPurpose = rand()%18;
			yPurpose = rand()%28;
			if(xPurpose == 0) xPurpose++;
			if(yPurpose == 0) yPurpose++;
		}
		
		screen[xPurpose][yPurpose] = '*';
		
		system("cls");
		
		/*Вывод игрового поля на экран*/
		for(i = 0; i < 20; i++)									
			  printf("%s\n", screen[i]);
  			  printf("SCORE: %d", score);
  			  key = getch();
	} while(key  != 'q');
	

	printf("\n**********GAME OVER**********\n");
		
	return 0;
}
