#include "data/scripts/grabscript.c"
void main(){
	// Custom sounds for picking itens
	// Douglas Baldan / O Ilusionista - 11/12/2016
	// Thanks Damon Caskey for the support
	
	void self = getlocalvar("self"); //get the self var
	void hit = getlocalvar("damagetaker"); // get target entity
	char Name = getentityproperty(self,"name"); // get target's name
	void power = getentityproperty(hit,"mp"); // get target's current mp 
	
	int SFX1 = loadsample("data/sounds/power-up.wav"); // load samples
	int SFX2 = loadsample("data/sounds/life-up.wav");
	int SFX3 = loadsample("data/sounds/full-power.wav");
	int SFX4 = loadsample("data/sounds/full-life.wav");
	int SFX5 = loadsample("data/sounds/power-life.wav");
	
	switch(Name) { // check the item name
		case "iMP" : // power up
        playsample(SFX1, 0, 120, 120, 100, 0);
		spawnAni("aitemFX",0,30,0,"ANI_FOLLOW1",NULL(),NULL(),NULL());			
        break;
		
		case "iHP" : // life up
		case "cola" : // life up
        playsample(SFX2, 0, 120, 120, 100, 0);
		spawnAni("aitemFX",0,30,0,"ANI_IDLE",NULL(),NULL(),NULL());		
        break;
		
		case "iFMP" : // full power up
        playsample(SFX3, 0, 120, 120, 100, 0);
		spawnAni("aitemFX",0,30,0,"ANI_FOLLOW4",NULL(),NULL(),NULL());			
        break;
		
		case "iFHP" : // full life up
        playsample(SFX4, 0, 120, 120, 100, 0);
		spawnAni("aitemFX",0,30,0,"ANI_FOLLOW3",NULL(),NULL(),NULL());			
        break;
		
		case "iHPMP" : // life and power up
		changeentityproperty(hit, "mp", power+30);  // add 30 to entity power
        playsample(SFX5, 0, 120, 120, 100, 0);
		spawnAni("aitemFX",0,30,0,"ANI_FOLLOW2",NULL(),NULL(),NULL());			
        break;
		
		case "1up" : // power up
		spawnAni("aitemFX",0,30,0,"ANI_FOLLOW6",NULL(),NULL(),NULL());			
        break;
		
		default : // in case of none of above
        break;
   }
}	