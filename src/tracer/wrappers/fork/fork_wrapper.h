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
 | @file: $HeadURL: https://svn.bsc.es/repos/ptools/extrae/trunk/src/tracer/wrappers/fork/fork_wrapper.h $
 | @last_commit: $Date: 2013-05-23 18:07:44 +0200 (jue, 23 may 2013) $
 | @version:     $Revision: 1762 $
\* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#ifndef FORK_WRAPPER_H_INCLUDED
#define FORK_WRAPPER_H_INCLUDED

int Extrae_isProcessMaster (void);
int Extrae_myDepthOfAllProcesses (void);

void Extrae_Probe_fork_Entry (void);
void Extrae_Probe_fork_Exit (void);
void Extrae_Probe_fork_parent_Exit (void);
void Extrae_Probe_fork_child_Exit (void);

void Extrae_Probe_wait_Entry (void);
void Extrae_Probe_wait_Exit (void);

void Extrae_Probe_waitpid_Entry (void);
void Extrae_Probe_waitpid_Exit (void);

void Extrae_Probe_exec_l_Entry (char *newbinary);
void Extrae_Probe_exec_v_Entry (char *newbinary, char *const argv[]);
void Extrae_Probe_exec_Exit (void);

void Extrae_Probe_system_Entry (char *newbinary);
void Extrae_Probe_system_Exit (void);

#endif /* FORK_WRAPPER_H_INCLUDED */

