#include "mex.h" // ʹ��MEX�ļ����������ͷ�ļ�
#include "Subsystem.h"

double runZSB(double b[]) {
	
	int i;
	Subsystem_initialize();

	for ( i = 0; i < 9; i++ )
		Subsystem_U.In1[ i ] = b[ i ];

	for ( i = 0; i < 20; i++ )
		Subsystem_step();

	return Subsystem_Y.Out1[0];
}

// MEX�ļ��ӿں���
void mexFunction(
 int nlhs,
 mxArray *plhs[],
 int nrhs,
 const mxArray *prhs[]) {
 int i;
 double *a;
 double b[9];
 plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL);
 a = mxGetPr(plhs[0]);
 for ( i = 0; i < 9; i++ )
    b[ i ] = *(mxGetPr(prhs[i]));
 *a = runZSB( b );
 return;
}