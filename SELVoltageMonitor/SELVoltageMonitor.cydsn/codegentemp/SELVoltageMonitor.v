// ======================================================================
// SELVoltageMonitor.v generated from TopDesign.cysch
// 12/08/2020 at 17:19
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 14
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 15
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 16
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 17
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 18
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 19
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 20
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 21
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 22
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 23
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 24
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 25
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 26
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 27
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 28
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 29
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 30
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 31
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 32
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 4
`define CYDEV_CHIP_MEMBER_USED 27
`define CYDEV_CHIP_REVISION_USED 33
// bIncludeDriverToComponent_v1_0(PDL_DRIVER_NAME=ble, PDL_DRIVER_REQ_VERSION=2.0.0, PDL_DRIVER_SUBGROUP=Stack library, PDL_DRIVER_VARIANT=Profile - Host CM0+ / Ctrl CM0+, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=bIncludeDriverToComponent_v1_0, CY_CONFIG_TITLE=IncludeBleLibs, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=BLE_1:IncludeBleLibs, CY_INSTANCE_SHORT_NAME=IncludeBleLibs, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=ble, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=Stack library, CY_PDL_DRIVER_VARIANT=Profile - Host CM0+ / Ctrl CM0+, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=BLE_1_IncludeBleLibs, )
module bIncludeDriverToComponent_v1_0_0 ;





endmodule

// BLE_PDL_v2_0(AddQdepthPerConn=0, AutopopulateWhitelist=true, ConnectionCount=1, coresCount=0, EnableExternalLnaRxOutput=false, EnableExternalPaLnaOutput=false, EnableExternalPaTxOutput=false, EnableExternalPrepWriteBuff=false, EnableL2capLogicalChannels=true, EnableLinkLayerPrivacy=true, GapConfig=<?xml version="1.0" encoding="utf-16"?>\r\n<CyGapConfiguration_T2 xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema">\r\n  <DeviceAddress>00A050000000</DeviceAddress>\r\n  <SiliconGeneratedAddress>true</SiliconGeneratedAddress>\r\n  <MtuSize>23</MtuSize>\r\n  <MaxTxPayloadSize>27</MaxTxPayloadSize>\r\n  <MaxRxPayloadSize>27</MaxRxPayloadSize>\r\n  <TxPowerLevelConnection>0</TxPowerLevelConnection>\r\n  <TxPowerLevelAdvScan>0</TxPowerLevelAdvScan>\r\n  <Le2Mbps>false</Le2Mbps>\r\n  <LePing>false</LePing>\r\n  <TxPowerCalRetention>false</TxPowerCalRetention>\r\n  <SecurityConfig>\r\n    <SecurityMode>SECURITY_MODE_1</SecurityMode>\r\n    <SecurityLevel>NO_SECURITY</SecurityLevel>\r\n    <StrictPairing>false</StrictPairing>\r\n    <KeypressNotifications>false</KeypressNotifications>\r\n    <IOCapability>DISPLAY</IOCapability>\r\n    <PairingMethod>JUST_WORKS</PairingMethod>\r\n    <Bonding>BOND</Bonding>\r\n    <BondListSize>16</BondListSize>\r\n    <WhitelistSize>16</WhitelistSize>\r\n    <EnableLinkLayerPrivacy>true</EnableLinkLayerPrivacy>\r\n    <ResolvingListSize>16</ResolvingListSize>\r\n    <EncryptionKeySize>16</EncryptionKeySize>\r\n  </SecurityConfig>\r\n  <AdditionalSecurityConfigList />\r\n  <PeripheralConfigList>\r\n    <CyPeripheralConfiguration>\r\n      <Name>Peripheral configuration 0</Name>\r\n      <GapRole>PERIPHERAL</GapRole>\r\n      <AdvertisementConfig>\r\n        <AdvScanMode>FAST_CONNECTION</AdvScanMode>\r\n        <AdvFastScanInterval>\r\n          <Minimum>20</Minimum>\r\n          <Maximum>30</Maximum>\r\n        </AdvFastScanInterval>\r\n        <AdvReducedScanInterval>\r\n          <Minimum>1000</Minimum>\r\n          <Maximum>10240</Maximum>\r\n        </AdvReducedScanInterval>\r\n        <AdvDiscoveryMode>GENERAL</AdvDiscoveryMode>\r\n        <AdvType>CONNECTABLE_UNDIRECTED</AdvType>\r\n        <AdvFilterPolicy>SCAN_REQUEST_ANY_CONNECT_REQUEST_ANY</AdvFilterPolicy>\r\n        <AdvChannelMap>ALL</AdvChannelMap>\r\n        <AdvFastTimeout>0</AdvFastTimeout>\r\n        <AdvReducedTimeout>150</AdvReducedTimeout>\r\n        <EnableReducedAdvertising>false</EnableReducedAdvertising>\r\n      </AdvertisementConfig>\r\n      <AdvertisementPacket>\r\n        <PacketType>ADVERTISEMENT</PacketType>\r\n        <Items>\r\n          <CyADStructure>\r\n            <ADType>1</ADType>\r\n            <ADData>06</ADData>\r\n          </CyADStructure>\r\n          <CyADStructure>\r\n            <ADType>9</ADType>\r\n            <ADData>53:45:4C:20:4D:6F:6E:69:74:6F:72</ADData>\r\n          </CyADStructure>\r\n          <CyADStructure>\r\n            <ADType>3</ADType>\r\n            <ADData>AF:E5:9C:F8:05:58</ADData>\r\n          </CyADStructure>\r\n        </Items>\r\n        <IncludedServicesServiceUuid>\r\n          <int>22</int>\r\n          <int>44</int>\r\n          <int>47</int>\r\n        </IncludedServicesServiceUuid>\r\n        <IncludedServicesServiceSolicitation />\r\n        <IncludedServicesServiceData />\r\n      </AdvertisementPacket>\r\n      <ScanResponsePacket>\r\n        <PacketType>SCAN_RESPONSE</PacketType>\r\n        <Items />\r\n        <IncludedServicesServiceUuid />\r\n        <IncludedServicesServiceSolicitation />\r\n        <IncludedServicesServiceData />\r\n      </ScanResponsePacket>\r\n    </CyPeripheralConfiguration>\r\n  </PeripheralConfigList>\r\n  <CentralConfigList />\r\n  <BroadcasterConfigList />\r\n  <ObserverConfigList />\r\n  <MixedPeripheralBroadcasterConfigList>\r\n    <CyPeripheralConfiguration>\r\n      <Name>Peripheral configuration 0</Name>\r\n      <GapRole>PERIPHERAL</GapRole>\r\n      <AdvertisementConfig>\r\n        <AdvScanMode>FAST_CONNECTION</AdvScanMode>\r\n        <AdvFastScanInterval>\r\n          <Minimum>20</Minimum>\r\n          <Maximum>30</Maximum>\r\n        </AdvFastScanInterval>\r\n        <AdvReducedScanInterval>\r\n          <Minimum>1000</Minimum>\r\n          <Maximum>10240</Maximum>\r\n        </AdvReducedScanInterval>\r\n        <AdvDiscoveryMode>GENERAL</AdvDiscoveryMode>\r\n        <AdvType>CONNECTABLE_UNDIRECTED</AdvType>\r\n        <AdvFilterPolicy>SCAN_REQUEST_ANY_CONNECT_REQUEST_ANY</AdvFilterPolicy>\r\n        <AdvChannelMap>ALL</AdvChannelMap>\r\n        <AdvFastTimeout>0</AdvFastTimeout>\r\n        <AdvReducedTimeout>150</AdvReducedTimeout>\r\n        <EnableReducedAdvertising>false</EnableReducedAdvertising>\r\n      </AdvertisementConfig>\r\n      <AdvertisementPacket>\r\n        <PacketType>ADVERTISEMENT</PacketType>\r\n        <Items>\r\n          <CyADStructure>\r\n            <ADType>1</ADType>\r\n            <ADData>06</ADData>\r\n          </CyADStructure>\r\n          <CyADStructure>\r\n            <ADType>9</ADType>\r\n            <ADData>53:45:4C:20:4D:6F:6E:69:74:6F:72</ADData>\r\n          </CyADStructure>\r\n          <CyADStructure>\r\n            <ADType>3</ADType>\r\n            <ADData>AF:E5:9C:F8:05:58</ADData>\r\n          </CyADStructure>\r\n        </Items>\r\n        <IncludedServicesServiceUuid>\r\n          <int>22</int>\r\n          <int>44</int>\r\n          <int>47</int>\r\n        </IncludedServicesServiceUuid>\r\n        <IncludedServicesServiceSolicitation />\r\n        <IncludedServicesServiceData />\r\n      </AdvertisementPacket>\r\n      <ScanResponsePacket>\r\n        <PacketType>SCAN_RESPONSE</PacketType>\r\n        <Items />\r\n        <IncludedServicesServiceUuid />\r\n        <IncludedServicesServiceSolicitation />\r\n        <IncludedServicesServiceData />\r\n      </ScanResponsePacket>\r\n    </CyPeripheralConfiguration>\r\n  </MixedPeripheralBroadcasterConfigList>\r\n  <MixedCentralObserverConfigList />\r\n  <GapRoles>\r\n    <CyEGapRole>PERIPHERAL</CyEGapRole>\r\n  </GapRoles>\r\n</CyGapConfiguration_T2>, HalBaudRate=115200, HalCtsEnable=true, HalCtsPolarity=0, HalOversampling=13, HalRtsEnable=true, HalRtsPolarity=0, HalRtsTriggerLevel=120, HciContrCore=1, HostCore=1, ImportFilePath=, KeypressNotifications=false, L2capMpsSize=23, L2capMtuSize=23, L2capNumChannels=1, L2capNumPsm=1, LE2Mbps=false, LLMaxRxPayloadSize=27, LLMaxTxPayloadSize=27, MaxAttrNoOfBuffer=0, MaxBondedDevices=16, MaxResolvableDevices=16, MaxWhitelistSize=16, Mode=0, PDL_PARAM=Csub="Core"  Cvariant="", ProfileConfig=<?xml version="1.0" encoding="utf-16"?>\r\n<Profile xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" ID="1" DisplayName="GATT" Name="GATT" Type="org.bluetooth.profile.custom">\r\n  <CyProfileRole ID="2" DisplayName="Server" Name="Server">\r\n    <CyService ID="3" DisplayName="Generic Access" Name="Generic Access" Type="org.bluetooth.service.generic_access" UUID="1800">\r\n      <CyCharacteristic ID="4" DisplayName="Device Name" Name="Device Name" Type="org.bluetooth.characteristic.gap.device_name" UUID="2A00">\r\n        <Field Name="Name">\r\n          <DataFormat>utf8s</DataFormat>\r\n          <ByteLength>11</ByteLength>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>SEL Monitor</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="5" DisplayName="Appearance" Name="Appearance" Type="org.bluetooth.characteristic.gap.appearance" UUID="2A01">\r\n        <Field Name="Category">\r\n          <DataFormat>16bit</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="6" DisplayName="Peripheral Preferred Connection Parameters" Name="Peripheral Preferred Connection Parameters" Type="org.bluetooth.characteristic.gap.peripheral_preferred_connection_parameters" UUID="2A04">\r\n        <Field Name="Minimum Connection Interval">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>6</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x0006</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Maximum Connection Interval">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>6</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x0028</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Slave Latency">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>0</Minimum>\r\n            <Maximum>499</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Connection Supervision Timeout Multiplier">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>10</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x03E8</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="7" DisplayName="Central Address Resolution" Name="Central Address Resolution" Type="org.bluetooth.characteristic.gap.central_address_resolution" UUID="2AA6">\r\n        <Field Name="Central Address Resolution Support">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="8" DisplayName="Resolvable Private Address Only" Name="Resolvable Private Address Only" Type="org.bluetooth.characteristic.gap.resolvable_private_address_only" UUID="2AC9">\r\n        <Field Name="Resolvable Private Address Only">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <Declaration>PrimarySingleInstance</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="9" DisplayName="Generic Attribute" Name="Generic Attribute" Type="org.bluetooth.service.generic_attribute" UUID="1801">\r\n      <CyCharacteristic ID="10" DisplayName="Service Changed" Name="Service Changed" Type="org.bluetooth.characteristic.gatt.service_changed" UUID="2A05">\r\n        <CyDescriptor ID="11" DisplayName="Client Characteristic Configuration" Name="Client Characteristic Configuration" Type="org.bluetooth.descriptor.gatt.client_characteristic_configuration" UUID="2902">\r\n          <Field Name="Properties">\r\n            <DataFormat>16bit</DataFormat>\r\n            <ByteLength>2</ByteLength>\r\n            <Range>\r\n              <IsDeclared>true</IsDeclared>\r\n              <Minimum>0</Minimum>\r\n              <Maximum>3</Maximum>\r\n            </Range>\r\n            <ValueType>BITFIELD</ValueType>\r\n            <Bit>\r\n              <Index>0</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Notifications disabled" />\r\n                <Enumeration key="1" value="Notifications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <Bit>\r\n              <Index>1</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Indications disabled" />\r\n                <Enumeration key="1" value="Indications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <ArrayValue />\r\n          </Field>\r\n          <Properties>\r\n            <Property Type="READ" Present="true" Mandatory="true" />\r\n            <Property Type="WRITE" Present="true" Mandatory="true" />\r\n          </Properties>\r\n          <Permission>\r\n            <AccessPermission>READ_WRITE</AccessPermission>\r\n          </Permission>\r\n        </CyDescriptor>\r\n        <Field Name="Start of Affected Attribute Handle Range">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>1</Minimum>\r\n            <Maximum>65535</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="End of Affected Attribute Handle Range">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>1</Minimum>\r\n            <Maximum>65535</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="INDICATE" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>NONE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <Declaration>PrimarySingleInstance</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="22" DisplayName="Meter" Name="Custom Service" Type="org.bluetooth.service.custom" UUID="E5AF">\r\n      <CyCharacteristic ID="23" DisplayName="Current Voltage" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="5C46F35B">\r\n        <Field Name="New field">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <Declaration>Primary</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="44" DisplayName="Event" Name="Custom Service" Type="org.bluetooth.service.custom" UUID="F89C">\r\n      <CyCharacteristic ID="45" DisplayName="ES_1_10" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="83EFC212">\r\n        <CyDescriptor ID="46" DisplayName="Custom Descriptor" Name="Custom Descriptor" Type="org.bluetooth.descriptor.custom" UUID="2D4BBBF2ECBB476EA4CCEB17C6280BFB">\r\n          <Field Name="New field">\r\n            <DataFormat>uint8</DataFormat>\r\n            <ByteLength>1</ByteLength>\r\n            <ValueType>BASIC</ValueType>\r\n            <ArrayValue />\r\n          </Field>\r\n          <Properties>\r\n            <Property Type="READ" Present="false" Mandatory="false" />\r\n            <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          </Properties>\r\n          <Permission />\r\n        </CyDescriptor>\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="56" DisplayName="ES_11_20" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="86D3DE04">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="58" DisplayName="ES_21_30" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="5F9E4FC5">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="60" DisplayName="ES_31_40" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="4E4A8BC4">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="62" DisplayName="ES_41_50" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="09D74D3D">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="64" DisplayName="ES_51_60" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="128380C9">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="65" DisplayName="ES_61_70" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="1E1F22AA">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="67" DisplayName="ES_71_80" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="1A8A5E13">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="69" DisplayName="ES_81_90" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="690501F7">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="71" DisplayName="ES_91_100" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="EA8CFB7E">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="73" DisplayName="ES_101_110" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="C8693F15">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="75" DisplayName="ES_111_120" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="829ADFE2">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="77" DisplayName="ES_121_130" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="1894D181">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="79" DisplayName="ES_131_140" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="84F6634E">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="81" DisplayName="ES_141_144" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="6A5DCA57">\r\n        <Field Name="New field">\r\n          <DataFormat>sint16 Array[]</DataFormat>\r\n          <ByteLength>10</ByteLength>\r\n          <ValueType>ARRAY</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <Declaration>Primary</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="47" DisplayName="Control" Name="Custom Service" Type="org.bluetooth.service.custom" UUID="5805">\r\n      <CyCharacteristic ID="48" DisplayName="Trigger" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="0467164D">\r\n        <Field Name="New field">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>WRITE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="50" DisplayName="Event Number" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="4F3CAB94">\r\n        <Field Name="New field">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>READ_WRITE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="52" DisplayName="Upper Threshold" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="CEAB1FA9">\r\n        <Field Name="New field">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x1234</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>READ_WRITE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="54" DisplayName="Lower Threshold" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="497BBD22">\r\n        <Field Name="New field">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x2345</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>READ_WRITE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="82" DisplayName="Number of Events" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="0258475E">\r\n        <Field Name="New field">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="83" DisplayName="Enable" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="25EB9E56">\r\n        <Field Name="New field">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>READ_WRITE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="84" DisplayName="Delete Event Number" Name="Custom Characteristic" Type="org.bluetooth.characteristic.custom" UUID="61B74E48">\r\n        <Field Name="Delete Event Number">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0</GeneralValue>\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="BROADCAST" Present="false" Mandatory="false" />\r\n          <Property Type="READ" Present="false" Mandatory="false" />\r\n          <Property Type="WRITE" Present="true" Mandatory="false" />\r\n          <Property Type="WRITE_WITHOUT_RESPONSE" Present="false" Mandatory="false" />\r\n          <Property Type="NOTIFY" Present="false" Mandatory="false" />\r\n          <Property Type="INDICATE" Present="false" Mandatory="false" />\r\n          <Property Type="AUTHENTICATED_SIGNED_WRITES" Present="false" Mandatory="false" />\r\n          <Property Type="RELIABLE_WRITE" Present="false" Mandatory="false" />\r\n          <Property Type="WRITABLE_AUXILIARIES" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>WRITE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <Declaration>Primary</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <RoleType>SERVER</RoleType>\r\n  </CyProfileRole>\r\n  <CyProfileRole ID="12" DisplayName="Client" Name="Client">\r\n    <CyService ID="13" DisplayName="Generic Access" Name="Generic Access" Type="org.bluetooth.service.generic_access" UUID="1800">\r\n      <CyCharacteristic ID="14" DisplayName="Device Name" Name="Device Name" Type="org.bluetooth.characteristic.gap.device_name" UUID="2A00">\r\n        <Field Name="Name">\r\n          <DataFormat>utf8s</DataFormat>\r\n          <ByteLength>0</ByteLength>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n          <Property Type="WRITE" Present="false" Mandatory="false" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="15" DisplayName="Appearance" Name="Appearance" Type="org.bluetooth.characteristic.gap.appearance" UUID="2A01">\r\n        <Field Name="Category">\r\n          <DataFormat>16bit</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <FillRequirement>C1</FillRequirement>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="16" DisplayName="Peripheral Preferred Connection Parameters" Name="Peripheral Preferred Connection Parameters" Type="org.bluetooth.characteristic.gap.peripheral_preferred_connection_parameters" UUID="2A04">\r\n        <Field Name="Minimum Connection Interval">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>6</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x0006</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Maximum Connection Interval">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>6</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x0028</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Slave Latency">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>0</Minimum>\r\n            <Maximum>499</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="Connection Supervision Timeout Multiplier">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>10</Minimum>\r\n            <Maximum>3200</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <GeneralValue>0x03E8</GeneralValue>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="17" DisplayName="Central Address Resolution" Name="Central Address Resolution" Type="org.bluetooth.characteristic.gap.central_address_resolution" UUID="2AA6">\r\n        <Field Name="Central Address Resolution Support">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <CyCharacteristic ID="18" DisplayName="Resolvable Private Address Only" Name="Resolvable Private Address Only" Type="org.bluetooth.characteristic.gap.resolvable_private_address_only" UUID="2AC9">\r\n        <Field Name="Resolvable Private Address Only">\r\n          <DataFormat>uint8</DataFormat>\r\n          <ByteLength>1</ByteLength>\r\n          <ValueType>ENUM</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="READ" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission />\r\n      </CyCharacteristic>\r\n      <Declaration>PrimarySingleInstance</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <CyService ID="19" DisplayName="Generic Attribute" Name="Generic Attribute" Type="org.bluetooth.service.generic_attribute" UUID="1801">\r\n      <CyCharacteristic ID="20" DisplayName="Service Changed" Name="Service Changed" Type="org.bluetooth.characteristic.gatt.service_changed" UUID="2A05">\r\n        <CyDescriptor ID="21" DisplayName="Client Characteristic Configuration" Name="Client Characteristic Configuration" Type="org.bluetooth.descriptor.gatt.client_characteristic_configuration" UUID="2902">\r\n          <Field Name="Properties">\r\n            <DataFormat>16bit</DataFormat>\r\n            <ByteLength>2</ByteLength>\r\n            <Range>\r\n              <IsDeclared>true</IsDeclared>\r\n              <Minimum>0</Minimum>\r\n              <Maximum>3</Maximum>\r\n            </Range>\r\n            <ValueType>BITFIELD</ValueType>\r\n            <Bit>\r\n              <Index>0</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Notifications disabled" />\r\n                <Enumeration key="1" value="Notifications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <Bit>\r\n              <Index>1</Index>\r\n              <Size>1</Size>\r\n              <Value>0</Value>\r\n              <Enumerations>\r\n                <Enumeration key="0" value="Indications disabled" />\r\n                <Enumeration key="1" value="Indications enabled" />\r\n              </Enumerations>\r\n            </Bit>\r\n            <ArrayValue />\r\n          </Field>\r\n          <Properties>\r\n            <Property Type="READ" Present="true" Mandatory="true" />\r\n            <Property Type="WRITE" Present="true" Mandatory="true" />\r\n          </Properties>\r\n          <Permission>\r\n            <AccessPermission>READ_WRITE</AccessPermission>\r\n          </Permission>\r\n        </CyDescriptor>\r\n        <Field Name="Start of Affected Attribute Handle Range">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>1</Minimum>\r\n            <Maximum>65535</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Field Name="End of Affected Attribute Handle Range">\r\n          <DataFormat>uint16</DataFormat>\r\n          <ByteLength>2</ByteLength>\r\n          <Range>\r\n            <IsDeclared>true</IsDeclared>\r\n            <Minimum>1</Minimum>\r\n            <Maximum>65535</Maximum>\r\n          </Range>\r\n          <ValueType>BASIC</ValueType>\r\n          <ArrayValue />\r\n        </Field>\r\n        <Properties>\r\n          <Property Type="INDICATE" Present="true" Mandatory="true" />\r\n        </Properties>\r\n        <Permission>\r\n          <AccessPermission>NONE</AccessPermission>\r\n        </Permission>\r\n      </CyCharacteristic>\r\n      <Declaration>PrimarySingleInstance</Declaration>\r\n      <IncludedServices />\r\n    </CyService>\r\n    <RoleType>CLIENT</RoleType>\r\n  </CyProfileRole>\r\n  <ClientInstCount>0</ClientInstCount>\r\n</Profile>, RadioPowerCalibration=false, SharingMode=0, SmartMeshConfig=, SmartMeshMode=false, StackMode=3, StrictPairing=false, UseDeepSleep=false, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=BLE_PDL_v2_0, CY_CONFIG_TITLE=BLE_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=BLE_PDL_v2_0.pdf, CY_FITTER_NAME=BLE_1, CY_INSTANCE_SHORT_NAME=BLE_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=ble, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=Core, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=BLE_1, )
module BLE_PDL_v2_0_1 (
    pa_tx_en,
    lna_rx_en,
    pa_lna_en);
    output      pa_tx_en;
    output      lna_rx_en;
    output      pa_lna_en;


          wire  Net_66;
          wire  Net_65;
          wire  Net_64;
          wire  Net_63;
          wire  Net_62;
          wire  Net_61;
          wire  Net_60;
          wire  Net_59;
          wire  Net_58;
          wire  Net_52;
          wire  Net_43;
          wire  Net_42;
          wire  Net_41;
          wire  Net_40;
          wire  Net_39;
          wire  Net_38;
          wire  Net_37;
          wire  Net_36;
          wire  Net_3;
          wire  Net_2;
          wire  Net_1;

    cy_mxs40_ble_v1_0 cy_mxs40_ble (
        .ext_pa_lna_chip_en_out(pa_lna_en),
        .ext_lna_rx_ctl_out(lna_rx_en),
        .ext_pa_tx_ctl_out(pa_tx_en),
        .interrupt(Net_1));
    defparam cy_mxs40_ble.low_power = 0;


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(1),
		  .int_type(2'b10))
		bless_isr
		 (.int_signal(Net_1));


    bIncludeDriverToComponent_v1_0_0 IncludeBleLibs ();



endmodule

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// SCB_UART_PDL_v2_0(BaudRate=115200, BitsOrder=0, BreakSignalBits=11, BufferMinSize=64, ByteMode=true, ClkFreqDes=1382.4, ClkMinusTolerance=5, ClkPlusTolerance=5, ClockFromTerm=false, ComMode=0, CtsPolarity=0, CtsTermEnable=false, DataWidth=8, Direction=3, DropOnFrameErr=false, DropOnParityErr=false, EnableCts=false, EnableInputFilter=false, EnableMultiProc=false, EnableRts=false, EnableRxOutput=false, EnableTxEn=false, EnableTxOutput=false, InterruptMode=1, InterruptTermEnable=false, IntrRxBreakDetected=false, IntrRxFrameErr=false, IntrRxFull=false, IntrRxNotEmpty=false, IntrRxOverflow=false, IntrRxParityErr=false, IntrRxTrigger=false, IntrRxUnderflow=false, IntrTxEmpty=false, IntrTxNotFull=false, IntrTxOverflow=false, IntrTxTrigger=false, IntrTxUartDone=false, IntrTxUartLostArb=false, IntrTxUartNack=false, IntrTxUnderflow=false, IrdaLowPower=false, IrdaPolarity=0, IsCtsPinAllowed=true, IsDmaCapable=true, IsEnableInputFilterVisible=true, IsMultiprocessorModeAvailable=false, IsRtsPinAllowed=true, IsRtsTriggerLevelVisible=false, IsRxIntrSourcesVisible=false, IsRxTriggerLevelVisible=false, IsTxIntrSourcesVisible=false, IsTxTriggerLevelVisible=false, MaxFifoLevel=127, MpRxAcceptAddress=false, MpRxAddress=0, MpRxAddressMask=255, OvsFactor=12, ParityType=0, PreconfigureIO=false, RemoveCtsPin=true, RemoveIntr=false, RemoveRtsPin=true, RemoveRxPin=false, RemoveRxTxPin=true, RemoveTxEnPin=true, RemoveTxPin=false, RtsPolarity=0, RtsTermEnable=false, RtsTriggerLevel=63, RxIntrMask=0, RxTermEnable=false, RxTriggerLevel=63, RxTxTermEnable=false, ShowTerminals=false, SmCardRetryOnNack=false, StopBits=2, SymbolShape=0, TriggerOutputEnable=false, TxEnTermEnable=false, TxIntrMask=0, TxTermEnable=false, TxTriggerLevel=63, UartMode=2, UseIntr=true, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SCB_UART_PDL_v2_0, CY_CONFIG_TITLE=UART, CY_CONST_CONFIG=false, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=UART, CY_INSTANCE_SHORT_NAME=UART, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=scb, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=UART, )
module SCB_UART_PDL_v2_0_2 (
    cts_in,
    tx_out,
    rts_out,
    interrupt,
    clock,
    rx_dma,
    tx_dma,
    rx_in,
    rx_tx_out,
    tx_en_out);
    input       cts_in;
    output      tx_out;
    output      rts_out;
    output      interrupt;
    input       clock;
    output      rx_dma;
    output      tx_dma;
    input       rx_in;
    output      rx_tx_out;
    output      tx_en_out;


          wire  rx_wire;
          wire  tx_wire;
          wire  rts_wire;
          wire  cts_wire;
          wire  intr_wire;
          wire  clock_wire;
          wire  Net_161;
          wire  Net_157;
          wire  Net_156;
          wire [3:0] Net_155;
          wire  Net_154;
          wire  Net_150;
          wire  Net_149;
          wire  Net_148;
          wire  Net_147;
          wire  Net_146;
          wire  Net_145;
          wire  Net_1172;
          wire  Net_23;
          wire  tx_en_wire;
          wire  Net_47;
          wire  Net_22;
          wire  Net_24;
          wire  Net_847;


	cy_clock_v1_0
		#(.id("bada9d75-aedb-412e-976e-3b8fbd3a5f0d/b68e5b9d-7828-482d-a282-930f990e3b3e"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("723379629.62963"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_847));


	// clock_VM (cy_virtualmux_v1_0)
	assign clock_wire = Net_847;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_22));


    assign Net_23 = Net_22 | Net_847;

	wire [0:0] tmpFB_0__tx_net;
	wire [0:0] tmpIO_0__tx_net;
	electrical [0:0] tmpSIOVREF__tx_net;

	cy_mxs40_gpio_v1_0
		#(.id("bada9d75-aedb-412e-976e-3b8fbd3a5f0d/65f3af6c-759b-4ccb-8c66-5c95ba1f5f4f"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		tx
		 (.oe({1'b1}),
		  .y({tx_wire}),
		  .fb({tmpFB_0__tx_net[0:0]}),
		  .io({tmpIO_0__tx_net[0:0]}),
		  .siovref(tmpSIOVREF__tx_net));


	wire [0:0] tmpIO_0__rx_net;
	electrical [0:0] tmpSIOVREF__rx_net;

	cy_mxs40_gpio_v1_0
		#(.id("bada9d75-aedb-412e-976e-3b8fbd3a5f0d/b7e8018e-1ef7-49c0-b5a5-61641a03e31c"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		rx
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({Net_1172}),
		  .io({tmpIO_0__rx_net[0:0]}),
		  .siovref(tmpSIOVREF__rx_net));


	// rx_VM (cy_virtualmux_v1_0)
	assign rx_wire = Net_1172;

	// cts_VM (cy_virtualmux_v1_0)
	assign cts_wire = cts_in;


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		SCB_IRQ
		 (.int_signal(intr_wire));


    cy_mxs40_scb_v1_10 SCB (
        .clock(clock_wire),
        .uart_rx(rx_wire),
        .uart_cts(cts_wire),
        .i2c_scl(Net_145),
        .i2c_sda(Net_146),
        .spi_clk_s(1'b0),
        .spi_select_s(1'b0),
        .spi_miso_m(1'b0),
        .spi_mosi_s(1'b0),
        .uart_tx(tx_wire),
        .uart_rts(rts_wire),
        .uart_tx_en(tx_en_wire),
        .spi_clk_m(Net_154),
        .spi_select_m(Net_155[3:0]),
        .spi_mosi_m(Net_156),
        .spi_miso_s(Net_157),
        .interrupt(intr_wire),
        .tr_tx_req(tx_dma),
        .tr_rx_req(rx_dma),
        .tr_i2c_scl_filtered(Net_161));
    defparam SCB.master = 0;
    defparam SCB.mode = 2;
    defparam SCB.requires_io_preconfigure = 0;


    assign tx_out = tx_wire;

    assign rts_out = rts_wire;

    assign interrupt = intr_wire;

    assign rx_tx_out = tx_wire;

    assign tx_en_out = tx_en_wire;


endmodule

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: Bus_Connect_v2_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Bus_Connect_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Bus_Connect_v2_50\Bus_Connect_v2_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Bus_Connect_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\Bus_Connect_v2_50\Bus_Connect_v2_50.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// Component: cy_vref_v1_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_vref_v1_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_vref_v1_70\cy_vref_v1_70.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_vref_v1_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_vref_v1_70\cy_vref_v1_70.v"
`endif

// Scan_ADC_v2_10(AclkMuxSelect=1, Config0=<?xml version="1.0" encoding="utf-16"?><CyConfigModel xmlns:Version="2_10"><SampleRateEditor>true</SampleRateEditor><SampleRate>99991</SampleRate><FreeRunning>false</FreeRunning><UseSoc>false</UseSoc><VrefBypass>false</VrefBypass><VrefSource>VREFSOURCE_HALFVDDA</VrefSource><VrefVoltage>1.65</VrefVoltage><VnegSource>VNEGSOURCE_VREFSHORT</VnegSource><DiffResultFormat>UNSIGNED_FORMAT</DiffResultFormat><SingleEndedResultFormat>UNSIGNED_FORMAT</SingleEndedResultFormat><SamplesAveraged>EIGHT_SAMPLES</SamplesAveraged><AveragingMode>SEQUENTIAL_AVG</AveragingMode><AlternateResolution>EIGHT_BIT</AlternateResolution><CompareMode>LESS_THAN</CompareMode><LowLimit>525</LowLimit><HighLimit>3584</HighLimit><NumChannels>1</NumChannels><ChannelList><CyChannelModel><Enabled>true</Enabled><UseAltResolution>false</UseAltResolution><InputMode>SINGLE_ENDED_CHAN</InputMode><UseAveraging>false</UseAveraging><MinimumAcqTime>167</MinimumAcqTime><UseLimitInterrupt>false</UseLimitInterrupt><ActualAcqTime>560</ActualAcqTime><UseSaturationInterrupt>false</UseSaturationInterrupt><ApertureTimer>0</ApertureTimer></CyChannelModel></ChannelList><ApertureTimers><int>2</int><int>2</int><int>2</int><int>2</int></ApertureTimers><AdcClockDivider>28</AdcClockDivider><FilterType>LOW_PASS</FilterType><FilterDown3OrCenter>10</FilterDown3OrCenter><FilterWidthOrNotch>50</FilterWidthOrNotch><FilterSample>1000</FilterSample><FilterUabStartDelay>0</FilterUabStartDelay><FilterUabClockDivider>0</FilterUabClockDivider><UabCaps><Gain>0</Gain><C1>0</C1><C2>0</C2><C3>0</C3><C4>0</C4><CA>0</CA><CB>0</CB><CP>0</CP><CPP>0</CPP><CPPP>0</CPPP></UabCaps><ActualSampleRate>111607</ActualSampleRate><ActualAdcClockHz>1785714</ActualAdcClockHz><ActualScanUs>8.96001146881468</ActualScanUs></CyConfigModel>, Config1=<?xml version="1.0" encoding="utf-16"?><CyConfigModel xmlns:Version="2_10"><SampleRateEditor>true</SampleRateEditor><SampleRate>100000</SampleRate><FreeRunning>true</FreeRunning><UseSoc>false</UseSoc><VrefBypass>true</VrefBypass><VrefSource>VREFSOURCE_VBGR</VrefSource><VrefVoltage>1.2</VrefVoltage><VnegSource>VNEGSOURCE_VREFSHORT</VnegSource><DiffResultFormat>SIGNED_FORMAT</DiffResultFormat><SingleEndedResultFormat>UNSIGNED_FORMAT</SingleEndedResultFormat><SamplesAveraged>TWO_SAMPLES</SamplesAveraged><AveragingMode>SEQUENTIAL_AVG</AveragingMode><AlternateResolution>EIGHT_BIT</AlternateResolution><CompareMode>LESS_THAN</CompareMode><LowLimit>512</LowLimit><HighLimit>3584</HighLimit><NumChannels>2</NumChannels><ChannelList><CyChannelModel><Enabled>true</Enabled><UseAltResolution>false</UseAltResolution><InputMode>DIFFERENTIAL_CHAN</InputMode><UseAveraging>false</UseAveraging><MinimumAcqTime>167</MinimumAcqTime><UseLimitInterrupt>false</UseLimitInterrupt><ActualAcqTime>8040</ActualAcqTime><UseSaturationInterrupt>false</UseSaturationInterrupt><ApertureTimer>0</ApertureTimer></CyChannelModel><CyChannelModel><Enabled>true</Enabled><UseAltResolution>false</UseAltResolution><InputMode>DIFFERENTIAL_CHAN</InputMode><UseAveraging>false</UseAveraging><MinimumAcqTime>167</MinimumAcqTime><UseLimitInterrupt>false</UseLimitInterrupt><ActualAcqTime>180</ActualAcqTime><UseSaturationInterrupt>false</UseSaturationInterrupt><ApertureTimer>1</ApertureTimer></CyChannelModel></ChannelList><ApertureTimers><int>135</int><int>4</int><int>2</int><int>2</int></ApertureTimers><AdcClockDivider>3</AdcClockDivider><FilterType>LOW_PASS</FilterType><FilterDown3OrCenter>10</FilterDown3OrCenter><FilterWidthOrNotch>50</FilterWidthOrNotch><FilterSample>1000</FilterSample><FilterUabStartDelay>0</FilterUabStartDelay><FilterUabClockDivider>0</FilterUabClockDivider><UabCaps><Gain>0</Gain><C1>0</C1><C2>0</C2><C3>0</C3><C4>0</C4><CA>0</CA><CB>0</CB><CP>0</CP><CPP>0</CPP><CPPP>0</CPPP></UabCaps><ActualSampleRate>99800</ActualSampleRate><ActualAdcClockHz>16666666</ActualAdcClockHz><ActualScanUs>10.020040080160321</ActualScanUs></CyConfigModel>, Config2=<?xml version="1.0" encoding="utf-16"?><CyConfigModel xmlns:Version="2_10"><SampleRateEditor>true</SampleRateEditor><SampleRate>100000</SampleRate><FreeRunning>true</FreeRunning><UseSoc>false</UseSoc><VrefBypass>true</VrefBypass><VrefSource>VREFSOURCE_VBGR</VrefSource><VrefVoltage>1.2</VrefVoltage><VnegSource>VNEGSOURCE_VREFSHORT</VnegSource><DiffResultFormat>SIGNED_FORMAT</DiffResultFormat><SingleEndedResultFormat>UNSIGNED_FORMAT</SingleEndedResultFormat><SamplesAveraged>TWO_SAMPLES</SamplesAveraged><AveragingMode>SEQUENTIAL_AVG</AveragingMode><AlternateResolution>EIGHT_BIT</AlternateResolution><CompareMode>LESS_THAN</CompareMode><LowLimit>512</LowLimit><HighLimit>3584</HighLimit><NumChannels>2</NumChannels><ChannelList><CyChannelModel><Enabled>true</Enabled><UseAltResolution>false</UseAltResolution><InputMode>DIFFERENTIAL_CHAN</InputMode><UseAveraging>false</UseAveraging><MinimumAcqTime>167</MinimumAcqTime><UseLimitInterrupt>false</UseLimitInterrupt><ActualAcqTime>8040</ActualAcqTime><UseSaturationInterrupt>false</UseSaturationInterrupt><ApertureTimer>0</ApertureTimer></CyChannelModel><CyChannelModel><Enabled>true</Enabled><UseAltResolution>false</UseAltResolution><InputMode>DIFFERENTIAL_CHAN</InputMode><UseAveraging>false</UseAveraging><MinimumAcqTime>167</MinimumAcqTime><UseLimitInterrupt>false</UseLimitInterrupt><ActualAcqTime>180</ActualAcqTime><UseSaturationInterrupt>false</UseSaturationInterrupt><ApertureTimer>1</ApertureTimer></CyChannelModel></ChannelList><ApertureTimers><int>135</int><int>4</int><int>2</int><int>2</int></ApertureTimers><AdcClockDivider>3</AdcClockDivider><FilterType>LOW_PASS</FilterType><FilterDown3OrCenter>10</FilterDown3OrCenter><FilterWidthOrNotch>50</FilterWidthOrNotch><FilterSample>1000</FilterSample><FilterUabStartDelay>0</FilterUabStartDelay><FilterUabClockDivider>0</FilterUabClockDivider><UabCaps><Gain>0</Gain><C1>0</C1><C2>0</C2><C3>0</C3><C4>0</C4><CA>0</CA><CB>0</CB><CP>0</CP><CPP>0</CPP><CPPP>0</CPPP></UabCaps><ActualSampleRate>99800</ActualSampleRate><ActualAdcClockHz>16666666</ActualAdcClockHz><ActualScanUs>10.020040080160321</ActualScanUs></CyConfigModel>, Config3=<?xml version="1.0" encoding="utf-16"?><CyConfigModel xmlns:Version="2_10"><SampleRateEditor>true</SampleRateEditor><SampleRate>100000</SampleRate><FreeRunning>true</FreeRunning><UseSoc>false</UseSoc><VrefBypass>true</VrefBypass><VrefSource>VREFSOURCE_VBGR</VrefSource><VrefVoltage>1.2</VrefVoltage><VnegSource>VNEGSOURCE_VREFSHORT</VnegSource><DiffResultFormat>SIGNED_FORMAT</DiffResultFormat><SingleEndedResultFormat>UNSIGNED_FORMAT</SingleEndedResultFormat><SamplesAveraged>TWO_SAMPLES</SamplesAveraged><AveragingMode>SEQUENTIAL_AVG</AveragingMode><AlternateResolution>EIGHT_BIT</AlternateResolution><CompareMode>LESS_THAN</CompareMode><LowLimit>512</LowLimit><HighLimit>3584</HighLimit><NumChannels>2</NumChannels><ChannelList><CyChannelModel><Enabled>true</Enabled><UseAltResolution>false</UseAltResolution><InputMode>DIFFERENTIAL_CHAN</InputMode><UseAveraging>false</UseAveraging><MinimumAcqTime>167</MinimumAcqTime><UseLimitInterrupt>false</UseLimitInterrupt><ActualAcqTime>8040</ActualAcqTime><UseSaturationInterrupt>false</UseSaturationInterrupt><ApertureTimer>0</ApertureTimer></CyChannelModel><CyChannelModel><Enabled>true</Enabled><UseAltResolution>false</UseAltResolution><InputMode>DIFFERENTIAL_CHAN</InputMode><UseAveraging>false</UseAveraging><MinimumAcqTime>167</MinimumAcqTime><UseLimitInterrupt>false</UseLimitInterrupt><ActualAcqTime>180</ActualAcqTime><UseSaturationInterrupt>false</UseSaturationInterrupt><ApertureTimer>1</ApertureTimer></CyChannelModel></ChannelList><ApertureTimers><int>135</int><int>4</int><int>2</int><int>2</int></ApertureTimers><AdcClockDivider>3</AdcClockDivider><FilterType>LOW_PASS</FilterType><FilterDown3OrCenter>10</FilterDown3OrCenter><FilterWidthOrNotch>50</FilterWidthOrNotch><FilterSample>1000</FilterSample><FilterUabStartDelay>0</FilterUabStartDelay><FilterUabClockDivider>0</FilterUabClockDivider><UabCaps><Gain>0</Gain><C1>0</C1><C2>0</C2><C3>0</C3><C4>0</C4><CA>0</CA><CB>0</CB><CP>0</CP><CPP>0</CPP><CPPP>0</CPPP></UabCaps><ActualSampleRate>99800</ActualSampleRate><ActualAdcClockHz>16666666</ActualAdcClockHz><ActualScanUs>10.020040080160321</ActualScanUs></CyConfigModel>, Debug=false, DeviceSeriesName=PSoC 63, ExternalClk=false, ExternalSoc=false, ExtVrefMuxSelect=2, FilterConfigMuxSelect_0=1, FilterConfigMuxSelect_1=1, FilterConfigMuxSelect_2=2, FilterConfigMuxSelect_3=3, FilterVinMuxSelect_1_0=0, FilterVinMuxSelect_2_0=0, FilterVinMuxSelect_2_1=0, FilterVinMuxSelect_3_0=0, FilterVinMuxSelect_3_1=0, FilterVinMuxSelect_3_2=0, IsEdgeTrigger=1, IsFilterPresent=false, NumConfigs=1, SarmuxDiffMask=0, SarmuxVinDiffWidth=1, SarmuxVinNegWidth=1, SarmuxVinPlusMuxSelect_0=0, SarmuxVinPlusMuxSelect_1=0, SarmuxVinPlusMuxSelect_10=0, SarmuxVinPlusMuxSelect_11=0, SarmuxVinPlusMuxSelect_12=0, SarmuxVinPlusMuxSelect_13=0, SarmuxVinPlusMuxSelect_14=0, SarmuxVinPlusMuxSelect_15=0, SarmuxVinPlusMuxSelect_16=0, SarmuxVinPlusMuxSelect_17=0, SarmuxVinPlusMuxSelect_18=0, SarmuxVinPlusMuxSelect_19=0, SarmuxVinPlusMuxSelect_2=0, SarmuxVinPlusMuxSelect_20=0, SarmuxVinPlusMuxSelect_21=0, SarmuxVinPlusMuxSelect_22=0, SarmuxVinPlusMuxSelect_23=0, SarmuxVinPlusMuxSelect_24=0, SarmuxVinPlusMuxSelect_25=0, SarmuxVinPlusMuxSelect_26=0, SarmuxVinPlusMuxSelect_27=0, SarmuxVinPlusMuxSelect_28=0, SarmuxVinPlusMuxSelect_29=0, SarmuxVinPlusMuxSelect_3=0, SarmuxVinPlusMuxSelect_30=0, SarmuxVinPlusMuxSelect_31=0, SarmuxVinPlusMuxSelect_32=0, SarmuxVinPlusMuxSelect_33=0, SarmuxVinPlusMuxSelect_34=0, SarmuxVinPlusMuxSelect_35=0, SarmuxVinPlusMuxSelect_36=0, SarmuxVinPlusMuxSelect_37=0, SarmuxVinPlusMuxSelect_38=0, SarmuxVinPlusMuxSelect_39=0, SarmuxVinPlusMuxSelect_4=0, SarmuxVinPlusMuxSelect_40=0, SarmuxVinPlusMuxSelect_41=0, SarmuxVinPlusMuxSelect_42=0, SarmuxVinPlusMuxSelect_43=0, SarmuxVinPlusMuxSelect_44=0, SarmuxVinPlusMuxSelect_45=0, SarmuxVinPlusMuxSelect_46=0, SarmuxVinPlusMuxSelect_47=0, SarmuxVinPlusMuxSelect_48=0, SarmuxVinPlusMuxSelect_49=0, SarmuxVinPlusMuxSelect_5=0, SarmuxVinPlusMuxSelect_50=0, SarmuxVinPlusMuxSelect_51=0, SarmuxVinPlusMuxSelect_52=0, SarmuxVinPlusMuxSelect_53=0, SarmuxVinPlusMuxSelect_54=0, SarmuxVinPlusMuxSelect_55=0, SarmuxVinPlusMuxSelect_56=0, SarmuxVinPlusMuxSelect_57=0, SarmuxVinPlusMuxSelect_58=0, SarmuxVinPlusMuxSelect_59=0, SarmuxVinPlusMuxSelect_6=0, SarmuxVinPlusMuxSelect_60=0, SarmuxVinPlusMuxSelect_61=0, SarmuxVinPlusMuxSelect_62=0, SarmuxVinPlusMuxSelect_63=0, SarmuxVinPlusMuxSelect_7=0, SarmuxVinPlusMuxSelect_8=0, SarmuxVinPlusMuxSelect_9=0, SocMuxSelect=1, Test_ConfigSpacing=15, Test_ExposeTestTerminals=false, VinMinusMuxSelect_0=1, VinMinusMuxSelect_1=1, VinMinusMuxSelect_10=1, VinMinusMuxSelect_11=1, VinMinusMuxSelect_12=1, VinMinusMuxSelect_13=1, VinMinusMuxSelect_14=1, VinMinusMuxSelect_15=1, VinMinusMuxSelect_16=1, VinMinusMuxSelect_17=1, VinMinusMuxSelect_18=1, VinMinusMuxSelect_19=1, VinMinusMuxSelect_2=1, VinMinusMuxSelect_20=1, VinMinusMuxSelect_21=1, VinMinusMuxSelect_22=1, VinMinusMuxSelect_23=1, VinMinusMuxSelect_24=1, VinMinusMuxSelect_25=1, VinMinusMuxSelect_26=1, VinMinusMuxSelect_27=1, VinMinusMuxSelect_28=1, VinMinusMuxSelect_29=1, VinMinusMuxSelect_3=1, VinMinusMuxSelect_30=1, VinMinusMuxSelect_31=1, VinMinusMuxSelect_32=1, VinMinusMuxSelect_33=1, VinMinusMuxSelect_34=1, VinMinusMuxSelect_35=1, VinMinusMuxSelect_36=1, VinMinusMuxSelect_37=1, VinMinusMuxSelect_38=1, VinMinusMuxSelect_39=1, VinMinusMuxSelect_4=1, VinMinusMuxSelect_40=1, VinMinusMuxSelect_41=1, VinMinusMuxSelect_42=1, VinMinusMuxSelect_43=1, VinMinusMuxSelect_44=1, VinMinusMuxSelect_45=1, VinMinusMuxSelect_46=1, VinMinusMuxSelect_47=1, VinMinusMuxSelect_48=1, VinMinusMuxSelect_49=1, VinMinusMuxSelect_5=1, VinMinusMuxSelect_50=1, VinMinusMuxSelect_51=1, VinMinusMuxSelect_52=1, VinMinusMuxSelect_53=1, VinMinusMuxSelect_54=1, VinMinusMuxSelect_55=1, VinMinusMuxSelect_56=1, VinMinusMuxSelect_57=1, VinMinusMuxSelect_58=1, VinMinusMuxSelect_59=1, VinMinusMuxSelect_6=1, VinMinusMuxSelect_60=1, VinMinusMuxSelect_61=1, VinMinusMuxSelect_62=1, VinMinusMuxSelect_63=1, VinMinusMuxSelect_7=1, VinMinusMuxSelect_8=1, VinMinusMuxSelect_9=1, VinNegMuxSelect_0=1, VinNegMuxSelect_1=1, VinNegMuxSelect_2=1, VinNegMuxSelect_3=1, VinPlusMuxSelect_0=0, VinPlusMuxSelect_1=1, VinPlusMuxSelect_10=1, VinPlusMuxSelect_11=1, VinPlusMuxSelect_12=1, VinPlusMuxSelect_13=1, VinPlusMuxSelect_14=1, VinPlusMuxSelect_15=1, VinPlusMuxSelect_16=1, VinPlusMuxSelect_17=1, VinPlusMuxSelect_18=1, VinPlusMuxSelect_19=1, VinPlusMuxSelect_2=1, VinPlusMuxSelect_20=1, VinPlusMuxSelect_21=1, VinPlusMuxSelect_22=1, VinPlusMuxSelect_23=1, VinPlusMuxSelect_24=1, VinPlusMuxSelect_25=1, VinPlusMuxSelect_26=1, VinPlusMuxSelect_27=1, VinPlusMuxSelect_28=1, VinPlusMuxSelect_29=1, VinPlusMuxSelect_3=1, VinPlusMuxSelect_30=1, VinPlusMuxSelect_31=1, VinPlusMuxSelect_32=1, VinPlusMuxSelect_33=1, VinPlusMuxSelect_34=1, VinPlusMuxSelect_35=1, VinPlusMuxSelect_36=1, VinPlusMuxSelect_37=1, VinPlusMuxSelect_38=1, VinPlusMuxSelect_39=1, VinPlusMuxSelect_4=1, VinPlusMuxSelect_40=1, VinPlusMuxSelect_41=1, VinPlusMuxSelect_42=1, VinPlusMuxSelect_43=1, VinPlusMuxSelect_44=1, VinPlusMuxSelect_45=1, VinPlusMuxSelect_46=1, VinPlusMuxSelect_47=1, VinPlusMuxSelect_48=1, VinPlusMuxSelect_49=1, VinPlusMuxSelect_5=1, VinPlusMuxSelect_50=1, VinPlusMuxSelect_51=1, VinPlusMuxSelect_52=1, VinPlusMuxSelect_53=1, VinPlusMuxSelect_54=1, VinPlusMuxSelect_55=1, VinPlusMuxSelect_56=1, VinPlusMuxSelect_57=1, VinPlusMuxSelect_58=1, VinPlusMuxSelect_59=1, VinPlusMuxSelect_6=1, VinPlusMuxSelect_60=1, VinPlusMuxSelect_61=1, VinPlusMuxSelect_62=1, VinPlusMuxSelect_63=1, VinPlusMuxSelect_7=1, VinPlusMuxSelect_8=1, VinPlusMuxSelect_9=1, VminusMuxSelect=2, VplusMuxSelect=1, VrefMuxSelect_0=1, VrefMuxSelect_1=1, VrefMuxSelect_2=1, VrefMuxSelect_3=1, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=Scan_ADC_v2_10, CY_CONFIG_TITLE=ADC, CY_CONST_CONFIG=false, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=Scan_ADC_P6_v2_10.pdf, CY_FITTER_NAME=ADC, CY_INSTANCE_SHORT_NAME=ADC, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=sar, CY_PDL_DRIVER_REQ_VERSION=1.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.2, INSTANCE_NAME=ADC, )
module Scan_ADC_v2_10_3 (
    sdone,
    eos,
    t_chidv,
    t_chid,
    t_dav,
    t_da,
    t_fvout,
    t_fvalid,
    t_fvinternal,
    vagnd,
    vinPlus_0);
    output      sdone;
    output      eos;
    output      t_chidv;
    output     [3:0] t_chid;
    output      t_dav;
    output     [11:0] t_da;
    inout       t_fvout;
    electrical  t_fvout;
    output      t_fvalid;
    inout      [0:1] t_fvinternal;
    electrical [0:1] t_fvinternal;
    inout       vagnd;
    electrical  vagnd;
    inout       vinPlus_0;
    electrical  vinPlus_0;


          wire  sarClock;
          wire [1:0] st_sel;
    electrical  vref;
          wire  Net_34;
    electrical [3:0] vinNeg;
    electrical  muxoutPlus;
    electrical  muxoutMinus;
    electrical  sarmuxOutMinus;
    electrical  sarmuxOutPlus;
          wire  Net_33;
    electrical  Net_105;
    electrical  Net_100;
    electrical  Net_99;
          wire  Net_29;
          wire  Net_43;
    electrical [63:0] vinPlus;
          wire  Net_42;
          wire  Net_41;
          wire  Net_40;
          wire  Net_56;
    electrical  Net_102;
    electrical  Net_1405;
    electrical  Net_1379;
    electrical  Net_1447;
    electrical  Net_1448;
    electrical  Net_1385;
    electrical  Net_1388;
    electrical  Net_1382;
    electrical  Net_459;
    electrical  Net_458;
    electrical  Net_457;
    electrical  Net_456;
    electrical  Net_1399;
    electrical  Net_1402;
    electrical  Net_1406;
    electrical  Net_349;
    electrical  Net_347;
    electrical  Net_345;
    electrical  Net_331;
    electrical  Net_316;
    electrical  Net_315;
    electrical  Net_314;
    electrical  Net_313;
    electrical  Net_312;
    electrical  Net_311;
    electrical  Net_310;
    electrical  Net_309;
    electrical  Net_308;
    electrical  Net_307;
    electrical  Net_306;
    electrical  Net_305;
    electrical  Net_304;
    electrical  Net_303;
    electrical  Net_302;
    electrical  Net_301;
    electrical  Net_300;
    electrical  Net_299;
    electrical  Net_298;
    electrical  Net_297;
    electrical  Net_296;
    electrical  Net_295;
    electrical  Net_294;
    electrical  Net_293;
    electrical [63:0] vinMinus;
    electrical  Net_292;
    electrical  Net_291;
    electrical  Net_290;
    electrical  Net_289;
    electrical  Net_288;
    electrical  Net_287;
    electrical  Net_286;
    electrical  Net_285;
    electrical  Net_278;
    electrical  Net_276;
    electrical  Net_274;
    electrical  Net_272;
    electrical  Net_270;
    electrical  Net_268;
    electrical  Net_266;
    electrical  Net_264;
    electrical  Net_262;
    electrical  Net_260;
    electrical  Net_258;
    electrical  Net_256;
    electrical  Net_254;
    electrical  Net_252;
    electrical  Net_250;
    electrical  Net_248;
    electrical  Net_246;
    electrical  Net_244;
    electrical  Net_242;
    electrical  Net_240;
    electrical  Net_238;
    electrical  Net_236;
    electrical  Net_234;
    electrical  Net_232;
    electrical  Net_230;
    electrical  Net_228;
    electrical  Net_226;
    electrical  Net_224;
    electrical  Net_222;
    electrical  Net_220;
    electrical  Net_218;
    electrical  Net_213;
    electrical  Net_211;
    electrical  Net_210;
    electrical  Net_209;
    electrical  Net_208;
    electrical  Net_207;
    electrical  Net_206;
    electrical  Net_205;
    electrical  Net_204;
    electrical  Net_203;
    electrical  Net_202;
    electrical  Net_201;
    electrical  Net_200;
    electrical  Net_199;
    electrical  Net_198;
    electrical  Net_197;
    electrical  Net_196;
    electrical  Net_195;
    electrical  Net_194;
    electrical  Net_193;
    electrical  Net_192;
    electrical  Net_191;
    electrical  Net_190;
    electrical  Net_189;
    electrical  Net_188;
    electrical  Net_187;
    electrical  Net_186;
    electrical  Net_185;
    electrical  Net_184;
    electrical  Net_183;
    electrical  Net_182;
    electrical  Net_181;
    electrical  Net_180;
    electrical [3:0] vrefBus;
    electrical  Net_172;
    electrical  Net_170;
    electrical  Net_168;
    electrical  Net_166;
    electrical  Net_164;
    electrical  Net_162;
    electrical  Net_160;
    electrical  Net_158;
    electrical  Net_156;
    electrical  Net_154;
    electrical  Net_152;
    electrical  Net_150;
    electrical  Net_148;
    electrical  Net_146;
    electrical  Net_144;
    electrical  Net_142;
    electrical  Net_139;
    electrical  Net_137;
    electrical  Net_135;
    electrical  Net_133;
    electrical  Net_131;
    electrical  Net_129;
    electrical  Net_127;
    electrical  Net_125;
    electrical  Net_123;
    electrical  Net_121;
    electrical  Net_119;
    electrical  Net_117;
    electrical  Net_115;
    electrical  Net_113;
    electrical  Net_110;
    electrical  Net_107;
    electrical  Net_408;
          wire  Net_415;
          wire  Net_423;
          wire  Net_428;
    electrical [0:0] Net_21;
    electrical [0:0] Net_340;
    electrical [0:0] Net_339;


	cy_clock_v1_0
		#(.id("52d749fd-001b-4c0c-9c57-ebf2f1f0b739/f7143d07-534d-4542-813a-8bb23ceb1ae9"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("1000000000"),
		  .is_direct(0),
		  .is_digital(0))
		intSarClock
		 (.clock_out(Net_428));


	// vplusMux (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vplusMux_connect(muxoutPlus, vinPlus[0]);
	defparam vplusMux_connect.sig_width = 1;

	// vminusMux (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vminusMux_connect(muxoutMinus, vinNeg[0]);
	defparam vminusMux_connect.sig_width = 1;

    Bus_Connect_v2_50 vinPlusConnect (
        .in_bus(vinPlus[63:0]),
        .out_bus(Net_339[0:0]));
    defparam vinPlusConnect.in_width = 64;
    defparam vinPlusConnect.out_width = 1;

    Bus_Connect_v2_50 vinMinusConnect (
        .in_bus(vinMinus[63:0]),
        .out_bus(Net_340[0:0]));
    defparam vinMinusConnect.in_width = 64;
    defparam vinMinusConnect.out_width = 1;

    Bus_Connect_v2_50 vinNegConnect (
        .in_bus(vinNeg[3:0]),
        .out_bus(Net_21[0:0]));
    defparam vinNegConnect.in_width = 4;
    defparam vinNegConnect.out_width = 1;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_40));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_41));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_42));

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_43));

    ZeroTerminal ZeroTerminal_6 (
        .z(st_sel[1]));

    ZeroTerminal ZeroTerminal_7 (
        .z(st_sel[0]));

	// aclkMux (cy_virtualmux_v1_0)
	assign sarClock = Net_428;

	// socMux (cy_virtualmux_v1_0)
	assign Net_415 = Net_29;

	// extVrefMux (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 extVrefMux_connect(Net_408, Net_105);
	defparam extVrefMux_connect.sig_width = 1;


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		IRQ
		 (.int_signal(Net_423));


    ZeroTerminal ZeroTerminal_8 (
        .z(Net_29));

	// vinPlusMux_0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_0_connect(vinPlus[0], vinPlus_0);
	defparam vinPlusMux_0_connect.sig_width = 1;


    assign Net_34 = Net_33 | Net_428;

    ZeroTerminal ZeroTerminal_9 (
        .z(Net_33));

    cy_mxs40_sar_v1_0 SAR (
        .vplus(muxoutPlus),
        .vminus(muxoutMinus),
        .vref(vref),
        .ext_vref(Net_408),
        .dsi_sar_cfg_st_sel(st_sel[1:0]),
        .dsi_sar_cfg_average(Net_40),
        .dsi_sar_cfg_differential(Net_41),
        .dsi_sar_sw_negvref(Net_42),
        .dsi_sar_data_hilo_sel(Net_43),
        .tr_sar_in(Net_415),
        .clock(sarClock),
        .dsi_sar_sample_done(sdone),
        .dsi_sar_chan_id_valid(t_chidv),
        .dsi_sar_data_valid(t_dav),
        .tr_sar_out(eos),
        .dsi_sar_data(t_da[11:0]),
        .dsi_sar_chan_id(t_chid[3:0]),
        .interrupt(Net_423));
    defparam SAR.edge_trigger = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_133 (
        .noconnect(Net_107));

	// vinPlusMux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_1_connect(vinPlus[1], Net_110);
	defparam vinPlusMux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_134 (
        .noconnect(Net_110));

	// vinPlusMux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_2_connect(vinPlus[2], Net_113);
	defparam vinPlusMux_2_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_135 (
        .noconnect(Net_113));

	// vinPlusMux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_3_connect(vinPlus[3], Net_115);
	defparam vinPlusMux_3_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_136 (
        .noconnect(Net_115));

	// vinPlusMux_4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_4_connect(vinPlus[4], Net_117);
	defparam vinPlusMux_4_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_137 (
        .noconnect(Net_117));

	// vinPlusMux_5 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_5_connect(vinPlus[5], Net_119);
	defparam vinPlusMux_5_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_138 (
        .noconnect(Net_119));

	// vinPlusMux_6 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_6_connect(vinPlus[6], Net_121);
	defparam vinPlusMux_6_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_139 (
        .noconnect(Net_121));

	// vinPlusMux_7 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_7_connect(vinPlus[7], Net_123);
	defparam vinPlusMux_7_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_140 (
        .noconnect(Net_123));

	// vinPlusMux_8 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_8_connect(vinPlus[8], Net_125);
	defparam vinPlusMux_8_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_141 (
        .noconnect(Net_125));

	// vinPlusMux_9 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_9_connect(vinPlus[9], Net_127);
	defparam vinPlusMux_9_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_142 (
        .noconnect(Net_127));

	// vinPlusMux_10 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_10_connect(vinPlus[10], Net_129);
	defparam vinPlusMux_10_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_143 (
        .noconnect(Net_129));

	// vinPlusMux_11 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_11_connect(vinPlus[11], Net_131);
	defparam vinPlusMux_11_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_144 (
        .noconnect(Net_131));

	// vinPlusMux_12 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_12_connect(vinPlus[12], Net_133);
	defparam vinPlusMux_12_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_145 (
        .noconnect(Net_133));

	// vinPlusMux_13 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_13_connect(vinPlus[13], Net_135);
	defparam vinPlusMux_13_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_146 (
        .noconnect(Net_135));

	// vinPlusMux_14 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_14_connect(vinPlus[14], Net_137);
	defparam vinPlusMux_14_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_147 (
        .noconnect(Net_137));

	// vinPlusMux_15 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_15_connect(vinPlus[15], Net_139);
	defparam vinPlusMux_15_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_148 (
        .noconnect(Net_139));

	// vinPlusMux_16 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_16_connect(vinPlus[16], Net_142);
	defparam vinPlusMux_16_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_149 (
        .noconnect(Net_142));

	// vinPlusMux_17 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_17_connect(vinPlus[17], Net_144);
	defparam vinPlusMux_17_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_150 (
        .noconnect(Net_144));

	// vinPlusMux_18 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_18_connect(vinPlus[18], Net_146);
	defparam vinPlusMux_18_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_151 (
        .noconnect(Net_146));

	// vinPlusMux_19 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_19_connect(vinPlus[19], Net_148);
	defparam vinPlusMux_19_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_152 (
        .noconnect(Net_148));

	// vinPlusMux_20 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_20_connect(vinPlus[20], Net_150);
	defparam vinPlusMux_20_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_153 (
        .noconnect(Net_150));

	// vinPlusMux_21 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_21_connect(vinPlus[21], Net_152);
	defparam vinPlusMux_21_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_154 (
        .noconnect(Net_152));

	// vinPlusMux_22 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_22_connect(vinPlus[22], Net_154);
	defparam vinPlusMux_22_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_155 (
        .noconnect(Net_154));

	// vinPlusMux_23 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_23_connect(vinPlus[23], Net_156);
	defparam vinPlusMux_23_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_156 (
        .noconnect(Net_156));

	// vinPlusMux_24 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_24_connect(vinPlus[24], Net_158);
	defparam vinPlusMux_24_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_157 (
        .noconnect(Net_158));

	// vinPlusMux_25 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_25_connect(vinPlus[25], Net_160);
	defparam vinPlusMux_25_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_158 (
        .noconnect(Net_160));

	// vinPlusMux_26 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_26_connect(vinPlus[26], Net_162);
	defparam vinPlusMux_26_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_159 (
        .noconnect(Net_162));

	// vinPlusMux_27 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_27_connect(vinPlus[27], Net_164);
	defparam vinPlusMux_27_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_160 (
        .noconnect(Net_164));

	// vinPlusMux_28 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_28_connect(vinPlus[28], Net_166);
	defparam vinPlusMux_28_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_161 (
        .noconnect(Net_166));

	// vinPlusMux_29 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_29_connect(vinPlus[29], Net_168);
	defparam vinPlusMux_29_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_162 (
        .noconnect(Net_168));

	// vinPlusMux_30 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_30_connect(vinPlus[30], Net_170);
	defparam vinPlusMux_30_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_163 (
        .noconnect(Net_170));

	// vinPlusMux_31 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_31_connect(vinPlus[31], Net_172);
	defparam vinPlusMux_31_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_164 (
        .noconnect(Net_172));

	// vinPlusMux_32 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_32_connect(vinPlus[32], Net_180);
	defparam vinPlusMux_32_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_165 (
        .noconnect(Net_180));

	// vinPlusMux_33 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_33_connect(vinPlus[33], Net_181);
	defparam vinPlusMux_33_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_166 (
        .noconnect(Net_181));

	// vinPlusMux_34 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_34_connect(vinPlus[34], Net_182);
	defparam vinPlusMux_34_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_167 (
        .noconnect(Net_182));

	// vinPlusMux_35 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_35_connect(vinPlus[35], Net_183);
	defparam vinPlusMux_35_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_168 (
        .noconnect(Net_183));

	// vinPlusMux_36 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_36_connect(vinPlus[36], Net_184);
	defparam vinPlusMux_36_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_169 (
        .noconnect(Net_184));

	// vinPlusMux_37 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_37_connect(vinPlus[37], Net_185);
	defparam vinPlusMux_37_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_170 (
        .noconnect(Net_185));

	// vinPlusMux_38 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_38_connect(vinPlus[38], Net_186);
	defparam vinPlusMux_38_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_171 (
        .noconnect(Net_186));

	// vinPlusMux_39 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_39_connect(vinPlus[39], Net_187);
	defparam vinPlusMux_39_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_172 (
        .noconnect(Net_187));

	// vinPlusMux_40 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_40_connect(vinPlus[40], Net_188);
	defparam vinPlusMux_40_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_173 (
        .noconnect(Net_188));

	// vinPlusMux_41 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_41_connect(vinPlus[41], Net_189);
	defparam vinPlusMux_41_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_174 (
        .noconnect(Net_189));

	// vinPlusMux_42 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_42_connect(vinPlus[42], Net_190);
	defparam vinPlusMux_42_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_175 (
        .noconnect(Net_190));

	// vinPlusMux_43 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_43_connect(vinPlus[43], Net_191);
	defparam vinPlusMux_43_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_176 (
        .noconnect(Net_191));

	// vinPlusMux_44 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_44_connect(vinPlus[44], Net_192);
	defparam vinPlusMux_44_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_177 (
        .noconnect(Net_192));

	// vinPlusMux_45 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_45_connect(vinPlus[45], Net_193);
	defparam vinPlusMux_45_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_178 (
        .noconnect(Net_193));

	// vinPlusMux_46 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_46_connect(vinPlus[46], Net_194);
	defparam vinPlusMux_46_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_179 (
        .noconnect(Net_194));

	// vinPlusMux_47 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_47_connect(vinPlus[47], Net_195);
	defparam vinPlusMux_47_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_180 (
        .noconnect(Net_195));

	// vinPlusMux_48 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_48_connect(vinPlus[48], Net_196);
	defparam vinPlusMux_48_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_181 (
        .noconnect(Net_196));

	// vinPlusMux_49 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_49_connect(vinPlus[49], Net_197);
	defparam vinPlusMux_49_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_182 (
        .noconnect(Net_197));

	// vinPlusMux_50 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_50_connect(vinPlus[50], Net_198);
	defparam vinPlusMux_50_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_183 (
        .noconnect(Net_198));

	// vinPlusMux_51 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_51_connect(vinPlus[51], Net_199);
	defparam vinPlusMux_51_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_184 (
        .noconnect(Net_199));

	// vinPlusMux_52 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_52_connect(vinPlus[52], Net_200);
	defparam vinPlusMux_52_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_185 (
        .noconnect(Net_200));

	// vinPlusMux_53 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_53_connect(vinPlus[53], Net_201);
	defparam vinPlusMux_53_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_186 (
        .noconnect(Net_201));

	// vinPlusMux_54 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_54_connect(vinPlus[54], Net_202);
	defparam vinPlusMux_54_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_187 (
        .noconnect(Net_202));

	// vinPlusMux_55 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_55_connect(vinPlus[55], Net_203);
	defparam vinPlusMux_55_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_188 (
        .noconnect(Net_203));

	// vinPlusMux_56 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_56_connect(vinPlus[56], Net_204);
	defparam vinPlusMux_56_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_189 (
        .noconnect(Net_204));

	// vinPlusMux_57 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_57_connect(vinPlus[57], Net_205);
	defparam vinPlusMux_57_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_190 (
        .noconnect(Net_205));

	// vinPlusMux_58 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_58_connect(vinPlus[58], Net_206);
	defparam vinPlusMux_58_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_191 (
        .noconnect(Net_206));

	// vinPlusMux_59 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_59_connect(vinPlus[59], Net_207);
	defparam vinPlusMux_59_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_192 (
        .noconnect(Net_207));

	// vinPlusMux_60 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_60_connect(vinPlus[60], Net_208);
	defparam vinPlusMux_60_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_193 (
        .noconnect(Net_208));

	// vinPlusMux_61 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_61_connect(vinPlus[61], Net_209);
	defparam vinPlusMux_61_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_194 (
        .noconnect(Net_209));

	// vinPlusMux_62 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_62_connect(vinPlus[62], Net_210);
	defparam vinPlusMux_62_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_195 (
        .noconnect(Net_210));

	// vinPlusMux_63 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinPlusMux_63_connect(vinPlus[63], Net_211);
	defparam vinPlusMux_63_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_196 (
        .noconnect(Net_211));

	// vinMinusMux_0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_0_connect(vinMinus[0], Net_213);
	defparam vinMinusMux_0_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_213));

	// vinMinusMux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_1_connect(vinMinus[1], Net_218);
	defparam vinMinusMux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_218));

	// vinMinusMux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_2_connect(vinMinus[2], Net_220);
	defparam vinMinusMux_2_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_220));

	// vinMinusMux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_3_connect(vinMinus[3], Net_222);
	defparam vinMinusMux_3_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_4 (
        .noconnect(Net_222));

	// vinMinusMux_4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_4_connect(vinMinus[4], Net_224);
	defparam vinMinusMux_4_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_5 (
        .noconnect(Net_224));

	// vinMinusMux_5 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_5_connect(vinMinus[5], Net_226);
	defparam vinMinusMux_5_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_6 (
        .noconnect(Net_226));

	// vinMinusMux_6 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_6_connect(vinMinus[6], Net_228);
	defparam vinMinusMux_6_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_7 (
        .noconnect(Net_228));

	// vinMinusMux_7 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_7_connect(vinMinus[7], Net_230);
	defparam vinMinusMux_7_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_8 (
        .noconnect(Net_230));

	// vinMinusMux_8 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_8_connect(vinMinus[8], Net_232);
	defparam vinMinusMux_8_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_9 (
        .noconnect(Net_232));

	// vinMinusMux_9 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_9_connect(vinMinus[9], Net_234);
	defparam vinMinusMux_9_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_10 (
        .noconnect(Net_234));

	// vinMinusMux_10 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_10_connect(vinMinus[10], Net_236);
	defparam vinMinusMux_10_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_11 (
        .noconnect(Net_236));

	// vinMinusMux_11 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_11_connect(vinMinus[11], Net_238);
	defparam vinMinusMux_11_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_12 (
        .noconnect(Net_238));

	// vinMinusMux_12 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_12_connect(vinMinus[12], Net_240);
	defparam vinMinusMux_12_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_13 (
        .noconnect(Net_240));

	// vinMinusMux_13 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_13_connect(vinMinus[13], Net_242);
	defparam vinMinusMux_13_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_14 (
        .noconnect(Net_242));

	// vinMinusMux_14 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_14_connect(vinMinus[14], Net_244);
	defparam vinMinusMux_14_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_15 (
        .noconnect(Net_244));

	// vinMinusMux_15 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_15_connect(vinMinus[15], Net_246);
	defparam vinMinusMux_15_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_16 (
        .noconnect(Net_246));

	// vinMinusMux_16 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_16_connect(vinMinus[16], Net_248);
	defparam vinMinusMux_16_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_17 (
        .noconnect(Net_248));

	// vinMinusMux_17 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_17_connect(vinMinus[17], Net_250);
	defparam vinMinusMux_17_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_18 (
        .noconnect(Net_250));

	// vinMinusMux_18 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_18_connect(vinMinus[18], Net_252);
	defparam vinMinusMux_18_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_19 (
        .noconnect(Net_252));

	// vinMinusMux_19 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_19_connect(vinMinus[19], Net_254);
	defparam vinMinusMux_19_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_20 (
        .noconnect(Net_254));

	// vinMinusMux_20 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_20_connect(vinMinus[20], Net_256);
	defparam vinMinusMux_20_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_21 (
        .noconnect(Net_256));

	// vinMinusMux_21 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_21_connect(vinMinus[21], Net_258);
	defparam vinMinusMux_21_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_22 (
        .noconnect(Net_258));

	// vinMinusMux_22 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_22_connect(vinMinus[22], Net_260);
	defparam vinMinusMux_22_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_23 (
        .noconnect(Net_260));

	// vinMinusMux_23 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_23_connect(vinMinus[23], Net_262);
	defparam vinMinusMux_23_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_24 (
        .noconnect(Net_262));

	// vinMinusMux_24 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_24_connect(vinMinus[24], Net_264);
	defparam vinMinusMux_24_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_25 (
        .noconnect(Net_264));

	// vinMinusMux_25 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_25_connect(vinMinus[25], Net_266);
	defparam vinMinusMux_25_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_26 (
        .noconnect(Net_266));

	// vinMinusMux_26 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_26_connect(vinMinus[26], Net_268);
	defparam vinMinusMux_26_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_27 (
        .noconnect(Net_268));

	// vinMinusMux_27 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_27_connect(vinMinus[27], Net_270);
	defparam vinMinusMux_27_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_28 (
        .noconnect(Net_270));

	// vinMinusMux_28 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_28_connect(vinMinus[28], Net_272);
	defparam vinMinusMux_28_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_29 (
        .noconnect(Net_272));

	// vinMinusMux_29 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_29_connect(vinMinus[29], Net_274);
	defparam vinMinusMux_29_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_30 (
        .noconnect(Net_274));

	// vinMinusMux_30 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_30_connect(vinMinus[30], Net_276);
	defparam vinMinusMux_30_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_31 (
        .noconnect(Net_276));

	// vinMinusMux_31 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_31_connect(vinMinus[31], Net_278);
	defparam vinMinusMux_31_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_32 (
        .noconnect(Net_278));

	// vinMinusMux_32 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_32_connect(vinMinus[32], Net_285);
	defparam vinMinusMux_32_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_33 (
        .noconnect(Net_285));

	// vinMinusMux_33 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_33_connect(vinMinus[33], Net_286);
	defparam vinMinusMux_33_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_34 (
        .noconnect(Net_286));

	// vinMinusMux_34 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_34_connect(vinMinus[34], Net_287);
	defparam vinMinusMux_34_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_35 (
        .noconnect(Net_287));

	// vinMinusMux_35 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_35_connect(vinMinus[35], Net_288);
	defparam vinMinusMux_35_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_36 (
        .noconnect(Net_288));

	// vinMinusMux_36 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_36_connect(vinMinus[36], Net_289);
	defparam vinMinusMux_36_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_37 (
        .noconnect(Net_289));

	// vinMinusMux_37 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_37_connect(vinMinus[37], Net_290);
	defparam vinMinusMux_37_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_38 (
        .noconnect(Net_290));

	// vinMinusMux_38 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_38_connect(vinMinus[38], Net_291);
	defparam vinMinusMux_38_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_39 (
        .noconnect(Net_291));

	// vinMinusMux_39 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_39_connect(vinMinus[39], Net_292);
	defparam vinMinusMux_39_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_40 (
        .noconnect(Net_292));

	// vinMinusMux_40 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_40_connect(vinMinus[40], Net_293);
	defparam vinMinusMux_40_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_41 (
        .noconnect(Net_293));

	// vinMinusMux_41 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_41_connect(vinMinus[41], Net_294);
	defparam vinMinusMux_41_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_42 (
        .noconnect(Net_294));

	// vinMinusMux_42 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_42_connect(vinMinus[42], Net_295);
	defparam vinMinusMux_42_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_43 (
        .noconnect(Net_295));

	// vinMinusMux_43 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_43_connect(vinMinus[43], Net_296);
	defparam vinMinusMux_43_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_44 (
        .noconnect(Net_296));

	// vinMinusMux_44 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_44_connect(vinMinus[44], Net_297);
	defparam vinMinusMux_44_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_45 (
        .noconnect(Net_297));

	// vinMinusMux_45 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_45_connect(vinMinus[45], Net_298);
	defparam vinMinusMux_45_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_46 (
        .noconnect(Net_298));

	// vinMinusMux_46 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_46_connect(vinMinus[46], Net_299);
	defparam vinMinusMux_46_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_47 (
        .noconnect(Net_299));

	// vinMinusMux_47 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_47_connect(vinMinus[47], Net_300);
	defparam vinMinusMux_47_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_48 (
        .noconnect(Net_300));

	// vinMinusMux_48 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_48_connect(vinMinus[48], Net_301);
	defparam vinMinusMux_48_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_49 (
        .noconnect(Net_301));

	// vinMinusMux_49 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_49_connect(vinMinus[49], Net_302);
	defparam vinMinusMux_49_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_50 (
        .noconnect(Net_302));

	// vinMinusMux_50 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_50_connect(vinMinus[50], Net_303);
	defparam vinMinusMux_50_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_51 (
        .noconnect(Net_303));

	// vinMinusMux_51 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_51_connect(vinMinus[51], Net_304);
	defparam vinMinusMux_51_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_52 (
        .noconnect(Net_304));

	// vinMinusMux_52 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_52_connect(vinMinus[52], Net_305);
	defparam vinMinusMux_52_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_53 (
        .noconnect(Net_305));

	// vinMinusMux_53 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_53_connect(vinMinus[53], Net_306);
	defparam vinMinusMux_53_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_54 (
        .noconnect(Net_306));

	// vinMinusMux_54 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_54_connect(vinMinus[54], Net_307);
	defparam vinMinusMux_54_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_55 (
        .noconnect(Net_307));

	// vinMinusMux_55 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_55_connect(vinMinus[55], Net_308);
	defparam vinMinusMux_55_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_56 (
        .noconnect(Net_308));

	// vinMinusMux_56 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_56_connect(vinMinus[56], Net_309);
	defparam vinMinusMux_56_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_57 (
        .noconnect(Net_309));

	// vinMinusMux_57 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_57_connect(vinMinus[57], Net_310);
	defparam vinMinusMux_57_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_58 (
        .noconnect(Net_310));

	// vinMinusMux_58 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_58_connect(vinMinus[58], Net_311);
	defparam vinMinusMux_58_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_59 (
        .noconnect(Net_311));

	// vinMinusMux_59 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_59_connect(vinMinus[59], Net_312);
	defparam vinMinusMux_59_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_60 (
        .noconnect(Net_312));

	// vinMinusMux_60 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_60_connect(vinMinus[60], Net_313);
	defparam vinMinusMux_60_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_61 (
        .noconnect(Net_313));

	// vinMinusMux_61 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_61_connect(vinMinus[61], Net_314);
	defparam vinMinusMux_61_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_62 (
        .noconnect(Net_314));

	// vinMinusMux_62 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_62_connect(vinMinus[62], Net_315);
	defparam vinMinusMux_62_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_63 (
        .noconnect(Net_315));

	// vinMinusMux_63 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinMinusMux_63_connect(vinMinus[63], Net_316);
	defparam vinMinusMux_63_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_64 (
        .noconnect(Net_316));

	// vinNegMux_0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinNegMux_0_connect(vinNeg[0], Net_331);
	defparam vinNegMux_0_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_65 (
        .noconnect(Net_331));

	// vinNegMux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinNegMux_1_connect(vinNeg[1], Net_345);
	defparam vinNegMux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_66 (
        .noconnect(Net_345));

	// vinNegMux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinNegMux_2_connect(vinNeg[2], Net_347);
	defparam vinNegMux_2_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_67 (
        .noconnect(Net_347));

	// vinNegMux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vinNegMux_3_connect(vinNeg[3], Net_349);
	defparam vinNegMux_3_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_68 (
        .noconnect(Net_349));

	// vrefMux_0 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vrefMux_0_connect(vrefBus[0], Net_456);
	defparam vrefMux_0_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_71 (
        .noconnect(Net_456));

	// vrefMux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vrefMux_1_connect(vrefBus[1], Net_457);
	defparam vrefMux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_72 (
        .noconnect(Net_457));

	// vrefMux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vrefMux_2_connect(vrefBus[2], Net_458);
	defparam vrefMux_2_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_73 (
        .noconnect(Net_458));

	// vrefMux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vrefMux_3_connect(vrefBus[3], Net_459);
	defparam vrefMux_3_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_74 (
        .noconnect(Net_459));

	// vrefMuxRemoved (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 vrefMuxRemoved_connect(vref, Net_1448);
	defparam vrefMuxRemoved_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_87 (
        .noconnect(Net_1448));

    assign t_fvalid = 1'h0;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_fvint (
        .noconnect(t_fvinternal[1]));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_fvint_1 (
        .noconnect(t_fvinternal[0]));


	cy_vref_v1_0
		#(.guid("6E0C5DC9-D531-4D01-9B49-536487FE4A82"),
		  .name("Bandgap Reference"),
		  .autoenable(1))
		vRef_4
		 (.vout(Net_1379));



	cy_vref_v1_0
		#(.guid("6E0C5DC9-D531-4D01-9B49-536487FE4A82"),
		  .name("Bandgap Reference"),
		  .autoenable(1))
		vRef_6
		 (.vout(Net_1385));



	cy_vref_v1_0
		#(.guid("6E0C5DC9-D531-4D01-9B49-536487FE4A82"),
		  .name("Bandgap Reference"),
		  .autoenable(1))
		vRef_7
		 (.vout(Net_1388));



	cy_vref_v1_0
		#(.guid("6E0C5DC9-D531-4D01-9B49-536487FE4A82"),
		  .name("Bandgap Reference"),
		  .autoenable(1))
		vRef_5
		 (.vout(Net_1382));



	cy_vref_v1_0
		#(.guid("A74A229D-E18B-4A00-BEEC-CCDCB446AC07 "),
		  .name(""),
		  .autoenable(1))
		vRef_8
		 (.vout(Net_102));


    cy_analog_noconnect_v1_0 cy_analog_noconnect_69 (
        .noconnect(Net_105));


    cy_connect_v1_0 vagnd__cy_connect_v1_0(vagnd, t_fvout);
    defparam vagnd__cy_connect_v1_0.sig_width = 1;


endmodule

// Component: cy_tff_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_tff_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_tff_v1_0\cy_tff_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_tff_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.2\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_tff_v1_0\cy_tff_v1_0.v"
`endif

// top
module top ;

          wire  Net_202;
          wire  Net_190;
    electrical  Net_148;
    electrical [1:0] Net_147;
          wire  Net_146;
    electrical  Net_145;
          wire [11:0] Net_144;
          wire  Net_143;
          wire [3:0] Net_142;
          wire  Net_141;
          wire  Net_160;
          wire  Net_139;
          wire  Net_28;
          wire  Net_27;
          wire  Net_26;
          wire  Net_25;
          wire  Net_24;
          wire  Net_23;
          wire  Net_22;
          wire  Net_21;
          wire  Net_20;
          wire  Net_19;
          wire  Net_205;
          wire  Net_204;
          wire  Net_203;
          wire  Net_194;
          wire  Net_195;
    electrical  Net_149;

    BLE_PDL_v2_0_1 BLE_1 (
        .pa_tx_en(Net_203),
        .lna_rx_en(Net_204),
        .pa_lna_en(Net_205));

	wire [0:0] tmpFB_0__Connection_LED_net;
	wire [0:0] tmpIO_0__Connection_LED_net;
	electrical [0:0] tmpSIOVREF__Connection_LED_net;

	cy_mxs40_gpio_v1_0
		#(.id("a61270bc-07ec-447d-ac9e-34cfe85c30e9"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Connection_LED
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Connection_LED_net[0:0]}),
		  .io({tmpIO_0__Connection_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__Connection_LED_net));


    SCB_UART_PDL_v2_0_2 UART (
        .cts_in(1'b0),
        .tx_out(Net_20),
        .rts_out(Net_21),
        .interrupt(Net_22),
        .clock(1'b0),
        .rx_dma(Net_24),
        .tx_dma(Net_25),
        .rx_in(1'b0),
        .rx_tx_out(Net_27),
        .tx_en_out(Net_28));

    Scan_ADC_v2_10_3 ADC (
        .sdone(Net_139),
        .eos(Net_160),
        .t_chidv(Net_141),
        .t_chid(Net_142[3:0]),
        .t_dav(Net_143),
        .t_da(Net_144[11:0]),
        .t_fvout(Net_145),
        .t_fvalid(Net_146),
        .t_fvinternal(Net_147[1:0]),
        .vagnd(Net_148),
        .vinPlus_0(Net_149));


	cy_clock_v1_0
		#(.id("4b937de1-f27f-4e94-9504-6c9a55a548db"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("231481481481.481"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_1
		 (.clock_out(Net_195));


	wire [0:0] tmpFB_0__Pin_1_net;
	wire [0:0] tmpIO_0__Pin_1_net;
	electrical [0:0] tmpSIOVREF__Pin_1_net;

	cy_mxs40_gpio_v1_0
		#(.id("0113321b-4a37-46f6-8407-2f8646c68756"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Pin_1
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Pin_1_net[0:0]}),
		  .analog({Net_149}),
		  .io({tmpIO_0__Pin_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_1_net));



	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b00))
		ADC_INT
		 (.int_signal(Net_160));


    assign Net_194 = 1'h1;

    // -- TFF Start --
    reg  cy_tff_1;
    always @(posedge Net_195)
    begin
        cy_tff_1 <= Net_194^Net_202;
    end
    assign Net_202 = cy_tff_1;
    // -- TFF End --


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b00))
		SCAN_INT
		 (.int_signal(Net_202));


	wire [0:0] tmpFB_0__Power_LED_net;
	wire [0:0] tmpIO_0__Power_LED_net;
	electrical [0:0] tmpSIOVREF__Power_LED_net;

	cy_mxs40_gpio_v1_0
		#(.id("84b7a192-d1d3-4e8f-b378-4c777a5797f7"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Power_LED
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Power_LED_net[0:0]}),
		  .io({tmpIO_0__Power_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__Power_LED_net));


	wire [0:0] tmpFB_0__Overvoltage_LED_net;
	wire [0:0] tmpIO_0__Overvoltage_LED_net;
	electrical [0:0] tmpSIOVREF__Overvoltage_LED_net;

	cy_mxs40_gpio_v1_0
		#(.id("0058b4aa-ace1-44e7-ad75-34d637c786ec"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Overvoltage_LED
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Overvoltage_LED_net[0:0]}),
		  .io({tmpIO_0__Overvoltage_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__Overvoltage_LED_net));


	wire [0:0] tmpFB_0__Undervoltage_LED_net;
	wire [0:0] tmpIO_0__Undervoltage_LED_net;
	electrical [0:0] tmpSIOVREF__Undervoltage_LED_net;

	cy_mxs40_gpio_v1_0
		#(.id("d6d5a67b-a8d9-4ad5-bfbc-7086657a7538"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Undervoltage_LED
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Undervoltage_LED_net[0:0]}),
		  .io({tmpIO_0__Undervoltage_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__Undervoltage_LED_net));


	wire [0:0] tmpFB_0__Voltage_OK_net;
	wire [0:0] tmpIO_0__Voltage_OK_net;
	electrical [0:0] tmpSIOVREF__Voltage_OK_net;

	cy_mxs40_gpio_v1_0
		#(.id("1cf55e7e-2075-40fe-8494-967e02c0a7b3"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Voltage_OK
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Voltage_OK_net[0:0]}),
		  .io({tmpIO_0__Voltage_OK_net[0:0]}),
		  .siovref(tmpSIOVREF__Voltage_OK_net));




endmodule

