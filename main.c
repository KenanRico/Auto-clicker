#include <stdio.h>

#include <windows.h>


typedef char bool;
#define true 1
#define false 0


bool ContextIsMinecraft();
int IsAutoclicking(bool*, int*);

int main(){
	bool autoclicking = false;
	int slot = 0;
	printf("Starting autoclicker...\n");
	while(true){
		Sleep(IsAutoclicking(&autoclicking, &slot));
		if(ContextIsMinecraft()&&autoclicking){
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

bool ContextIsMinecraft(){
	return (GetForegroundWindow()==FindWindowA(NULL, "Minecraft 1.13.2"));
}

int IsAutoclicking(bool* autoclicking, int* slot){
	*autoclicking = ( *autoclicking != (GetAsyncKeyState((int)'F')&0x00000001)>0 );
	if(*autoclicking){
		if((GetAsyncKeyState((int)'1')&0x00000001)>0){
			*slot = 1;
		}else if((GetAsyncKeyState((int)'2')&0x00000001)>0){
			*slot = 2;
		}
	}else{
		*slot = 0;
	}
	return *autoclicking ? rand()%40+150 : 10;
}
