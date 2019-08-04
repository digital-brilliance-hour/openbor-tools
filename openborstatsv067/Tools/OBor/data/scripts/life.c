void main()
{
	// Change entity map based on its life
	// Douglas Baldan - 02/08/14
	void self = getlocalvar("self");
    void health = getentityproperty(self,"health"); //get health
	void maxhealth = getentityproperty(self,"maxhealth"); //get health
	if (health<=maxhealth/2 && health >maxhealth/4)// checks if the health is 50% or less
	{
		changeentityproperty(self, "map", 2); //Set map.
	}
		
	if (health<=maxhealth/4)// checks if the health is 25% or less
	{
		changeentityproperty(self, "map", 3); //Set map.
	}
		

}