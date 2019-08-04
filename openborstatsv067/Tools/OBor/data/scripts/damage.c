void main()
{
	void self = getlocalvar("self");
	float damage = getlocalvar("damage");
	setglobalvar("last_damage", damage);
	int combo_step = getentityproperty(self,"combostep");

	if ( combo_step == 1 ) setglobalvar("last_combo_dmg", damage);
	else setglobalvar("last_combo_dmg", getglobalvar("last_combo_dmg")+damage);
}

