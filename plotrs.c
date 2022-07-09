#include <stdio.h>
#include <math.h>
extern FILE *psfile;

void plot_ratbez_surfaces(bez_x,bez_y,bez_w,lu,lv,u_points,v_points,scale_x,scale_y,value)
/*	Plots piecewise cubic surface, i.e., generates postscript output  
Input:	bez_x, bez_y: 	  control nets
	lu,lv:        	  no. of segments in u- and v- direction
	u_points,v_p oints: per patch: v_points many
	              	  isoparametric curves with u_points
	              	  points on each
	value:		  minmax box of all control nets. 
	scale_x,scale_y:  scale factors for  postscript
*/
	float bez_x[20][20], bez_y[20][20],bez_w[20][20],value[4],scale_x,scale_y;
	int lu,lv;
{
	int i,j,ii,jj,lu3,lv3;
	float aux_x[20][20], aux_y[20][20],aux_w[20][20];

	lu3=lu*3;  lv3=lv*3;

	

		fprintf(psfile,"%f %f translate\n",
			-1.0*scale_x*value[0], -1.0*scale_y*value[2]);

	for(i=0; i<lu3; i=i+3)
	for(j=0; j<lv3; j=j+3)
	{
		for(ii=0; ii<=3; ii++)
		for(jj=0; jj<=3; jj++)
		{
			aux_x[ii][jj]=bez_x[i+ii][j+jj];
			aux_y[ii][jj]=bez_y[i+ii][j+jj];
			aux_w[ii][jj]=bez_w[i+ii][j+jj];

		}
		plot_ratsurf(aux_x,aux_y,aux_w,3,3,u_points,v_points,
				scale_x,scale_y);
	}
}
