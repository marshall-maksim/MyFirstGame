/* First simple game */

#include <stdio.h>
#include <locale.h>
#include <conio.h>      //��� getch()
#include <stdlib.h>		//��� rand() � RAND_MAX

#define DOG_START_X 10
#define DOG_START_Y 10

char screen[20][31];       //������� ����
int score = -1;            //���� (-1 ���������������� � 0 ��� ������ ��������� ��������� ����)
typedef struct {       //Unit - ������ �� ������� ����
		int x;
		int y;
}Unit;

Unit Dog = {DOG_START_X, DOG_START_Y};				//�����
Unit BfrDog;               							//���������� ��������� �����
Unit Purpose = {DOG_START_X, DOG_START_Y};			//����			
	
void InitMap(void); 
void SetDog(void);	
void SetPurpose(void);	
void ShowMap(void);	
	
char key;					//������� �������
int i;	
			
int main(void){
	setlocale(LC_ALL, "Rus");
	do{
		InitMap();
		SetDog();
		SetPurpose();
		
		system("cls");
		
		ShowMap();
		
	 	key = getch();
	} while(key  != 'q');
	

	printf("\n**********GAME OVER**********\n");
		
	return 0;
}


/*������������� �������� ����*/
void InitMap()
{
	sprintf(screen[0], "#############################");          
		for(i = 1; i<20; i++){
			sprintf(screen[i], "#                           #");
		}
	sprintf(screen[19], "#############################");
}


/*������� ��������� �����*/
void SetDog()
{
	BfrDog.x = Dog.x;
	BfrDog.y = Dog.y;
	if(key == 'w') Dog.x--;
	if(key == 's') Dog.x++;
	if(key == 'a') Dog.y--;
	if(key == 'd') Dog.y++;
	if(screen[Dog.x][Dog.x] == '#'){
		Dog.x = BfrDog.x;
		Dog.y = BfrDog.y;
	}
	screen[Dog.x][Dog.y] = '@';
}


/*������� ��������� ����*/
void SetPurpose()
{
	if(Purpose.x == Dog.x && Purpose.y == Dog.y){
			score++;
			srand(time(NULL));
			Purpose.x = rand()%18;
			Purpose.y = rand()%28;
			if(Purpose.x == 0) Purpose.x++;
			if(Purpose.y == 0) Purpose.y++;
	}
	screen[Purpose.x][Purpose.y] = '*';
}


/*����������� �������� ���� �� ������*/
void ShowMap()
{
 	 for(i = 0; i < 20; i++)									
		 printf("%s\n", screen[i]);
	printf("SCORE: %d", score);
}
