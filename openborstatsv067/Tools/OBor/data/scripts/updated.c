void oncreate()
{
    if(!getglobalvar("spritex"))
    {
        setglobalvar("spritex", loadsprite("data/sprites/hud-base.gif"));
    }
	    if(!getglobalvar("spritex2"))
    {
        setglobalvar("spritex2", loadsprite("data/sprites/hud.gif"));
    }
}


void zoom()
{
   void vscreen = openborvariant("vscreen");
   int maxz=openborvariant("PLAYER_MAX_Z")+1000;
   int zoom_value=getglobalvar("zoomvalue");
   int zoom_x=getglobalvar("zoomx");
   int zoom_y=getglobalvar("zoomy");
   void ent=getglobalvar("zoomentity");
   int px=getentityproperty(ent,"x") +  zoom_x - openborvariant("xpos");
   int py=getentityproperty(ent,"z") + zoom_y - openborvariant("ypos") - getentityproperty(ent,"a");
   void zoom_scr = getglobalvar("zoomscreen");
   if(!zoom_scr){
      zoom_scr = allocscreen(openborvariant("hResolution"),openborvariant("vResolution"));
      setglobalvar("zoomscreen",zoom_scr);
   }
   clearscreen(zoom_scr);

   //draw what we need 
   drawspriteq(zoom_scr,0,openborconstant("MIN_INT"),maxz,0,0);
   //setup drawMethod
   changedrawmethod(NULL(),"reset",1);
   changedrawmethod(NULL(),"enabled",1);
   changedrawmethod(NULL(),"scalex",zoom_value);
   changedrawmethod(NULL(),"scaley",zoom_value);
   changedrawmethod(NULL(),"centerx",px);
   changedrawmethod(NULL(),"centery",py);
   //Draw the resized customized screen to main screen.
   drawscreen(zoom_scr,px,py, maxz+1);
   changedrawmethod(NULL(),"enabled", 0);
   drawspriteq(vscreen, 0, maxz+1,maxz+1, 0, 0);
   drawspriteq(vscreen, 0, maxz+2,openborconstant("MAX_INT"), 0, 0);
   clearspriteq();
}


void inTitleLoop(int distitle)
{
	void clearCount,ptitle;
	

		if(distitle)
		
		{
			clearCount=getglobalvar("clearCount");
                        if(clearCount==NULL()){ // clearCount empty?
                          setglobalvar("clearCount", 0);
                          clearCount = 0;
                        } 

			if(clearCount<=2)
			{
			    //drawstring(335,258,0,"Secret Characters Unlocked");
			    drawstring(18,258,0,"Version 12.25.16");
			    ptitle=clearCount;
		        drawstring(355,258,1,"Unlocked "+ptitle);
			} else
			{
			    drawstring(18,258,0,"All Secret Characters Unlocked!");				
			}

		}
}


void main(){
if(openborvariant("in_level"))
{	
//drawstring( 190, 10,0,"Var (P1 Pos):  a = "+getentityproperty(getplayerproperty(0, "entity"), "a")); 
//drawstring( 190, 10,0,"Var (P1 Pos):  z = "+getentityproperty(getplayerproperty(0, "entity"), "z")); 
//drawstring( 190, 20,1,"Var (P1 Pos):  x = "+(getentityproperty(getplayerproperty(0, "entity"), "x"))/10.0+"- z = "+getentityproperty(getplayerproperty(0, "entity"), "z") );
//drawstring( 190, 30,0,"Var (Camera Z):  "+getlevelproperty("camerazoffset")+" Camera X:  "+getlevelproperty("cameraxoffset") ); 
//drawstring( 190, 40,1,"Var (Time):  "+openborvariant("elapsed_time") % 10000 ); 
//drawstring( 190, 50,0,"Var (animid):  "+getentityproperty(getplayerproperty(0, "entity"), "animationid") + " dir:  " + getentityproperty(getplayerproperty(0, "entity"),"direction") ); 
//drawstring( 190,60,1,"Stage:  "+openborvariant("levelwidth")+" x "+openborvariant("levelheight"));
//drawstring( 140,50,0,"Chars:  Enemies - "+openborvariant("count_enemies")+" - NPCs:  "+openborvariant("count_npcs")+" - Ents:  "+openborvariant("count_entities"));
//drawstring( 190, 90,1,"P1 stats:  Life= "+getentityproperty(getplayerproperty(0, "entity"), "health")+" - MP: " +getentityproperty(getplayerproperty(0, "entity"), "mp")); 

//drawstring(190,100,0,"Damage:  "+getglobalvar("last_damage")+" - Last Combo Damage:  "+getglobalvar("last_combo_dmg"));
//drawstring(190,40,0,"Helper:  "+getglobalvar("HelperControl"));
//drawstring(190,60,0,"Ammo:  "+getglobalvar("ammoControl"));
//drawstring(190,60,1,"MindControl:  "+getglobalvar("MindControl"));
//drawstring(190,120,0,"Arrow:  "+getlocalvar("arrowControl"));
//drawstring(190,130,0,"Resolution:  "+openborvariant("hResolution")); 
//void HUD = loadsprite("data/sprites/hud-base.gif");
//void HUD2 = loadsprite("data/sprites/hud.gif");


//========================================== WHITE DRAGON ENTITY NAME DEBUG ========================
int debugWD = getglobalvar("debugWD");

if (debugWD==1){
int i = 0, count = 0;
int x = 10, y = 70, font_index = 0, yspace = 10;
int prev_strwidth = 0, cols = 4;

for(i = 0; i < openborvariant("count_entities"); i++) {
	void ent = getentity(i);
	char name = "", comma = ", ";
	int col = count/cols; // current colon

	if ( ent == NULL() || !getentityproperty(ent,"exists") ) continue;

	name = getentityproperty(ent,"model");
	if (i >= openborvariant("count_entities")-1) comma = "";

	drawstring(x+prev_strwidth,y+yspace*col,font_index,(name+comma));

	prev_strwidth += strwidth((name+comma),font_index); // sum row spaces
	++count; // count ents
	if (col < count/cols) prev_strwidth = 0; // reset colons
}

}
//========================================== 

//drawstring(201,2,3,"stage:  "+openborvariant("current_stage"));
//void HUD;
//void HUD2;

//if (!HUD){
//	HUD = loadsprite("data/sprites/hud-base.gif");
//}
//if (!HUD2){
//	HUD2 = loadsprite("data/sprites/hud.gif");
//}

//drawsprite(getglobalvar("spritex"), 0, 0, 8000, -100);
//drawsprite(getglobalvar("spritex2"), 0, 0, 10000, -100);

//drawsprite(HUD2, 0, 0, 10000, -100);

//DEBUG
//drawstring(220,225,0,"Helper= "+getglobalvar("HelperControl"));
//drawstring(220,235,0,"Gun= "+getglobalvar("ammoControl"));
//drawstring(220,55,0,"Boss Kill= "+getglobalvar("BossKill"));

//testing lines
//drawline(x1, y1, x2, y2, z, color, alpha);
void P1 = getplayerproperty(0, "entity");
void P2 = getplayerproperty(1, "entity");
if (P1){
//hp
drawline(62, 243, 62, 246, 10000, rgbcolor(171,75,0), 0);
drawline(72, 243, 72, 246, 10000, rgbcolor(171,75,0), 0);
drawline(82, 243, 82, 246, 10000, rgbcolor(171,75,0), 0);
drawline(92, 243, 92, 246, 10000, rgbcolor(171,75,0), 0);
drawline(102, 243, 102, 246, 10000, rgbcolor(171,75,0), 0);
drawline(112, 243, 112, 246, 10000, rgbcolor(171,75,0), 0);
//mp
drawline(82, 250, 82, 253, 10000, rgbcolor(171,75,0), 0);
}

if (P2){
//hp
drawline(367, 243, 367, 246, 10000, rgbcolor(171,75,0), 0);
drawline(377, 243, 377, 246, 10000, rgbcolor(171,75,0), 0);
drawline(387, 243, 387, 246, 10000, rgbcolor(171,75,0), 0);
drawline(397, 243, 397, 246, 10000, rgbcolor(171,75,0), 0);
drawline(407, 243, 407, 246, 10000, rgbcolor(171,75,0), 0);
drawline(417, 243, 417, 246, 10000, rgbcolor(171,75,0), 0);
//mp
drawline(397, 250, 397, 253, 10000, rgbcolor(171,75,0), 0);
}

}


if(openborvariant("game_paused"))
{
//void HUD;
//if (!HUD){
//	HUD = loadsprite("data/sprites/hud-base.gif");
//}	
//drawsprite(HUD, 0, -20, 8000, -100);
}










   if(getglobalvar("zoomentity"))
   {
      zoom();        
   }
   
   
   if(openborvariant("in_titlescreen")||openborvariant("in_menuscreen")||openborvariant("in_selectscreen"))
	{
		inTitleLoop(1);
	}
		if(openborvariant("in_titlescreen"))
	{	
        void contador = getlocalvar("contador"); 
		void counter = getlocalvar("counter"); 
		counter = setlocalvar("counter",0);
		
		int SFX1 = loadsample("data/sounds/voices/start.wav");
		while(contador!=1)
		{
	        playsample(SFX1, 0, 120, 120, 100, 0);
		contador = setlocalvar("contador",1);

		}
		
	}
	
	//		if(openborvariant("in_menuscreen"))
	//{	
    //    void contadorm = getlocalvar("contadorm"); 
	//	int SFX1 = loadsample("data/sounds/voices/start.wav");
	//	while(contadorm!=1)
	//	{
	 //       playsample(SFX1, 0, 120, 120, 100, 0);
	//	contadorm = setlocalvar("contadorm",1);
	//	}
		
		
	//}
	
			if(openborvariant("in_selectscreen"))
	{	
  
		void counter = getlocalvar("counter"); 
		void vSpawn;
		int SFX1 = loadsample("data/sounds/voices/choose.wav");
		while(counter!=1)
		{
	        playsample(SFX1, 0, 120, 120, 100, 0);
			counter = setlocalvar("counter",1);
			playgif("data/scenes/selectani.gif" , 0, 0, 1);
			void subent;
			loadmodel("rain");
			clearspawnentry();
			setspawnentry("name", "rain");
			setspawnentry("coords", 50,250,0);
			subent=spawn();
			changeentityproperty(subent, "position", 50,250,0); //for safe
			//counter = setlocalvar("counter",1);
			}
	}
	
	
}
void ondestroy()
{ 
   if(getglobalvar("stageName"))
    {
        free(getglobalvar("stageName"));
        setglobalvar("stageName",  NULL());
    }
	
	   if(getglobalvar("spritex"))
    {
        free(getglobalvar("spritex"));
        setglobalvar("spritex",  NULL());
    }
		if(getglobalvar("spritex2"))
    {
        free(getglobalvar("spritex2"));
        setglobalvar("spritex2",  NULL());
    }
		if(getglobalvar("arrowControl"))
    {
        free(getglobalvar("arrowControl"));
        setglobalvar("arrowControl",  NULL());
    }

}



