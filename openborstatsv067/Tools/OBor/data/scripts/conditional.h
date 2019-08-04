#define FALSE	0	// False value.
#define TRUE	1	// True value.
#define DEFAULT	NULL()	// No parameter value - fall back to a default.

/******Animation, adjustment flags*****/
#define ANI_BY_CHANGE_PROP	0	// Set animation using "changentityproperty".
#define ANI_BY_PERFORM_ATTACK	1	// Set animation using "performattack".
#define ANI_RESET_FALSE		0	// Performattack will do nothing if new animation = current.
#define ANI_RESET_TRUE		1	// Performattack will reset animation to first frame if new animation = current.

int ani_set_animation(void ent, int animation, int method, int reset)
{
	/*
	ani_set_animation
	Damon Vaughn Caskey
	2013-11-03

	Animation switch wrapper. Verify animation exists and then set using desired method. Replaces ani0009.

	vEnt:		Target entity.
	animation:	Animation to use.
	method:		Method to set animation. See Animation, adjustment flags in constants.h for flag list.
	*/

	int valid = FALSE;		// Requested animation valid.

	// Default for any omitted values.
	if(ent == DEFAULT) ent = getlocalvar("self");
	if(method == DEFAULT) method = ANI_BY_CHANGE_PROP;
	if(reset == DEFAULT) reset = ANI_RESET_FALSE;

	valid = getentityproperty(ent, "animvalid", animation);

	// Is requested animation valid?
	if (valid == TRUE)			
    	{
		switch (method)
		{
			// Set animation with entity property.
			default:			
			case ANI_BY_CHANGE_PROP:

				changeentityproperty(ent, "animation", animation);	
				break;

			// Set animation with perform attack command.
			case ANI_BY_PERFORM_ATTACK:

				performattack(ent, animation, reset);				
				break;
		}
    	}
    
	// Return valid as a result.
	return valid;
}

int ani_set_on_range(void ent, int alternate, int target_ani){
    
	/*
	ani_set_on_range
	Damon Vaughn Caskey
	2014-07-24

	Perform alternate animation if target is within range and in (optionaly) in specified animation.

	ent:		Entity that will switch animations. If NULL will default to caller.
	alternate:	Alternate attack.
	target_ani:	Target animation.	
	*/

	int  result		= NULL();	// Result of function. 
    	void target		= NULL();	// Target entity.
	void target_ani_current	= NULL();	// Target entity's current animation.

	// Default to caller if ent is not provided.
	if(ent == DEFAULT) ent = getlocalvar("self");
	 
	
	// Find target (if any) in range of specified animation.
	target = findtarget(ent, alternate);
	
	// Found a target?
	if (target)												
	{
		// Get target's current animation.
		target_ani_current = getentityproperty(target, "animationID");

		// Animation match or omitted?
		if(target_ani_current == target_ani || target_ani == DEFAULT)
		{
			// Perform alternate attack.
			result = ani_set_animation(ent, alternate, ANI_BY_CHANGE_PROP);					
		}
	}

	// Return result.
	return result;
}