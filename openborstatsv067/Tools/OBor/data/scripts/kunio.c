//#include "data/scripts/common/spawn.c"
//#include "data/scripts/common/commons.c"
//#include "data/scripts/common/cmdslam.c"
//#include "data/scripts/common/player.c"
//#include "data/scripts/library/spawn.h"
//#include "data/scripts/ani0020.h"

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


void stop()
{// Stop hero's movement!
    void self = getlocalvar("self");
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void keymove(float Vx, float Vz)
{// Move hero if direction button is pressed
      void self = getlocalvar("self");
      int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir = 0;
	float zdir = 0;

      if (playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
	  xdir = -Vx;
	} else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
	  xdir = Vx;
      }

	if(playerkeys(iPIndex, 0, "moveup")){// Up is pressed?
	  zdir = -Vz;
	} else if(playerkeys(iPIndex, 0, "movedown")){// Down is pressed?
	  zdir = Vz;
      }

	changeentityproperty(self, "velocity", xdir, zdir);
}

void anichange(void Ani)
{// Animation changer
    void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}

void attack1(int RxMin, int RxMax, int Rz, void Ani)
{// Attack interruption with range check
    void self = getlocalvar("self");
    void target = findtarget(self); //Get nearest player
    float x = getentityproperty(self, "x");
    float z = getentityproperty(self, "z");
    int dir = getentityproperty(self, "direction");

    if(target!=NULL()){
      float Tx = getentityproperty(target, "x");
      float Tz = getentityproperty(target, "z");
      float Disx = Tx - x;
      float Disz = Tz - z;

      if(Disz < 0){
        Disz = -Disz;
      }

      if( Disx >= RxMin && Disx <= RxMax && Disz <= Rz && dir == 1) // Target within range on right facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      } else if( Disx >= -RxMax && Disx <= -RxMin && Disz <= Rz && dir == 0) // Target within range on left facing?
      {
        performattack(self, openborconstant(Ani)); //Change the animation
      }
    }
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

void floater( int Time )
{// Floats in Time centiseconds
    void self = getlocalvar("self");
    int eTime = openborvariant("elapsed_time");

    changeentityproperty(self, "tosstime", eTime + Time*2);
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
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // 1st throw type
     }

     if(Type==2)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
     }

     if(Type==3)
     {
       damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL2")); // 3rd throw type, enemies can autoland here
     }

     changeentityproperty(target, "attacking", 1);
     changeentityproperty(target, "damage_on_landing", Damage);
     changeentityproperty(target, "projectile", 1);
     changeentityproperty(target, "direction", MDir);
     tossentity(target, y, x, z); // Toss opponent ;)
   }
}
