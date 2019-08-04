void main()
{
void self = getlocalvar("self");
changeentityproperty(self, "type", openborconstant("TYPE_ENEMY"));
changeentityproperty(self, "velocity", 0, 0, 0);
changeentityproperty(self, "speed", 0);
}