#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#endif

#include <irrlicht.h>
#include <iostream> 
#include <windows.h>
#include <math.h>
#include <fstream>
#include <irrKlang.h>

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;

#pragma comment(lib, "irrKlang.lib")



using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace std;

#include "Ricevitore_Eventi.h"

int ritardo=100;
MyEventReceiver receiver; //DICHIARO IL RICEVITORE DI EVENTI
//CREO LA FINESTRA DEL GIOCO CON TUTTI I PARAMETRI COME LA RISOLUZIONE, IL NUMER DI BIT, LA MODALITà DI APERTURA, IMPOSTO SE DEVO 
//DISEGNARE O NO LE OMBRE, LA SINCRONIZZAZIONE VERTICALE E IL RICEVITORE DI EVENTI COLLEGATO ALLA FINESTRA
IrrlichtDevice* device = createDevice(video::EDT_OPENGL,core::dimension2d<s32>(1024, 768), 32, false, false, false, &receiver);
video::IVideoDriver*    driver = device->getVideoDriver();
scene::ISceneManager*	smgr = device->getSceneManager();
IGUIEnvironment* guienv = device->getGUIEnvironment();  

#include "Funzioni.add.h"
//#include "Gioco.add.h"	


int main()
{    
     //creiamo il device di irrklang, il motore che gestirà i suoni e la musica
     ISoundEngine* engine = createIrrKlangDevice();
	if (!engine)
	{
		printf("Could not startup engine\n");
		return 0; // error starting up the engine
	}

    engine->play2D("Music/menu.mp3", true);//faccio partire la musica del menu
     
     
    //CREO LA FINESTRA DEL GIOCO CON TUTTI I PARAMETRI COME LA RISOLUZIONE, IL NUMER DI BIT, LA MODALITà DI APERTURA, IMPOSTO SE DEVO 
    //DISEGNARE O NO LE OMBRE, LA SINCRONIZZAZIONE VERTICALE E IL RICEVITORE DI EVENTI COLLEGATO ALLA FINESTRA
	if (device == 0)
		return 1;
    device->getCursorControl()->setVisible(false);
    
	int lastFPS = -1;
    u32 then = device->getTimer()->getTime();
    const f32 MOVEMENT_SPEED = 5.f;
    
    device->setWindowCaption(L"Air Race");
    bool selezione;
    bool esci;
    //carico i valori di default dei parametri del gioco.
    char VOLUME, MUSIC, EFFECTS, SHADOWS, VIEW, RESOLUTION, MOVEMENT, RENDER;
    configurazione(VOLUME, MUSIC, EFFECTS, SHADOWS, VIEW, RESOLUTION, MOVEMENT, RENDER);
    #include "LoadTexture.add.h"	
	#include "Menu.add.h"
    	
	device->drop();	
	return 0;
}
