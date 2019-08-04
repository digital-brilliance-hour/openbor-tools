#include "data/scripts/library/ani0009.h"
#include "data/scripts/library/run0001.h"

int ani0020(int iAni, int iTAni){
    
	/*
	ani0020
	Damon Vaughn Caskey
	Perform alternate animation if target is within range and in specified animation.

	iAni:	Alternate attack.
	iTAni:	Target animation.
	*/

    void vSelf      = getlocalvar("self");					//Caller.                                                         
    void vOpp       = findtarget(vSelf, iAni);				//Nearest target in range of alternate attack.
	
	if (vOpp)												//Found a target?
	{
		if(getentityproperty(vOpp, "animationID") == iTAni)	//Animation match?
		{
			ani0009(vSelf, iAni, 0);						//Perform alternate attack.
			return 1;										//Return 1.
		}
	}

	return 0;												//Return 0.
}

void bind(int null, float x, float z, float y, int dir){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	if(null == 1)
	{
		bindentity(opp, self, x, z, y, dir, 0);
	}
	else if(null == 0)
	{
		bindentity(opp, NULL());
	}
}

void forceanim(int anim){
	void self = getlocalvar("self");
	void opp = getentityproperty(self, "opponent");
	changeentityproperty(opp, "animation", anim);
}

void beidle()
{// Go to IDLE animation!
    void self = getlocalvar("self");

    setidle(self);
}

void block(int Flag)
{// Turns blocking status
    void self = getlocalvar("self");
    changeentityproperty(self, "aiflag", "blocking", Flag);
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void slamstart()
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
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
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
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
   }
}

void slamstart3()
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
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // Slam Starter
   }
}

void slamstart4()
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
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // Slam Starter
   }
}

void slamstart5()
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
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL6")); // Slam Starter
   }
}

void slamstart6()
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
     damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL6")); // Slam Starter
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

void antiwall(int Dist, int Move, int Distz)
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

void antiwall2(int Dist, int Move, int Distz)
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
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
   }

   if(H > 0)
   {
     changeentityproperty(self, "position", x+Move);
     changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
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
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL5")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_BURN")); // 3rd throw type
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}

void stop()
{// Stop hero's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void clearL()
{// Clears all local variables
     clearlocalvar();
}

void degravity(int Ratio)
{// Changes antigravity effect
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
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

      if (Key=="UA"){ //Up and Attack Required?
        iRKey = playerkeys(iPIndex, 0, "moveup", "Attack"); // "Up" + "Attack"
	}

      if (Key=="DA"){ //Down and Attack Required?
        iRKey = playerkeys(iPIndex, 0, "movedown", "Attack"); // "Down" + "Attack"
	}

      if (Hflag==1){ //Not holding the button case?
        iRKey = !iRKey; //Take the opposite condition
	}

      if ((Health > Limit)&&iRKey){
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
        changeentityproperty(self, "animpos", Frame);

        if (Key=="UA"){ 
          // This is copy of dethrown
          changeentityproperty(self, "attacking", 0);
          changeentityproperty(self, "damage_on_landing", 0);
          changeentityproperty(self, "projectile", 0);
        }

        if (Key=="DA"){ 
          // This is copy of dethrown
          changeentityproperty(self, "attacking", 0);
          changeentityproperty(self, "damage_on_landing", 0);
          changeentityproperty(self, "projectile", 0);
        }
      }
}

void nograb(int Flag)
{// Turns grabbable status
    void self = getlocalvar("self");
    changeentityproperty(self, "nograb", Flag);
}

void antiwall(int Dist, int Move, int Distz)
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

void anichange(void Ani)
{// Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}

void hurt(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     void THealth = getentityproperty(target,"health"); //Get target's health
     if(THealth > Damage)
     {
       changeentityproperty(target, "health", THealth - Damage); //Damage target with desired damage
     } else {
       changeentityproperty(target, "health", 1); //Damage target with less damage
     }
   }
}

void hurt2(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 0, openborconstant("ATK_NORMAL7")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 0, openborconstant("ATK_NORMAL7")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

void hurt3(int Damage)
{ // Damage without altering opponent's animation + less damage if opponent has less health
// Mainly used for slams
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "opponent");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     int THealth = getentityproperty(target,"health"); //Get target's health
     int TAniPos = getentityproperty(target,"animpos"); //Get target's animation frame
     if(THealth > Damage)
     {
       damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // Damage target with desired damage
       updateframe(target, TAniPos);
     } else {
       int Damage2 = THealth - 1;
       damageentity(target, self, Damage2, 1, openborconstant("ATK_NORMAL")); //Damage target with less damage
       updateframe(target, TAniPos);
     }
   }
}

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

void spawnbind(void Name, float dx, float dy, float dz)
{ // Spawn and bind other entity
   void self = getlocalvar("self");
   void Spawn;

   Spawn = spawn01(Name, dx, dy, 0);
   bindentity(Spawn, self, dx, dz, dy, 0, 0);
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

void riseattack(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        if(Tx < x){
          changeentityproperty(self, "direction", 0);
        } else {
          changeentityproperty(self, "direction", 1);
        }
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      } 
    }
}

void riseattack2(int Rx, int Rz, void Ani)
{// Riseattack with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disx < 0){
        Disx = -Disx;
      }
      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx <= Rx && Disz <= Rz ) // Target within range?
      {
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
      } 
    }
}

void conditionalflip()
{
	void self = getlocalvar("self");
	int p = getentityproperty(self, "playerindex");
	int dir = getglobalvar("p"+p+"lastdir");
	int sdir = getentityproperty(self, "direction");
	int flip;
	if(dir!=NULL() && dir!=sdir)
	{
		flip = 0;
	}
	else
	{
		flip = 1;
	}

	if(flip) {
		changeentityproperty(self, "direction", !sdir);
	}

}

void paus0001(int iToggle, int iTime){

    /*
    paus0001
    Damon Vaughn Caskey
    11022009
    Pause or unpause action for all entities except self.
    */

    void vSelf      = getlocalvar("self");                  //Caller    
    int  iETime     = openborvariant("elapsed_time");       //Current time.
    int  iMax       = openborvariant("ent_max");            //Entity count.
    int  iEntity;                                           //Loop counter.
    void vEntity;                                           //Target entity.

    for(iEntity=0; iEntity<iMax; iEntity++)
    {    
        vEntity = getentity(iEntity);                                       //Get target entity from current loop.        
        
        if (vEntity != vSelf)                                               //Not Self?
        {
            changeentityproperty(vEntity, "frozen", iToggle);               //Toggle frozen.
            changeentityproperty(vEntity, "freezetime", iETime + iTime);    //Toggle frozen time.
        }
    }    
}

