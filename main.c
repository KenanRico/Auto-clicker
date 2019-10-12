#include <stdio.h>
#include <string.h>

#include <windows.h>


typedef char bool;
#define true 1
#define false 0


typedef struct _Attributes{
	bool autoclicking;
	bool mode;
	int button;
} Attributes;


//int IsAutoclicking(bool*, bool*, int*);
void DefineKeys(int*, int);
int IsAutoclicking(Attributes*, int const *);

int main(){
	printf("Starting autoclicker...\n");
	//def keys
	int keys[4];
	DefineKeys(&keys[0], 4);
	printf("%d %d %d %d\n", keys[0], keys[1], keys[2], keys[3]);
	//def autoclick attribs
	Attributes attribs = {false, false, 1};
	while(true){
		//Sleep(IsAutoclicking(&autoclicking, &mode, &button, ));
		Sleep(IsAutoclicking(&attribs, keys));
		if(attribs.autoclicking){
			//press and release left button
			if(attribs.button==1){
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}else if(attribs.button==2){
				mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			}
		}
	}
    return 0;
}

void DefineKeys(int* keys, int kc){
	FILE* file = fopen("./config/keyconf.conf", "r");
	char line[128];
	int length = sizeof(line);
	int i=0; 
	while(fgets(line, length, file) && i<kc){
		char opt[16];
		memcpy(opt, strtok(line, ":"), 15); opt[15] = '\0';
		char key[16];
		memcpy(key, strtok(NULL, ":"), 15); key[15] = '\0';
		int k = 0;
		if(strlen(key)==2){
			k = (int)key[0];
		}else{
			if(strcmp(key, "lshift\n")==0){
				k = VK_LSHIFT;
			}else if(strcmp(key, "lctrl\n")==0){
				k = VK_LCONTROL;
			}else if(strcmp(key, "mmiddle\n")==0){
				k = VK_MBUTTON;
			}
		}
		keys[i++] = k;
		printf("%s is set to 0x%x\n", opt, k);
	}
	fclose(file);
}

int IsAutoclicking(Attributes* attribs, int const * keys){
	attribs->autoclicking = ( attribs->autoclicking != ((GetAsyncKeyState(keys[0])&0x00000001)>0) );
	attribs->mode = ( attribs->mode != ((GetAsyncKeyState(keys[1])&0x00000001)>0) );
	if((GetAsyncKeyState(keys[2])&0x00000001)>0){
		attribs->button = 1;
	}else if((GetAsyncKeyState(keys[3])&0x00000001)>0){
		attribs->button = 2;
	}
	return attribs->autoclicking ? (attribs->mode ? 10 : rand()%80+100) : 10;
}
