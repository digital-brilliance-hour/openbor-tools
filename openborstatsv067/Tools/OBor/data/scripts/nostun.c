void main()
{// Anti stun script
    void self = getlocalvar("self"); //Get calling entity.
    int Type = getlocalvar("attacktype");

    if(Type == openborconstant("ATK_NORMAL2")){
      changeentityproperty(self, "freezetime", 1);
    }
}