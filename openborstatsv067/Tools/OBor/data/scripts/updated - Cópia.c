/*
//ondeath tanos//
@script
      
      if (frame==1){
         void c=getglobalvar("clearCount");
        if (c==NULL() ){
           c=0;
        }
         c++;
         saveSetting(c);
         setglobalvar("clearCount",c);
      
      }
   @end_script
////////////////////////////////////////////
*/



void main ()
{

	if(openborvariant("in_titlescreen")||openborvariant("in_menuscreen")||openborvariant("in_selectscreen"))
	{
		inTitleLoop(1);
	}
 //loadSaveData();
}







void saveSetting(void value)
{
	void pakname=openborvariant("pakname");
	void file=createfilestream();
	filestreamappend(file,value,1);
	savefilestream(file,"save.s");
	closefilestream(file);
}
void loadSetting(void fn)
{
	void pakname=openborvariant("pakname");
	//void file=openfilestream("saves/"+pakname+"/"+fn);
	void file=openfilestream(fn,1);
	void ret;
	if(file==-1)
	{
		return 0;
	}else{
		ret=getfilestreamargument(file, 0, "int");
		closefilestream(file);
		return ret;
	}
}

void loadSaveData()
{
	setglobalvar("clearCount",loadSetting("save.s"));
	setglobalvar("inv",loadSetting("inv.cfg"));
}


void looper(int Frame, int Limit)
{// Loops current animation
    void self = getlocalvar("self");
    void loop = getlocalvar("Loop" + self);

    if(loop==NULL()){ // Localvar empty?
      setlocalvar("Loop" + self, 0);
      loop = 0;
    } 
   
    if(loop < Limit){ // loops reach limit?
      updateframe(self, Frame); //Change frame
      setlocalvar("Loop" + self, loop+1); // Increment number of loops
    } else if(loop==Limit){ // loops reach limit?
      setlocalvar("Loop" + self, NULL());
    }
}




void inTitleLoop(int distitle)
{
	void clearCount,ptitle;
	

		if(distitle)
		{
			clearCount=getglobalvar("clearCount");
                        if(clearCount==NULL()){ // clearCount empty?
                          setglobalvar("clearCount", 0);
                          clearCount = 0;
                        } 

			if(clearCount<=10)
			{
			    drawstring(335,258,0,"Secret Characters Unlocked");
			    drawstring(18,258,0,"v.beta 6");
			    ptitle=clearCount;
		            drawstring(198,258,1,"Unlocked "+ptitle);
			} else
			{
			    drawstring(18,258,0,"All Secret Characters Unlocked!");				
			}

		}
}

