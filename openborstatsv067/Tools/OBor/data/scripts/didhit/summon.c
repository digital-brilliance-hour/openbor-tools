#include "data/scripts/grabscript.c"
void main()
{
   setglobalvar("HelperControl", 1);
   int SFX1 = loadsample("data/sounds/announcer/avengers-assemble.wav");
   playsample(SFX1, 0, 120, 120, 100, 0);
   spawnAni("aitemFX",0,30,0,"ANI_FOLLOW5",NULL(),NULL(),NULL());	
}
