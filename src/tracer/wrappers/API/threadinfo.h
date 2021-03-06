/*****************************************************************************\
 *                        ANALYSIS PERFORMANCE TOOLS                         *
 *                                   Extrae                                  *
 *              Instrumentation package for parallel applications            *
 *****************************************************************************
 *     ___     This library is free software; you can redistribute it and/or *
 *    /  __         modify it under the terms of the GNU LGPL as published   *
 *   /  /  _____    by the Free Software Foundation; either version 2.1      *
 *  /  /  /     \   of the License, or (at your option) any later version.   *
 * (  (  ( B S C )                                                           *
 *  \  \  \_____/   This library is distributed in hope that it will be      *
 *   \  \__         useful but WITHOUT ANY WARRANTY; without even the        *
 *    \___          implied warranty of MERCHANTABILITY or FITNESS FOR A     *
 *                  PARTICULAR PURPOSE. See the GNU LGPL for more details.   *
 *                                                                           *
 * You should have received a copy of the GNU Lesser General Public License  *
 * along with this library; if not, write to the Free Software Foundation,   *
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA          *
 * The GNU LEsser General Public License is contained in the file COPYING.   *
 *                                 ---------                                 *
 *   Barcelona Supercomputing Center - Centro Nacional de Supercomputacion   *
\*****************************************************************************/

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- *\
 | @file: $HeadURL: https://svn.bsc.es/repos/ptools/extrae/trunk/src/tracer/wrappers/API/threadinfo.h $
 | @last_commit: $Date: 2013-04-30 12:07:29 +0200 (mar, 30 abr 2013) $
 | @version:     $Revision: 1692 $
\* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#ifndef __THREADINFO_H_INCLUDED_
#define __THREADINFO_H_INCLUDED_

#define THREAD_INFO_NAME_LEN 256

typedef struct Extrae_thread_info
{
	char ThreadName[THREAD_INFO_NAME_LEN];
} Extrae_thread_info_t;

void Extrae_allocate_thread_CleanUp (void);
void Extrae_allocate_thread_info (unsigned nthreads);
void Extrae_reallocate_thread_info (unsigned prevnthreads, unsigned nthreads);
void Extrae_set_thread_name (unsigned thread, char *name);
char *Extrae_get_thread_name (unsigned thread);
unsigned Extrae_search_thread_name (char *name, int *found);


#endif /* __THREADINFO_H_INCLUDED_ */

