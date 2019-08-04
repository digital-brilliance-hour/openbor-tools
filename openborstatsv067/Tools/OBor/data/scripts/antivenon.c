void main()
{// anit-venon script
    void self = getlocalvar("self"); //Get calling entity.
    void Health = getentityproperty(self,"health");
	int Type = getlocalvar("attacktype");
    int oPal = getentityproperty(self, "mapdefault");
	if(Type == openborconstant("ATK_NORMAL4")){
	changeentityproperty(self, "map", oPal);


		
		if (Health > 0){
		  changeentityproperty(self, "dot", 1, "owner", self);
          changeentityproperty(self, "dot", 1, "force", 1);
          changeentityproperty(self, "dot", 1, "mode", 4);
          changeentityproperty(self, "dot", 1, "rate", 80);
          changeentityproperty(self, "dot", 1, "time", 1600);
		}
	}

}