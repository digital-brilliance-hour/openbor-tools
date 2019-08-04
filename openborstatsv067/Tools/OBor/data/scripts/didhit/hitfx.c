int isvalid(void ent)
{
	if (getentityproperty(ent,"type")!=openborconstant("TYPE_OBSTACLE"))
	{return 1;}else{return 0;}
}
void getAni()
{
	void ent = getlocalvar("self");
	return getentityproperty(ent,"animationID");
}
int getAniPos()
{
	return getentityproperty(getlocalvar("self"),"animpos");
}
void freeze(void ent,void freeze_time)
{
	changeentityproperty(ent,"freezetime",openborvariant("elapsed_time")+freeze_time);
	changeentityproperty(ent,"aiflag","frozen",1);
}
void hitEffect(void ani,void vName,int startframe,int endframe)
{
	if(getlocalvar("blocked")){return;}else{}
	void self=getlocalvar("self");
	int anipos=getentityproperty(self,"animpos");
	if((getAni() == openborconstant(ani)||ani=="ALL") && anipos>=startframe && anipos<=endframe){
		void target=getlocalvar("damagetaker");
		if (isvalid(target))
		{
			void vSpawn;
			clearspawnentry();
			setspawnentry("name", vName);
			vSpawn = spawn();
			
			changeentityproperty(vSpawn, "parent", target);
			//changeentityproperty(vSpawn, "owner", self);
			setentityvar(vSpawn,0,self);
			changeentityproperty(vSpawn, "speed", getglobalvar("eParm"));
			changeentityproperty(vSpawn, "candamage", getentityproperty(self, "candamage")+openborconstant("TYPE_RESERVED"));
			setglobalvar("eParm",NULL());
			bindentity(vSpawn, target, 0, 1, 6, 1, 0);
		}
	}
}

void hitBack(char ani,int startframe,int endframe,float spd)
{
	eParm(spd);
	hitEffect(ani,"hitback",startframe,endframe);
}
void hitDelay(char ani,int startframe,int endframe)
{
	if(getlocalvar("blocked")){return;}else{}
	int anipos=getentityproperty(getlocalvar("self"),"animpos");
	if(getAni() == openborconstant(ani) && anipos>=startframe && anipos<=endframe){
		void opp = getlocalvar("damagetaker");
		if (getentityproperty(opp,"health")<=0)
		{
			return;
		}else{}
		int enextanim = getentityproperty(opp, "nextanim");
		int enextthink = getentityproperty(opp, "nextthink");
		changeentityproperty(opp, "nextanim", enextanim + 80);
		changeentityproperty(opp, "nextthink", enextthink + 80);

		if (getentityproperty(opp,"a")==0){
			hitEffect(ani,"delayHit",startframe,endframe);
		}
	}
}

void hitDelay2(char ani,int startframe,int endframe,long freezetime)
{
	if(getlocalvar("blocked")){return;}else{}
	int anipos=getentityproperty(getlocalvar("self"),"animpos");
	if(getAni() == openborconstant(ani) && anipos>=startframe && anipos<=endframe){
		void opp = getlocalvar("damagetaker");
		if (getentityproperty(opp,"a")==0){
			int enextanim = getentityproperty(opp, "nextanim");
			int enextthink = getentityproperty(opp, "nextthink");
			changeentityproperty(opp, "nextanim", enextanim + freezetime);
			changeentityproperty(opp, "nextthink", enextthink + freezetime);
			setglobalvar(getlocalvar("self")+"_delayhit",1);
		}
	}
}

void eParm(float value)
{
	setglobalvar("eParm",value);
}
