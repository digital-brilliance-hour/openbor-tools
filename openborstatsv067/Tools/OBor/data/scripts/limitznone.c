void main()
{ // Limits z movement to certain z coords
    void self = getlocalvar("self");
    int z = getentityproperty(self,"z"); //Get character's z coordinate
	int minZ = openborvariant("PLAYER_MIN_Z");
	int maxZ = openborvariant("PLAYER_MAX_Z");
	
    if(z < minZ){ // Reached z limit
      changeentityproperty(self, "position", NULL(), minZ+5);
    }
	if(z > maxZ){ // Reached z limit
      changeentityproperty(self, "position", NULL(), maxZ-5);
    }
}