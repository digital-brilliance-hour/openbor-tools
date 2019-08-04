void main(){
   void self = getlocalvar("self"); //Get calling entity.
   void health = getentityproperty(self,"health"); //get health
   int time = openborvariant("elapsed_time");// get time

   if ( time % 300 == 0 && getentityproperty(self, "exists") && !getentityproperty(self, "dead"))
   {
   changeentityproperty(self, "health", health+1);//add health
   }
}

//void main(){
//   void self = getlocalvar("self"); //Get calling entity.
//   void health = getentityproperty(self,"health"); //get health
//   int time = openborvariant("elapsed_time");// get time
//   int recovery_time = 1000;

//   time %= recovery_time*2; // game time protection OPTIONAL!!

//   if ( getlocalvar("time_flag") == NULL() ) setlocalvar("time_flag",time+recovery_time);  

//   if ( time >= getlocalvar("time_flag") )
//   {
//        if ( health < getentityproperty(self, "maxhealth") )
//        {
//              changeentityproperty(self, "health", health+1); //add health
              //setlocalvar("time_flag",NULL());
//        }
//   }
//}

