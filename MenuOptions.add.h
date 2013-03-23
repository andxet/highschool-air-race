//questi menu gestiscono tutte le opzioni di sistema, come l'audio, il video o impostazioni come i tasti usati per muovere la macchina ecc.
//lo schema è lo stesso di tutti gli altri menu
//#include "Menu_Options.h"*******************************************************************
int opzione=0;
selezione=false;
bool indietro=false;
bool back=false;
esci=false;

while(device->run() && !esci && !indietro && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
{                                              
    device->getGUIEnvironment()->clear();
                        
    if (receiver.IsKeyDown(irr::KEY_LEFT))
        opzione--;
    else if(receiver.IsKeyDown(irr::KEY_RIGHT))
        opzione++;
    if (receiver.IsKeyDown(irr::KEY_RETURN) || (receiver.IsKeyDown(irr::KEY_DOWN) && opzione<3))
        selezione=true;
                        
    receiver.UpKey(irr::KEY_RETURN);
    receiver.UpKey(irr::KEY_ESCAPE);
    receiver.UpKey(irr::KEY_BACK);
                        
    if(opzione<0)
        opzione=5;
    if(opzione>5)
        opzione=0;
	device->getGUIEnvironment()->addImage(OPTIONS2,core::position2d<s32>(0,0));
	device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));

	switch(opzione){
		case 0:
			device->getGUIEnvironment()->addImage(OPTIONS_SOUND,core::position2d<s32>(50,150));
			device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
            if(selezione){
			//#include "Options_sound.h"*******************************************************************
				int sound=0;
				selezione=false;
				back=false;
				esci=false;
				while(device->run() && !esci && !back && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
				{                                              
					device->getGUIEnvironment()->clear();
					
					if (receiver.IsKeyDown(irr::KEY_UP))
						sound--;
					else if(receiver.IsKeyDown(irr::KEY_DOWN))
						sound++;
					if (receiver.IsKeyDown(irr::KEY_RETURN))
						selezione=true;
						
					receiver.UpKey(irr::KEY_RETURN);
					receiver.UpKey(irr::KEY_ESCAPE);
					receiver.UpKey(irr::KEY_BACK);
					
					if(sound>3)
						sound=3;
					device->getGUIEnvironment()->addImage(OPTIONS2,core::position2d<s32>(0,0));
					device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
					
					
					switch(VOLUME){
						case '0':
							device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(234,276));
							break;
						case '1':
							device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(258,276));
							device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(234,276));
							break;
						case '2':
							device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(282,276));
							device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(258,276));
							device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(234,276));
							break;
						case '3':
							device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(306,276));
							device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(282,276));
							device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(258,276));
							device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(234,276));
							break;
					}
					switch(MUSIC){
						case '0':
							device->getGUIEnvironment()->addImage(QUAD_NS_VUOTO,core::position2d<s32>(280,340));
							break;
						case '1':
							device->getGUIEnvironment()->addImage(QUAD_NS_PIENO,core::position2d<s32>(280,340));
							break;
					}
					switch(EFFECTS){
						case '0':
							device->getGUIEnvironment()->addImage(QUAD_NS_VUOTO,core::position2d<s32>(280,400));
							break;
						case '1':
							device->getGUIEnvironment()->addImage(QUAD_NS_PIENO,core::position2d<s32>(280,400));
							break;
					}
					
					switch(sound){
						case 0:
							back=true;                                
							break;
						case 1:
							device->getGUIEnvironment()->addImage(OPTIONS_SOUND_VOLUME,core::position2d<s32>(50,150));
							switch(VOLUME){
								case '0':
									device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(234,276));
									break;
								case '1':
									device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(258,276));
									device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(234,276));
									break;
								case '2':
									device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(282,276));
									device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(258,276));
									device->getGUIEnvironment()->addImage(QUAD_NS_AVANZAMENTO,core::position2d<s32>(234,276));
									break;
								case '3':
									device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(306,276));
									device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(282,276));
									device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(258,276));
									device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(234,276));
									break;
							}
							if(selezione){
							//#include "Options_sound_volume"*******************************************************************
								selezione=false;
								bool back2=false;
								esci=false;
								while(device->run() && !esci && !back2 && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
								{                                              
									device->getGUIEnvironment()->clear();
									
									if (receiver.IsKeyDown(irr::KEY_LEFT))
										VOLUME--;
									else if(receiver.IsKeyDown(irr::KEY_RIGHT))
										VOLUME++;
									if (receiver.IsKeyDown(irr::KEY_RETURN))
										selezione=true;
									
									if (receiver.IsKeyDown(irr::KEY_UP)){
										sound--;
										back2=true;
									}
									else if(receiver.IsKeyDown(irr::KEY_DOWN)){
										sound++;
										back2=true;
									}
										
									receiver.UpKey(irr::KEY_RETURN);
									receiver.UpKey(irr::KEY_ESCAPE);
									receiver.UpKey(irr::KEY_BACK);
									
									if(VOLUME<'0')
										VOLUME='0';
									if(VOLUME>'3')
										VOLUME='3';
										
									device->getGUIEnvironment()->addImage(OPTIONS2,core::position2d<s32>(0,0));
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									device->getGUIEnvironment()->addImage(OPTIONS_SOUND_VOLUME,core::position2d<s32>(50,150));
									
									switch(VOLUME){
										case '0':
											device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(234,276));
											break;
										case '1':
											device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(258,276));
											device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(234,276));
											break;
										case '2':
											device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(282,276));
											device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(258,276));
											device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(234,276));
											break;
										case '3':
											device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(306,276));
											device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(282,276));
											device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(258,276));
											device->getGUIEnvironment()->addImage(QUAD_S_AVANZAMENTO,core::position2d<s32>(234,276));
											break;
									}
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									driver->beginScene(true, true, video::SColor(255,113,113,133));
									smgr->drawAll();
									device->getGUIEnvironment()->drawAll();
									driver->endScene();
									Sleep(ritardo);
								}
								receiver.UpKey(irr::KEY_RETURN);
								selezione=false;
							}
							//******************************************************************************************
							break;
							
						case 2:
							device->getGUIEnvironment()->addImage(OPTIONS_SOUND_MUSIC,core::position2d<s32>(50,150));
							switch(MUSIC){
								case '0':
									device->getGUIEnvironment()->addImage(QUAD_NS_VUOTO,core::position2d<s32>(280,340));
									break;
								case '1':
									device->getGUIEnvironment()->addImage(QUAD_NS_PIENO,core::position2d<s32>(280,340));
									break;
							}
							if(selezione){
							//#include "Options_sound_music"*******************************************************************
							
								selezione=false;
								bool back2=false;
								esci=false;
								while(device->run() && !esci && !back2 && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
								{                                              
									device->getGUIEnvironment()->clear();
									
									if (receiver.IsKeyDown(irr::KEY_RETURN)){
										selezione=true;
										MUSIC++;
                                    }
									
									if (receiver.IsKeyDown(irr::KEY_UP)){
										sound--;
										back2=true;
									}
									else if(receiver.IsKeyDown(irr::KEY_DOWN)){
										sound++;
										back2=true;
									}
										
									receiver.UpKey(irr::KEY_RETURN);
									receiver.UpKey(irr::KEY_ESCAPE);
									receiver.UpKey(irr::KEY_BACK);
									
									if(MUSIC>'1')
										MUSIC='0';
										
									device->getGUIEnvironment()->addImage(OPTIONS2,core::position2d<s32>(0,0));
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									device->getGUIEnvironment()->addImage(OPTIONS_SOUND_MUSIC,core::position2d<s32>(50,150));
									
									switch(MUSIC){
										case '0':
											device->getGUIEnvironment()->addImage(QUAD_S_VUOTO,core::position2d<s32>(280,340));
											break;
										case '1':
											device->getGUIEnvironment()->addImage(QUAD_S_PIENO,core::position2d<s32>(280,340));
											break;
									}
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									driver->beginScene(true, true, video::SColor(255,113,113,133));
									smgr->drawAll();
									device->getGUIEnvironment()->drawAll();
									driver->endScene();
									Sleep(ritardo);
								}
								receiver.UpKey(irr::KEY_RETURN);
								selezione=false;
							}
							//******************************************************************************************
							break;
						case 3:
							device->getGUIEnvironment()->addImage(OPTIONS_SOUND_EFFECTS,core::position2d<s32>(50,150));
							switch(EFFECTS){
								case '0':
									device->getGUIEnvironment()->addImage(QUAD_NS_VUOTO,core::position2d<s32>(280,400));
									break;
								case '1':
									device->getGUIEnvironment()->addImage(QUAD_NS_PIENO,core::position2d<s32>(280,400));
									break;
							}
							if(selezione){
								selezione=false;
                                bool back2=false;
								esci=false;
								while(device->run() && !esci && !back2 && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
								{                                              
									device->getGUIEnvironment()->clear();
									
									if (receiver.IsKeyDown(irr::KEY_RETURN)){
										selezione=true;
										EFFECTS++;
                                    }
									
									if (receiver.IsKeyDown(irr::KEY_UP)){
										sound--;
										back2=true;
									}
									else if(receiver.IsKeyDown(irr::KEY_DOWN)){
										sound++;
										back2=true;
									}
										
									receiver.UpKey(irr::KEY_RETURN);
									receiver.UpKey(irr::KEY_ESCAPE);
									receiver.UpKey(irr::KEY_BACK);
									
									if(EFFECTS>'1')
										EFFECTS='0';
										
									device->getGUIEnvironment()->addImage(OPTIONS2,core::position2d<s32>(0,0));
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									device->getGUIEnvironment()->addImage(OPTIONS_SOUND_MUSIC,core::position2d<s32>(50,150));
									
									switch(EFFECTS){
										case '0':
											device->getGUIEnvironment()->addImage(QUAD_S_VUOTO,core::position2d<s32>(280,400));
											break;
										case '1':
											device->getGUIEnvironment()->addImage(QUAD_S_PIENO,core::position2d<s32>(280,400));
											break;
									}
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									driver->beginScene(true, true, video::SColor(255,113,113,133));
									smgr->drawAll();
									device->getGUIEnvironment()->drawAll();
									driver->endScene();
									Sleep(ritardo);
								}
								receiver.UpKey(irr::KEY_RETURN);
								selezione=false;
							}
							//******************************************************************************************
							break;
					}
					device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
					driver->beginScene(true, true, video::SColor(255,113,113,133));
					smgr->drawAll();
					device->getGUIEnvironment()->drawAll();
					driver->endScene();
					Sleep(ritardo);
				}
				receiver.UpKey(irr::KEY_RETURN);
				selezione=false;
				
			}
			//******************************************************************************************                                
            break;
        case 1:
            device->getGUIEnvironment()->addImage(OPTIONS_SCREEN,core::position2d<s32>(358,150));
			
			if(selezione)
			{
			//#include "Options_screen.h"*******************************************************************
				int screen=0;
				selezione=false;
				/*indietro*/back=false;
				esci=false;
				while(device->run() && !esci && !back && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
				{                                              
					device->getGUIEnvironment()->clear();
					
					if (receiver.IsKeyDown(irr::KEY_UP))
						screen--;
					else if(receiver.IsKeyDown(irr::KEY_DOWN))
						screen++;
					if (receiver.IsKeyDown(irr::KEY_RETURN))
						selezione=true;
						
					receiver.UpKey(irr::KEY_RETURN);
					receiver.UpKey(irr::KEY_ESCAPE);
					receiver.UpKey(irr::KEY_BACK);
					
					if(screen>7)
						screen=7;
						
					device->getGUIEnvironment()->addImage(OPTIONS2,core::position2d<s32>(0,0));
					
					if(SHADOWS=='0')
						device->getGUIEnvironment()->addImage(QUAD_NS_VUOTO,core::position2d<s32>(620,275));
                    else
                        device->getGUIEnvironment()->addImage(QUAD_NS_PIENO,core::position2d<s32>(620,275));
                        
                    if(VIEW=='0')
						device->getGUIEnvironment()->addImage(QUAD_MULTI_NS,core::position2d<s32>(620,370));
                    else
                        device->getGUIEnvironment()->addImage(QUAD_MULTI_NS,core::position2d<s32>(620,405));
                    
                    switch(RESOLUTION){
						case '0':
							device->getGUIEnvironment()->addImage(QUAD_MULTI_NS,core::position2d<s32>(620,370));
                    }
					
					switch(screen){
						case 0:
							back=true;                                
							break;
						case 1:
							device->getGUIEnvironment()->addImage(OPTIONS_SCREEN_SHADOWS,core::position2d<s32>(358,150));
							if(SHADOWS=='0')
        						device->getGUIEnvironment()->addImage(QUAD_NS_VUOTO,core::position2d<s32>(620,275));
                            else
                                device->getGUIEnvironment()->addImage(QUAD_NS_PIENO,core::position2d<s32>(620,275));
                                
                            if(selezione){
								selezione=false;
                                bool back2=false;
								esci=false;
								while(device->run() && !esci && !back2 && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
								{                                              
									device->getGUIEnvironment()->clear();
									
									if (receiver.IsKeyDown(irr::KEY_RETURN)){
										selezione=true;
										SHADOWS++;
                                    }
									
									if (receiver.IsKeyDown(irr::KEY_UP)){
										screen--;
										back2=true;
									}
									else if(receiver.IsKeyDown(irr::KEY_DOWN)){
										screen++;
										back2=true;
									}
										
									receiver.UpKey(irr::KEY_RETURN);
									receiver.UpKey(irr::KEY_ESCAPE);
									receiver.UpKey(irr::KEY_BACK);
									
									if(SHADOWS>'1')
										SHADOWS='0';
										
									device->getGUIEnvironment()->addImage(OPTIONS2,core::position2d<s32>(0,0));
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									device->getGUIEnvironment()->addImage(OPTIONS_SCREEN_SHADOWS,core::position2d<s32>(358,150));
									
									switch(SHADOWS){
										case '0':
											device->getGUIEnvironment()->addImage(QUAD_S_VUOTO,core::position2d<s32>(620,275));
											break;
										case '1':
											device->getGUIEnvironment()->addImage(QUAD_S_PIENO,core::position2d<s32>(620,275));
											break;
									}
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									driver->beginScene(true, true, video::SColor(255,113,113,133));
									smgr->drawAll();
									device->getGUIEnvironment()->drawAll();
									driver->endScene();
									Sleep(ritardo);
								}
								receiver.UpKey(irr::KEY_RETURN);
								selezione=false;
                            }
							break;
						case 2:
							device->getGUIEnvironment()->addImage(OPTIONS_SCREEN_FULL,core::position2d<s32>(358,150));
							if(VIEW=='0')
    						    device->getGUIEnvironment()->addImage(QUAD_MULTI_NS,core::position2d<s32>(620,370));
                            else
                                device->getGUIEnvironment()->addImage(QUAD_MULTI_NS,core::position2d<s32>(620,405));
							if(selezione){
								selezione=false;
                                bool back2=false;
								esci=false;
								while(device->run() && !esci && !back2 && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
								{                                              
									device->getGUIEnvironment()->clear();
									
									if (receiver.IsKeyDown(irr::KEY_RETURN)){
										selezione=true;
										VIEW='0';
                                    }
									
									if (receiver.IsKeyDown(irr::KEY_UP)){
										screen--;
										back2=true;
									}
									else if(receiver.IsKeyDown(irr::KEY_DOWN)){
										screen++;
										back2=true;
									}
										
									receiver.UpKey(irr::KEY_RETURN);
									receiver.UpKey(irr::KEY_ESCAPE);
									receiver.UpKey(irr::KEY_BACK);
										
									device->getGUIEnvironment()->addImage(OPTIONS2,core::position2d<s32>(0,0));
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									device->getGUIEnvironment()->addImage(OPTIONS_SCREEN_FULL,core::position2d<s32>(358,150));
									
									switch(VIEW){
										case '0':
											device->getGUIEnvironment()->addImage(QUAD_MULTI_S,core::position2d<s32>(620,370));
											break;
										case '1':
											device->getGUIEnvironment()->addImage(QUAD_MULTI_NS,core::position2d<s32>(620,405));
											break;
									}
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									driver->beginScene(true, true, video::SColor(255,113,113,133));
									smgr->drawAll();
									device->getGUIEnvironment()->drawAll();
									driver->endScene();
									Sleep(ritardo);
								}
								receiver.UpKey(irr::KEY_RETURN);
								selezione=false;
                            }
							break;
						case 3:
							device->getGUIEnvironment()->addImage(OPTIONS_SCREEN_WINDOW,core::position2d<s32>(358,150));
							if(VIEW=='0')
    						    device->getGUIEnvironment()->addImage(QUAD_MULTI_NS,core::position2d<s32>(620,405));
                            else
                                device->getGUIEnvironment()->addImage(QUAD_MULTI_NS,core::position2d<s32>(620,370));
							if(selezione){
								selezione=false;
                                bool back2=false;
								esci=false;
								while(device->run() && !esci && !back2 && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
								{                                              
									device->getGUIEnvironment()->clear();
									
									if (receiver.IsKeyDown(irr::KEY_RETURN)){
										selezione=true;
										VIEW='1';
                                    }
									
									if (receiver.IsKeyDown(irr::KEY_UP)){
										screen--;
										back2=true;
									}
									else if(receiver.IsKeyDown(irr::KEY_DOWN)){
										screen++;
										back2=true;
									}
										
									receiver.UpKey(irr::KEY_RETURN);
									receiver.UpKey(irr::KEY_ESCAPE);
									receiver.UpKey(irr::KEY_BACK);
									
										
									device->getGUIEnvironment()->addImage(OPTIONS2,core::position2d<s32>(0,0));
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									device->getGUIEnvironment()->addImage(OPTIONS_SCREEN_WINDOW,core::position2d<s32>(358,150));
									
									switch(VIEW){
										case '0':
											device->getGUIEnvironment()->addImage(QUAD_MULTI_S,core::position2d<s32>(620,405));
											break;
										case '1':
											device->getGUIEnvironment()->addImage(QUAD_MULTI_NS,core::position2d<s32>(620,370));
											break;
									}
									device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
									driver->beginScene(true, true, video::SColor(255,113,113,133));
									smgr->drawAll();
									device->getGUIEnvironment()->drawAll();
									driver->endScene();
									Sleep(ritardo);
								}
								receiver.UpKey(irr::KEY_RETURN);
								selezione=false;
                            }
							break;
						case 4:
							device->getGUIEnvironment()->addImage(OPTIONS_SCREEN_800,core::position2d<s32>(358,150));
							//if(selezione)
							break;
						case 5:
							device->getGUIEnvironment()->addImage(OPTIONS_SCREEN_1024,core::position2d<s32>(358,150));
							//if(selezione)
							break;
						case 6:
							device->getGUIEnvironment()->addImage(OPTIONS_SCREEN_1280,core::position2d<s32>(358,150));
							//if(selezione)
							break;
						case 7:
							device->getGUIEnvironment()->addImage(OPTIONS_SCREEN_1600,core::position2d<s32>(358,150));
							//if(selezione)
							break;
					}
					device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
					driver->beginScene(true, true, video::SColor(255,113,113,133));
					smgr->drawAll();
					device->getGUIEnvironment()->drawAll();
					driver->endScene();
					Sleep(ritardo);
				}
				receiver.UpKey(irr::KEY_RETURN);
				selezione=false;
			}
			
			//******************************************************************************************  
            break;
        case 2:
            device->getGUIEnvironment()->addImage(OPTIONS_SETTINGS,core::position2d<s32>(666,150));
			if (selezione){
				//#include "Options_settings.h"*******************************************************************
				int settings=0;
				selezione=false;
				back=false;
				esci=false;
				while(device->run() && !esci && !back && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
				{                                              
					device->getGUIEnvironment()->clear();
					
					if (receiver.IsKeyDown(irr::KEY_UP))
						settings--;
					else if(receiver.IsKeyDown(irr::KEY_DOWN))
						settings++;
					if (receiver.IsKeyDown(irr::KEY_RETURN))
						selezione=true;
						
					receiver.UpKey(irr::KEY_RETURN);
					receiver.UpKey(irr::KEY_ESCAPE);
					receiver.UpKey(irr::KEY_BACK);
											
					if(settings>5)
						settings=5;
					device->getGUIEnvironment()->addImage(OPTIONS2,core::position2d<s32>(0,0));
					
					switch(settings){
						case 0:
							back=true;                               
							break;
						case 1:
							device->getGUIEnvironment()->addImage(OPTIONS_SETTINGS_ARROWS,core::position2d<s32>(666,150));
							break;
						case 2:
							device->getGUIEnvironment()->addImage(OPTIONS_SETTINGS_WASD,core::position2d<s32>(666,150));
							//if(selezione)
							break;
						case 3:
							device->getGUIEnvironment()->addImage(OPTIONS_SETTINGS_OGL,core::position2d<s32>(666,150));
							if(selezione)
								back=true;
							break;
						case 4:
							device->getGUIEnvironment()->addImage(OPTIONS_SETTINGS_DX8,core::position2d<s32>(666,150));
							//if(selezione)
							break;
						case 5:
							device->getGUIEnvironment()->addImage(OPTIONS_SETTINGS_DX9,core::position2d<s32>(666,150));
							//if(selezione)
							break;
					}
					device->getGUIEnvironment()->addImage(OPTIONS_MENU,core::position2d<s32>(0,668));
					driver->beginScene(true, true, video::SColor(255,113,113,133));
					smgr->drawAll();
					device->getGUIEnvironment()->drawAll();
					driver->endScene();
					Sleep(ritardo);
				}
				receiver.UpKey(irr::KEY_RETURN);
				selezione=false;
			}
			
			//******************************************************************************************  
			break;
        case 3:
            device->getGUIEnvironment()->addImage(OPTIONS_BACK,core::position2d<s32>(0,668));
            if(selezione)
                indietro=true;
            break;
        case 4:
            device->getGUIEnvironment()->addImage(OPTIONS_SAVE,core::position2d<s32>(0,668));
            if(selezione){
                /*core::string str1=VOLUME+MUISC+EFFECTS+SHADOWS+VIEW+RESOLUTION+MOVEMENT+RENDER;
                char *str[2] = {"config.txt",str1.c_str()};
                scrivi(2,str);*/
                selezione=false;
			}
            break;
        case 5:
            device->getGUIEnvironment()->addImage(OPTIONS_DEFAULT,core::position2d<s32>(0,668));
            if(selezione){
				char *str[2] = {"config.txt","2\n1\n1\n1\n1\n2\n2\n3"};
                scrivi(2,str);
                selezione=false;
                configurazione(VOLUME, MUSIC, EFFECTS, SHADOWS, VIEW, RESOLUTION, MOVEMENT, RENDER);
			}
            break;
    }
    driver->beginScene(true, true, video::SColor(255,113,113,133));
    smgr->drawAll();
    device->getGUIEnvironment()->drawAll();
    driver->endScene();
    Sleep(ritardo);
}
