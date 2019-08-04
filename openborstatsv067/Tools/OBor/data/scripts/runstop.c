void main()
{
    int iPlIndex = getlocalvar("player"); //Get calling player
    void vSelf = getplayerproperty(iPlIndex , "entity"); //Get calling entity
    void vAniID = getentityproperty(vSelf,"animationID"); //Get current animation ID
    void vAniPos = getentityproperty(vSelf, "animpos"); //Get current animation frame
    int iDir = getentityproperty(vSelf, "direction");  //Get current facing direction
    int x = getentityproperty(vSelf, "x");
    int y = getentityproperty(vSelf, "a");
    int z = getentityproperty(vSelf, "z");
    int XPos = openborvariant("xpos"); //Get screen edge's position
    int Screen = openborvariant("hResolution"); // Get screen width
    
    void iUp = playerkeys(iPlIndex, 1, "moveup"); // New key status of "Up"
    void iDown = playerkeys(iPlIndex, 1, "movedown"); // New key status of "Down"
    void iLeft = playerkeys(iPlIndex, 1, "moveleft"); // New key status of "Left"
    void iRight = playerkeys(iPlIndex, 1, "moveright"); // New key status of "Right"
    void iJump = playerkeys(iPlIndex, 1, "jump"); //New key status of "Jump"
    void iSpecial = playerkeys(iPlIndex, 1, "Special"); //New key status of "Special"
    void iAttack = playerkeys(iPlIndex, 1, "attack"); //New key status of "Attack"
    void iAttack2 = playerkeys(iPlIndex, 1, "attack2"); // New key of "Attack 2"
    void iAttack3 = playerkeys(iPlIndex, 1, "attack3"); // New key of "Attack 3"

	if(vAniID == openborconstant("ANI_RUN"))
	{ 
			if(iDir == 0 && iRight) // facing left
			{
				changeentityproperty(vSelf, "velocity", 0, 0, 0); 
				// Set velocity
				changeentityproperty(vSelf, "animation", openborconstant("ANI_RISE"));
			}

	}
}