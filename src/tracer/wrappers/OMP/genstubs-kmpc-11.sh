#!/bin/bash

MAXNUMBER=512
INTERMEDIATE_FUNCS="intel-kmpc-11-intermediate.c"
INTERMEDIATE_SWITCH="intel-kmpc-11-intermediate-switch.c"
INTERMEDIATE_HEADER="intel-kmpc-11-intermediate.h"

rm -f ${INTERMEDIATE_FUNCS} ${INTERMEDIATE_SWITCH}

echo "/* Automagically generated file by $0 at `date` */" > ${INTERMEDIATE_HEADER}
echo "#ifndef INTEL_OMP_FUNC_ENTRIES" >> ${INTERMEDIATE_HEADER}
echo "# define INTEL_OMP_FUNC_ENTRIES ${MAXNUMBER}" >> ${INTERMEDIATE_HEADER}
echo "#endif" >> ${INTERMEDIATE_HEADER}

for number in `seq 0 ${MAXNUMBER}`
do
	
	# Generate the intermediate routines

	echo -n "static void __kmpc_parallel_func${number}param (int *par1, int *par2" >> ${INTERMEDIATE_FUNCS}
	for i in `seq 1 ${number}` 
	do
		echo -n ", void *p${i}" >> ${INTERMEDIATE_FUNCS}
	done
	echo ")" >> ${INTERMEDIATE_FUNCS}
	echo "{" >> ${INTERMEDIATE_FUNCS}
	echo -e "\tvoid *p = (void*) par_func;" >> ${INTERMEDIATE_FUNCS}
	echo -e -n "\tvoid (*intermediate)(int*,void*" >> ${INTERMEDIATE_FUNCS}
	for i in `seq 1 ${number}`
	do
		echo -n ",void *" >> ${INTERMEDIATE_FUNCS}
	done
	echo -n ") = (void(*)(int*,void*" >> ${INTERMEDIATE_FUNCS}
	for i in `seq 1 ${number}`
	do
		echo -n ",void *" >> ${INTERMEDIATE_FUNCS}
	done
	echo ")) par_func;" >> ${INTERMEDIATE_FUNCS}
	echo "" >> ${INTERMEDIATE_FUNCS}
	echo -e "\tExtrae_OpenMP_UF_Entry (p);" >> ${INTERMEDIATE_FUNCS}
	echo -e "\tBackend_Leave_Instrumentation (); /* We're entering in user code */" >> ${INTERMEDIATE_FUNCS}
	echo -e -n "\tintermediate (par1,par2" >> ${INTERMEDIATE_FUNCS}
	for i in `seq 1 ${number}`
	do
	  echo -n ",p${i}" >> ${INTERMEDIATE_FUNCS}
	done
	echo ");" >> ${INTERMEDIATE_FUNCS}
	echo -e "\tExtrae_OpenMP_UF_Exit ();" >> ${INTERMEDIATE_FUNCS}
	echo "}" >> ${INTERMEDIATE_FUNCS}
	echo >> ${INTERMEDIATE_FUNCS}

	# Generate the switch body

	echo -e "\t\t\tcase ${number}:" >> ${INTERMEDIATE_SWITCH}
	echo -e -n "\t\t\t\t__kmpc_fork_call_real (p1, p2, __kmpc_parallel_func${number}param" >> ${INTERMEDIATE_SWITCH}
	for i in `seq 1 ${number}`
	do
		let "tmp = i - 1"
		echo -n ", params[${tmp}]" >> ${INTERMEDIATE_SWITCH}
	done
	echo ");" >> ${INTERMEDIATE_SWITCH}
	echo -e "\t\t\t\tbreak;" >> ${INTERMEDIATE_SWITCH}

done
