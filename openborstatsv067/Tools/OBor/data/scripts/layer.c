void main(){
     void self = getlocalvar("self");
     void inStage = getglobalvar("stageName");
     int layer = getentityproperty(self, "setlayer");
     if (inStage=="mirror")
     {
      	changeentityproperty(self,"setlayer",0);
      	//drawstring( 290,90,1,"layer: "+getentityproperty(self, "setlayer"));
      	//drawstring( 290,110,1,"stage: "+getglobalvar("stageName"));
     } else {
      changeentityproperty(self,"setlayer",-2);
     // drawstring( 290,90,1,"layer: "+getentityproperty(self, "setlayer"));
      //drawstring( 290,110,1,"stage: "+getglobalvar("stageName"));
      }
}