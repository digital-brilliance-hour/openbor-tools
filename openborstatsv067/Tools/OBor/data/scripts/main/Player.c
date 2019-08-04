#include "data/scripts/afterimg.c"

void main()
{
   void AniID = getani();
   if( AniID == openborconstant("ANI_WALK")
	){
		afterimg();
   }
}
