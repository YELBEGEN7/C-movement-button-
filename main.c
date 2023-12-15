#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x-1, y-1};

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}

void movement_buttons(){
	int kontrol=0,tus,x=10,y=10;
	while(kontrol==0){
		tus=getch();
		if(tus==27){
			if(kontrol==0){
				kontrol++;
			}
			else if(kontrol==1){
				kontrol--;
			}
		}
		else if(tus==224){
			tus=getch();
			if(tus==77){
				x++;
				gotoxy(x,y);
			}
			else if(tus==75){
				x--;
				gotoxy(x,y);
			}
			else if(tus==80){
				y++;
				gotoxy(x,y);
			}
			else if(tus==72){
				y--;
				gotoxy(x,y);
			}
		}
	}
}

int main() {
	movement_buttons();
	return 0;
}
