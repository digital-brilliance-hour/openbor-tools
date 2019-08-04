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

    if(vAniID == openborconstant("ANI_JUMP") || vAniID == openborconstant("ANI_FORWARDJUMP")){ 
      if(iJump){
        if(iDir == 1 && y <= checkwall(x+15,z)){
          changeentityproperty(vSelf, "direction", 0);
          tossentity(vSelf, 3, -1, 0); // Wall Bounce
        } else if(iDir == 0 && y <= checkwall(x-15,z)){
          changeentityproperty(vSelf, "direction", 1);
          tossentity(vSelf, 3, 1, 0); // Wall Bounce
        } else if(iDir == 0 && x <= XPos+10){
          changeentityproperty(vSelf, "direction", 1);
          tossentity(vSelf, 3, 1, 0); // Edge Bounce
        } else if(iDir == 1 && x >= XPos+Screen-10){
          changeentityproperty(vSelf, "direction", 0);
          tossentity(vSelf, 3, -1, 0); // Edge Bounce
        }
      }
    }
}