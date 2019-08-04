void velo001(float fX, float fZ, float fY){
     
    //velo001
	//Damon Vaughn Caskey
	//05/06/2007
	//
	//Replicates movement effect.
	//
	//fX: X axis speed.
	//fZ: Z axis speed.
	//fY: Y axis speed.
	
	void vSelf = getlocalvar("self"); //Get calling entity.
	
	if (getentityproperty(vSelf, "direction")==0){ //Is entity facing right?                  
     
         fX = -fX; ////Reverse X direction to match facing.
         
    }         
	
	changeentityproperty(vSelf, "velocity", fX, fZ, fY); //Apply movement.

}
