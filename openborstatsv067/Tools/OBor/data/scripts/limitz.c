void main()
{ // Limits z movement to certain z coords
    void self = getlocalvar("self");
    int z = getentityproperty(self,"z"); //Get character's z coordinate

    if(z != 200){ // Reached z limit
      changeentityproperty(self, "position", NULL(), 200);
      changeentityproperty(self, "velocity", NULL(), 0);
    }
}