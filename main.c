#include <stdio.h>

#include <windows.h>


typedef char bool;
#define true 1
#define false 0


int IsAutoclicking(bool*, bool*, int*);

int main(){
	bool autoclicking = false;
	bool mode = false; //false for rate alternation (20~80 ms), true for fast rate (5 ms)
	int slot = 0;
	printf("Starting autoclicker...\n");
	while(true){
		Sleep(IsAutoclicking(&autoclicking, &mode, &slot));
		if(autoclicking){
			//press and release left button
			if(slot==1){
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}else if(slot==2){
				mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			}
		}
	}
    return 0;
}

int IsAutoclicking(bool* autoclicking, bool* mode, int* slot){
	*autoclicking = ( *autoclicking != (GetAsyncKeyState((int)'F')&0x00000001)>0 );
	*mode = ( *mode != (GetAsyncKeyState((int)'R')&0x00000001)>0 );
	if(*autoclicking){
		if((GetAsyncKeyState((int)'1')&0x00000001)>0){
			*slot = 1;
		}else if((GetAsyncKeyState((int)'2')&0x00000001)>0){
			*slot = 2;
		}
	}else{
		*slot = 0;
	}
	return *autoclicking ? (*mode ? rand()%60+20 : 10) : 10;
}
