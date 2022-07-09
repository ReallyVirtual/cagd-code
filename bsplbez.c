void bspline_to_bezier(bspl,knot,l,bez)
/* converts  cubic B-spline polygon into piecewise Bezier polygon 
Input:	bspl: B-spline control polygon 
	knot: knot sequence
	l:    no. of intervals

Output:	bez:  piecewise Bezier polygon 

*/

	float bspl[],  knot[], bez[];
	int l;
{
	int i, i3, l3;
/* The first points need special attention:  */

	bez[0]=bspl[0];
	bez[1]=bspl[1];
	if(l>1)
	{
		bez[2]=((knot[2]-knot[1])*bspl[1]
		+(knot[1]-knot[0])*bspl[2]    )/(knot[2]-knot[0]);
	}   
	if(l>2)
	{
		bez[4]=( (knot[3]-knot[1])*bspl[2]
	        +(  knot[1]-knot[0])*bspl[3]  )/(knot[3]-knot[0]);
		bez[3]=( (knot[2]-knot[1])*bez[2]
	        + (knot[1]-knot[0])*bez[4]    )/(knot[2]-knot[0]);
	}
/* Now the main part:   */

	for(i=2; i<l-1; i++)
	{		
	i3=3*i;
	bez[i3-1]=( (knot[i+1]-knot[i])*bspl[i]
	         +  (knot[i]-knot[i-2])*bspl[i+1]    )/(knot[i+1]-knot[i-2]);

	bez[i3+1]=( (knot[i+2]-knot[i])*bspl[i+1]
	         +(  knot[i]-knot[i-1])*bspl[i+2]  )/(knot[i+2]-knot[i-1]);

	bez[i3]  =( (knot[i+1]-knot[i])*bez[i3-1]
		  + (knot[i]-knot[i-1])*bez[i3+1]  )/(knot[i+1]-knot[i-1]);
	}
	
/* The last points need special attention:  */

	l3=l*3;
	if(l>2)
	{
	bez[l3-4]=( (knot[l]-knot[l-1])*bspl[l-1]
	         +  (knot[l-1]-knot[l-3])*bspl[l]  )/(knot[l]-knot[l-3]);
	}
	if(l>1)
	{
	bez[l3-2]=( (knot[l]-knot[l-1])*bspl[l]
		 +  (knot[l-1]-knot[l-2])*bspl[l+1]    )/(knot[l]-knot[l-2]);

	bez[l3-3]=( (knot[l]-knot[l-1])*bez[l3-4]
		 + (knot[l-1]-knot[l-2])*bez[l3-2]   )/(knot[l]-knot[l-2]);
	}
	bez[l3-1]= bspl[l+1];
	bez[l3]  = bspl[l+2];       
}
