void main()
{
	void	s;
	void	value	=	getlocalvar("value");
	void	max		=	getlocalvar("max");
	if(max==1){
		return;
	}else{}

	void percent=value*100/max;
	percent%=++percent;

	void dot=percent%3;
	if(dot==0)
		s=">___";
	else if(dot==1)
		s="_>__";
	else
		s="__>_";

	if (percent<=20){
	drawstring(143,242,0,"Loading_ Heroes"+s+percent+"%__Complete");
	}
	else if (percent>20 && percent <=40){
	drawstring(143,242,0,"Now_Loading_Enemies"+s+percent+"%__Complete");
	}
	else if (percent>40 && percent <=60){
	drawstring(143,242,0,"How_about_some_Fun_Factor"+s+percent+"%__Complete");
	}else{
	drawstring(143,242,0,"Where_is_Deadpool???"+s+percent+"%__Complete");
	}
	
	//loading log
	if (percent==5){
	log("\n");
    log("---------------------------------------------------------------------loading 5%---- ");
	log("\n");
	}
	if (percent==10){
	log("\n");
    log("---------------------------------------------------------------------loading 10%---- ");
	log("\n");
	}
	if (percent==15){
	log("\n");
    log("---------------------------------------------------------------------loading 15%---- ");
	log("\n");
	}
	if (percent==20){
	log("\n");
    log("---------------------------------------------------------------------loading 20%---- ");
	log("\n");
	}
	if (percent==25){
	log("\n");
    log("---------------------------------------------------------------------loading 25%---- ");
	log("\n");
	}
	if (percent==30){
	log("\n");
    log("---------------------------------------------------------------------loading 30%---- ");
	log("\n");
	}
	
	drawbox(0,259,480,15,11,rgbcolor(0,122,133),0);
	drawbox(0,259,percent*480*0.01,5,15,rgbcolor(0,233,233),0);
	drawbox(0,264,percent*480*0.01,5,15,rgbcolor(0,213,233),0);
	drawbox(0,269,percent*480*0.01,5,15,rgbcolor(0,193,233),0);
	drawline(percent*480*0.01, 257, percent*480*0.01, 273, 25, rgbcolor(255,255,255), 0);

	//drawline(x1, y1, x2, y2, z, color, alpha)
	//drawbox(x, y, width, height, z, color, alpha)
}
