#import "data/scripts/randsound.c"
void visRise()
{
void self = getlocalvar("self");
int hpfx = getentityproperty(self, "health");
int r = rand()%900;
	
if (hpfx == 54)	playSound("data/chars/vision/sound/voice7.wav");
else if (hpfx == 78) playSound("data/chars/vision/sound/78.wav");
else if (hpfx == 2) playSound("data/chars/vision/sound/voice8.wav");
else if (hpfx <= 6) playSound("data/chars/vision/sound/035pct.wav");
else if (r<=-50) playSound("data/chars/vision/sound/voice6.wav");
else if (r<=50) playSound("data/chars/vision/sound/voice5.wav");
else playSound("data/sounds/null.wav");
}
