void main()
{
    void self = getlocalvar("self");

    int z = getentityproperty(self, "z");
    int ypos = openborvariant("ypos");
    int zoom = 256 + (z - 160 - ypos-30) * 2;
    if(zoom < 0) {zoom = 0;}
    setdrawmethod(self, 1, zoom, zoom, 0, 0, 0, -1);
}

