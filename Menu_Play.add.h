int gioca=0;
selezione=false;
bool indietro=false;
                    
while(device->run() && !esci && !indietro && !receiver.IsKeyDown(irr::KEY_ESCAPE) && !receiver.IsKeyDown(irr::KEY_BACK))
{                                              
    device->getGUIEnvironment()->clear();
                        
    if (receiver.IsKeyDown(irr::KEY_UP))
        gioca--;
    else if(receiver.IsKeyDown(irr::KEY_DOWN))
        gioca++;
    if (receiver.IsKeyDown(irr::KEY_RETURN))
        selezione=true;
                        
    receiver.UpKey(irr::KEY_RETURN);
    receiver.UpKey(irr::KEY_ESCAPE);
    receiver.UpKey(irr::KEY_BACK);
                        
    if(gioca<0)
        gioca=3;
    if(gioca>3)
        gioca=0;
    device->getGUIEnvironment()->addImage(PLAY,core::position2d<s32>(0,0));               
    switch(gioca){
                  case 0:
                       device->getGUIEnvironment()->addImage(PLAY_TIME_ATTACK,core::position2d<s32>(724,0));
					   if(selezione){
                                     
                            device->getGUIEnvironment()->clear();
                            engine->stopAllSounds();
                            
                            int ris=0, macchina=0, pista=1, vite=0;
                            
                            
                            macchina=scegli();
                            
                            if(macchina!=-1)
                            {
                             macchina++;                        
                             do{
                                switch (pista)
							    {
                                 case 1:
                                  engine->play2D("Music/Livello1.ogg", true);
                                 break;
                                 case 2:
                                  engine->play2D("Music/Livello2.mp3", true);
                                 break;
                                 case 3:
                                  engine->play2D("Music/Livello3.mp3", true);
                                 break;
                                };

                                
							    ris=gioco(macchina,pista,gioca,vite);//0perso, 1 vinto,2 uscito x volere dell'utente
							    if(ris==1)
							     pista++;
							    
							    engine->stopAllSounds();
							    
							   }while(ris!=2&&pista<=3);
							 
							 engine->play2D("Music/Menu.mp3", true);
							 vite*=-1;
							  if(pista==4)
							  {
							   core::stringw tmp(L"Hai finito la modalita' time attack morendo ");
								tmp += vite;
								tmp += L" volte!!";
							    IGUIWindow* window = guienv->addWindow(
								core::rect<s32>(100, 100, 300, 200),
								false, // modal?
								tmp.c_str());
							  }
						
							 indietro=true;
                            }
                       }
                  break;
                  case 1:
                      device->getGUIEnvironment()->addImage(PLAY_ARCADE,core::position2d<s32>(724,0));
                      if(selezione)
                      {
                      device->getGUIEnvironment()->clear();
                            engine->stopAllSounds();
                            
                            int ris=0, macchina=0, pista=1, vite=3;
                            
                            
                            macchina=scegli();
                            
                            if(macchina!=-1)
                            {
                             macchina++;                        
                             do{
                                switch (pista)
							    {
                                 case 1:
                                  engine->play2D("Music/Livello1.ogg", true);
                                 break;
                                 case 2:
                                  engine->play2D("Music/Livello2.mp3", true);
                                 break;
                                 case 3:
                                  engine->play2D("Music/Livello3.mp3", true);
                                 break;
                                };

                                
							    ris=gioco(macchina,pista,gioca,vite);//0perso, 1 vinto,2 uscito x volere dell'utente
							    if(ris==1)
							     pista++;
							    
							    engine->stopAllSounds();
							    
							   }while(ris!=2&&pista<=3&&ris!=0);
							 
							 engine->play2D("Music/Menu.mp3", true);
							 
							  if(pista==4)
							   cout<<"Hai finito la modalita' arcade!!";
							  if(ris==0)
							   cout<<"Hai fallito la modalita' acade!!";
                             indietro=true;
                      }
                      }
                 break;
                  case 2:
                      device->getGUIEnvironment()->addImage(PLAY_SURVIVE,core::position2d<s32>(724,0));
                      if(selezione)
                       {
                        device->getGUIEnvironment()->clear();
                            engine->stopAllSounds();
                            
                            int ris=0, macchina=0, pista=1, vite=0;
                            
                            
                            macchina=scegli();
                            
                            if(macchina!=-1)
                            {
                             macchina++;                        
                             do{
                                switch (pista)
							    {
                                 case 1:
                                  engine->play2D("Music/Livello1.ogg", true);
                                 break;
                                 case 2:
                                  engine->play2D("Music/Livello2.mp3", true);
                                 break;
                                 case 3:
                                  engine->play2D("Music/Livello3.mp3", true);
                                 break;
                                };

                                
							    ris=gioco(macchina,pista,gioca,vite);//0 perso, 1 vinto,2 uscito x volere dell'utente
							    if(ris==1)
							     pista++;
							    
							    engine->stopAllSounds();
							    
							   }while(ris!=2&&pista<=3&&ris!=0);
							 
							 engine->play2D("Music/Menu.mp3", true);
							 
							  if(pista==4)
							   cout<<"Hai finito la modalita' survive!!";
							  if(ris==0)
							   cout<<"Hai fallito la modalita' survive.";
                             indietro=true;
                             }
                       }
                      break;
                  case 3:
                      device->getGUIEnvironment()->addImage(PLAY_BACK,core::position2d<s32>(724,0));
                      if(selezione)
                                 indietro=true;
                  }
                  driver->beginScene(true, true, video::SColor(255,113,113,133));
                  smgr->drawAll();
                  device->getGUIEnvironment()->drawAll();
                  driver->endScene();
                  Sleep(ritardo);
                 }
