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

			if(clearCount<=10)
			{
			    drawstring(235,458,0,"Secret Characters Unlocked");
			    drawstring(18,458,0,"v.beta 6");
			    ptitle=clearCount;
		            drawstring(98,158,1,"Unlocked "+ptitle);
			} else
			{
			    drawstring(18,158,0,"All Secret Characters Unlocked!");				
			}

		}
}

void main(){
drawstring( 190, 10,0,"Var (P1 Pos):  a = "+getentityproperty(getplayerproperty(0, "entity"), "a")); 
drawstring( 190, 20,1,"Var (P1 Pos):  x = "+getentityproperty(getplayerproperty(0, "entity"), "x")+"- z = "+getentityproperty(getplayerproperty(0, "entity"), "z") ); 
drawstring( 190, 30,0,"Var (Camera Z):  "+getlevelproperty("camerazoffset")+" Camera X:  "+getlevelproperty("cameraxoffset") ); 
drawstring( 190, 40,1,"Var (Time):  "+openborvariant("elapsed_time") % 10000 ); 
drawstring( 190, 50,0,"Var (animid):  "+getentityproperty(getplayerproperty(0, "entity"), "animationid") + " dir:  " + getentityproperty(getplayerproperty(0, "entity"),"direction") ); 
drawstring( 190,60,1,"Stage:  "+openborvariant("levelwidth")+" x "+openborvariant("levelheight"));
drawstring( 190,70,0,"Chars:  Enemies - "+openborvariant("count_enemies")+" - NPCs:  "+openborvariant("count_npcs"));
drawstring( 190, 90,1,"P1 stats:  Life= "+getentityproperty(getplayerproperty(0, "entity"), "health")+" - MP: " +getentityproperty(getplayerproperty(0, "entity"), "mp")); 
drawstring(190,100,0,"Damage:  "+getglobalvar("last_damage")+" - Last Combo Damage:  "+getglobalvar("last_combo_dmg"));
//drawstring(190,110,0,"Shield:  "+getglobalvar("ShieldC"));
//drawstring(190,120,0,"Arrow:  "+getlocalvar("arrowControl"));
drawstring(190,130,0,"Resolution:  "+openborvariant("hResolution"));




if(openborvariant("in_selectscreen"))
	{
		inTitleLoop(1);
		drawstring(18,258,0,"All Secret Characters Unlocked!");
	}
}

