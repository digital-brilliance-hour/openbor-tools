#include "data/scripts/ilu.h"
#import  "data/scripts/library/ani0020.h"
#import "data/scripts/randsound.c"
//#import "data/scripts/trail.c"

void spawn01(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
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
    
	return vSpawn; //Return spawn.
}

void spawn03(void vName, float fX, float fY, float fZ, int iDir)
{
	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fY: Y location adjustment.
      //fZ: Z location adjustment.

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

	if (iDir == 1){  
	  changeentityproperty(vSpawn, "direction", iDirection); //Set direction
        } else if (iDir == -1){  
	  if (iDirection == 0){ 
	    changeentityproperty(vSpawn, "direction", 1); //Set direction
          } else {
	    changeentityproperty(vSpawn, "direction", 0); //Set direction
          }
        }
    
	return vSpawn; //Return spawn.
}

void spawn06(void vName, float fX, float fY, float fZ)
{
	//Spawns entity based on left screen edge and z axis
	//Auto adjust with camera's position
	//vName: Model name of entity to be spawned in.
	//fX: X distance relative to left edge
	//fY: Y height from ground
      //fZ: Z coordinate

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
	return vSpawn; //Return spawn
}

void limiter(int Limit)
{// Prevents hero from performing the animation if his/her health is less than Limit
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health"); //Get entity's HP.

   if(Health<=Limit) // Don't have enough HP?
   {
     setidle(self); //Don't play the animation.
   }
}

void norun()
{// Turns off running status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "running", 0);
}



void block(int Flag)
{// Turns blocking status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void looper(int Frame, int Limit)
{// Loops current animation
    void self = getlocalvar("self");
    void loop = getlocalvar("Loop" + self);

    if(loop==NULL()){ // Localvar empty?
      setlocalvar("Loop" + self, 0);
      loop = 0;
    } 
   
    if(loop < Limit){ // loops reach limit?
      updateframe(self, Frame); //Change frame
      setlocalvar("Loop" + self, loop+1); // Increment number of loops
    }
}

void grabcheck()
{// Prevents hero from performing the slam if he/she's not grabbing anyone
   void self = getlocalvar("self");
   void target = getentityproperty(self, "grabbing");

   if(target==NULL())
   {
     setidle(self); //Don't perform the slam.
   }
}

void dethrown()
{// Disables thrown status
    void self = getlocalvar("self");

    changeentityproperty(self, "attacking", 0);
    changeentityproperty(self, "damage_on_landing", 0);
    changeentityproperty(self, "projectile", 0);
}

void beidle()
{// Go to IDLE animation!
    void self = getlocalvar("self");

    setidle(self);
}

void anti()
{ // Makes grabbed opponent slighty lifted to air
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     tossentity(target, 1, 0, 0); // Toss opponent a little ;)
   }
}

void anti2()
{ // Makes opponent slighty lifted to air
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int Check = checkgrab(target);
     if(Check == 1)
     {
       tossentity(target, 1, 0, 0); // Toss opponent a little ;)
     } else if(Check == 0)
     {
       beidle();
     }
   }
}

void fixGrab(void Ani)
{ // Makes grabbed opponent slighty lifted to air
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     tossentity(target, 1, 0, 0); // Toss opponent a little ;)
	 changeentityproperty(target, "animation", openborconstant(Ani));
     changeentityproperty(target,"subject_to_gravity",1);	 
   }
}

void fixGrab2(void Ani)
{ // Makes grabbed opponent slighty lifted to air
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     //tossentity(target, 0, 0, 0);
	changeentityproperty(target, "animation", openborconstant(Ani));
    changeentityproperty(target, "position", NULL(), NULL(), 1);
    changeentityproperty(target, "velocity", 0, 0, 0);
	//changeentityproperty(target, "speed", 0);
    changeentityproperty(target,"subject_to_gravity",0);	
   }
}

void anichange(void Ani)
{// Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}



void slamstart(int iDrop)
{ // Slam Starter
// Use finish after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 0, iDrop, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}


void slamstart2()
{ // Slam Starter for nongrab slams
// Use finish or throw after using this
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     damageentity(target, self, 1, 100, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}

void position(int Frame, float dx, float dy, float dz, int face)
{ // Modify grabbed entity's position relative to grabber
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     updateframe(target, Frame);
     bindentity(target, self, dx, dz, dy, face, 0);
   }
}

void depost(int Gr)
{// Release grabbed entity
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
   }
}

void antiwall_OLD(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
   }
}
void antiwall(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;
   float Hw;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);
   Hw = checkwall(x+Dist,z-Distz);

   if(Hz > y && Hw <= y)
   {
     changeentityproperty(self, "position", x, z-Distz);
   }

   if(H > y)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void antiwallHit(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int Vx = getentityproperty(self, "xdir"); // Get current x velocity
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "velocity", -Vx); // Reverses velocity
     changeentityproperty(self, "direction", 0);
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
   }
}

void antiwallturn(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;

   if (Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);

   if(Hz > 0)
   {
     changeentityproperty(self, "position", x, z-Distz);
	 
   }

   if(H > 0)
   {
     //changeentityproperty(self, "position", x+Move);
	 if(Direction==0){
	 changeentityproperty(self, "direction", 1);
	 
	 }if(Direction==1){
	 changeentityproperty(self, "direction", 0);
	  
	 }
   }
}
void antiwallanim(int Dist, int Move, int Distz, void Ani)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   float H;
   float Hz;
   float Hw;

   if(Direction == 0){ //Is entity facing left?                  
      Dist = -Dist; //Reverse Dist to match facing
      Move = -Move; //Reverse Move to match facing
   }

   H = checkwall(x+Dist,z);
   Hz = checkwall(x+Dist,z+Distz);
   Hw = checkwall(x+Dist,z-Distz);

   if(Hz > y && Hw <= y)
   {
     changeentityproperty(self, "position", x, z-Distz);
	 changeentityproperty(self, "animation", openborconstant(Ani));
   }

   if(H > y)
   {
	changeentityproperty(self, "position", x+Move);
    changeentityproperty(self, "animation", openborconstant(Ani));
   }
}

void hurt2(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL7")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 1, openborconstant("ATK_NORMAL7")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void hurt9(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL7")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 5;
       damageentity(target, self, Damage2, 1, openborconstant("ATK_NORMAL7")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void finish(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as slam or throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // 1st Finisher
     }

     if(Type==2)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL9")); // 2nd Finisher
     }

     tossentity(target, y, x, z); // Toss opponent ;)
	 changeentityproperty(target,"subject_to_gravity",1);
     changeentityproperty(target, "direction", MDir);
   }
}

void throw(int Damage, int Type, int x, int y, int z, int Face)
{ // Damage as throw finisher
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);
   int SDir = getentityproperty(target,"direction");
   int MDir;

   if(Face==0){ // Same facing?
       MDir = SDir;
   }

   if(Face==1){ // Opposite facing?

     if(SDir==0){ // Facing left?
       MDir = 1;
     } else { MDir = 0;}
   }

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
     if(dir==0){ // Facing left?
       x = -x;
     }

     if(Type==1)
     {
       damageentity(target, self, 1, 1, openborconstant("ATK_NORMAL")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 1, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 1, 1, openborconstant("ATK_NORMAL2")); // 3rd throw type
     }
	 
	 if(Type==4)
     {
       damageentity(target, self, 1, 1, openborconstant("ATK_SHOCK")); // 4rd throw type
     }
	 
	  if(Type==5)
     {
       damageentity(target, self, 1, 1, openborconstant("ATK_NORMAL11")); // 5th throw type
     }
	 
	 if(Type==6)
     {
       damageentity(target, self, 1, 1, openborconstant("ATK_BURN")); // 5th throw type
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void move(int dx, int dz,int da)
{ // Moves entity freely and ignores obstacles
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int z = getentityproperty(self,"z"); //Get character's z coordinate
    int a = getentityproperty(self,"a"); //Get character's a coordinate
    int dir = getentityproperty(self,"direction"); //Get character's facing direction

     if(dir==0){ // Facing left?
      changeentityproperty(self, "position", x-dx, z+dz, a+da); //Move
     }
     else if(dir==1){ // Facing right?
      changeentityproperty(self, "position", x+dx, z+dz, a+da); //Move
     }
}

void dasher( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
}

void leaper( float Vx, float Vy, float Vz )
{// Leap with desired speed!
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    tossentity(self, Vy, Vx, Vz); //Leap!
}

void stop()
{// Stop hero's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0);
	changeentityproperty(self, "speed", 0); //Stop moving!
}

void clearL()
{// Clears all local variables
     clearlocalvar();
}

void slammed(int Damage)
{
   // Hurt self
    void self = getlocalvar("self");
    damageentity(self, self, Damage, 1, openborconstant("ATK_NORMAL9")); // Slam damage is inserted here
    tossentity(self, 2, 0, 0);
}

void keyint(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
    void self = getlocalvar("self");
    void Health = getentityproperty(self,"health");    
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void iRKey;

      if (Key=="U"){ //Up Required?
       iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	}

      if (Key=="D"){ //Down Required?
        iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	}

      if (Key=="J"){ //Jump Required?
        iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	}

      if (Key=="A"){ //Attack Required?
        iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
	}

      if (Key=="S"){ //Special Required?
        iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	}

      if (Key=="A2"){ //Attack2 Required?
        iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack2"
	}

      if (Key=="UJ"){ //Up and Jump Required?
        iRKey = playerkeys(iPIndex, 0, "moveup", "jump"); // "Up" + "Jump"
	}

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if ((Health > Limit)&&iRKey){
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
        changeentityproperty(self, "animpos", Frame);

        if (Key=="UJ"){ 
          // This is copy of dethrown
          changeentityproperty(self, "attacking", 0);
          changeentityproperty(self, "damage_on_landing", 0);
          changeentityproperty(self, "projectile", 0);
        }
      }
}

void keyflip()
{// Change hero's facing direction if left or right is pressed
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index

    if (playerkeys(iPIndex, 0, "moveleft")){ // Left is pressed?
      changeentityproperty(self, "direction", 0); //Face left
    } else if (playerkeys(iPIndex, 0, "moveright")){ // Right is pressed?
      changeentityproperty(self, "direction", 1); //Face right
    }
}

void keymove(float V)
{// Move hero if direction button is pressed
      void self = getlocalvar("self");
      int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir = 0;
	float zdir = 0;

      if (playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
	  xdir = -V;
	} else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
	  xdir = V;
      }

	if(playerkeys(iPIndex, 0, "moveup")){// Up is pressed?
	  zdir = -V/2;
	} else if(playerkeys(iPIndex, 0, "movedown")){// Down is pressed?
	  zdir = V/2;
      }

	changeentityproperty(self, "velocity", xdir, zdir);
}

void spawn01map(void vName, float fX, float fY, float fZ)
{
	//spawn01 (Generic spawner)
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
	int  iMap = getentityproperty(self, "map"); // Get caller's remap.
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
	changeentityproperty(vSpawn, "map", iMap); //Set map.
    
	return vSpawn; //Return spawn.
}

void spawner(void vName, float fX, float fY, float fZ)
{	//Spawns entity next to caller and set them as child.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	
	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
    
	return vSpawn; //Return spawn.
}

void spawnbind(void Name, float dx, float dy, float dz, int iDir,int iBind)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, iDir, iBind);
}

void shoot(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
}

void shooter2(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{ // Shooting special projectile with speed control
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      Vx = -Vx; //Reverse Vx direction to match facing
   }

   vShot = spawn01(Shot, dx, dy, dz);
   changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
   changeentityproperty(vShot, "owner", self);
   return vShot;
}

void toss(void Bomb, float dx, float dy, float dz)
{ // Tossing bomb
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
}

void adjustX()
{// Special script for Bao's Air Pressure
// It moves Bao right to enemy's head
    void self = getlocalvar("self");
    void target = getlocalvar("Target" + self);

    if(target==NULL())
    {
      target = getentityproperty(self, "opponent");
      setlocalvar("Target" + self, target);
    }

    if(target!=NULL())
    {
      int x = getentityproperty(target,"x"); //Get target's x coordinate
      int z = getentityproperty(target,"z"); //Get target's z coordinate

      changeentityproperty(self, "position", x, z, 0); //Grounding
    }
}

void entergrab()
{// Script to change jumping state to grabattacking state
// Used in air grabs
    void self = getlocalvar("self");

    changeentityproperty(self, "aiflag", "jumping", 0); // Disable jumping status
    changeentityproperty(self, "aiflag", "attacking", 1); // Enable attacking status

    changeentityproperty(self, "takeaction", "common_grabattack"); // Enters grabattack
}

void grabcheckA(void Ani1, void Ani2, void Ani3)
{ // Hero's airgrab checker
// This script prevents hero from grabbing ground enemies, bikers, jetpacks, special enemies and non-enemy entities
//  Ani1 = Grab animation to play
//  Ani2 = Animation to play if hit enemy are bikers or jetpacks
//  Ani3 = Animation to play if hit opponent are not airborne enemies

    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");

    if(target!=NULL()){

      if(getentityproperty(target, "a") > 0){
        int Check = checkgrab(target);

        if(Check == 0)
        { 
          changeentityproperty(self, "animation", openborconstant(Ani2));
        } else if(Check == 1){
          setlocalvar("Target" + self, target);
          changeentityproperty(self, "animation", openborconstant(Ani1));
        }
      } else {
        changeentityproperty(self, "animation", openborconstant(Ani3));
      }

    }
}

void grabcheckG(void Ani1, void Ani2, void Ani3)
{ // Hero's groundgrab checker
// This script prevents hero from grabbing airborne enemies, bikers, jetpacks, special enemies and non-enemy entities
//  Ani1 = Grab animation to play
//  Ani2 = Animation to play if hit enemy are bikers or jetpacks
//  Ani3 = Animation to play if hit opponent are not ground enemies

    void self = getlocalvar("self");
    void target = getentityproperty(self, "opponent");

    if(target!=NULL()){

      if(getentityproperty(target, "a") == 0){
        int Check = checkgrab(target);

        if(Check == 0)
        { 
          changeentityproperty(self, "animation", openborconstant(Ani2));
        } else if(Check == 1){
          setlocalvar("Target" + self, target);
          changeentityproperty(self, "animation", openborconstant(Ani1));
        }
      } else {
        changeentityproperty(self, "animation", openborconstant(Ani3));
      }

    }
}

void checkgrab(void target)
{ // Opponent Checker
// This script checks hero's current opponent. If he/she/it is biker, jetpack, special enemy or non-enemy entity this function returns 0
// Otherwise it returns 1.

    if(getentityproperty(target, "type") == openborconstant("TYPE_ENEMY")){
      char Tname = getentityproperty(target, "defaultname");

      if(Tname == "Badai" || Tname == "BikerL" || Tname == "BikerL1" || Tname == "BikerT" || Tname == "Rider" || Tname == "Rider2" )
      { // Normal Bikers
        return 0;
      } else if(Tname == "BikerS" || Tname == "Storm" || Tname == "BikerAT" || Tname == "Bikeman" || Tname == "BikeBoss" )
      { // Special Bikers
        return 0;
      } else if(Tname == "Biker" || Tname == "RiderB" || Tname == "BikerB" || Tname == "Rover" || Tname == "Candy" || Tname == "Button")
      { // Bonus Bikers, Candy & Dog
        return 0;
      } else if(Tname == "Skystar" || Tname == "Aerial" || Tname == "Raidi" || Tname == "Rockette" || Tname == "Jetpac" || Tname == "Rocket")
      { // Jetpacks
        return 0;
      } else {
        return 1;
      }
    } else {
      return 0;
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

void shoot(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
   return vShot;
}

//void shooter(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz)
//{ // Shooting projectile with speed control
 //  void vShot = shoot(Shot, dx, dy, dz);
//
 //  changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
  // changeentityproperty(vShot, "speed", Vx);
//}
void shooter(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz, int Dir)

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
}

void shooterD(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz, int iDir)
{ // Shooting projectile with speed control and direction
   void self = getlocalvar("self");
   void vShot;

   vShot = shoot(Shot, dx, dy, dz);
   changeentityproperty(vShot, "direction", iDir);
   changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
   changeentityproperty(vShot, "speed", Vx);

}

void shootDir(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz, int iDir)
{ // Shooting projectile
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");
   void vShot;

     vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
	 changeentityproperty(vShot, "direction", iDir);
	changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
   
   return vShot;
}


void keyshoot(void Shot, float dx, float dy, float dz, float Vx, float Vz)
{ // Shooting projectile with key based speed control
    void self = getlocalvar("self");
    int iPIndex = getentityproperty(self,"playerindex"); //Get player index
    void vShot = shoot(Shot, dx, dy, dz);

    if (playerkeys(iPIndex, 0, "moveup")){
      changeentityproperty(vShot, "velocity", Vx, -Vz);
    } else if (playerkeys(iPIndex, 0, "movedown")){
      changeentityproperty(vShot, "velocity", Vx, Vz);
    } else {
      changeentityproperty(vShot, "velocity", Vx, 0);
    }
    changeentityproperty(vShot, "speed", Vx);
}

void toss(void Bomb, float dx, float dy, float dz)
{ // Tossing bomb
   void self = getlocalvar("self");
   int Direction = getentityproperty(self, "direction");
   int x = getentityproperty(self, "x");
   int y = getentityproperty(self, "a");
   int z = getentityproperty(self, "z");

   if (Direction == 0){ //Is entity facing left?                  
      dx = -dx; //Reverse X direction to match facing
   }

   projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
}

void velo001(float fX, float fZ, float fY){
     
    //velo001
	//Damon Vaughn Caskey
	//05/06/2007
	//
	//Replicates movement effect.
	//
	//fX: X axis speed.
	//fZ: Z axis speed.
	//fY: Y axis speed.
	
	void vSelf = getlocalvar("self"); //Get calling entity.
	
	if (getentityproperty(vSelf, "direction")==0){ //Is entity facing right?                  
     
         fX = -fX; ////Reverse X direction to match facing.
         
    }         
	
	changeentityproperty(vSelf, "velocity", fX, fZ, fY); //Apply movement.

}
void suicide()
{ // Suicide!!
    void self = getlocalvar("self");

    killentity(self); //Suicide!
}

void noscroll()
{
    void self = getlocalvar("self"); //Get calling entity.
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int XPos = openborvariant("xpos");

    changeentityproperty(self, "position", x - XPos);
}


void slow(int swi)
{
	changeopenborvariant("slowmotion", swi);
}
void targetL(float Vy, float dx, float dz)

{// Targetting opponent before performing targetted leap attack
// Vy = y Velocity
// dx = x added distance
// dz = z added distance

    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if (dir == 0){ //Is entity facing left? 
      dx = -dx; //Reverse X direction to match facing
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");

      if(Tx < x){
        changeentityproperty(self, "direction", 0);
      } else {
        changeentityproperty(self, "direction", 1);
      }

      x = x+dx;
      z = z+dz;
      setlocalvar("x"+self, (Tx-x)/(22*Vy));
      setlocalvar("z"+self, (Tz-z)/(22*Vy));

    } else {
      setlocalvar("z"+self, 0);
      setlocalvar("x"+self, 0);
    }
}

void target(float Velx, float Velz)
{// Targetting opponent before leaping or dashing
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction"); // Get enemy's facing direction
    float x = getentityproperty(self, "x"); // Get enemy's x coordinate
    float z = getentityproperty(self, "z"); // Get enemy's z coordinate

    setlocalvar("T"+self, findtarget(self)); // Find target and put it in local variable

    if( getlocalvar("T"+self) != NULL()){ // Is there a target?
      void target = getlocalvar("T"+self);
      float Tx = getentityproperty(target, "x"); // Get target's x coordinate
      float Tz = getentityproperty(target, "z"); // Get target's z coordinate
      float Disx = Tx - x; // Get x distance
      float Disz = Tz - z; // Get z distance

      if(Disx < 0){ // Negative Disx?
        Disx = -Disx; // Turn it to positive
        changeentityproperty(self, "direction", 0); // Face left
      } else {
        changeentityproperty(self, "direction", 1); // Face right
      }

      if(Disz < 0){ // Negative Disz?
        Disz = -Disz; // Turn it to positive
      }

      if(Disz < Disx) // Disx bigger than Disz?
      {
        if(Tx < x){ // Player is behind enemy?
          setlocalvar("x"+self, -Velx); // Turn Vx to negative
        } else { setlocalvar("x"+self, Velx); } // Use defined Vx

        setlocalvar("z"+self, Velx*(Tz-z)/Disx); // Calculate Vz then store value in local variable
      } else { // Disz bigger than Disx!
        if(Tz < z){ // Player is behind enemy?
          setlocalvar("z"+self, -Velz); // Turn Vz to negative
        } else { setlocalvar("z"+self, Velz); } // Use defined Vz

        setlocalvar("x"+self, Velz*(Tx-x)/Disz); // Calculate Vx then store value in local variable
      }

    } else { // No target at all!
      setlocalvar("z"+self, 0); // 0 velocity
      if(dir==0){ // Facing left?
        setlocalvar("x"+self, -Velx); // Negative velocity
      } else { setlocalvar("x"+self, Velx); } // Positive velocity
    }
} 


void dash()
{// Dash with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self); // Attain x velocity
    float Vz = getlocalvar("z"+self); // Attain z velocity
    if( Vx!=NULL() && Vz!=NULL() ){ // Are both velocity available?
      changeentityproperty(self, "velocity", Vx, Vz); //Move towards target!
    }
}

void leap(float Vely)
{// Leap with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);
    if( Vx!=NULL() && Vz!=NULL() ){
      tossentity(self, Vely, Vx, Vz); //Leap towards target!
    }
}

void spawn06(void vName, float fX, float fY, float fZ, int iDir)
{
	//Spawns entity based on left screen edge and z axis
	//Auto adjust with camera's position
	//vName: Model name of entity to be spawned in.
	//fX: X distance relative to left edge
	//fY: Y height from ground
      //fZ: Z coordinate
      // iDir : Flip flag

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

	return vSpawn; //Return spawn
}



		
void shoot_spawner(int follow, float fX, float fY, float fZ)
{


	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int direction = getentityproperty(self,"direction");
	int  vAlias = getentityproperty(self, "name");
	int  iHealth = getentityproperty(self, "health");
	int  iDirection = getentityproperty(self, "direction");
        killentity(getglobalvar("indexedw"+self));
	clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", getglobalvar("iWeapon" + self)); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?
          fX = -fX; ////Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
	changeentityproperty(vSpawn, "health", iHealth); //Set health.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
	
	if(direction ==1)changeentityproperty(vSpawn, "velocity", 10); //Set direction.
	if(direction ==0)changeentityproperty(vSpawn, "velocity", -10);
	
	performattack(vSpawn,openborconstant("ani_follow"+follow));
	changeentityproperty(self,"velocity",0,0,0);
        //changeentityproperty(vSpawn,"subject_to_gravity",0);
	
  	setglobalvar("iWeapon" + self,NULL());
  	setglobalvar("indexedw" + self,NULL());
  	setglobalvar("maxhealth" + self,NULL());
  	setglobalvar("health" + self,NULL());

 	return vSpawn; //Return spawn.

}
void nullopponent()
{

void self = getlocalvar("self");
if (getentityproperty(self,"opponent"))changeentityproperty(self,"opponent",NULL());


}

void checkobject()
{
void self 	= getlocalvar("self");
int pindex 	= getentityproperty(self,"playerindex");
void moveright 	= playerkeys(pindex, 0, "moveright");
void moveleft 	= playerkeys(pindex, 0, "moveleft");
int direction 	= getentityproperty(self,"direction");

    if(getentityproperty(self,"opponent"))
       {
       	void opp 	= getentityproperty(self,"opponent");
	int antigrab 	= getentityproperty(opp,"antigrab");

		if(direction == 1 && antigrab ==99 && moveright)performattack(self,openborconstant("ani_follow13"));
		if(direction == 0 && antigrab ==99 && moveleft)performattack(self,openborconstant("ani_follow13"));



       }





}

void aniNHoldSwitch(char vAni, char keyCond){
	void vEnt = getlocalvar("self");
	int iIndex = getentityproperty(vEnt, "playerindex");
	
	if(keyCond == "A2"){ // Is A2 pressed?
		if(keyCond == "A2" && !(((playerkeys(iIndex, 0, "attack2")))
			)
		){
				changeentityproperty(vEnt, "animation", openborconstant(vAni));
		}
	}
	
	     
	
	else if(! (playerkeys(iIndex, 0, keyCond) && ! playerkeys(iIndex, 2, keyCond))){
		changeentityproperty(vEnt, "animation", openborconstant(vAni));
	}
}

void scrollcam(float xoff, float zoff, float spd) {
  if( openborvariant("in_level") ) {
    changelevelproperty("cameraxoffset", xoff); //X offset for camera
    changelevelproperty("camerazoffset", zoff); //Z offset for camera
    changelevelproperty("scrollspeed", spd); //Scrolling camera speed
  }
}



///=============================================================================
void invincibleentity(void entity, int btime)
{
  //MatMan v0.03

        void iTime = openborvariant("elapsed_time") + getentityproperty(entity, "freezetime");

        changeentityproperty(entity, "invincible", 1);
        changeentityproperty(entity, "invinctime", iTime + btime);
  
        return entity;
}

void BShooter(void Name, float dx, float dy, float Vx, float Vy, int Angle)
{ // Shooting angled projectiles 
   void self = getlocalvar("self");
   void Missile;

   if(Angle == 0){
     Missile = shooter(Name, dx, dy, Vx, 0);
     changeentityproperty(Missile, "aggression", 0);
   } else if (Angle == 2){
     Missile = shooter(Name, dx, dy, Vx*0.7, Vy*0.7);
     changeentityproperty(Missile, "aggression", 2);
   } else if (Angle == 4){
     Missile = shooter(Name, dx, dy, 0, Vy);
     changeentityproperty(Missile, "aggression", 4);
   } else if (Angle == -2){
     Missile = shooter(Name, dx, dy, Vx*0.7, -Vy*0.7);
     changeentityproperty(Missile, "aggression", -2);
   } else if (Angle == -4){
     Missile = shooter(Name, dx, dy, 0, -Vy);
     changeentityproperty(Missile, "aggression", -4);
   }
}

void dodgez( float Vx, float Vy, float Vz )
{// Dodge by moving up or down depending on z location
    void self = getlocalvar("self");
    int z = getentityproperty(self, "z");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    if(z > (openborconstant("PLAYER_MIN_Z") + openborconstant("PLAYER_MAX_Z")) / 2 ) {
      Vz = -Vz ;
    }

    if( Vx!=NULL() && Vy!=NULL() && Vz!=NULL() ){
      changeentityproperty(self, "velocity", Vx, Vz, Vy); //Dodge away!
    }
}

void dodgeleapz( float Vx, float Vy, float Vz )
{// Dodge by leaping up or down depending on z location
    void self = getlocalvar("self");
    int z = getentityproperty(self, "z");
    int dir = getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    if(z > (openborconstant("PLAYER_MIN_Z") + openborconstant("PLAYER_MAX_Z")) / 2 ) {
      Vz = -Vz ;
    }

    if( Vx!=NULL() && Vy!=NULL() && Vz!=NULL() ){
      tossentity(self, Vy, Vx, Vz); //Dodge and leap away!
    }
}

void teledodgez( float dx, float dy, float dz )
{// Dodge by teleporting up or down depending on z location
    void self = getlocalvar("self");
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int z = getentityproperty(self,"z"); //Get character's z coordinate
    int a = getentityproperty(self,"a"); //Get character's a coordinate
    int dir = getentityproperty(self,"direction"); //Get character's facing direction
    float H;
    int FZ;

    if(z > (openborconstant("PLAYER_MIN_Z") + openborconstant("PLAYER_MAX_Z")) / 2 ) {
      dz = -dz ;
    }
    FZ = z+dz;

    if(dir==0){ // Facing left?
      dx = -dx ;
    }

    if((z + dz) > openborconstant("PLAYER_MAX_Z")) {
      FZ = openborconstant("PLAYER_MAX_Z");
    } else if((z + dz) < openborconstant("PLAYER_MIN_Z")) {
      FZ = openborconstant("PLAYER_MIN_Z");
    }

    H = checkwall(x+dx,FZ);

    if(H > 0){ // Is there a wall on teleport destination?
      dx = -dx ;
    }

    changeentityproperty(self, "position", x+dx, FZ, a+dy); //Teleport away!
}

void teletarget(int dx, int dy, int dz)
{// Targetting opponent then teleport to target
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");

    if(dir==0){ // Facing left?
      dx = -dx ;
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player

    if( getlocalvar("T"+self) != NULL()){
      void target = getlocalvar("T"+self);
      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");

      changeentityproperty(self, "position", Tx+dx, Tz+dz, dy); //Teleport to target!
    } 
}

void addhits(int hits)
{
// by Don Drago
	void self = getlocalvar("self");
	int previous = getentityproperty(self, "rush_count");
	changeentityproperty(self, "rush_count", previous+hits);
}

void checkent(void self)
{
  // V0.05 matman
  //Checks if a entity is alive and valid
  int s = 0;
  if ( self != NULL() )
  {
    if (
       getentityproperty(self, "exists")
   && !getentityproperty(self, "dead")
   //&&  getentityproperty(self, "health") > 0
   && getentityproperty( self, "aiflag", "autokill" ) == 0
    ) {
      //_gep_aiflag_autokill
      s = 1;
    }
  }
  return s;
}