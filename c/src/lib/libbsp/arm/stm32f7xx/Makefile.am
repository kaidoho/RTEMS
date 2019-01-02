##
#
# @file
#
# @brief Makefile of LibBSP for the STM32F7xx boards.
#

ACLOCAL_AMFLAGS = -I ../../../../aclocal

include $(top_srcdir)/../../../../automake/compile.am
include $(top_srcdir)/../../bsp.am

###############################################################################
#                  Header                                                     #
###############################################################################

###############################################################################
#                  Data                                                       #
###############################################################################

dist_project_lib_DATA = ../../../../../../bsps/arm/stm32f7xx/start/bsp_specs

start.$(OBJEXT): ../../../../../../bsps/arm/shared/start/start.S
	$(CPPASCOMPILE) -o $@ -c $<
project_lib_DATA = start.$(OBJEXT)

project_lib_DATA += linkcmds
dist_project_lib_DATA += ../../../../../../bsps/arm/stm32f7xx/start/linkcmds.nucleo-stm32f746zg

###############################################################################
#                  LibBSP                                                     #
###############################################################################

project_lib_LIBRARIES = librtemsbsp.a

librtemsbsp_a_SOURCES =

# Shared
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/dev/getentropy/getentropy-cpucounter.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/start/bspfatal-default.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/start/bspgetworkarea-default.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/dev/cpucounter/cpucounterfrequency.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/dev/cpucounter/cpucounterread.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/start/sbrk.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/start/stackalloc.c

# Startup
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/shared/start/bsp-start-memcpy.S
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/start/bspstart.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/start/bspstarthook.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/start/bspreset.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/start/io.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/start/rcc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/start/start-config-io.c

# IRQ
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/irq/irq-default-handler.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/shared/irq/irq-armv7m.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/shared/irq/irq-dispatch-armv7m.c

# Console
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/dev/serial/legacy-console.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/dev/serial/legacy-console-control.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/dev/serial/legacy-console-select.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/console/console-config.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/console/usart.c


# Clock
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/shared/clock/clock-armv7m.c

# Timer
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/dev/btimer/btimer-stub.c

# Cache
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/cache/nocache.c

###############################################################################
#                  Special Rules                                              #
###############################################################################


include $(srcdir)/../../../../../../bsps/shared/irq-sources.am
include $(srcdir)/../../../../../../bsps/shared/shared-sources.am
include $(srcdir)/../../../../../../bsps/arm/stm32f7xx/headers.am
