//Questa funzione converte in radianti il valore in gradi ricevuto come parametro
float radianti(float gradis)
{
 float radiantis=(M_PI/180)*gradis;
 return radiantis;
}

//Quest'altra effettua l'operazione contraria, ossia converte da radianti a gradi
float gradi (float radiantis)
{
 float gradis=(180/M_PI)*radiantis;
 return gradis;
}

//funzione usata per scrivere molte stringhe di seguito in un file. 
//le stringhe non devono avere un numero preciso ma la prima deve contenere per forza il nome del file
void scrivi(int argc, char*argv[]){
	fstream file;
    file.open(argv[0],ios::out);
	for(int i=1; i<argc;i++){
		file<<argv[i]<<"\n";
	}
	file.close();
}

//carica le impostazioni del gioco dal file config.txt
void configurazione(char &volume,char &musica,char &effetti,char &ombre,char &vista,char &risoluzione,char &movimento,char &render){
	fstream f;
	f.open("config.txt",ios::in);
	if(!f)
        cout<<"ERRORE NELL'APERTURA DEL FILE config.txt O FILE ASSENTE";
	else{
		f>>volume>>musica>>effetti>>ombre>>vista>>risoluzione>>movimento>>render;
	}
	f.close();
}

/////////////////////////////////////////////////Funzione che fa scegliere la macchina

int scegli()
{
//crea una telecamera che ruota intorno al punto 0. 
 scene::ICameraSceneNode * Cam=smgr->addCameraSceneNode(0, core::vector3df(0,120,0), core::vector3df(0,0,0),0);
    if (Cam)
	{
		scene::ISceneNodeAnimator* anim =
			smgr->createFlyCircleAnimator(core::vector3df(0,0.5,0), 1.0f);
		if (anim)
		{
			Cam->addAnimator(anim);
			anim->drop();
		}
	}
    if(!Cam)
    cout<<"Impossibile creare la telecamera rotante.";
    
    //creo tre luci per illuminare la scena
    scene::ILightSceneNode * sole = smgr->addLightSceneNode(0,//Parentela, 0 se non è imparentato(un nodo imparentato può essere padre o figlio. Qualunque spostamento, rotazione, ecc.. che compie il nodo padre, lo fa automaticamente anche il figlio.)
                                core::vector3df(-5,10,-5),
                                video::SColorf(1.0f, 1.0f, 1.0f),
                                7.0f, -1);
    scene::ILightSceneNode * sole2 = smgr->addLightSceneNode(0,//Parentela, 0 se non è imparentato(un nodo imparentato può essere padre o figlio. Qualunque spostamento, rotazione, ecc.. che compie il nodo padre, lo fa automaticamente anche il figlio.)
                                core::vector3df(5,10,-5),
                                video::SColorf(1.0f, 1.0f, 1.0f),
                                7.0f, -1);
     scene::ILightSceneNode * sole3 = smgr->addLightSceneNode(0,//Parentela, 0 se non è imparentato(un nodo imparentato può essere padre o figlio. Qualunque spostamento, rotazione, ecc.. che compie il nodo padre, lo fa automaticamente anche il figlio.)
                                core::vector3df(0,10,8.66f),
                                video::SColorf(1.0f, 1.0f, 1.0f),
                                7.0f, -1);

    //Dichiarazione della macchina, di tipo IMeshSceneNode
scene::IMeshSceneNode * macchina = smgr->addMeshSceneNode(smgr->getMesh("Macchine/Macchina1/macchina.3ds"));
	if (macchina)
	{
		macchina->setPosition(core::vector3df(0,0,0));//Indico la posizione iniziale
		macchina->setRotation(core::vector3df(0,0,0));//la rotazione
		macchina->setMaterialType(video::EMT_SOLID );//il tipo di materiale (in questo caso solido) EMT_REFLECTION_2_LAYER
		macchina->setMaterialTexture(0, driver->getTexture("Macchine/Macchina1/macchina.jpg"));	//e la textura da applicare al modello
		macchina->setMaterialFlag(video::EMF_LIGHTING, true);//e se il modello deve essere soggetto alle ombre e luci
	}
	int n=0;
	while(device->run()) //con la pressione del tasto sinistro e destro permetto al giocatore di selezionare la macchina
	{	
        if(receiver.IsKeyDown(irr::KEY_LEFT))
			{
               receiver.UpKey(irr::KEY_LEFT);
             n--;
             if(n<0)
             n=1;
             if(n==0)
             {
              macchina->setMesh(smgr->getMesh("Macchine/Macchina1/macchina.3ds"));
              macchina->setMaterialTexture(0, driver->getTexture("Macchine/Macchina1/macchina.jpg"));
             }
             if(n==1)
             {
              macchina->setMesh(smgr->getMesh("Macchine/Macchina2/macchina.3ds"));
              macchina->setMaterialTexture(0, driver->getTexture("Macchine/Macchina2/macchina.jpg"));
             }
            }
		else if(receiver.IsKeyDown(irr::KEY_RIGHT))
			{
             receiver.UpKey(irr::KEY_RIGHT);
             n++;
             if(n>1)
             n=0;
             if(n==0)
             {
              macchina->setMesh(smgr->getMesh("Macchine/Macchina1/macchina.3ds"));
              macchina->setMaterialTexture(0, driver->getTexture("Macchine/Macchina1/macchina.jpg"));
             }
             if(n==1)
             {
              macchina->setMesh(smgr->getMesh("Macchine/Macchina2/macchina.3ds"));
              macchina->setMaterialTexture(0, driver->getTexture("Macchine/Macchina2/macchina.jpg"));
             }
            }
        	
  	    if(receiver.IsKeyDown(irr::KEY_RETURN)) // alla pressione di invio ritorno la macchina selezionata
			{
             macchina->remove();
             sole->remove();
             sole2->remove();
             sole3->remove();
             Cam->remove();       
             return n;
            }
            
        if(receiver.IsKeyDown(irr::KEY_ESCAPE)) //alla pressione del tasto esc torno al menu precedente comunicando la non selezione della macchina
			{
             macchina->remove();
             sole->remove();
             sole2->remove();
             sole3->remove();
             Cam->remove();       
             return -1;
            }
   
   //faccio puntare sempre la telecamera alla macchina
        Cam->setTarget(core::vector3df(0,0,0));
		driver->beginScene(true, true, video::SColor(255,113,113,133));
        smgr->drawAll(); //genero il fotogramma
		device->getGUIEnvironment()->drawAll();
        driver->endScene();
	}
}


//////////////////////////////////////////////Funzione che gestisce la partita
int gioco(int numMacchina, int numPista, int mod, int &vite)
{
//Queste sono le variabili della macchina: Velocità, Velocità massima, Velocità
//minima(retromarcia), Freno, Accelerazione, Manovrabilità, Attrito,
//Coefficiente freno a mano
float V=0, Vmax=500, Vmin=-40, Fren=50, Acc=20, Man=5000, Attr=8, CoeffFM=1.1, fineX=0, fineY=5, larg=6;

//Queste sono le variabili della telecamera: MaxRot è la differenza massima tra 
//la rotazione della macchina e quella della camera, Bdist è la distanza della
//camera dalla macchina, Altezza della camera, Distanza dalla macchina del punto
//a cui la camra punta, la differenza tra la rotazione della macchina e della
//camera, e la velocità con cui la camera si riallinea alla macchina (gradi al secondo)
float MaxRot=10, Bdist=4, Alt=2, Dist=50, Alfadiff=0, Allin=20;
//Queste sono le variabili dell'ambiente: il tempo che la macchina sta' cadendo 
//(per calcolare la caduta), la gravità, il numero della macchina da utilizzare,
//il numero della pista da caricare, ed un valore booleano che indica se la
//macchina sta' cadendo
float TempoCaduta=0, Grav=20;
int Nmacc=1, Npista=1;
bool Cadendo=false, arrivato=false;

//Dichiarazione della macchina, di tipo IMeshSceneNode
scene::IMeshSceneNode * macchina = 0;
switch(numMacchina) //seleziona la macchina in base al parametro
{
case 1:
macchina = smgr->addMeshSceneNode(smgr->getMesh("Macchine/Macchina1/macchina.3ds"));
if (macchina)
macchina->setMaterialTexture(0, driver->getTexture("Macchine/Macchina1/macchina.jpg"));//e la textura da applicare al modello
Vmax=150;
Vmin=-40;
Fren=50;
Acc=20;
Man=5000;
Attr=8;
CoeffFM=1.1;
break;

case 2:
macchina = smgr->addMeshSceneNode(smgr->getMesh("Macchine/Macchina2/macchina.3ds"));
if (macchina)
macchina->setMaterialTexture(0, driver->getTexture("Macchine/Macchina2/macchina.jpg"));
Vmax=200;
Vmin=-50;
Fren=30;
Acc=15;
Man=40;
Attr=13;
CoeffFM=0.9;
break;
};

//assegno e proprietà al nodo, ovvero la texture, il materiale, la posizione e la rotazione
if (macchina)
{
 macchina->setPosition(core::vector3df(0,0,0));//Indico la posizione iniziale
 macchina->setRotation(core::vector3df(0,0,0));//la rotazione
 macchina->setMaterialType(video::EMT_SOLID);//il tipo di materiale (in questo caso solido)
 macchina->setMaterialFlag(video::EMF_LIGHTING, true);//e se il modello deve essere soggetto alle ombre e luci
}

//Dichiaro la mesh della pista
scene::IMesh *meshPista=0;
scene::ISceneNode * pista = 0;
//creo il cubo di arrivo
scene::ISceneNode* arrivo = 0;
scene::ISceneNode* skybox=0;

switch (numPista)
{
case 1:
default:
meshPista=smgr->getMesh("Piste/Pista1/pista.3ds");
if(meshPista)
pista=smgr->addOctTreeSceneNode(smgr->getMesh("Piste/Pista1/pista.3ds"));

//Aggiungo lo scenario sullo sfondo: un skybox, che applica ad un cubo, al cui interno si trova la pista, una serie di immagini	per creare un effetto panorama
skybox=smgr->addSkyBoxSceneNode(driver->getTexture("Piste/Pista1/su.jpg"),driver->getTexture("Piste/Pista1/giu.jpg"),driver->getTexture("Piste/Pista1/sinistra.jpg"),driver->getTexture("Piste/Pista1/destra.jpg"),driver->getTexture("Piste/Pista1/fronte.jpg"),driver->getTexture("Piste/Pista1/dietro.jpg"));


arrivo = smgr->addMeshSceneNode(smgr->getMesh("Piste/Pista1/cubo.3ds"));
fineX=94;
fineY=-57;
larg=6;
break;
case 2:
meshPista=smgr->getMesh("Piste/Pista2/pista.3ds");
if(meshPista)
pista=smgr->addOctTreeSceneNode(smgr->getMesh("Piste/Pista2/pista.3ds"));

//Aggiungo lo scenario sullo sfondo: un skybox, che applica ad un cubo, al cui interno si trova la pista, una serie di immagini	per creare un effetto panorama
skybox=smgr->addSkyBoxSceneNode(driver->getTexture("Piste/Pista2/su.jpg"),driver->getTexture("Piste/Pista2/giu.jpg"),driver->getTexture("Piste/Pista2/sinistra.jpg"),driver->getTexture("Piste/Pista2/destra.jpg"),driver->getTexture("Piste/Pista2/fronte.jpg"),driver->getTexture("Piste/Pista2/dietro.jpg"));


arrivo = smgr->addMeshSceneNode(smgr->getMesh("Piste/Pista2/cubo.3ds"));
fineX=30;
fineY=-7;
larg=3;
break;
case 3:
meshPista=smgr->getMesh("Piste/Pista3/pista.3ds");
if(meshPista)
pista=smgr->addOctTreeSceneNode(smgr->getMesh("Piste/Pista3/pista.3ds"));

//Aggiungo lo scenario sullo sfondo: un skybox, che applica ad un cubo, al cui interno si trova la pista, una serie di immagini	per creare un effetto panorama
skybox=smgr->addSkyBoxSceneNode(driver->getTexture("Piste/Pista3/su.jpg"),driver->getTexture("Piste/Pista3/giu.jpg"),driver->getTexture("Piste/Pista3/sinistra.jpg"),driver->getTexture("Piste/Pista3/destra.jpg"),driver->getTexture("Piste/Pista3/fronte.jpg"),driver->getTexture("Piste/Pista3/dietro.jpg"));


arrivo = smgr->addMeshSceneNode(smgr->getMesh("Piste/Pista3/cubo.3ds"));
fineX=-47;
fineY=-1;
larg=4;
break;
};



if(arrivo)
{
 arrivo->setPosition(core::vector3df(0,0,0));
 
 arrivo->setMaterialTexture(0, driver->getTexture("Piste/Pista1/cubo.jpg"));
 arrivo->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR );//il tipo di materiale (in questo caso solido)
}
//Creo il nodo della pista


scene::ITriangleSelector* sel=0;//Inizializzo la variabile del selezionatore di triangoli
if (pista)
	{
        sel = smgr->createTriangleSelector(meshPista,pista);//assegno al selezionatore la mesh della pista ed il nodo
        pista->setTriangleSelector(sel);//e così comunico al nodo pista di utilizzare quel selezionatore
        sel->drop();

		pista->setPosition(core::vector3df(0,0,0));//posizione della pista
		pista->setRotation(core::vector3df(0,0,0));	//rotazione	
		pista->setMaterialType(video::EMT_SOLID);//tipo di materiale
		pista->setMaterialFlag(video::EMF_LIGHTING, true);//comportamento con le luci
		pista->setMaterialTexture(1, driver->getTexture("Piste/Pista1/Pista.jpg"));//ed infine la texture
	}

//Aggiungo lo scenario sullo sfondo: un skybox, che applica ad un cubo, al cui interno si trova la pista, una serie di immagini	per creare un effetto panorama
smgr->addSkyBoxSceneNode(driver->getTexture("Piste/Pista1/su.jpg"),driver->getTexture("Piste/Pista1/giu.jpg"),driver->getTexture("Piste/Pista1/sinistra.jpg"),driver->getTexture("Piste/Pista1/destra.jpg"),driver->getTexture("Piste/Pista1/fronte.jpg"),driver->getTexture("Piste/Pista1/dietro.jpg"));
//Creo una lampada che illumini la scena
scene::ILightSceneNode * sole = smgr->addLightSceneNode(0,//Parentela, 0 se non è imparentato(un nodo imparentato può essere padre o figlio. Qualunque spostamento, rotazione, ecc.. che compie il nodo padre, lo fa automaticamente anche il figlio.)
                                core::vector3df(0,100,0),
                                video::SColorf(1.0f, 1.0f, 1.0f),
                                1000.0f, -1);

//Ed infine aggiungo la telecamera
scene::ICameraSceneNode * CamMacchina=smgr->addCameraSceneNode(0, core::vector3df(0,120,0), core::vector3df(0,0,0),0);

//Rendo invisibile il puntatore del mouse quando si trova sopra la finestra del gioco  
device->getCursorControl()->setVisible(false);

	
	int lastFPS = -1;
	float lastCamRot=0;
    u32 then = device->getTimer()->getTime();

    //creo una linea che verrà posizionata al di sotto della macchina. Quando verrà individuata una collisione tra la linea e la pista, la macchina non cadrà, altrimenti si. Per fare cadere la macchina si diminuisce il valore della posizione di Y della macchina.
    core::line3d<f32> line;
    
    for(irr::s32 i=0; (i<vite&&i<8); i++)
      device->getGUIEnvironment()->addImage(driver->getTexture("Macchine/Vite.jpg"),core::position2d<s32>((2+(106*i)),2));
 
//Questo ciclo è la parte fondamentale del programma. E' infatti qua che vengono calcolati
//tutti i parametri del movimento della telecamera e della macchina, più le collisioni
//ed infine la generazione del fotogramma. Ad ogni ciclo viene generato un nuovo fotogramma.
	while(device->run())//Se premo Esc, esco dal gioco
	{
		// Calcolo il frame delta time.
		// Il frame delta time è il tempo che intercorre dalla generazione di un fotogramma al successivo,
		// ed è il tempo che dovremo moltiplicare a tutti i valori che dovremo sommare ai parametri dei nodi.
		const u32 now = device->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
		then = now;

		
        core::vector3df macchinaPos = macchina->getPosition();//Salvo in una variabile la posizione attuale della macchina
        core::vector3df macchinaRot = macchina->getRotation();//Salvo il una variabile la rotazione attuale della macchina
		
		
		//Collisioni
		line.start = macchinaPos;//Pongo l'inizio della linea al di sotto della macchina.
		line.end = core::vector3df(macchinaPos.X,macchinaPos.Y-5,macchinaPos.Z);//Pongo la fine della linea 4 unità al di sotto della macchina                 
        core::vector3df  outCollisionPoint;//Creo due variabili: una è il punto in cui avviene la collisione
        core::triangle3df  outTriangle;//l'altro è un oggetto di tipo triangolo che riceverà il triangolo in cui avviene la collisione con la linea
        
        //Utilizzando la funzione getCollisionPoint, rilevo se avviene una collisione
        if (!smgr->getSceneCollisionManager()->getCollisionPoint(line, sel, outCollisionPoint, outTriangle)) 
         if(Cadendo==false)
          Cadendo=true;//Se avviene, la macchina deve iniziare acadere
          
        if(Cadendo==true)//Calcolo la nuova coordinata utilizzando la formula del moto uniformemente accelerato
         {
          TempoCaduta+=frameDeltaTime;//Aggiorno il tempo che la macchina sta' cadendo
		  macchinaPos.Y-=(Grav*TempoCaduta)*frameDeltaTime;//e applico la formula
         }
		
		
		//Quando la macchina inizia a cadere, devo bloccare tutti i comandi di imput		
        
        //Comandi della velocità
		if(receiver.IsKeyDown(irr::KEY_UP)&&Cadendo==false&&arrivato==false)//Se è premuto "SU" auento la velocità.
			{
             if(V<0)//Se si sta andando in retromarcia, premendo in alto la macchina dovrà fermarsi e ripartire, per questo di aumenta per il valore del freno.
             V += Fren * frameDeltaTime;
             else //Altrimenti si somma l'accelerazione                               
             {
              if(V<5)
              V=5;
              V += Acc * frameDeltaTime;
             }
             if(V>Vmax)//Se la velocità è maggiore della sua velocità massima, la velocità è uguale alla velocutà massima.
              V=Vmax;
            }
		else if(receiver.IsKeyDown(irr::KEY_DOWN)&&Cadendo==false&&arrivato==false)//Alla pressione del tasto "GIU" la macchina rallenta e inizia la retromarcia.
			{
             if(V<0)
             V -= Acc * frameDeltaTime;
             else                                      
             V -= Fren * frameDeltaTime;
             if (V<Vmin)
             V=Vmin;
            }
            
        //Comandi dello sterzo
        
        //Per simulare lo sterzo di una macchina, si calcola un valore da sommare all'attuale rotazione.
		if(receiver.IsKeyDown(irr::KEY_LEFT)&&Cadendo==false&&arrivato==false)
			{
             if(V>1||V<-1)//se la velocità è compresa tra -1 e 1 non è possibile sterzare
             macchinaRot.Y-= gradi(atan(Man/V)) * frameDeltaTime;
            }
		else if(receiver.IsKeyDown(irr::KEY_RIGHT)&&Cadendo==false&&arrivato==false)
			{
             if(V>1||V<-1)
             macchinaRot.Y+= gradi(atan(Man/V)) * frameDeltaTime;
            }
        //Freno a mano
        if(receiver.IsKeyDown(irr::KEY_SPACE)&&Cadendo==false&&arrivato==false)//Con il freno a mano si rallenta per affrontare le curve.
			{
             if(V>0)
             {
              V -= (Fren * CoeffFM) * frameDeltaTime;
              if(V<0)
              V=0;
             }
             else
             {
              V += (Fren * CoeffFM) * frameDeltaTime;
              if(V>0)
              V=0;
             }
            }

		//Attrito
        if(V>=0)//L'attrito diminuisce la velocità della macchina facendola tendere a 0.
		{
		 V-= Attr * frameDeltaTime;
		 if(V<0)
		 V=0;
		}
		else
	    {
		 V+= Attr * frameDeltaTime;
		 if(V>0)
		 V=0;
		}        
        //se il giocatore preme esc il gioco ritorna al menu principale restituendo 2, 
        //che è il valore di annullamento da parte dell'utente
        if(receiver.IsKeyDown(irr::KEY_ESCAPE))
		{
         arrivo->remove();
         macchina->remove();
         pista->remove();
         sole->remove();
         CamMacchina->remove();
         skybox->remove();
         return 2;
		}		

        //Ora che conosco la velocità e la rotazione, posso calcolare le nuove coordinate e la rotazione della macchina.
        macchinaPos.X += V * sin(radianti(macchinaRot.Y))*frameDeltaTime;
        macchinaPos.Z += V * cos(radianti(macchinaRot.Y))*frameDeltaTime;
        		
		//Controllo se la macchina è caduta troppo in basso
		if(Cadendo==true)
        if(macchinaPos.Y<-50)
		{
         if(vite==0&&mod!=0)
         {
          arrivo->remove();
          macchina->remove();
          pista->remove();
          sole->remove();
          CamMacchina->remove();          
          skybox->remove();
          return 0;//perso
         }
         else
         {
          vite--;
          device->getGUIEnvironment()->clear();
          for(irr::s32 i=0; (i<vite&&i<8); i++)//disegno le automobili che rappresentano i tentativi disponibili
          device->getGUIEnvironment()->addImage(driver->getTexture("Macchine/Vite.jpg"),core::position2d<s32>((2+(106*i)),2));
               
          Cadendo=false;//Se è così, la macchina smette di cadere
		  V=0;//si ferma
		  macchinaPos=core::vector3df(0,0,0);//ritorna all'inizio
		  macchinaRot=core::vector3df(0,0,0);//e con la rotazione iniziale
		  lastCamRot=0;
		  TempoCaduta=0;
         }
        }
        
        //Controllo se la macchina è arrivata
        if(!Cadendo)
        if(macchinaPos.X>=fineX&&macchinaPos.X<=fineX+6&&macchinaPos.Z<=fineY&&macchinaPos.Z>=fineY-6)//se le coordinate dell macchina sono contenute all'interno del cub il giocatore ha concluso la pista
         {
          arrivo->remove();
          arrivato=true;
          macchina->remove();
          pista->remove();
          sole->remove();
          CamMacchina->remove();          
          skybox->remove();
          return 1;
         }
        
        //Infine assegno i valori ai nodi
		macchina->setPosition(macchinaPos);
		macchina->setRotation(macchinaRot);	
        
        

		///////////////Controllo della camera
		if(V<0)//Simulo un angolo che tende ad uguagliarsi alla rotazione della macchina
		Alfadiff=0;
		else
		{
		 Alfadiff+=(lastCamRot)-(macchinaRot.Y);
		 if(Alfadiff<0)
		 {
          Alfadiff+=Allin*frameDeltaTime;
		  if(Alfadiff>0)
		   Alfadiff=0;
         }
         else
         {
		  Alfadiff-=Allin*frameDeltaTime;
	 	  if(Alfadiff<0)
	  	   Alfadiff=0;
         }
        }
        
        if(Alfadiff<-MaxRot)//Se questo angolo è maggiore del suo valore massimo, lo eguaglio al valore massimo
        Alfadiff=-MaxRot;
        if(Alfadiff>MaxRot)//e se è minore del minimo, lo eguaglio al minimo
        Alfadiff=MaxRot;
		
        //Camera per la retromarcia
		if(V<-2)//Cambio posizione della camera per la retromarcia, se la velocità è < di 0
         macchinaRot.Y+=180;		
		
		core::vector3df nuovaPos=core::vector3df(macchinaPos.X-(Bdist * sin(radianti(macchinaRot.Y+Alfadiff))),Alt,macchinaPos.Z-(Bdist * cos(radianti(macchinaRot.Y+Alfadiff))));//La posizione della telecamera ed il suo target dipendono da quella della macchina e da Alfadiff, che è la differenza tra la rotazione della macchina e della telecamera
		core::vector3df nuovoTarget=core::vector3df(macchinaPos.X+Dist*sin(radianti(macchinaRot.Y+Alfadiff)),0,macchinaPos.Z+Dist*cos(radianti(macchinaRot.Y+Alfadiff)));
		
		CamMacchina->setPosition(nuovaPos);
        CamMacchina->setTarget(nuovoTarget);
        
        //Inizializzo la scena
		driver->beginScene(true, true, video::SColor(255,113,113,133));

		smgr->drawAll(); // Genero il fotogramma
        device->getGUIEnvironment()->drawAll(); // visualizzo gli elementi dell'interfaccia
		driver->endScene();
		
	if(V>=-2)	
	 lastCamRot=macchinaRot.Y;
    else
     lastCamRot=macchinaRot.Y-180;
     
}
}
