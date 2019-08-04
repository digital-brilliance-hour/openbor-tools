#include "data/scripts/define.h"

void afterimg(){
	afterimga(6);
}

void afterimga(int alpha)
{
	void k,facing,cd,spr,a,z,x,img,spra;
	void ent = getlocalvar("self");
	int elapsed_time = openborvariant("elapsed_time");
	if(!(elapsed_time%trailerd))
	{
		spr	=	getentityproperty(ent,"sprite");
		x	=	getentityproperty(ent,"x");
		z	=	getentityproperty(ent,"z");
		a	=	getentityproperty(ent,"a");
		facing=	!getentityproperty(ent,"direction");

		for(k=1; k<=trailermax; k++)
		{
			void img=getglobalvar("trailer."+k);
			if(!img)img=array(8);
			spra=get(img,IMG_SPRITE);
			if(!spra){
				set(img,IMG_SPRITE,spr);
				set(img,IMG_X,x);
				set(img,IMG_Z,z);
				set(img,IMG_A,a);
				set(img,IMG_FACING,facing);
				set(img,IMG_TIME,elapsed_time );
				set(img,IMG_COLORMAP,getentityproperty(ent, "colourmap"));
				set(img,IMG_ALPHA, alpha);
				setglobalvar("trailer."+k,img);
				break;
			}
		}
	}
}

void getani()
{
	void ent = getlocalvar("self");
	return getentityproperty(ent,"animationID");
}

void getframe()
{
	void ent = getlocalvar("self");
	return getentityproperty(ent,"animpos");
}
