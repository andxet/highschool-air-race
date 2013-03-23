//il caricamento delle texture di tutti i menu in memoria viene effettuato tutto all'inizio. 
//ad ogni texture caricata viene visualizzata una tacchetta in più nella barra di avanzamento

int x=213;
device->getGUIEnvironment()->addImage(driver->getTexture("img/loading.jpg"),core::position2d<s32>(0,0));

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *MENU=driver->getTexture("img/menu.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *MENU_CREDITS=driver->getTexture("img/menu_credits.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *MENU_OPTIONS=driver->getTexture("img/menu_options.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *MENU_PLAY=driver->getTexture("img/menu_play.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *MENU_QUIT=driver->getTexture("img/menu_quit.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS2=driver->getTexture("img/options2.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_BACK=driver->getTexture("img/options_back.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_DEFAULT=driver->getTexture("img/options_default.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_MENU=driver->getTexture("img/options_menu.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SAVE=driver->getTexture("img/options_save.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SCREEN=driver->getTexture("img/options_screen.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SCREEN_800=driver->getTexture("img/options_screen_800.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SCREEN_1024=driver->getTexture("img/options_screen_1024.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SCREEN_1280=driver->getTexture("img/options_screen_1280.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SCREEN_1600=driver->getTexture("img/options_screen_1600.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SCREEN_FULL=driver->getTexture("img/options_screen_full.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SCREEN_SHADOWS=driver->getTexture("img/options_screen_shadows.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SCREEN_WINDOW=driver->getTexture("img/options_screen_window.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SETTINGS=driver->getTexture("img/options_settings.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SETTINGS_ARROWS=driver->getTexture("img/options_settings_arrows.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SETTINGS_DX8=driver->getTexture("img/options_settings_dx8.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SETTINGS_DX9=driver->getTexture("img/options_settings_dx9.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SETTINGS_OGL=driver->getTexture("img/options_settings_ogl.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SETTINGS_WASD=driver->getTexture("img/options_settings_wasd.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SOUND=driver->getTexture("img/options_sound.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SOUND_EFFECTS=driver->getTexture("img/options_sound_effects.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SOUND_MUSIC=driver->getTexture("img/options_sound_music.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *OPTIONS_SOUND_VOLUME=driver->getTexture("img/options_sound_volume.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *PLAY=driver->getTexture("img/play.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *PLAY_ARCADE=driver->getTexture("img/play_arcade.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *PLAY_BACK=driver->getTexture("img/play_back.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *PLAY_SURVIVE=driver->getTexture("img/play_survive.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *PLAY_TIME_ATTACK=driver->getTexture("img/play_time_attack.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *QUAD_NS_AVANZAMENTO=driver->getTexture("img/quad_ns_avanzamento.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *QUAD_NS_PIENO=driver->getTexture("img/quad_ns_pieno.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *QUAD_NS_VUOTO=driver->getTexture("img/quad_ns_vuoto.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *QUAD_S_AVANZAMENTO=driver->getTexture("img/quad_s_avanzamento.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *QUAD_S_PIENO=driver->getTexture("img/quad_s_pieno.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *QUAD_S_VUOTO=driver->getTexture("img/quad_s_vuoto.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *QUAD_MULTI_S=driver->getTexture("img/quad_multi_s.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
video::ITexture *QUAD_MULTI_NS=driver->getTexture("img/quad_multi_ns.jpg");

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
if(x<835) x+=3;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();



while (x<823){

device->getGUIEnvironment()->addImage(driver->getTexture("img/loading2.jpg"),core::position2d<s32>(x,350));
x++;
driver->beginScene(true, true, video::SColor(255,113,113,133));
smgr->drawAll();
device->getGUIEnvironment()->drawAll();
driver->endScene();
      
} 
