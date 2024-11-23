#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <ogc/pad.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

int main(int argc, char **argv) {
	// Some initializing stuff
	// -------------------------------------------
	VIDEO_Init();
	WPAD_Init();
	PAD_Init();
	rmode = VIDEO_GetPreferredMode(NULL);
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(xfb);
	VIDEO_SetBlack(false);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
	printf("\x1b[2;0H");
	int homebutton = 0;
	int nunchuck = 0;
	int classic = 0;
	int gh3 = 0;
    // -------------------------------------------
	printf("Text-based Controller Test v1.3\n");
	printf("Welcome! This is a simple app that allows you to test your controllers!\n");
	printf("Press the HOME button 3 times to exit.\n");

	while(1) {
		WPAD_ScanPads();
		PAD_ScanPads();
		
		u32 pressed = WPAD_ButtonsDown(0);
		u16 gcpressed = PAD_ButtonsDown(0);
		u32 exp_type;
        WPAD_Probe(0, &exp_type);

		if(exp_type == WPAD_EXP_NUNCHUK) {
			if(nunchuck == 0) {
				nunchuck++;
				printf("Nunchuck connected!\n");
			}
			
			if(pressed & WPAD_NUNCHUK_BUTTON_C) {
				printf("Nunchuck: Button C pressed.\n");
			}
			
			if(pressed & WPAD_NUNCHUK_BUTTON_Z) {
				printf("Nunchuck: Button Z pressed.\n");
			}
		}
			
		if(exp_type == WPAD_EXP_CLASSIC) {
			if(classic == 0) {
				classic++;
				printf("Classic Controller connected!\n");
			}
				
				
			if(pressed & WPAD_CLASSIC_BUTTON_UP) {
				printf("Classic Controller: Button up pressed.\n");
			}
				
			if(pressed & WPAD_CLASSIC_BUTTON_DOWN) {
				printf("Classic Controller: Button down pressed.\n");
			}
				
			if(pressed & WPAD_CLASSIC_BUTTON_LEFT) {
				printf("Classic Controller: Button left pressed.\n");
			}
			
			if(pressed & WPAD_CLASSIC_BUTTON_RIGHT) {
				printf("Classic Controller: Button right pressed.\n");
			}
				
			if(pressed & WPAD_CLASSIC_BUTTON_A) {
				printf("Classic Controller: Button A pressed.\n");
			}
			
			if(pressed & WPAD_CLASSIC_BUTTON_B) {
				printf("Classic Controller: Button B pressed.\n");
			}
			
			if(pressed & WPAD_CLASSIC_BUTTON_X) {
				printf("Classic Controller: Button X pressed.\n");
			}
			
			if(pressed & WPAD_CLASSIC_BUTTON_Y) {
				printf("Classic Controller: Button Y pressed.\n");
			}
			
			if(pressed & WPAD_CLASSIC_BUTTON_FULL_L) {
				printf("Classic Controller: L trigger pressed.\n");
			}
				
			if(pressed & WPAD_CLASSIC_BUTTON_FULL_R) {
				printf("Classic Controller: R trigger pressed.\n");
			}
			
			if(pressed & WPAD_CLASSIC_BUTTON_ZL) {
				printf("Classic Controller: ZL trigger pressed.\n");
			}
			
			if(pressed & WPAD_CLASSIC_BUTTON_ZR) {
				printf("Classic Controller: ZR trigger pressed.\n");
			}
			
			if(pressed & WPAD_CLASSIC_BUTTON_PLUS) {
				printf("Classic Controller: Button + pressed.\n");
			}
			
			if(pressed & WPAD_CLASSIC_BUTTON_MINUS) {
				printf("Classic Controller: Button - pressed.\n");
			}
				
			if(pressed & WPAD_CLASSIC_BUTTON_HOME) {
				printf("Classic Controller: HOME button pressed.\n");
				homebutton++;
				if (homebutton == 3) {
					printf("exiting...\n");
					exit(0);
				}
			}
		}
		
		if(exp_type == WPAD_EXP_GUITARHERO3) {
			if(gh3 == 0) {
				gh3++;
				printf("Guitar connected!\n");
			}
			
			if(pressed & WPAD_GUITAR_HERO_3_BUTTON_STRUM_UP) {
				printf("Guitar Hero 3 Controller: Button up pressed.\n");
			}
			
			if(pressed & WPAD_GUITAR_HERO_3_BUTTON_STRUM_DOWN) {
				printf("Guitar Hero 3 Controller: Button down pressed.\n");
			}
			
			if(pressed & WPAD_GUITAR_HERO_3_BUTTON_PLUS) {
				printf("Guitar Hero 3 Controller: Button + pressed.\n");
			}
			
			if(pressed & WPAD_GUITAR_HERO_3_BUTTON_MINUS) {
				printf("Guitar Hero 3 Controller: Button - pressed.\n");
			}
			
			if(pressed & WPAD_GUITAR_HERO_3_BUTTON_ORANGE) {
				printf("Guitar Hero 3 Controller: Orange button pressed.\n");
			}
			
			if(pressed & WPAD_GUITAR_HERO_3_BUTTON_RED) {
				printf("Guitar Hero 3 Controller: Red button pressed.\n");
			}
			
			if(pressed & WPAD_GUITAR_HERO_3_BUTTON_YELLOW) {
				printf("Guitar Hero 3 Controller: Yellow button pressed.\n");
			}
			
			if(pressed & WPAD_GUITAR_HERO_3_BUTTON_BLUE) {
				printf("Guitar Hero 3 Controller: Blue button pressed.\n");
			}
			
			if(pressed & WPAD_GUITAR_HERO_3_BUTTON_GREEN) {
				printf("Guitar Hero 3 Controller: Green button pressed.\n");
			}
		}
		
		
		if(gcpressed & PAD_BUTTON_A) {
			printf("GameCube Controller: Button A pressed.\n");
		}
		
		if(gcpressed & PAD_BUTTON_B) {
			printf("GameCube Controller: Button B pressed.\n");
		}
		
		if(gcpressed & PAD_BUTTON_X) {
			printf("GameCube Controller: Button X pressed.\n");
		}
		
		if(gcpressed & PAD_TRIGGER_Z) {
			printf("GameCube Controller: Z trigger pressed.\n");
		}

		if(gcpressed & PAD_BUTTON_Y) {
			printf("GameCube Controller: Button Y pressed.\n");
		}
		
		if(gcpressed & PAD_TRIGGER_L) {
			printf("GameCube Controller: L trigger pressed.\n");
		}
		
		if(gcpressed & PAD_TRIGGER_R) {
			printf("GameCube Controller: R trigger pressed.\n");
		}
		
		if(gcpressed & PAD_BUTTON_UP) {
			printf("GameCube Controller: Button up pressed.\n");
		}
		
		if(gcpressed & PAD_BUTTON_DOWN) {
			printf("GameCube Controller: Button down pressed.\n");
		}
		
		if(gcpressed & PAD_BUTTON_LEFT) {
			printf("GameCube Controller: Button left pressed.\n");
		}
		
		if(gcpressed & PAD_BUTTON_RIGHT) {
			printf("GameCube Controller: Button right pressed.\n");
		}
		
		if(gcpressed & PAD_BUTTON_START) {
			printf("GameCube Controller: Start button pressed.\n");
		}
		
		if(pressed & WPAD_BUTTON_A) {
			printf("Wiimote: Button A pressed.\n");
		}
	
		if(pressed & WPAD_BUTTON_B) {
			printf("Wiimote: Button B pressed.\n");
		}
		
		if(pressed & WPAD_BUTTON_1) {
			printf("Wiimote: Button 1 pressed.\n");
		}
		
		if(pressed & WPAD_BUTTON_2) {
			printf("Wiimote: Button 2 pressed.\n");
		}
		
		if(pressed & WPAD_BUTTON_MINUS) {
			printf("Wiimote: Button - pressed.\n");
		}
		
		if(pressed & WPAD_BUTTON_PLUS) {
			printf("Wiimote: Button + pressed.\n");
		}
		
		if(pressed & WPAD_BUTTON_HOME) {
			printf("Wiimote: HOME button pressed.\n");
			homebutton++;
			if (homebutton == 3) {
				printf("exiting...\n");
				exit(0);
			}
		}
		
		if(pressed & WPAD_BUTTON_UP) {
			printf("Wiimote: Button up pressed.\n");
		}
		
		if(pressed & WPAD_BUTTON_DOWN) {
			printf("Wiimote: Button down pressed.\n");
		}
		
		if(pressed & WPAD_BUTTON_LEFT) {
			printf("Wiimote: Button left pressed.\n");
		}
		
		if(pressed & WPAD_BUTTON_RIGHT) {
			printf("Wiimote: Button right pressed.\n");
		}
            
		VIDEO_WaitVSync();
			
			
        
	}
	
	// we should never get here. this is just to make the compiler happy.
	return 0;
}
