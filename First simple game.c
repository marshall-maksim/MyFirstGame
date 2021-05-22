/* Chapter 4. Ex. 3 */

#include <stdio.h>
#include <locale.h>
#include <conio.h>

int main(void){
	setlocale(LC_ALL, "Rus");
	char screen[30][40];
	int x, y;
	int xDog = 15, 
		yDog = 20;
	char key;
	do
	{
		
		/*������� ������ �������� ����*/
		for (x = 0; x < 30; x++){
			for (y = 0; y < 40; y++){
				if(x == 0 || x == 29)
					 screen[x][y] = '#';
		 		 else if(y == 0 || y == 39)
		 		 	  screen[x][y] = '#';
	 	  		  else
	 	  		  	  screen[x][y] = ' ';
			}
		}
		
		/*������� ��������� �����*/
		if(key == 'w') xDog--;
		if(key == 's') xDog++;
		if(key == 'a') yDog--;
		if(key == 'd') yDog++;
		screen[xDog][yDog] = '@';
		
		/*���������� �����*/
		system("cls");                    //������� ������
		for(x = 0; x < 30; x++){
			for(y = 0; y < 40; y++){
				printf(" %c", screen[x][y]);
			}
			printf("\n");
		}
		
		key = getch();                //���������� ������� ������
		
	} while (key  != 'q');
	printf("\n***********************************GAME OVER************************************\n");
		
	return 0;
}
