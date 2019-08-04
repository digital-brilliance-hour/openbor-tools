
#define MAX_TRAILS 50

int clear_shadowtrail(void ent) {
    int i;

        for( i = 0; i < MAX_TRAILS; ++i) {
            setlocalvar("xpos"+ent+"_"+i, NULL());
            setlocalvar("zpos"+ent+"_"+i, NULL());
            setlocalvar("apos"+ent+"_"+i, NULL());
            setlocalvar("spr"+ent+"_"+i, NULL());
            setlocalvar(ent+"_k",NULL());
        }

   return 0;
}

int draw_shadowtrail(void ent, int maxtrails, int refresh_frm, int min_transp, int max_transp, int swap_flag) {

     int i, k, c;
	 void spr = getentityproperty(ent, "sprite");
	 float x = getentityproperty(ent, "x");
     float z = getentityproperty(ent, "z");
     float a = getentityproperty(ent, "a");
	 int facing = getentityproperty(ent, "direction");
	 int colourmap = getentityproperty(ent, "colourmap");
     int elapsed_time = openborvariant("elapsed_time");
     float xpos, zpos, apos;

	 if (facing == 1) facing = 0;
	 else facing = 1;

	 if (maxtrails > MAX_TRAILS) maxtrails = MAX_TRAILS;

     if ( elapsed_time%refresh_frm == 0 && openborvariant("in_level") ) { // memorizziamo sprites e posizioni nel tempo
            if ( getlocalvar(ent+"_k") != NULL() ) k = getlocalvar(ent+"_k"); else k = 0;
            // SPRITES SWAP
            if ( swap_flag && getlocalvar(ent+"_k") != NULL() ) {
                int tk = k;
                void tspr = NULL();

                for( i = 0; i < maxtrails; ++i) {
                    --tk;
                    if ( tk < 0 ) tk = maxtrails-1;
                    tspr = getlocalvar("spr"+ent+"_"+tk);
                    --tk;
                    if ( tk < 0 ) tk = maxtrails-1;
                    setlocalvar("spr"+ent+"_"+tk, tspr); // inseriamo lo sprite precedente nello slot ancora precedente
                }
            }
            // END SPRITES SWAP

            setlocalvar("xpos"+ent+"_"+k, x);
            setlocalvar("zpos"+ent+"_"+k, z);
            setlocalvar("apos"+ent+"_"+k, a);
            setlocalvar("spr"+ent+"_"+k, spr);
            ++k;
            if ( k >= maxtrails ) k = 0;
            setlocalvar(ent+"_k", k);
     }

	 if( openborvariant("in_level") ) { // draw trails

		 for( i = 0; i < maxtrails; ++i) {
                int transp, gradient;
                int layer = getentityproperty(ent, "setlayer");

                if ( getlocalvar("spr"+ent+"_"+i) != NULL() ) {
                     x = getlocalvar("xpos"+ent+"_"+i);
                     z = getlocalvar("zpos"+ent+"_"+i);
                     a = getlocalvar("apos"+ent+"_"+i);
                     spr = getlocalvar("spr"+ent+"_"+i);

                     // naturalmente il più recente deve essere il meno trasparente, ecco perchè usiamo k e non i!!
                     if ( getlocalvar(ent+"_k") != NULL() ) k = getlocalvar(ent+"_k")-1; else k = 0;
                     if (k < 0 ) k = maxtrails-1;
                     // Presa la k più recente impostiamo la k corrispondente alla i dalla più recente alla meno recente
                     // Dobbiamo sottrarre quindi maxtrails-i a k
                     for ( c = 0; c < i; ++c ) {
                        --k;
                        if ( k < 0 ) k = maxtrails-1;
                     }
                     gradient = maxtrails-1;
                     for ( c = 0; c < k; ++c ) {
                        --gradient;
                        if ( gradient < 0 ) gradient = maxtrails-1;
                     }

                     //changedrawmethod(NULL(), "tintmode", 1);
                     //changedrawmethod(NULL(), "tintcolor", 0xFF00FF);
                     transp = ( (max_transp-min_transp)*(gradient+1)/maxtrails )+min_transp;
                     changedrawmethod(NULL(), "channelg", transp);
                     changedrawmethod(NULL(), "channelr", transp);
                     changedrawmethod(NULL(), "channelb", transp);

                     // (entity, int flag, int scalex, int scaley, int flipx, int flipy, int shiftx, int alpha, int remap, int fillcolor, int rotate, int fliprotate, int transparencybg, void* colourmap, int centerx, int centery);
                     setdrawmethod(NULL(), 1, 256, 256, facing, 0, 0, 6, 1, 0, 0, 0, 0, colourmap); // map: -1 = Use entity's colormap.

                     if ( x != NULL() ) drawsprite(spr, x-openborvariant("xpos"), z-a-openborvariant("ypos")-4, z-(maxtrails-1-gradient), layer);
                     setdrawmethod(NULL(), 0);
                } // fine if spr != NULL()

		 } // fine for
	 } // if in_level

    return 0;
}

