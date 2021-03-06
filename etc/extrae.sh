#
# This file is automatically generated by the Extrae instrumentation Makefile.
# Edit with caution
#

if test "${EXTRAE_HOME}" != "" ; then

	# Read configuration variables if available!
	if ! test -f ${EXTRAE_HOME}/etc/extrae-vars.sh ; then
		echo "Error! Unable to locate ${EXTRAE_HOME}/etc/extrae-vars.sh"
		echo "Dying..."
		break
	else
		source ${EXTRAE_HOME}/etc/extrae-vars.sh
	fi

	if test -f "${EXTRAE_ONLINE_SOURCES}"; then
		source ${EXTRAE_ONLINE_SOURCES}
	fi

else
	echo "You have to define EXTRAE_HOME to run this script"
fi

