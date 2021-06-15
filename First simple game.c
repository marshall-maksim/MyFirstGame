/* First simple game */

#include <stdio.h>
#include <locale.h>
#include <conio.h>      //��� getch()
#include <stdlib.h>		//��� rand() � RAND_MAX

int main(void){
	setlocale(LC_ALL, "Rus");
	char screen[20][31];       //������� ����
	int x, y;
	int score = -1;				//���� (-1 ���������������� � 0 ��� ������ ��������� ��������� ����)
	int xDog = 10, 				//������������������ �����
		yDog = 10,				//
		bfr_xDog,				//���������� ���������� �����
		bfr_yDog,				//
		xPurpose = xDog,		//���������� ���� (��� ������ ������������� ����� ����������� 
		yPurpose = yDog;		//����� ��� ����������� ������� �� ����������� ���������)
	char key;	
	int i;				//������� �������
	
	do{
		/*������������� ������ �������� ����*/
		sprintf(screen[0], "#############################");          
		for(i = 1; i<20; i++){
			sprintf(screen[i], "#                           #");
		}
		sprintf(screen[19], "#############################");
		
		/*������� ��������� �����*/
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
		
		/*������� ��������� ����*/
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
		
		/*����� �������� ���� �� �����*/
		for(i = 0; i < 20; i++)									
			  printf("%s\n", screen[i]);
  			  printf("SCORE: %d", score);
  			  key = getch();
	} while(key  != 'q');
	

	printf("\n**********GAME OVER**********\n");
		
	return 0;
}
