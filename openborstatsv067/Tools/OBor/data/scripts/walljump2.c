void main()
{
//	int iPlIndex = 0; //Player index.
	int iPlIndex = getlocalvar("self"); //Get calling player
//	int iPlIndex = getentityproperty(self,"playerindex"); //Get player index
    void vSelf = getplayerproperty(iPlIndex , "entity"); //Get calling entity
    void vAniID = getentityproperty(vSelf,"animationID"); //Get current animation ID
    void vAniPos = getentityproperty(vSelf, "animpos"); //Get current animation frame
    int iDir = getentityproperty(vSelf, "direction");  //Get current facing direction
	int x = getentityproperty(vSelf, "x");	// Get x pos
    int y = getentityproperty(vSelf, "a");	// Get y pos
    int z = getentityproperty(vSelf, "z");	// Get z pos

    void iUp = playerkeys(iPlIndex, 1, "moveup"); // New key status of "Up"
    void iDown = playerkeys(iPlIndex, 1, "movedown"); // New key status of "Down"
    void iLeft = playerkeys(iPlIndex, 1, "moveleft"); // New key status of "Left"
    void iRight = playerkeys(iPlIndex, 1, "moveright"); // New key status of "Right"
    void iJump = playerkeys(iPlIndex, 1, "jump"); //New key status of "Jump"
    void iSpecial = playerkeys(iPlIndex, 1, "Special"); //New key status of "Special"
    void iAttack = playerkeys(iPlIndex, 1, "attack"); //New key status of "Attack"
    void iAttack2 = playerkeys(iPlIndex, 1, "attack2"); // New key status of "Attack 2"
    void iAttack3 = playerkeys(iPlIndex, 1, "attack3"); // New key status of "Attack 3"
    void iAttack4 = playerkeys(iPlIndex, 1, "attack4"); // New key status of "Attack 4"

	void iUpR = playerkeys(iPlIndex, 2, "moveup"); // Release status of "moveup"
	void iDownR = playerkeys(iPlIndex, 2, "movedown"); // Release status of "movedown"
    void iLeftR = playerkeys(iPlIndex, 2, "moveleft"); // Release status of "Left"
    void iRightR = playerkeys(iPlIndex, 2, "moveright"); // Release status of "Right"
	void iJumpR = playerkeys(iPlIndex, 2, "jump"); // Release status of "Jump"
	void iSpecialR = playerkeys(iPlIndex, 2, "Special"); // Release status of "Special"
	void iAttackR = playerkeys(iPlIndex, 2, "attack"); //Release status of "Attack"
	void iAttack2R = playerkeys(iPlIndex, 2, "attack2"); // Release status of "Attack 2"
	void iAttack3R = playerkeys(iPlIndex, 2, "attack3"); // Release status of "Attack 3"
	void iAttack4R = playerkeys(iPlIndex, 2, "attack4"); // Release status of "Attack 4"

	if(vAniID == openborconstant("ANI_JUMP") || vAniID == openborconstant("ANI_FORWARDJUMP") || vAniID == openborconstant("ANI_RUNJUMP") || vAniID == openborconstant("ANI_FOLLOW16"))
	{ //Jumping?	
		if (iJump)
		{ //New jump key press?
			if(iDir == 1 && y <= checkwall(x+5,z))
			{ // There is a wall
				changeentityproperty(vSelf, "direction", 0); 
				// Change to left facing
				changeentityproperty(vSelf, "velocity", 0, 0, 0); 
				// Set velocity
				changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW20"));
				// Switch to wall jump anim
			}
			else if(iDir == 0 && y <= checkwall(x-5,z))
			{ // There is a wall
				changeentityproperty(vSelf, "direction", 1);
				// Change to left facing
				changeentityproperty(vSelf, "velocity", 0, 0, 0);
				// Set velocity
				changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW20"));
				// Switch to wall jump anim
			}
			else if(y > checkwall(x-5,z) || checkwall(x-5,z))
			{ // There is no wall
				changeentityproperty(vSelf, "animation", openborconstant("ANI_FOLLOW21"));
				// Switch to double jump anim
			}
		}	
		}
	}