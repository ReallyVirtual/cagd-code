void degree_elevate(bx,by,wb,degree,cx,cy,wc)
/*	input: two-d bezier polygon in bx, by and with weights
	in wb. Degree is degree. Output is degree elevated
	curve in cx,cy and with weights in wc.
	Note: for nonrational (polynomial) case, fill wc with 1's.
*/
	float bx[],by[],cx[],cy[],wb[],wc[];
	int degree;

	{
	int i,degree1;
	float ww;

	degree1 = degree+1;

	cx[0] = bx[0];
	cy[0] = by[0];
	wc[0] = wb[0];

	for(i=1; i<= degree; i++)
		{
		ww = i*wb[i-1] + (degree1 - i)*wb[i];

		cx[i]=(i*wb[i-1]*bx[i-1]+
		       (degree1 - i)*wb[i]*bx[i])/ww;

		cy[i]=(i*wb[i-1]*by[i-1]+
	    	   (degree1 - i)*wb[i]*by[i])/ww;

		wc[i] = ww/ degree1;		
		}

	cx[degree1]= bx[degree]; cy[degree1]= by[degree];
	wc[degree1] = wb[degree];

	}
