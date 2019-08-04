void summonH()
{//Script for summoning based on item's alias
    void self = getlocalvar("self");
    //char Item = getentityproperty(self,"name");
    void target = getlocalvar("damagetaker"); // Get player who picks the item
    int  PIndex = getentityproperty(target,"playerindex"); // Get player's index
    int  PScore = getplayerproperty(PIndex,"score"); // Get player's score
    int Direction = getentityproperty(target, "direction");
    int fZ = getentityproperty(target, "z"); //Get Z location
    int XPos = openborvariant("xpos"); //Get screen edge's position
    int Screen = openborvariant("hResolution"); // Get screen width
    int fX = 60; // Set distance from screen edge
    void vSpawn; //Spawn object.

    if(PScore == NULL()){
      PScore=0;
    }

    changeplayerproperty(PIndex, "score", PScore-1); // Reduce score a bit

    clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", "aHelper"); //Acquire spawn entity by name.

    if (Direction == 0){ //Is entity facing left?                  
      fX = Screen-fX; //Reverse X direction to match facing and screen length
    }

    vSpawn = spawn(); //Spawn in entity.

    changeentityproperty(vSpawn, "position", XPos+fX, fZ); //Set spawn location.
    changeentityproperty(vSpawn, "direction", Direction); //Set direction
}
