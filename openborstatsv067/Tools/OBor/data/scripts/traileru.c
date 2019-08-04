#include "data/scripts/trailer.h"

void main()
{
	int i, j, k;
	void spr;
	int facing, cd;
	float a, z, x;
	float sx = 256;
	float sy = 256;
void map = getglobalvar("blahblah.map");
	for(i=1; i<=trailermax; i++)
	{
		spr = getglobalvar("trailer"+i+".s");
		if(spr)
		{
			cd = getglobalvar("trailer"+i+".c");
			if(!cd) 
			{
				setglobalvar("trailer"+i+".c", NULL());
				setglobalvar("trailer"+i+".s", NULL());
				setglobalvar("trailer"+i+".x", NULL());
				setglobalvar("trailer"+i+".z", NULL());
				setglobalvar("trailer"+i+".a", NULL());
				setglobalvar("trailer"+i+".sx", NULL());
				setglobalvar("trailer"+i+".sy", NULL());
			}
			else
			{
				if(openborvariant("game_paused")==0)
				{
					setglobalvar("trailer"+i+".c", cd-1);
				}
				x = getglobalvar("trailer"+i+".x");
				z = getglobalvar("trailer"+i+".z");
				a = getglobalvar("trailer"+i+".a");
				if ( getglobalvar("trailer"+i+".sx") != NULL()) { sx = getglobalvar("trailer"+i+".sx"); }
				if ( getglobalvar("trailer"+i+".sy") != NULL()) { sy = getglobalvar("trailer"+i+".sy"); }
				facing = getglobalvar("trailer"+i+".f");
                                //,entity ,flag ,scalex ,scaley ,flipx ,flipy ,shiftx ,alpha ,colourmap ,fillcolour ,rotate ,rotateflip ,transparencybg
                                //setdrawmethod(NULL(),1, 256,256,facing,0,0,6,0,0,0,0,0,getglobalvar("trailer"+i+".colormap"));
                                setdrawmethod(NULL(),1, sx, sy,facing,0,0,6,0,0,0,0,0,map);
								
                                //drawsprite(spr, x-openborvariant("xpos"), z-a-openborvariant("ypos"), z-i, 0);

				//setdrawmethod(NULL(), 1, 256, 256, facing, 0, 0, 6, 0);
				//drawsprite(sprite, int x, int y, int z, int sortid)
				drawsprite(spr, x-openborvariant("xpos"), z-a-openborvariant("ypos")-3, z-i, 0);
                                //setdrawmethod(NULL(),0, 256, 256,0,    0,0,0,0,0,0,0,0,NULL());
			}
		}
	}
}