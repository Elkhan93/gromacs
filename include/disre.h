/*
 * $Id$
 * 
 *                This source code is part of
 * 
 *                 G   R   O   M   A   C   S
 * 
 *          GROningen MAchine for Chemical Simulations
 * 
 *                        VERSION 3.2.0
 * Written by David van der Spoel, Erik Lindahl, Berk Hess, and others.
 * Copyright (c) 1991-2000, University of Groningen, The Netherlands.
 * Copyright (c) 2001-2004, The GROMACS development team,
 * check out http://www.gromacs.org for more information.

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * If you want to redistribute modifications, please consider that
 * scientific software is very special. Version control is crucial -
 * bugs must be traceable. We will be happy to consider code for
 * inclusion in the official distribution, but derived work must not
 * be called official GROMACS. Details are found in the README & COPYING
 * files - if they are missing, get the official version at www.gromacs.org.
 * 
 * To help us fund GROMACS development, we humbly ask that you cite
 * the papers on the package - you can find them in the top README file.
 * 
 * For more info, check our website at http://www.gromacs.org
 * 
 * And Hey:
 * Gromacs Runs On Most of All Computer Systems
 */

#ifndef _disre_h
#define _disre_h

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef CPLUSPLUS
extern "C" {
#endif

#include "sysstuff.h"
#include "typedefs.h"

void init_disres(FILE *log,int nbonds,t_iatom forceatoms[],t_iparams ip[],
		 t_inputrec *ir,t_commrec *mcr,t_fcdata *fcd);
/* Initiate *fcd data, must be called once, nbonds is the number 
 * of iatoms in the ilist of the idef struct
 */

extern void calc_disres_R_6(t_commrec *mcr,
			    int nfa,t_iatom forceatoms[],t_iparams ip[],
			    rvec x[],bool bFullPBC,t_fcdata *fcd);
/* Calculates r and r^-3 (inst. and time averaged) for all pairs
 * and the ensemble averaged r^-6 (inst. and time averaged) for all restraints
 */

extern real ta_disres(int nbonds,t_iatom fa[],t_iparams *fp,
		      rvec x[],rvec f[],t_forcerec *fr,t_graph *g,
		      matrix box,real lambda,real *dvdlambda,
		      t_mdatoms *md,int ngrp,real egnb[],real egcoul[],
		      t_fcdata *fcd);
/* Calculate the distance restraint forces, return the potential */

#ifdef CPLUSPLUS
}
#endif

#endif	/* _disre_h */
