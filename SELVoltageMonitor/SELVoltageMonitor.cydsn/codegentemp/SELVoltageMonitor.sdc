# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\PSoC 6 Projects\sel_voltage_monitor\SELVoltageMonitor\SELVoltageMonitor.cydsn\SELVoltageMonitor.cyprj
# Date: Thu, 05 Mar 2020 21:58:25 GMT
#set_units -time ns
create_clock -name {CyClk_LF} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyFLL} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/fll}]]
create_clock -name {CyClk_HF0} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/hfclk_0}]]
create_clock -name {CyClk_Fast} -period 10 -waveform {0 5} [list [get_pins {ClockBlock/fastclk}]]
create_clock -name {CyClk_Peri} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/periclk}]]
create_generated_clock -name {CyClk_Slow} -source [get_pins {ClockBlock/periclk}] -edges {1 2 3} [list [get_pins {ClockBlock/slowclk}]]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/periclk}] -edges {1 37 73} [list [get_pins {ClockBlock/ff_div_5}]]
create_clock -name {CyPeriClk_App} -period 20 -waveform {0 10} [list [get_pins {ClockBlock/periclk_App}]]
create_clock -name {CyAltHF} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/altHf}]]
create_clock -name {CyIMO} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/imo}]]


# Component constraints for C:\PSoC 6 Projects\sel_voltage_monitor\SELVoltageMonitor\SELVoltageMonitor.cydsn\TopDesign\TopDesign.cysch
# Project: C:\PSoC 6 Projects\sel_voltage_monitor\SELVoltageMonitor\SELVoltageMonitor.cydsn\SELVoltageMonitor.cyprj
# Date: Thu, 05 Mar 2020 21:57:18 GMT
