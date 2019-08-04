#include "data/scripts/ilu.h"
#import "data/scripts/grabscript.c"
void main()
{
void self = getlocalvar("self");
int health = getentityproperty(self,"health");

int  selfx     = getentityproperty(self, "x");
int XPos = openborvariant("xpos"); //Get screen edge's position
int YPos = openborvariant("ypos"); // Get camera position
setglobalvar("BossKill", 2); // Reset Emma's mind control

if (selfx > XPos + 480 ){
		spawn06("kofx", 240, 0, 140, 1);
      } else if (selfx < XPos + 1 ){
		spawn06("kofx", 240, 0, 140, 1);
      } else {
		spawn01("kofx", 0, 40, 0); 
	  }

  
}