void main()
{// Anti stun script
    void self = getlocalvar("self"); //Get calling entity.
    int Type = getlocalvar("attacktype");
	
	void target = getlocalvar("Target" + self);

    if(target==NULL())
    {
      target = getentityproperty(self, "opponent");
      setlocalvar("Target" + self, target);
    }
	
	if(target!=NULL() && target==openborconstant("ANI_PAIN3"))
    {
performattack(target, "animation", openborconstant("ANI_FALL")) ;  
 }

}