void main()
{
    int i; int z; int t;int health;int off;
    void pl;
	char cstring;
    if(openborvariant("in_level")==1)
    {
        z = openborconstant("FRONTPANEL_Z");
        for(i=0; i<3; i++)
        {
            pl = getplayerproperty(i, "ent");
            if(pl!=NULL())
            {
                void self = getlocalvar("self");
				void target = findtarget(self); 
				health = getentityproperty(target, "health");
				
			
			if (health<=15)// checks if the health is 15 or less and draws a red box
			{
				//drawbox(x, y, width, height, z, color, alpha)		
				drawbox(i*160+54, 142, health, 6, z+18000, rgbcolor(255,0,0));//health red
			} else { // if not, draws a yellow box
				drawbox(i*160+54, 142, health, 6, z+18000, rgbcolor(255,180,0));//health yellow 1
				
		}
            }
        }
    }
}