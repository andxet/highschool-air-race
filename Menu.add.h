
//un metodo funzionale per costruire un'interfaccia grafica è quella di utilizzare una serie di immagini.
// ogni volta che l'utente preme un tasto, questo visualizza l'immagine desiderata.
int menu=0;
    // le variabili selezione ed esci verranno utilizzati anche da tutti gli altri sottomenu creati dopo.
    //per questo motivo prima di ogni utilizzo di selezione bisogna portarla a falso
    //per quanto riguarda esci in tutti i cicli dei menu, sarà un fattore di uscita dal ciclo
    selezione=false;
    esci=false;
    //faccio partire il ciclo della schermata che voglio visualizzare e una variabile menu carica 
    //l'immagine giusta in base al valore che contiene. tutti i menu seguiranno questo schema.
	while(device->run() && !esci && !receiver.IsKeyDown(irr::KEY_ESCAPE))
	{                                              
        device->getGUIEnvironment()->clear();
        if (receiver.IsKeyDown(irr::KEY_UP))
			menu--;
        else if(receiver.IsKeyDown(irr::KEY_DOWN))
            menu++;
        if (receiver.IsKeyDown(irr::KEY_RETURN))
			selezione=true;
			
	    receiver.UpKey(irr::KEY_RETURN);
        receiver.UpKey(irr::KEY_ESCAPE);
        receiver.UpKey(irr::KEY_BACK);
        
        if(menu<0)
            menu=3;
        if(menu>3)
            menu=0;
        device->getGUIEnvironment()->addImage(MENU,core::position2d<s32>(0,0));   
        switch(menu){
            case 0:
                device->getGUIEnvironment()->addImage(MENU_PLAY,core::position2d<s32>(724,0));
                if (selezione)
				{
                 //un sottomenu è costruito allo stesso identico modo del menu principale. è stato incluso in un file
                 //per allegerire un po' la lettura del codice
                 #include "Menu_Play.add.h"
                }
                selezione=false;
                //******************************************************************************************
                break;
            case 1:
                device->getGUIEnvironment()->addImage(MENU_OPTIONS,core::position2d<s32>(724,0));
                if(selezione)
				{
				 #include "MenuOptions.add.h"
                }
                selezione=false;
                //******************************************************************************************
                break;
            case 2:
                device->getGUIEnvironment()->addImage(MENU_CREDITS,core::position2d<s32>(724,0));
                if(selezione)
					selezione=false;
                //#include "Menu_Credits.h"
                break;
            case 3:
                device->getGUIEnvironment()->addImage(MENU_QUIT,core::position2d<s32>(724,0));
                if(selezione)
					esci=true;
        }
		
	driver->beginScene(true, true, video::SColor(255,113,113,133));
	smgr->drawAll();
	device->getGUIEnvironment()->drawAll();
	driver->endScene();
	Sleep(ritardo);
	}
