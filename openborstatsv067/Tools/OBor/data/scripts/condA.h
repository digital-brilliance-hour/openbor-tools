void attackM(void Ani, int Remap)
{// Attack interruption if there's player
// Only occurs if remap matches
    void self = getlocalvar("self");
    int Map = getentityproperty(self, "map");
    void target = findtarget(self); //Find player

    if(target!=NULL() && Map==Remap){
      performattack(self, openborconstant(Ani)); //Attack!
    }
}