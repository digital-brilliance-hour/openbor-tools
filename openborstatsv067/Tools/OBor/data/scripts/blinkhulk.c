void main()
{// Blink effect script + avoid palette change against freeze
    void self = getlocalvar("self"); //Get calling entity.
    void Health = getentityproperty(self,"health");
	int Type = getlocalvar("attacktype");
	
	if(Type != openborconstant("ATK_NORMAL4")){
	if(Type != openborconstant("ATK_FREEZE")){
		if (Health > 0){
			
		changeentityproperty(self, "colourmap", 6);
		changeentityproperty(self, "maptime", 20 + openborvariant("elapsed_time"));
			
		}
	}
	}

}