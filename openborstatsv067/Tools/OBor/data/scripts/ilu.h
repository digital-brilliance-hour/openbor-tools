#import "data/scripts/visRise.c"
#import "data/scripts/randsound.c"
#include "data/scripts/conditional.h"
#import "data/scripts/summonH.c"

void terminate(char target_name)
{// kill any entity on the screen by the given name
//Douglas Baldan - 11.27.2016 - Really thanks for the fix, White Dragon
// Thanks Lagarto
	int i;
	for (i = 0; i < openborvariant("count_entities"); ++i)
	{
    		void ent = getentity(i);
		if ( getentityproperty(ent, "exists") )
	   	{
       			if ( getentityproperty(ent,"model") == target_name)
			{
				killentity(ent);
				continue;
			}
		} else continue;
	} 
	return;	
}

void bmtMusicTempo (int iRatio)
// Change the background music tempo to the desired value
// Normal ratio is 100. Higher the value, higher the tempo and vice versa.
// Douglas Baldan - 14.12.2016
{
setmusictempo(iRatio);
}

void bmtDeathMusicTempo (int iRatio, int iLife)
// Change the background music tempo to the desired value bases on how much life the entity has.
// Normal ratio is 100. Higher the value, higher the tempo and vice versa.
// Douglas Baldan - 14.12.2016
{
    void self = getlocalvar("self"); // get caller
    void life = getentityproperty(self,"health"); //get health
	void maxlife = getentityproperty(self, "maxhealth"); // get max health
	
	if (life<=maxlife/iLife)
	{
	setmusictempo(iRatio);
	}
}


void hpcost( int HCost)
{// Spend some life
    void self = getlocalvar("self");
    void Life = getentityproperty(self,"health"); //get health
if (Life > HCost){ //Does the entity have enough health?
       changeentityproperty(self, "health", Life-HCost);//consume health
      } 

}

void damage_all_enemies(int damage, int drop, void atk_type, void vName, char sound)
//thanks Lagarto, Piccolo and White Dragon
{
 	int  iEntity; 
        void vEntity;
        void self        = getlocalvar("self");
        int  iMax        = openborvariant("count_entities");   
		playSound("data/sounds/"+sound);
		
        for(iEntity=0; iEntity<iMax; iEntity++)
        {
        vEntity = getentity(iEntity);
		float x = getentityproperty(vEntity, "x") - openborvariant("xpos");
		float a = getentityproperty(vEntity, "a");
		float z = getentityproperty(vEntity, "z");
		void Spawn;
		if(getentityproperty(vEntity, "type")==openborconstant("TYPE_enemy"))
		{
		
		clearspawnentry();
        setspawnentry("name", vName);
        setspawnentry("coords", x, z+1, a+30);
        spawn();
        clearspawnentry();
		damageentity(vEntity,self,damage,drop,openborconstant(atk_type));
		
		}
	}
}
void flash_all_enemies(void vName, char sound)
//thanks Lagarto, Piccolo and White Dragon
{
 	int  iEntity; 
        void vEntity;
        void self        = getlocalvar("self");
        int  iMax        = openborvariant("count_entities");   
		playSound("data/sounds/"+sound);
		
        for(iEntity=0; iEntity<iMax; iEntity++)
        {
        vEntity = getentity(iEntity);
		float x = getentityproperty(vEntity, "x") - openborvariant("xpos");
		float a = getentityproperty(vEntity, "a");
		float z = getentityproperty(vEntity, "z");
		void Spawn;
		if(getentityproperty(vEntity, "type")==openborconstant("TYPE_enemy"))
		{
		
		clearspawnentry();
        setspawnentry("name", vName);
        setspawnentry("coords", x, z+1, a+30);
        spawn();
        clearspawnentry();
		}
	}
}



void cancelgrab(void Ani)
        {// Check grabbed opponent's name
        // If it's forbidden to grab him/her, revert to IDLE
           void self = getlocalvar("self");
           void target = getlocalvar("Target" + self);

           if(target==NULL())
           {
             target = getentityproperty(self, "opponent");
             setlocalvar("Target" + self, target);
           }
           if(target!=NULL())
           {
             char Tname = getentityproperty(target, "defaultname");
             char iType = getentityproperty(target, "type");

             if(Tname == "Drum" || Tname == "Crate" || Tname == "golem" || Tname == "golem_beta" || Tname == "guardian"|| Tname == "msentinel" || iType == openborconstant("TYPE_OBSTACLE") || iType ==openborconstant("TYPE_ITEM") || iType ==openborconstant("TYPE_NPC"))
             {
                 //clearlocalvar();
				 changeentityproperty(self, "animation", openborconstant(Ani));
             }
           }
        }

void cancelgrabOBJ(void Ani)
        {// Check grabbed opponent's name
        // If it's forbidden to grab him/her, revert to IDLE
           void self = getlocalvar("self");
           void target = getlocalvar("Target" + self);

           if(target==NULL())
           {
             target = getentityproperty(self, "opponent");
             setlocalvar("Target" + self, target);
           }
           if(target!=NULL())
           {
             char Tname = getentityproperty(target, "defaultname");
             char iType = getentityproperty(target, "type");

             if(iType == openborconstant("TYPE_OBSTACLE") || iType ==openborconstant("TYPE_ITEM") || iType ==openborconstant("TYPE_NPC"))
             {
                 //clearlocalvar();
				 changeentityproperty(self, "animation", openborconstant(Ani));
             }
           }
        }
		
		
		
void setspeed(int fX)
{// Set entity speed
    void self = getlocalvar("self");
changeentityproperty(self, "speed", fX); //moving!
}

//@script
//if(frame ==0)
//{
//	void self = getlocalvar("self");
//	int P1 = getplayerproperty(0, "entity");
//    int P2 = getplayerproperty(1, "entity");
//  	int P1Name = getentityproperty(P1,"model");
//	int P2Name = getentityproperty(P2,"model");
//	
//	if (P1Name == "wolverine" || P2Name == "wolverine")
//	{
//    performattack(self, openborconstant("ani_follow4"));
//	}
//}
//@end_script


void paleta(int Pal)
{// 
    void self = getlocalvar("self"); //Get calling entity.
    int oPal = getentityproperty(self, "mapdefault"); //Get calling entity.

    if (Pal > 0){
	changeentityproperty(self, "colourmap", Pal);
   }
	else{
changeentityproperty(self, "colourmap", oPal);

}

}

void changepal(int Pal)
{// change the current pallete
// O Ilusionista - 20/11/2013
    void self = getlocalvar("self"); //Get calling entity.
    changeentityproperty(self, "map", Pal);
}

void resetpal()
{// revert to original palette
// O Ilusionista - 20/11/2013 - Thanks White Dragon!
    void self = getlocalvar("self"); //Get calling entity.
    changeentityproperty(self, "map", 0);
}


void regen (int regH)
{// Spend some life
    void self = getlocalvar("self");// get caller
    void Life = getentityproperty(self,"health"); //get health
    changeentityproperty(self, "health", Life+regH);//add health
}

void checkPal(void Ani, int Remap)
{// Attack interruption if there's player
// Only occurs if remap matches is not the one given
    void self = getlocalvar("self");
    int Map = getentityproperty(self, "map");

    if(Map!=Remap){
      performattack(self, openborconstant(Ani)); //Attack!
    }
}

void checkPal2(void Ani, int Remap)
{// 
// Only occurs if remap matches
// O Ilusionista - 20/11/2013
    void self = getlocalvar("self");
    int Map = getentityproperty(self, "map");

    if(Map==Remap){
      performattack(self, openborconstant(Ani)); //Attack!
    }
}

void spawnAni(void vName, float fX, float fY, float fZ, void Ani, float Vx, float Vy, float Vz)
{
	//spawnB (Generic spawner) + Specific animation + velocities
	//Damon Vaughn Caskey + Douglas Baldan
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    performattack(vSpawn, openborconstant(Ani)); 
	changeentityproperty(vSpawn, "velocity", Vx, Vy, Vz);

	return vSpawn; //Return spawn.
}

void spawnAniMap(void vName, float fX, float fY, float fZ, void Ani, int iControl)
{
	//spawnB (Generic spawner) + Specific animation + velocities + map
	//Damon Vaughn Caskey + Douglas Baldan
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");
    int  iMap = getentityproperty(self, "map"); // Get caller's remap.

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?                  
          fX = -fX; //Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	//changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

	if (iControl){
	changeentityproperty(vSpawn, "map", iMap); //Set map.
	}
    performattack(vSpawn, openborconstant(Ani)); 
	//changeentityproperty(vSpawn, "velocity", Vx, Vy, Vz);

	return vSpawn; //Return spawn.
}

void spawn000(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner) without direction
	//Damon Vaughn Caskey
	//07/06/2007 -- Modified by Douglas Baldan/O Ilusionista
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", vName); //Acquire spawn entity by name.

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
    
	return vSpawn; //Return spawn.
}

void teleportentityrandomlyonscreen(int screenwidth)
{
  //MatMan v0.02
  //Screenwidth needs to be put in manually as openborcvarial hresolution doesn't work
	void self = getlocalvar("self");
  int ichancex = 0;
  int ichancey = 0;
  ichancex = rand()%screenwidth;
  if (ichancex < 0) { ichancex = -ichancex ;}
  ichancex = ichancex + openborvariant("xpos");
  ichancey = rand()%screenwidth;
  if (ichancey < 0) { ichancey = -ichancey ;}
  ichancey = ichancey + openborvariant("ypos");// + openborvariant("PLAYER_MIN_Z");
  changeentityproperty(self, "position", ichancex, getentityproperty(self, "z"), getentityproperty(self, "a"));

  //TODO: Need to set it that it randomly place's the entity along the z plane.
  //changeentityproperty(self, "position", ichancex, ichancey, getentityproperty(self, "a"));

  //changeentityproperty(self, "position", fx, fz, fy);
  //openborvariant("PLAYER_MIN_Z");
  //openborvariant("PLAYER_MAX_Z");
  return self;
}


void randomteleonscreen()
{// Randomly teleports onscreen

    void self = getlocalvar("self"); //Get calling entity
    int XPos = openborvariant("xpos"); //Get screen edge's position
    int Screen = openborvariant("hResolution"); // Get screen width
    int Width = openborvariant("PLAYER_MAX_Z") - openborvariant("PLAYER_MIN_Z"); // Get width
    int iRx = rand()%(Screen/2) + Screen/2 ;
    int iRz;

	if (Width>0){
    iRz = rand()%(Width/2) + Width/2 ;
	}

    changeentityproperty(self, "position", iRx + XPos, iRz + openborvariant("PLAYER_MIN_Z")); //Randomly teleport
}

void randomteleZ(float Min, float Max)
{// Randomly teleports onscreen only in Z axis

    void self = getlocalvar("self"); //Get calling entity
    int XPos = getentityproperty(self, "x");
    int Width = Max - Min; // Get width
    int iRz;

	if (Width>0){
    iRz = rand()%(Width/2) + Width/2 ;
	}

    changeentityproperty(self, "position", XPos, iRz + openborvariant("PLAYER_MIN_Z")/2); //Randomly teleport
}

void fixRandom()
{// Randomly teleports onScreenB

    void self = getlocalvar("self"); //Get calling entity
    int XPosB = openborvariant("XPos"); //Get ScreenB edge's position
    int ScreenB = openborvariant("hResolution"); // Get ScreenB WidthB
    int WidthB = openborvariant("PLAYER_MAX_Z") - openborvariant("PLAYER_MIN_Z"); // Get WidthB
    int iRxB = rand()%(ScreenB/2) + ScreenB/2 ;
    int iRzB;

	if (WidthB>0){
    iRzB = rand()%(WidthB/2) + WidthB/2 ;
	}

    changeentityproperty(self, "position", iRxB + XPosB, iRzB + openborvariant("PLAYER_MIN_Z")); //Randomly teleport
}

void randomX()
{// Randomly teleports onscreen X

    void self = getlocalvar("self"); //Get calling entity
    int XPos = openborvariant("xpos"); //Get screen edge's position
    int Screen = openborvariant("hResolution"); // Get screen width
    //int Width = openborvariant("PLAYER_MAX_Z") - openborvariant("PLAYER_MIN_Z"); // Get width
    int iRx = rand()%(Screen/2) + Screen/2 ;
    //int iRz;

    //iRz = rand()%(Width/2) + Width/2 ;

    changeentityproperty(self, "position", iRx + XPos, NULL()); //Randomly teleport
}


void antiwallCollide(int Dist, void Ani)
{// Checks if there is wall at defined distance (Dist)
// If there is wall, change animation to Ani
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);
   if(H > y)
   {
      changeentityproperty(self, "animation", openborconstant(Ani));
   }
}

void antiwallCollideDir(int Dist)
{// Checks if there is wall at defined distance (Dist)
// If there is wall, change direction
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int Vx = getentityproperty(self, "xdir"); // Get current x velocity
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);
   if(H > y)
   {
      //changeentityproperty(self, "velocity", -Vx); // Reverses velocity));
	  if (Direction == 0) // facing left
	  {
		changeentityproperty(self, "direction", 1); //Set direction  
	  }else{
		 changeentityproperty(self, "direction", 0); //Set direction   
	  }
	  
   }
}

void antiwallRandom(int Dist)
{// Checks if there is wall at defined distance (Dist)
// If there is wall, change to random position to avoid landing on walls
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);
   if(H > y)
   {
	randomteleonscreen();

   }
}

void antiwallRandomZ(int Dist)
{// Checks if there is wall at defined distance (Dist)
// If there is wall, change to random position to avoid landing on walls
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);
   if(H > y)
   {
	randomteleZ();

   }
}

void antiwallCenter(int Dist)
{// Checks if there is wall at defined distance (Dist)
// If there is wall, change to center stage
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
   }

   H = checkwall(x+Dist,z);
   if(H > y)
   {
	changeentityproperty(self, "velocity", 0); // Reverses velocity
	bmtcenter();

   }
}



void anichangeattack(void Ani)
{
	// Douglas Baldan / O Ilusionista
	// version 1.0 - 23/07/13
	// Animation changer into attacks
    void self = getlocalvar("self");
    performattack(self, openborconstant(Ani)); //Change the animation
}

void randomJump (int vx, int vy)
{
	// Douglas Baldan / O Ilusionista
	// version 1.0 - 23/07/13
	// makes the entity execute a jump into a random direction
      void vSelf = getlocalvar("self"); // Gets the caller
      int Xr = rand()%vx+0.5;	// Random X vel, between the chosen velocity
      int Yr = 2+rand()%vy;	// Random Y vel + 1, to ensure a vertical jump, between the chosen velocity
	  //int Zr = rand()%2;
      if (Yr <0){			// If the Y is negative,
		Yr = Yr*-1;			// Make it positive
      }
      changeentityproperty(vSelf, "velocity", Xr, 0, Yr); // Change entity velocity
       }

 void moveRandom(int vx, int vy, int vz)
{ // Moves entity freely and ignores obstacles
// Bloodbane + O Ilusionista
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int z = getentityproperty(self,"z"); //Get character's z coordinate
    int a = getentityproperty(self,"a"); //Get character's a coordinate
    int dir = getentityproperty(self,"direction"); //Get character's facing direction
	int Xr = rand()%vx;
	int Yr = 1+rand()%vy;
	int Zr = rand()%vz;
	
     if(dir==0){ // Facing left?
      changeentityproperty(self, "position", x-Xr, z+Zr, a+Yr); //Move
     }
     else if(dir==1){ // Facing right?
      changeentityproperty(self, "position", x+Xr, z+Zr, a+Yr); //Move
     }
}
	   
void randomJumpZ (int vx, int vy, int vz)
{
	// Douglas Baldan / O Ilusionista
	// version 1.0 - 23/07/13
	// makes the entity execute a jump into a random direction
      void vSelf = getlocalvar("self"); // Gets the caller
      int Xr = rand()%vx;	// Random X vel, between the chosen velocity
      int Yr = 3+rand()%vy;	// Random Y vel + 3, to ensure a vertical jump, between the chosen velocity
	  int Zr = rand()%vz;	// Random Z vel, between the chosen velocity
     if (Yr <0){			// If the Y is negative,
		Yr = Yr*-1;			// Make it positive
      }
      changeentityproperty(vSelf, "velocity", Xr, Zr, Yr); // Change entity velocity
       }
	   
void randomJumpZ2 (int vx, int vy, int vz)
{
	// Douglas Baldan / O Ilusionista
	// version 1.0 - 23/07/13
	// makes the entity execute a jump into a random direction
      void vSelf = getlocalvar("self"); // Gets the caller
      int Xr = rand()%vx;	// Random X vel, between the chosen velocity
      int Yr = 3+rand()%vy;	// Random Y vel + 3, to ensure a vertical jump, between the chosen velocity
	  int Zr = -2-rand()%vz;	// Random Z vel, between the chosen velocity
     if (Yr <0){			// If the Y is negative,
		Yr = Yr*-1;			// Make it positive
      }
      changeentityproperty(vSelf, "velocity", Xr, Zr, Yr); // Change entity velocity
       }
	   
	   
//void randomPitch (void iSample, int basePitch, int rangePitch)
//{
	// Douglas Baldan / O Ilusionista
	// version 1.0 - 18/08/13
	// plays a sound sample using random pitch
//int iPitch = basePitch+(rand()%rangePitch);
//if (iPitch <0){iPitch = iPitch *-1}
//int iSound = loadsample(iSample);
//playsample(iSound, 0, openborvariant("effectvol"), openborvariant("effectvol"), iPitch, 0)
//}

// Captain America check shield function
void checkShield (int sVal, void Ani)
{
	void vSelf = getlocalvar("self");
	int ShieldC= getglobalvar("ShieldC");
	 if(ShieldC==sVal){
       performattack(vSelf, openborconstant(Ani));
	   
	   
  	}
}

void echeckShield (int sVal, void Ani)
{
	void vSelf = getlocalvar("self");
	int eShieldC = getglobalvar("eShieldC");
	 if(eShieldC==sVal){
       performattack(vSelf, openborconstant(Ani));
	   
	   
  	}
}

// Douglas Baldan / O Ilusionista
// version 1.0 - 20/08/2016
// Check stage type and change animation
void checkStageType (int sVal, void Ani)
{
	void vSelf = getlocalvar("self");
	int stageT = getglobalvar("stageType");
	
	 if(stageT==sVal){
       performattack(vSelf, openborconstant(Ani));
	   
	   
  	}
}

void changeName (void iName)
// Change entity name
// 24.09.2013 - Douglas Baldan - O Ilusionista
{
        void    vSelf   = getlocalvar("self");
        changeentityproperty(vSelf, "name", iName);
}

void unbind ()
// unbind entity
// 24.09.2013 - Douglas Baldan - O Ilusionista
{
void    vSelf   = getlocalvar("self");
bindentity(vSelf, NULL());
}


void spawnRandom(void vName,int vx, int vy )
// Spawn entity at random places
// 24.09.2013 - Douglas Baldan - O Ilusionista
// Based in Damon Caskey "spawn01" function, and you need that function to make it works.
// vx = maximum X position range
// vy = maximum Y position range
{
int Xr = rand()%vx;	// Random X pos
int Yr = rand()%vy;	// Random Y pos
clearspawnentry();
spawn01(vName,vx+Xr,vy+Yr,0);
}

void spawnRandomZ(void vName,int vx, int vy, int vz )
// Spawn entity at random places
// 24.09.2013 - Douglas Baldan - O Ilusionista
// Based in Damon Caskey "spawn01" function, and you need that function to make it works.
// vx = maximum X position range
// vy = maximum Y position range
// vz = maximum Z position range
{
int Xr = rand()%vx;	// Random X pos
int Yr = rand()%vy;	// Random Y pos
int Zr = rand()%vz;	// Random Z pos

spawn000(vName,Xr,Yr,Zr);
}

void spawnRandEnt(void vName1,void vName2,void vName3,void vName4,int vx, int vy, int vz )
// Spawn Random entities at random places
// 03/02/2014 - Douglas Baldan - O Ilusionista
{
// int Xr = rand()%vx;	// Random X pos
// int Yr = rand()%vy;	// Random Y pos
// int Zr = rand()%vz;	// Random Z pos

int Sr = rand()%4+4;

if(Sr == 0){
        spawn000(vName1,vx,vy,vz);
       }
	   
else if(Sr == 1){
        spawn000(vName2,vx,vy,vz);
       }
else if(Sr == 2){
        spawn000(vName3,vx,vy,vz);
       }
else {
        spawn000(vName4,vx,vy,vz);
       }

}

void spawnRandomZAnim(void vName,int vx, int vy, int vz, void ani )
// Spawn entity at random places
// 24.09.2013 - Douglas Baldan - O Ilusionista
{
int Xr = rand()%vx;	// Random X pos
int Yr = rand()%vy;	// Random Y pos
int Zr = rand()%vz;	// Random Z pos
void    self   = getlocalvar("self");
spawn000(vName,Xr,Yr,Zr);
changeentityproperty(self, "animation", openborconstant(ani));
}


void refill(int iValue)
//Refill the MP bar witht the desired value.
//Douglas Baldan
{
    void self = getlocalvar("self");
    changeentityproperty(self, "mp", iValue);
}

void mpadd(int iValue)
//Refill the MP bar witht the desired value.
//Douglas Baldan
{
    void self = getlocalvar("self");
	void MPower = getentityproperty(self,"mp"); //get mp
    changeentityproperty(self, "mp", MPower+iValue);
}
	
void mpcost( int MCost)
{// Spend some life
    void self = getlocalvar("self");
    void MPower = getentityproperty(self,"mp"); //get mp
    changeentityproperty(self, "mp", MPower-MCost);//consume mp
}

void reinforcement (int Enemies,void vName, float fX, float fY, float fZ, void Ani, float Vx, float Vy, float Vz)
{
    void self = getlocalvar("self");
    int Enemy = openborvariant("count_enemies");

    if(Enemy < Enemies){
	spawnAni(vName, fX, fY,fZ,Ani,Vx,Vy,Vz);
	}
}

void reinforcementCheck (int Enemies, void Ani)
{
// Check how much enemies are on the screen and if it less than the desired, change caller animation
// Douglas Baldan - 28/09/2016
    void self = getlocalvar("self");
    int Enemy = openborvariant("count_enemies");

    if(Enemy < Enemies){
	performattack(self, openborconstant(Ani));
	}
}

void stealthMode (int sValue)
// sets the Stealth ability
// Douglas Baldan - 04/11/2013
// http://www.brazilmugenteam.com]www.brazilmugenteam.com
{
void self = getlocalvar("self");
changeentityproperty(self, "stealth", sValue);

}

void lifeCheck (int iLife, void Ani)
// Check the life and change the animation if the life is lower than given value
// Douglas Baldan - 04/01/2014
{
     void self = getlocalvar("self");
     void Health = getentityproperty(self,"health");

      if(Health<=iLife)
      {
        changeentityproperty(self, "animation", openborconstant(Ani));
      }
	  
}

void maxZ (int iZ)	
{
// controls the subject to Max Z
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
int z = getentityproperty(self,"z"); //Get character's z coordinate
changeentityproperty(self, "subject_to_maxz", iZ);
}

void minZ (int iZ)	
{
// controls the subject to Min Z
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
int z = getentityproperty(self,"z"); //Get character's z coordinate
changeentityproperty(self, "subject_to_minz", iZ);
}	

void gravity (int iG)
{
// controls the subject to gravity
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
changeentityproperty(self,"subject_to_gravity",iG);
}

void subjectWall (int iG)
{
// controls the subject to Wall
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
changeentityproperty(self,"subject_to_wall",iG);
}

void subjectScreen (int iG)
{
// controls the subject to Wall
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
changeentityproperty(self,"subject_to_screen",iG);
}

void noplayerJoin (int iG)
{
// controls if other players can join the game or not
// 1 - players CAN NOT join, 0 play CAN join
// remember to set it 0 when you are done, or you will have a 1P only game.
// Douglas Baldan/O Ilusionista - 20/09/14
changeopenborvariant("nojoin", iG);
}


void layer (int iG)
{
// Sets the entity layer
// Douglas Baldan/O Ilusionista
void self = getlocalvar("self");
changeentityproperty(self,"setlayer",iG);
}

void bmtFriction(float fX, float fY, float fZ)
{
// Reduces the actual velocity, simulating friction.
// Douglas Baldan - 13/01/2014
// http://www.brazilmugenteam.com
void self = getlocalvar("self");
float Xvel = getentityproperty(self, "xdir");// x velocity
float Yvel = getentityproperty(self, "tossv");// y velocity
float Zvel = getentityproperty(self, "zdir");// z velocity
changeentityproperty(self, "velocity", Xvel/fX, Yvel/fY, Zvel/fZ);
}

void randomAnim(int iLimit, int iChance, void Ani)
{
      void self = getlocalvar("self");
      int r = rand()%iLimit;

		if(r > iChance){
			performattack(self, openborconstant(Ani));
		}
}
	  
void shooterCD(void Shot, void Can, float dx, float dy, float dz, float Vx, float Vy, float Vz, int Dir)

{ // Shooting projectile with speed control and CanDamage control
// Douglas Baldan - Based on Bloodbane's codes
   void self = getlocalvar("self");
   int Dire;
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
     dx = -dx; //Reverse X direction to match facing
     if (Dir == 1){
       Dire = 0;
     } else if (Dir == -1){
       Dire = 1;
     }
   } else if (Direction == 1){ //Is entity facing right?                  
     if (Dir == 1){
       Dire = 1;
     } else if (Dir == -1){
       Dire = 0;
     }
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Dire, 0, 0, 0);
   changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
   changeentityproperty(vShot, "speed", Vx);
   changeentityproperty(vShot, "candamage", Can); 
}

void shooterAni(void Shot, float dx, float dy, float dz, void Ani, float Vx, float Vy, float Vz, int Dir)

{ // Shooting projectile with speed control
   void self = getlocalvar("self");
   int Dire;
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
     dx = -dx; //Reverse X direction to match facing
     if (Dir == 1){
       Dire = 0;
     } else if (Dir == -1){
       Dire = 1;
     }
   } else if (Direction == 1){ //Is entity facing right?                  
     if (Dir == 1){
       Dire = 1;
     } else if (Dir == -1){
       Dire = 0;
     }
   }
   
   vShot = projectile(Shot, x+dx, z+dz, y+dy, Dire, 0, 0, 0);
   changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
   changeentityproperty(vShot, "speed", Vx);
    performattack(vShot, openborconstant(Ani)); 

}

void spawnPosAni(void vName, float fX, float fY, float fZ, void Ani, int iDir)
{
	//Spawns entity based on left screen edge and z axis
	//Auto adjust with camera's position
	//vName: Model name of entity to be spawned in.
	//fX: X distance relative to left edge
	//fY: Y height from ground
      //fZ: Z coordinate
	  // Ani: Desired animation
      // iDir : Flip flag
	  // By Douglas Baldan / O Ilusionista - Based on BB's Spawn06 - 12.09.2014

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int Direction = getentityproperty(self, "direction");
        int XPos = openborvariant("xpos"); //Get screen edge's position
        int YPos = openborvariant("ypos"); // Get camera position
        int Screen = openborvariant("hResolution"); // Get screen width

	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Acquire spawn entity by name.

   if (Direction == 0){ //Is entity facing left?                  
      fX = Screen-fX; //Reverse X direction to match facing and screen length
   }

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX + XPos, fZ + YPos, fY); //Set spawn location.

	if (iDir == 1){  
	  changeentityproperty(vSpawn, "direction", Direction); //Set direction
        } else if (iDir == -1){  
	  if (Direction == 0){ 
	    changeentityproperty(vSpawn, "direction", 1); //Set direction
          } else {
	    changeentityproperty(vSpawn, "direction", 0); //Set direction
          }
        }
	performattack(vSpawn, openborconstant(Ani)); 
	return vSpawn; //Return spawn
}

void bmtcenter()
{		// centers the entity on the screen		
		// Douglas Baldan - 06/10/2014
        void self = getlocalvar("self"); //Get calling entity.
		int Screen = openborvariant("hResolution")/2; // Get screen width divided by 2
        int XPos = openborvariant("xpos"); // Get camera x position
        int Width = openborvariant("PLAYER_MIN_Z")+(openborvariant("PLAYER_MAX_Z") - openborvariant("PLAYER_MIN_Z"))/2; // Get playable area size center
        changeentityproperty(self, "position", Screen+XPos-20, Width+1, 0);

}

void bmtPosition(float fX, float fY, float fZ, int iDirection)
{
	// set the entity position on the screen + set direction
	// Douglas Baldan - 11/09/2016
	void self = getlocalvar("self"); //Get calling entity.
	changeentityproperty(self, "position", fX, fZ, fY); //Set entity position
	changeentityproperty(self, "direction", iDirection); //Set direction.	
}


void checkHelper(void Ani)
{
	// Check for Helper value and change the animation if no valid helper is found
	// Script releated to Avengers United Battle Force project
	// Douglas Baldan - 21/10/2016	
	void vSelf = getlocalvar("self");
	int getHelper = getglobalvar("HelperControl");
	 if(!getHelper || getHelper <1 ){
       performattack(vSelf, openborconstant(Ani));	   
  	}
	
}

void checkParentAnim(void PAni, void Ani)
{
	// Check the parent animation and change the caller animation if the parent animation is valid
	// Douglas Baldan / O Ilusionista - 11/10/2016
void self = getlocalvar("self");
void parent = getentityproperty(self, "parent");
void parAnim = getentityproperty(parent, "animationID");	
   if(parent!=NULL()){
		if (parAnim==openborconstant(PAni)) {
		changeentityproperty(self, "animation", openborconstant(Ani));
		}
   }		
}

void checkParentAnimName(void PAni, void Ani, char name)
{
	// Check the parent animation & name and change the caller animation if the parent animation is valid
	// Douglas Baldan / O Ilusionista - 11/10/2016
void self = getlocalvar("self");
void parent = getentityproperty(self, "parent");
void parAnim = getentityproperty(parent, "animationID");
void parName = getentityproperty(parent, "name");	
   if(parent!=NULL()){
		if (parAnim==openborconstant(PAni) && parName==name) {
		changeentityproperty(self, "animation", openborconstant(Ani));
		}
   }		
}

void checkParentHealth(void Ani)
{
	// Check the parent health and change the caller animation if the parent animation is valid
	// Douglas Baldan / O Ilusionista - 11/13/2016
void self = getlocalvar("self");
void parent = getentityproperty(self, "parent");
	if(parent!=NULL()){
	float Health = getentityproperty(parent,"health");
		if(Health<=0){
			changeentityproperty(self, "animation", openborconstant(Ani));
		}	
	}		
}


/// -------------------------------------------------------------------- by Mtrain
void rspeed()
// gives a random walk speed
{
   void spd = getentityproperty(getlocalvar("self"),"speed");
   void ri = rand()%1000+1000;
   void ra = rand()%1000+1000;
   float sp = spd + ( ri*0.001 + ra*0.001 )/10.0;
   changeentityproperty(getlocalvar("self"), "speed", sp);
}

void rrise()
//random rise anim
{    
   void self = getlocalvar("self");
      int r = rand()%30;
      if( r > 15){
        changeentityproperty(self, "animpos", 1);
      } else if( r < -15){
        changeentityproperty(self, "animpos", 2);
      } else if( r < 0){
        changeentityproperty(self, "animpos", 0);
      } else if( r > 0){
        changeentityproperty(self, "animpos", 3);
      }
}
