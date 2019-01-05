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

###############################################################################
#                  Header                                                     #
###############################################################################
librtemsbsp_a_CPPFLAGS = $(AM_CPPFLAGS)
librtemsbsp_a_CPPFLAGS += -I$(RTEMS_SOURCE_ROOT)/bsps/arm/stm32f7xx/contrib/Configuration
librtemsbsp_a_CPPFLAGS += -I$(RTEMS_SOURCE_ROOT)/bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Inc
librtemsbsp_a_CPPFLAGS += -I$(RTEMS_SOURCE_ROOT)/bsps/arm/stm32f7xx/contrib/Drivers/CMSIS/Device/ST/STM32F7xx/Include

###############################################################################
#                  Source                                                     #
###############################################################################
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
#librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/start/io.c
#librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/start/rcc.c
#librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/start/start-config-io.c

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


# ST STM32F7xx HAL
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_can.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cec.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cryp.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cryp_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dcmi.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dcmi_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dfsdm.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_eth.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hash.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hash_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hcd.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2s.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_irda.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_iwdg.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_jpeg.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_lptim.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_mdios.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_mmc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_nand.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_nor.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rng.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rtc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rtc_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_smartcard.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_smartcard_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_smbus.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spdifrx.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sram.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_usart.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_wwdg.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_adc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_crc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_dac.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_dma.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_dma2d.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_exti.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_gpio.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_i2c.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_lptim.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_pwr.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_rcc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_rng.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_rtc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_spi.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_tim.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usart.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usb.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/arm/stm32f7xx/contrib/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_utils.c



###############################################################################
#                  Special Rules                                              #
###############################################################################


include $(srcdir)/../../../../../../bsps/shared/irq-sources.am
include $(srcdir)/../../../../../../bsps/shared/shared-sources.am
include $(srcdir)/../../../../../../bsps/arm/stm32f7xx/headers.am
include $(srcdir)/../../../../../../bsps/arm/stm32f7xx/contrib/headers.am
